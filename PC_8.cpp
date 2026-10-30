#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



int main() {

    int cantidad;
    cin >> cantidad;
    string operacion;
    vector<int> v;
    long long int x=0;
    int n;
    while (cantidad > 0) {
        cin >> operacion;
        if (operacion == "add") {
            if (!v.empty()) {
                long long int suma=1;
                for (int i = 0; i < v.size(); i++) {
                        suma=suma*v[i];

                }
                x+=suma;
                if (x > (pow(2,32)-1)) {
                    cout<<"OVERFLOW!!!";
                    return 0;
                }

            }
            else {
                x++;
            }
        }
        else if (operacion == "for") {
            cin>>n;
            v.push_back(n);
        }
        else if (operacion == "end") {
            v.pop_back();

        }

        cantidad--;
    }
    cout << x;
    return 0;
}