//
// Created by maydelithzuniga on 18/09/2026.
//

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
template<typename key_type, typename value_type>
struct my_map {
    int m;
    vector<vector<pair<key_type, value_type>>> chains;

    my_map(int m) : m(m) {
        chains.resize(m);
    }

    value_type& operator [] (const key_type &key) {
        int chain_position = _hash(key);
        int at = 0;
        while (at < chains[chain_position].size() and chains[chain_position][at].first != key) {
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
        while (at < chains[chain_position].size() and chains[chain_position][at].first != key) {
            ++at;
        }
        if (at == chains[chain_position].size()) {
            return false;
        }
        return true;
    }

    int _hash(key_type key) {
        // Para enteros
        const int B = 311;
        const int MOD = 1e9 + 7;
        int hash_value = 0;
        while (key > 0) {
            int d = key % 10;
            hash_value = (1ll * hash_value * B + (d + 1)) % MOD;
            key /= 10;
        }
        return hash_value % m;
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
    int x;
    cin>>x;
    my_map<int,int> cantidad(x);
    vector<int> numeros;
    int d;
    for (int i = 0; i < x; ++i) {
        cin>>d;
        numeros.push_back(d);
        cantidad[d]++;
    }
    for (int i = 0; i < numeros.size(); ++i) {
        if (cantidad[numeros[i]]>x/2) {
            cout << numeros[i] << "\n";
            return 0;
        }
    }
    cout << "NO EXISTE" << "\n";
    return 0;
}