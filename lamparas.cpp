//
// Created by maydelithzuniga on 17/10/2026.
//
#include <iostream>
#include <vector>
using namespace std;
void hacer(int n,vector<int>&cantidad, vector<int>&numeros) {

    if (n==2 and cantidad[n-1]==1) {
        numeros.push_back(2);
        numeros.push_back(1);
        return;
    }
    else if (n==2 and cantidad[n-1]==0) {
        numeros.push_back(1);
        numeros.push_back(2);
        return;

    }
    if (n!=1)
    hacer(n-1,cantidad,numeros);
    if (n!=1 and n-1==cantidad[n-1]) {
        numeros.insert(numeros.begin(),n);
    }
    else {
        if (n!=1)
        numeros.insert(numeros.begin()+(numeros.size() - cantidad[n-1]),n);

    }


}
int main() {
    int n;
    cin>>n;
    vector<int> cantidad;
    vector<int>numeros;
    int x;
    for (int i=0;i<n;i++) {
        cin>>x;
        cantidad.push_back(x);
    }
    hacer(n,cantidad,numeros);
    for (int i=0;i<n;i++) {
        cout<<numeros[i]<<" ";
    }
    return 0;
}