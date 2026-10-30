#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void hanoi(int n, stack<int> &uno, stack<int> &dos, stack<int> &tres, string cambio) {
    if (cambio=="3") {
        cout<<n<<" "<<cambio<<endl;
        tres.push(n);
        return;
    }
    if (uno.empty() and dos.empty()) {
        return;
    }
    if (uno.empty()) {
        hanoi(n-1, uno, dos, tres, "1");
    }
    else if (dos.empty()) {
        hanoi(n-1, uno, dos, tres, "2");
    }
    cout <<n<<" "<<cambio<<endl;

}

int main() {
    int n;
    cin>>n;
    stack<int> uno;
    stack<int> dos;
    stack<int> tres;
    for (int i = 1; i < n+1; i++) {
        uno.push(i);
    }
    string cambio="";
    hanoi(n, &uno, &dos, &tres,cambio);

    return 0;
}