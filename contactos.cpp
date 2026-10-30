#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> vector(n+1);
    int u,v;

    for(int i=0;i<m;i++) {
        cin>>u>>v;
        vector[u].push_back(v);
        vector[v].push_back(u);
    }
    for(int i=1;i<vector.size();i++) {
        sort(vector[i].begin(),vector[i].end());
    }

    int operacion;
    for(int i=0;i<q;i++) {
        cin>>operacion;
        cin>>u>>v;
        if (operacion==1) {
            int k=v;
            if(vector[u].size()<k) {
                cout<<"-1"<<"\n";
            }
            else {
                auto it=next(vector[u].begin(),k-1);
                cout<<*it<<"\n";
            }
        }
        else {
            auto it= upper_bound(vector[u].begin(),vector[u].end(),v);
            cout<<it-vector[u].begin()<<"\n";
        }

    }
    return 0;
}