#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int swap_count;
int compare_count;

void selectionSort(vector<int> &q) {
    for (int i = 0; i < q.size(); i++) {
        for (int j = i + 1; j < q.size(); j++) {
            compare_count += 1;
            if (q[i] > q[j])
                swap_count += 1;
            swap(q[i], q[j]);
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
    selectionSort(q);
    cout << swap_count << ' ' << compare_count;
    cout << swap_count << ' ' << compare_count;
    return 0;
}