#include <iostream>
#include <map>
#include <math.h>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    map<pair<int,int>,int> mutuo;
    vector<vector<pair<int,int>>> vector(n+1);
    int u,v;
    for(int i=0;i<m;i++) {
        cin>>u>>v;
        mutuo[{u,v}]++;
        vector[v].push_back({u,v});
    }
    pair<int,int> mas_seguidores={-INFINITY,-INFINITY};
    int seguir_mutuo=0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<vector[i].size();j++) {
            auto it=mutuo.find({vector[i][j].second,vector[i][j].first});
            if(it!=mutuo.end()) {
                seguir_mutuo++;
            }
        }
        pair<int,int> cantidad={vector[i].size(),i};
        if (cantidad.first==mas_seguidores.first) {
            if (cantidad.second<mas_seguidores.second) {
                mas_seguidores={cantidad.first,cantidad.second};
            }
        }
        else if (cantidad.first>mas_seguidores.first) {
            mas_seguidores={cantidad.first,cantidad.second};
        }
    }
    cout<<seguir_mutuo/2<<" "<<mas_seguidores.second<<" "<<mas_seguidores.first<<"\n";

    return 0;
}