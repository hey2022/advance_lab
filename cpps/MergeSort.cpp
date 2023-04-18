#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void mergeSort(vector<int> &q, int l, int r){
    if(l >= r)
        return;
    int mid = l + r >> 1;
    mergeSort(q, l, mid);
    mergeSort(q, mid + 1, r);
    static vector<int> w;
    w.clear();
    int i = l, j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] > q[j])
            w.push_back(q[j++]);
        else
            w.push_back(q[i++]);
    }
    while(i <= mid)
        w.push_back(q[i++]);
    while(j <= mid)
        w.push_back(q[j++]);
    for(int i : w)
        q[l++] = i;
}

int main(){
    freopen("/home/huangqixuan/PycharmProject/pythonProject/testingdata.in","r",stdin);
    int n;
    vector<int> q;
    cin >> n;
    for(int i = 0, t; i < n; i++){
        cin >> t;
        q.push_back(t);
    }
    mergeSort(q, 0, n - 1);
    return 0;
}