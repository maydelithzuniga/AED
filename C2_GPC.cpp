#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pos(n, -1);

    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma = (suma + a[i]) % n;

        if (suma == 0) {
            cout << i + 1 << '\n';

            for (int j = 0; j <= i; j++) {
                cout << a[j] << " ";
            }

            cout << '\n';
            return 0;
        }

        if (pos[suma] != -1) {
            int inicio = pos[suma] + 1;
            int fin = i;

            cout << fin - inicio + 1 << '\n';

            for (int j = inicio; j <= fin; j++) {
                cout << a[j] << " ";
            }

            cout << '\n';
            return 0;
        }

        pos[suma] = i;
    }

    return 0;
}