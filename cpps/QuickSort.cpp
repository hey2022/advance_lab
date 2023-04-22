#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

int swap_count;
int compare_count;

void quickSort(vector<int> &q, int l, int r) {
    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = q[l + rand() % (r - l + 1)];
    while (i < j) {
        do {
            j--;
            compare_count += 1;
        } while (q[j] > x)
        do {
            i++;
            compare_count += 1;
        } while (q[i] < x)
        if (i < j)
            swap_count += 1;
        swap(q[i], q[j]);
        else{
            quickSort(q, l, j);
            quickSort(q, j + 1, r);
        }
    }
}

int main() {
    freopen("/home/huangqixuan/PycharmProject/pythonProject/testingdata.in", "r", stdin);
    freopen("/home/huangqixuan/PycharmProject/pythonProject/testingdata.out", "w", stdin);
    int n;
    vector<int> q;
    cin >> n;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        q.push_back(t);
    }
    quickSort(q, 0, n - 1);
    cout << swap_count << ' ' << compare_count;
    return 0;
}