#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int  kth_smallest(vector<int> arr, int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<arr.size();i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(){
    vector <int> arr={5,2,1,3,4,6};
    int k=3;
    cout<< kth_smallest(arr,k);
}