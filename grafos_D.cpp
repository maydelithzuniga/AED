#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long int>> adj(n+1);
    long long int u,v;

    for(int i=0;i<m;i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    int consulta;
    for(int i=0;i<q;i++) {
        cin>>consulta;
        if(consulta==1) {
            cin>>u>>v;
            if(adj[u].size()<v) {
                cout<<"-1"<<"\n";
            }
            else {
                auto it= next(adj[u].begin(), v-1);
                cout<<*it<<"\n";
            }
        }
        else {
            cin>>u>>v;
            cout<<upper_bound(adj[u].begin(),adj[u].end(),v)-adj[u].begin()<<"\n";
        }
    }

    //ordered_set
    //findbyorder
    //




    return 0;
}