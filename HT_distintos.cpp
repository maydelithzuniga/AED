//
// Created by maydelithzuniga on 08/09/2026.
//
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
        int hash_value = 0;
        while (key > 0) {
            int d = key % 10;
            hash_value = (1ll * hash_value * B + (d + 1)) % MOD;
            key /= 10;
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
        return
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
    cin.tie(0) -> sync_with_stdio(false);
    int tamano;
    cin >> tamano;
    my_map<int, int> contadores(tamano);
    int x;
    for (int i = 0; i < tamano; ++i) {
        cin >> x;
        ++contadores[x];
    }
    cout<<contadores.size()<<endl;

    return 0;
}
