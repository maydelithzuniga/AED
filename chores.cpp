//
// Created by maydelithzuniga on 17/10/2026.
//
#include <iostream>
#include <vector>
using namespace std;

bool validar(vector<long long int> & v, int x) {
    bool veredicto = false;
    if (v[v.size()-1]-v[v.size()-2]!=1 or x-v[v.size()-1]!=1 ) {
        veredicto= true;
    }
    return veredicto;
}

int main() {
    int n;
    cin>>n;
    vector<long long int> sergio;
    vector<long long int> andrea;
    vector<long long int> quehace_sergio;
    vector< long long int> quehace_andrea;
    long long int x;
    for (int i=0;i<n;i++) {
        cin>>x;
        sergio.push_back(x);
    }
    for (int i=0;i<n;i++) {
        cin>>x;
        andrea.push_back(x);
    }
    long long int suma=0;
    for (int i=0;i<n;i++) {
        long long int minimo=min(sergio[i],andrea[i]);
        if (minimo==sergio[i]) {
            if (quehace_sergio.size()>=2) {
                if (validar(quehace_sergio,i+1)) {
                    suma+=minimo;
                    quehace_sergio.push_back(i+1);
                }
                else {
                    long long int minimo_andrea=min(andrea[i-1],andrea[i-2]);
                    if ( minimo_andrea==andrea[i-1] and andrea[i-1]<andrea[i]) {
                        suma-=sergio[i-1];
                        suma+=andrea[i-1];
                        quehace_sergio.pop_back();
                        quehace_andrea.push_back(i);
                    }
                    else if (minimo_andrea==andrea[i-2] and andrea[i-2]<andrea[i]) {
                        if (validar(quehace_andrea,i-2)) {
                            suma-=sergio[i-2];
                            suma+=andrea[i-2];
                            quehace_sergio.erase(quehace_sergio.begin()+i-2);
                            quehace_andrea.push_back(i-1);
                        }
                        else {
                            if (andrea[i-1]<andrea[i]) {
                                suma-=sergio[i-1];
                                suma+=andrea[i-1];
                                quehace_sergio.pop_back();
                                quehace_andrea.push_back(i);
                            }
                            else {
                                suma+=andrea[i];
                                quehace_andrea.push_back(i+1);
                            }
                        }
                    }
                    else {
                        suma+=andrea[i];
                        quehace_andrea.push_back(i+1);
                    }
                    suma+=minimo;
                    quehace_sergio.push_back(i+1);

                }
            }
            else {
                suma+=minimo;
                quehace_sergio.push_back(i+1);
            }
        }
        else {
                if (quehace_andrea.size()>=2) {
                    if (validar(quehace_andrea,i+1)) {
                        suma+=minimo;
                        quehace_andrea.push_back(i+1);
                    }
                    else {
                        long long int minimo_sergio=min(sergio[i-1],sergio[i-2]);
                        if ( minimo_sergio==sergio[i-1] and sergio[i-1]<sergio[i]) {
                            suma-=andrea[i-1];
                            suma+=sergio[i-1];
                            quehace_andrea.pop_back();
                            quehace_sergio.push_back(i);
                        }
                        else if (minimo_sergio==sergio[i-2] and sergio[i-2]<sergio[i]) {
                            if (validar(quehace_sergio,i-2)) {
                                suma-=andrea[i-2];
                                suma+=sergio[i-2];
                                quehace_andrea.erase(quehace_sergio.begin()+i-2);
                                quehace_sergio.push_back(i-1);
                            }
                            else {
                                if (sergio[i-1]<sergio[i]) {
                                    suma-=andrea[i-1];
                                    suma+=sergio[i-1];
                                    quehace_andrea.pop_back();
                                    quehace_sergio.push_back(i);
                                }
                                else {
                                    suma+=sergio[i];
                                    quehace_sergio.push_back(i+1);
                                }
                            }
                        }
                        else {
                            suma+=sergio[i];
                            quehace_sergio.push_back(i+1);
                        }
                        suma+=minimo;
                        quehace_andrea.push_back(i+1);
                    }
                }
                else {
                    suma+=minimo;
                    quehace_andrea.push_back(i+1);
                }

        }
    }
    cout << suma << "\n";


    return 0;
}