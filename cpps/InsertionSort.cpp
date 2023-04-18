#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void insertionSort(vector<int> &q){
    for(int i = 1; i < q.size(); i++){
        int t = q[i], j;
        for(j = i - 1; j >= 0; j--){
            if(q[j] > t)
                q[j+1] = q[j];
            else
                break;
        }
        q[j+1] = t;
    }
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
    insertionSort(q);
    return 0;
}