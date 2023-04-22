#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int swap_count;
int compare_count;

void insertionSort(vector<int> &q) {
    for (int i = 1; i < q.size(); i++) {
        int t = q[i], j;
        for (j = i - 1; j >= 0; j--) {
            compare_count += 1;
            if (q[j] > t)
                swap_count += 1;
            q[j + 1] = q[j];
            else
            break;
        }
        swap_count += 1;
        q[j + 1] = t;
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
    insertionSort(q);
    cout << swap_count << ' ' << compare_count;
    return 0;
}