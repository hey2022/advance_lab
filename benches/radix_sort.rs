use advance_lab::radix_sort;
use criterion::{criterion_group, criterion_main, BenchmarkId, Criterion};
use rand::Rng;

pub fn criterion_benchmark(c: &mut Criterion) {
    let size = 2usize.pow(20);
    let mut i = 1;
    let mut group = c.benchmark_group("radix_sort");
    while i <= size {
        group.bench_with_input(BenchmarkId::from_parameter(i), &i, |b, &i| {
            let mut data = Vec::with_capacity(size);
            let mut rng = rand::thread_rng();
            for _ in 0..i {
                data.push(rng.gen_range(i32::MIN..i32::MAX));
            }
            b.iter(|| radix_sort::radix_sort_neg(&mut data, 10));
        });
        i *= 2;
    }
    group.finish();
}

criterion_group!(benches, criterion_benchmark);
criterion_main!(benches);
