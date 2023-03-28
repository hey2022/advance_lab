fn main() {
    let mut data = vec![7, 5, 7, 2, 4, 6, 13, 3, 9, 6, 4, 2, 3, 4];
    radix_sort_helper(&mut data, 10);
    println!("{:?}", data);
}

fn radix_sort_helper(array: &mut [i32], radix: usize) {
    let mut negative = array
        .iter()
        .copied()
        .filter(|&x| x < 0)
        .map(|x| x.abs())
        .collect::<Vec<i32>>();
    radix_sort(&mut negative, radix);
    negative = negative.iter().rev().map(|x| -x).collect::<Vec<i32>>();
    let mut positive = array
        .iter()
        .copied()
        .filter(|&x| x >= 0)
        .collect::<Vec<i32>>();
    radix_sort(&mut positive, radix);
    negative.append(&mut positive);
    for (i, n) in negative.iter().enumerate() {
        array[i] = *n; 
    }
}

fn radix_sort(array: &mut [i32], radix: usize) {
    if array.is_empty() {
        return;
    }
    let mut max = *array.iter().max().expect("array empty");
    let mut max_digit = 0;
    while max != 0 {
        max /= radix as i32;
        max_digit += 1;
    }
    for digit in 0..max_digit {
        counting_sort(array, digit, radix);
    }
}

fn counting_sort(array: &mut [i32], digit: u32, radix: usize) {
    let mut count = vec![0; radix];
    for number in array.iter() {
        count[get_digit(*number, digit, radix)] += 1;
    }
    for i in 1..count.len() {
        count[i] += count[i - 1];
    }
    for num in array.to_owned().iter().rev() {
        count[get_digit(*num, digit, radix)] -= 1;
        array[count[get_digit(*num, digit, radix)]] = *num;
    }
}

fn get_digit(number: i32, digit: u32, radix: usize) -> usize {
    let radix = radix as i32;
    (number / radix.pow(digit) % radix) as usize
}

#[cfg(test)]
mod tests {
    use crate::radix_sort_helper;
    use rand::Rng;

    const SIZE: usize = 1000;
    const NUM_RANGE: std::ops::Range<i32> = i32::MIN..i32::MAX; 

    #[test]
    fn empty() {
        let mut data = [];
        radix_sort_helper(&mut data, 10);
        assert_eq!(data, []);
    }

    #[test]
    fn single() {
        let mut data = [1];
        radix_sort_helper(&mut data, 10);
        assert_eq!(data, [1]);
    }

    #[test]
    fn zero() {
        let mut data = [0; SIZE];
        radix_sort_helper(&mut data, 10);
        assert_eq!(data, [0; SIZE]);
    }

    #[test]
    fn ordered() {
        let mut data = (0..=SIZE as i32).collect::<Vec<i32>>();
        radix_sort_helper(&mut data, 10);
        assert_eq!(data, (0..=SIZE as i32).collect::<Vec<i32>>());
    }

    #[test]
    fn reversed() {
        let mut data = (0..=SIZE as i32).rev().collect::<Vec<i32>>();
        radix_sort_helper(&mut data, 10);
        assert_eq!(data, (0..=SIZE as i32).collect::<Vec<i32>>());
    }

    #[test]
    fn same() {
        let mut data = [5; SIZE];
        radix_sort_helper(&mut data, 10);
        assert_eq!(data, [5; SIZE]);
    }

    #[test]
    fn positive() {
        let mut data = [17, 5, 7, 2, 4, 6, 13, 3, 9, 6];
        radix_sort_helper(&mut data, 10);
        assert_eq!(data, [2, 3, 4, 5, 6, 6, 7, 9, 13, 17]);
    }

    #[test]
    fn negative() {
        let mut data = [-2, -4, -2, -6, -234, -45, -13, -65, -23, -456];
        radix_sort_helper(&mut data, 10);
        assert_eq!(data, [-456, -234, -65, -45, -23, -13, -6, -4, -2, -2]);
    }

    #[test]
    fn mixed() {
        let mut data = [234, -234, 564, -25, 63, -62, 64, -267, -246, 163];
        radix_sort_helper(&mut data, 10);
        assert_eq!(data, [-267, -246, -234, -62, -25, 63, 64, 163, 234, 564]);
    }

    #[test]
    fn random() {
        let mut data = Vec::with_capacity(SIZE);
        let mut rng = rand::thread_rng();
        for _ in 0..SIZE {
            data.push(rng.gen_range(NUM_RANGE));
        }
        radix_sort_helper(&mut data, 10);
        for i in 1..data.len() {
            if data[i] < data[i - 1] {
                panic!();
            }
        }
    }
}
