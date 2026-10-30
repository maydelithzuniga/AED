//
// Created by maydelithzuniga on 17/09/2026.
//
#include<iostream>
#include<vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n,r,b;
  vector<int> cantidad;
  while(t--) {
    cin >> n >> r >> b;
    int c_c=r/(b+1);
    for(int i=0;i<b+1;i++) {
      cantidad.push_back(c_c);
    }
    if (r%(b+1)!=0) {
      int resto=r%(b+1);
      for (int i=0;i<resto;i++) {
        cantidad[i]++;
      }

    }


    for (int i=0;i<cantidad.size();i++) {
      for (int j=0;j<cantidad[i];j++) {
        cout<<"R";
      }
      if (i!=cantidad.size()-1) {
        cout<<"B";
      }
    }
    cout<<"\n";
    cantidad.clear();

  }

};