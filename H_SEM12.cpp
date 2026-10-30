//
// Created by maydelithzuniga on 30/10/2026.
//
/*
 F. Luces Apagadas
 time limit per test: 2 seconds
 memory limit per test: 256 megabytes

 Rosangel tiene un tablero de n filas y m columnas con una lámpara en cada
 casilla, cada una encendida (1) o apagada (0). Al presionar una lámpara,
 ella y sus vecinas de arriba, abajo, izquierda y derecha (las que existan)
 cambian de estado: las encendidas se apagan y las apagadas se encienden.

 ¿Cuál es la menor cantidad de presiones para apagar todas las lámparas?

 Input
 La primera línea contiene dos enteros n y m (1 <= n, m <= 4).
 Cada una de las siguientes n líneas contiene una cadena de m caracteres
 0 o 1: el estado inicial del tablero.

 Output
 Imprime la menor cantidad de presiones para apagar todas las lámparas,
 o -1 si es imposible.

 Ejemplo 1
 input:
 3 3
 010
 111
 010
 output:
 1

 Ejemplo 2
 input:
 1 2
 10
 output:
 -1

 Note
 En el primer ejemplo, presionar la lámpara central cambia las cinco
 lámparas en cruz de un tablero de 3x3, que justo son las encendidas. En el
 segundo, el tablero de 1x2 tiene una sola lámpara encendida y presionar
 cualquiera de las dos cambia ambas: siempre queda exactamente una lámpara
 encendida.

 ---------------------------------------------------------------------------
 IDEA:
 - n*m <= 16 casillas, así que hay a lo sumo 2^16 = 65536 subconjuntos de
   presiones.
 - Presionar dos veces la misma lámpara no sirve (se cancela), así que cada
   lámpara se presiona 0 o 1 veces: fuerza bruta sobre máscaras.
 - Para cada máscara de presiones, se calcula el estado final aplicando el
   XOR de la máscara de efecto de cada lámpara presionada.
 - Si el estado final es 0 (todo apagado), se toma el mínimo popcount.
 - Complejidad O(2^(nm) * nm), trivial.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int total = n * m;
    int init = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '1') init |= 1 << (i * m + j);
    }

    // eff[p] = máscara de lámparas que cambian al presionar la lámpara p
    vector<int> eff(total, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int p = i * m + j;
            eff[p] |= 1 << p;
            if (i > 0)     eff[p] |= 1 << ((i - 1) * m + j);
            if (i < n - 1) eff[p] |= 1 << ((i + 1) * m + j);
            if (j > 0)     eff[p] |= 1 << (i * m + j - 1);
