//
// Created by maydelithzuniga on 19/10/2026.
//
#include <iostream>
#include <queue>
#include <set>
using namespace std;
int main() {
    int n;
    int m;
    cin>>n>>m;
    long long int costo=0;
    int x;
    priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
    for (int i=0;i<m;i++) {
        cin>>x;
        pq.push(x);
    }
    while (pq.size()>1) {
        long long int a=pq.top();  pq.pop();
        long long int b=pq.top();  pq.pop();
        costo+=a+b;
        pq.push(a+b);
    }
    cout<<costo;

    return 0;
}