//
// Created by maydelithzuniga on 11/10/2026.
//
#include <iostream>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    int cartas;
    cin>>cartas;
    int x;
    deque<int> jugador1;
    deque<int> jugador2;
    for (int i = 0; i < cartas; i++) {
        cin>>x;
        jugador1.push_front(x);
    }
    cin>>cartas;
    for (int i = 0; i < cartas; i++) {
        cin>>x;
        jugador2.push_front(x);
    }
    int y=0;
    int z=0;
    vector<deque<int>> jugador_1_estados;
    vector<deque<int>> jugador_2_estados;
    int puntaje_1=0;
    int puntaje_2=0;
    while (!jugador1.empty() and !jugador2.empty()) {
        if (jugador1.back()<jugador2.back()) {
            y=jugador1.back();
            jugador1.pop_back();
            z=jugador2.back();
            jugador2.pop_back();
            jugador2.push_front(y);
            jugador2.push_front(z);
            puntaje_2++;
        }
        else if (jugador1.back()>jugador2.back()) {
            y=jugador2.back();
            jugador2.pop_back();
            z=jugador1.back();
            jugador1.pop_back();
            jugador1.push_front(y);
            jugador1.push_front(z);
            puntaje_1++;
        }
        if (!jugador_1_estados.empty()) {
            if (jugador_1_estados.size()>1) {
                for (int i = 0; i < jugador_1_estados.size()-1; i++) {
                    deque<int> comparacion1=jugador_1_estados[i];
                    deque<int> comparacion2=jugador_2_estados[i];
                    deque<int> jugador_1_temp=jugador1;
                    deque<int> jugador_2_temp=jugador2;
                    while (!comparacion1.empty() and !jugador_1_temp.empty()) {
                        if (comparacion1.back()!=jugador_1_temp.back()) {
                            break;
                        }
                        jugador_1_temp.pop_back();
                        comparacion1.pop_back();
                    }
                    if (comparacion1.empty() and jugador_1_temp.empty()) {
                        while (!comparacion2.empty() and !jugador_2_temp.empty()) {
                            if (comparacion2.back()!=jugador_2_temp.back()) {
                                break;
                            }
                            jugador_2_temp.pop_back();
                            comparacion2.pop_back();
                        }
                    }
                    if (comparacion1.empty() and jugador_1_temp.empty() and comparacion2.empty() and jugador_2_temp.empty()) {
                        cout<<"-1";
                        return 0;
                    }
                }
            }
            jugador_1_estados.push_back(jugador1);
            jugador_2_estados.push_back(jugador2);
        }
        else {
            jugador_1_estados.push_back(jugador1);
            jugador_2_estados.push_back(jugador2);

        }


    }

    cout << jugador_1_estados.size()<<" ";
    if (puntaje_1>puntaje_2) {
        cout << "1"<<"\n";
    }
    else {
        cout <<"2"<<"\n";
    }


    return 0;
}