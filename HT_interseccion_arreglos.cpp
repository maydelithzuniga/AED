//
// Created by maydelithzuniga on 08/09/2026.
//
#include <bits/stdc++.h>
using namespace std;

template<typename key_type, typename value_type>
struct my_map {
    int m;
    int _size;
    vector<vector<pair<key_type, value_type>>> chains;

    my_map(int m) : m(m) {
        chains.resize(m);
    }

    value_type& operator [] (const key_type &key) {
        int chain_position = _hash(key);
        int at = 0;
        while (at < chains[chain_position].size() && chains[chain_position][at].first != key) {
            ++at;
        }
        if (at == chains[chain_position].size()) {
            chains[chain_position].emplace_back(key, value_type());
        }
        return chains[chain_position][at].second;
    }

    bool has_key (const key_type &key) const {
        int chain_position = _hash(key);
        int at = 0;
        while (at < chains[chain_position].size() && chains[chain_position][at].first != key) {
            ++at;
        }
        if (at == chains[chain_position].size()) {
            return false;
        }
        return true;
    }

    // Nota: Esta función asume que key_type se puede tratar como un número entero.
    // También se eliminó el 'const' de la firma para poder modificar la copia local de 'key'.
    int _hash(key_type key) const {
        const int B = 311;
        const int MOD = 1e9 + 7;
        long long k = key;
        if (k < 0) k = -k;          // manejar negativos
        int hash_value = 0;
        if (k == 0) hash_value = 1; // manejar el cero explícitamente (dígito "0" -> +1)
        while (k > 0) {
            int d = k % 10;
            hash_value = (1ll * hash_value * B + (d + 1)) % MOD;
            k /= 10;
        }
        return hash_value % m;
    }
    int size() const {
        int result = 0;
        for (int i = 0; i < m; ++i) {
            result += chains[i].size();
        }
        return result;
    }
    void erase(const key_type &key) {
        int chain_position = _hash(key);
        int at = 0;
        while (at< chains[chain_position].size() && chains[chain_position][at].first != key) {
            ++at;
        }
        if (at == chains[chain_position].size()) {
            if (at+1<chains[chain_position].size()) {
                swap(chains[chain_position][at], chains[chain_position].back());
            }
            chains[chain_position].pop_back();
            --_size;
        }
    }

    void print() {
        for (int i = 0; i < m; ++i) {
            cout << "Bucket " << i << ": " << endl;
            for (auto &e : chains[i]) {
                cout << e.first << " --> " << e.second << endl;
            }
            cout << "End bucket" << endl;
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    int tamano1,tamano2;
    cin >> tamano1;
    int x;
    vector<int> A1;
    for (int i = 0; i < tamano1; ++i) {
        cin >> x;
        A1.push_back(x);
    }
    cin >> tamano2;
    my_map<int, int> A2(tamano2);
    for (int i = 0; i < tamano2; ++i) {
        cin >> x;
        ++A2[x];
    }
    set<int> duplicados;
    for (int i = 0; i < tamano1; ++i) {
        if (A2.has_key(A1[i])) {
            duplicados.emplace(A1[i]);
        }
    }
    cout << duplicados.size() << "\n";
    for (auto valor: duplicados) {
        cout << valor << " ";
    }

    return 0;

}