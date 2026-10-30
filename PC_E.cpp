//
// Created by maydelithzuniga on 24/09/2026.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    int x;
    vector<int> v;
    stack<int> q;
    for (int i = 0; i < n; i++) {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = n-1; i >=0; i--) {
        q.push(v[i]);
    }
    int h=0;
    int y=0;
    int operacion=0;
    while (!q.empty()) {
        h=q.top();
        q.pop();
        y=q.top();
        q.pop();
        operacion=h + 2*y;
        if (operacion<k) {
            
        }
    }

    return 0;
}
