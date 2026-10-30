//
// Created by maydelithzuniga on 19/09/2026.
//
#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n;
    cin>>n;
    string j;
    for (int i=0;i<n;i++) {
        stack<char> s;
        cin>>j;
        bool verificar=true;
        if (j.size()%2!=0) cout<<"NO"<<endl;
        else {
            for (auto k:j) {
                if (k!=')' and k!='}' and k!=']')
                   s.push(k);
                else {
                    if (!s.empty()) {
                        char top=s.top();
                        if (top=='{' and k=='}') {
                            s.pop();
                        }
                        else if (top=='[' and k==']') {
                            s.pop();
                        }
                        else if (top=='(' and k==')') {
                            s.pop();
                        }
                        else {
                            verificar=false;
                        }
                    }
                    else {
                        verificar=false;
                        break;
                    }

                }
            }
            if (!s.empty()) {
                verificar=false;
            }
            cout<<(verificar?"YES":"NO")<<endl;
        }
    }

    return 0;
}
