#include <iostream>
#include <hash_set>
#include <list>
#include <set>
#include <vector>
using namespace std;




void cadenas(string s, int n, vector<string>& v) {
    if (s.length() == n) {
        v.push_back(s);
        return;
    }
    if (s.substr(s.length()-1) == "1") {
        cadenas(s + "0", n, v);
    }
    else {
        cadenas(s + "0", n, v);
        cadenas(s + "1", n, v);
    }
}

int main() {
    int n;
    cin>>n;
    string s1="0";
    string s2="1";
    vector<string> v;
    cadenas(s1, n, v);
    cadenas(s2, n, v);

    cout<<v.size()<<"\n";
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
    sort(v.begin(), v.end());


    return 0;
}