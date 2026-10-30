#include <iostream>
#include <vector>
using namespace std;
int main() {
    int A,B, x,y;
    cin>>A>>B>>x>>y;
    int estados=(A+1)*(B+1);
    vector<vector<pair<int,int>>> pares(estados);
    int k=0;
    int j=0;
    int consulta=0;
    while (k<=B) {
        for (int i=0;i<=A;i++) {
            int a=i;
            int b=k;
            if (a!=A) {
                pares[j].push_back({A,b});
                if (x==A and y==b) {
                    consulta++;
                }
            }
            if (b!=B) {
                pares[j].push_back({a,B});
                if (x==a and y==B) {
                    consulta++;
                }
            }
            if (a!=0) {
                pares[j].push_back({0,b});
                if (x==0 and y==b) {
                    consulta++;
                }
            }
            if (b!=0) {
                pares[j].push_back({a,0});
                if (x==a and y==0) {
                    consulta++;
                }
            }
            if (a!=0 and b!=B) {
                int resto;
                resto=B-b;
                if (resto>=a) {
                    pares[j].push_back({0,b+a});
                    if (x==0 and y==b+a) {
                        consulta++;
                    }
                }
                else {
                    pares[j].push_back({a-resto,B});
                    if (x==a-resto and y==B) {
                        consulta++;
                    }
                }
            }

            if (b!=0 and a!=A) {
                int resto;
                resto=A-a;
                if (resto>=b) {
                    pares[j].push_back({a+b,0});
                    if (x==a+b and y==0) {
                        consulta++;
                    }
                }
                else {
                    pares[j].push_back({A,b-resto});
                    if (x==A and y==b-resto) {
                        consulta++;
                    }
                }
            }

            j++;
        }
        k++;
    }
    int total_aristas=0;
    for (int i=0;i<estados;i++) {
        total_aristas+=pares[i].size();
    }

    cout<<total_aristas<<" "<<consulta<<"\n";




    return 0;
}
