//
// Created by maydelithzuniga on 18/09/2026.
//
#include <iostream>
#include <vector>
using namespace std;
vector<int> A;
vector<int> B;
vector<int> C;
vector<int> D;
int x;
int main () {
    vector<int> A;
    vector<int> B;
    vector<int> C;
    vector<int> D;
    int x;
    cin>>x;
    int n;
    for (int i=0;i<x;i++) {
        cin>>n;
      A.push_back(n);
    }
    for (int i=0;i<x;i++) {
        cin>>n;

        B.push_back(n);
    }
    for (int i=0;i<x;i++) {
        cin>>n;
        C.push_back(n);
    }
    for (int i=0;i<x;i++) {
        cin>>n;
        D.push_back(n);
    }
    int contador=0;
    for (int i=0;i<x;i++) {
        for (int j=0;j<x;j++) {
            for (int k=0;k<x;k++) {
                for (int l=0;l<x;l++) {
                    if (A[i] + B[j] + C[k] + D[l] == 0) {
                        contador++;
                    }
                }
            }
        }
    }
    cout << contador << endl;
};
