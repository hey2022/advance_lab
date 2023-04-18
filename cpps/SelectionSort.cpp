#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void selectionSort(vector<int> &q){
    for(int i = 0; i < q.size(); i++){
        for(int j = i + 1; j < q.size(); j++){
            if(q[i] > q[j])
                swap(q[i], q[j]);
        }
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
    selectionSort(q);
    return 0;
}