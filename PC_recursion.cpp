#include <iostream>
using namespace std;

void contar(int &contador, int total, int &tope) {
    if (total == tope) {
        contador++;
        return;
    }
    else if (total > tope) {
        return;
    }
    contar(contador, total+1, tope);
    contar(contador, total+2, tope);
    contar(contador, total+3, tope);
}



int main() {
    int inicio, final;
    cin>>inicio>> final;
    int contador = 0;
    contar(contador, inicio, final);
    cout<<contador<<"\n";

    return 0;
}