#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int swap_count;
int compare_count;

void bubbleSort(vector<int> &q) {
    for (int i = q.size() - 1; i > 0; i--) {
        bool flag = false;
        for (int j = 0; j + 1 <= i; j++) {
            compare_count += 1;
            if (q[j] > q[j + 1]) {
                swap_count += 1;
                swap(q[j], q[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
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
    bubbleSort(q);
    cout << swap_count << ' ' << compare_count;
    return 0;
}
