#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool son_par(string a, string b) {
    int contador=1;
    int k=0;
    for (auto c: a) {
        if (c!=b[k]) {
            contador--;
        }
        k++;
    }
    if (contador==0) {
        return true;
    }
    else {
        return false;
    }
}

void compara(vector<vector<string> > &adj, vector<string> &v, string s,int i) {
    for(int j=0;j<i;j++) {
        if(son_par(v[j],s)) {
            adj[i].push_back(v[j]);
            adj[j].push_back(v[i]);
        }
    }
}

int main() {
    int n,l;
    cin>>n>>l;
    vector<vector<string>> adj(n);
    vector<string> v(n);
    string s;
    for(int i=0;i<n;i++) {
        cin>>s;
        v[i]=s;
        compara(adj,v,v[i],i);
    }
    int grados=0;
    vector<int> grado;
    for(int i=0;i<n;i++) {
        grados+=adj[i].size();
        grado.push_back(adj[i].size());
    }

    auto maximum=max_element(grado.begin(),grado.end());
    int ceros=count(grado.begin(),grado.end(),0);
    cout<<grados/2<<" "<<*maximum<<" "<<ceros<<"\n";

    return 0;
}