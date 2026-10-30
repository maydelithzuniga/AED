//
// Created by maydelithzuniga on 14/10/2026.
//
#include <iostream>
#include <vector>
using namespace std;

long long int operacion(long long int x, long long int y, string operacion) {
    long long int result = 0;
    if (operacion == "+") {
        result = (x) + (y);
    }
    else if (operacion == "-") {
        result = (x) - (y);
    }
    else if (operacion == "*") {
        result = (x)*(y);
    }
    return result;
}

long long int resolver(vector<string> &conjunto, int i, int j) {
    if (conjunto[i]=="-" or conjunto[i]=="+" or conjunto[i]=="*") {
        bool confirmar=true;
            if (i+1!=j) {
                if (conjunto[i+1]=="-" or conjunto[i+1]=="+" or conjunto[i+1]=="*") {
                    confirmar=false;
                }
            }

        if (confirmar) {
            return operacion( stoll(conjunto[i+1]), resolver(conjunto,i+2,j),conjunto[i]);
        }
        else {
            return operacion(operacion(stoll(conjunto[i+2]),stoll(conjunto[i+3]),conjunto[i+1]),resolver(conjunto,i+4,j),conjunto[i]);
        }

    }
    else {
        return stoll(conjunto[i]);
    }




}

int main () {
    int n;
    cin >> n;
    vector<string> conjunto;
    long long int suma=0;
    string x;
    for (int i = 0; i < n; i++) {
        cin>>x;
        conjunto.push_back(x);
    }
    suma=resolver(conjunto,0,n-1);
    cout << suma << endl;

    return 0;
}