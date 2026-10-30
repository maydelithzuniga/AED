#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<unordered_map<long long int,long long int>> estados(n+1);
    vector<vector<long long int>> p(n+1);
    long long int x,y;
    for (int i=0;i<m;i++) {
        cin>>x>>y;
        estados[x][y]=1;
        estados[y][x]=1;
        p[x].push_back(y);
        p[y].push_back(x);
    }
    long long int u,v;
    long long int amigos=0;
    for (int i=0;i<q;i++) {
        cin>>u>>v;
        amigos=0;
        if (p[u].size()<p[v].size()) {
            for (int j=0;j<p[u].size();j++) {
                if (estados[v][p[u][j]]==1) {
                    amigos++;
                }
            }
        }
        else {
            for (int j=0;j<p[v].size();j++) {
                if (estados[u].count(p[v][j])==1) {
                    amigos++;
                }
            }
        }
        cout<<amigos<<"\n";
    }

    return 0;
}