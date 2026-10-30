#include<iostream>
#include<queue>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int x;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> minimo;
    for(int i=0;i<n;i++) {
        cin>>x;
        pq.push(x);
        minimo.push(x);
    }
    int k=1;
    while(k<=m) {
        int max=pq.top();pq.pop();
        if (max%2==0) {
            pq.push(max/2);
            minimo.push(max/2);
            pq.push(max/2);
            minimo.push(max/2);
        }
        else {
            pq.push(max/2);
            minimo.push(max/2);
            pq.push(max/2 +1);
            minimo.push(max/2 +1);
        }
        int diferencia=pq.top()-minimo.top();
        cout<<diferencia<<" ";

        k++;
    }
    return 0;
}
