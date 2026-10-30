//
// Created by maydelithzuniga on 19/09/2026.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<string> v;
    string s;
    stack<string> stack_guardado;

    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    int operacion_final=0;
    string x;
    string y;
    for (int i = 0; i < n; i++) {

        if (v[i]=="+" || v[i]=="-" || v[i]=="*" || v[i]=="/") {
            if (!stack_guardado.empty()) {
                x=stack_guardado.top();
                stack_guardado.pop();
                y=stack_guardado.top();
                stack_guardado.pop();
            }
            if (v[i]=="+") {
                operacion_final=stoi(x)+stoi(y);
            }
            else if (v[i]=="-") {
                operacion_final=stoi(y)-stoi(x);
            }
            else if (v[i]=="*") {
                operacion_final=stoi(y)*(stoi(x));
            }
            else if (v[i]=="/") {
                operacion_final=stoi(y)/(stoi(x));
            }
            stack_guardado.push(to_string(operacion_final));
        }
        else {

            stack_guardado.push(v[i]);

        }


    }
    cout << operacion_final;


    return 0;
}