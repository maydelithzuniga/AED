#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {

    int n,m,q;
    cin>>n>>m>>q;
    vector<unordered_map<int,int>> estados(n+1);
    int x,y;
    for (int i=0;i<m;i++) {
        cin>>x>>y;
        estados[x][y]++;
    }
    int u,v;
    int contador=0;
    for (int i=0;i<q;i++) {
        cin>>u>>v;
        contador=0;
        if (u==v) {
            auto it=estados[u].find(v);
            if (it!=estados[u].end()) {
                contador=it->second;
            }
        }
        else {
            auto it=estados[u].find(v);
            if (it!=estados[u].end()) {
                contador=it->second;
            }
            it=estados[v].find(u);
            if (it!=estados[v].end()) {
                contador+=it->second;
            }
        }
        if (contador==0) {
            cout<<"0"<<"\n";
        }
        else {
            cout<<contador<<"\n";
        }

    }
    return 0;
}