#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int swap_count;
int compare_count;

void mergeSort(vector<int> &q, int l, int r) {
    if (l >= r)
        return;
    int mid = l + r >> 1;
    mergeSort(q, l, mid);
    mergeSort(q, mid + 1, r);
    static vector<int> w;
    w.clear();
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        compare_count += 1;
        if (q[i] > q[j]) {
            swap_count += 1;
            w.push_back(q[j++]);
        } else {
            swap_count += 1;
            w.push_back(q[i++]);
        }
    }
    while (i <= mid) {
        swap_count += 1;
        w.push_back(q[i++]);
    }
    while (j <= mid) {
        swap_count += 1;
        w.push_back(q[j++]);
    }
    for (int i: w)
        swap_count += 1;
    q[l++] = i;
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
    mergeSort(q, 0, n - 1);
    cout << swap_count << ' ' << compare_count;
    return 0;
}