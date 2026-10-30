//
// Created by maydelithzuniga on 19/09/2026.
//
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int st1;
    int st2;
    int st3;
    cin>>st1;
    cin>>st2;
    cin>>st3;
    int x;
    vector<int> inversion;
    stack<int> st1_v;
    stack<int> st2_v;
    stack<int> st3_v;
    int suma_1=0;
    int suma_2=0;
    int suma_3=0;
    for (int i=0;i<st1;i++) {
        cin>>x;
        inversion.push_back(x);
        suma_1+=x;
    }
    for (int i=inversion.size()-1;i>=0;i--) {
        st1_v.push(inversion[i]);
    }
    inversion.clear();
    for (int i=0;i<st2;i++) {
        cin>>x;
        inversion.push_back(x);
        suma_2+=x;

    }
    for (int i=inversion.size()-1;i>=0;i--) {
        st2_v.push(inversion[i]);
    }
    inversion.clear();
    for (int i=0;i<st3;i++) {
        cin>>x;
        inversion.push_back(x);
        suma_3+=x;
    }
    for (int i=inversion.size()-1;i>=0;i--) {
        st3_v.push(inversion[i]);
    }

    while (suma_1!=suma_2 || suma_2!=suma_3) {
        int minimo= min(min(suma_1,suma_2),  suma_3);
        if (suma_1>minimo) {
            suma_1-=st1_v.top();
            st1_v.pop();
        }
        if (suma_2>minimo) {
            suma_2-=st2_v.top();
            st2_v.pop();
        }
        if (suma_3>minimo) {
            suma_3-=st3_v.top();
            st3_v.pop();
        }

    }
    cout<<suma_1<<endl;

    return 0;
}