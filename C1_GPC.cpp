//
// Created by maydelithzuniga on 14/09/2026.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
vector<char> dic;
map<char, int> dic2;
int main() {
    int n;
    cin >> n;
    int m;
    string x;
    vector<char> abc = {
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'
    };
    for (int i = 0; i < n; i++) {
        cin>>m;
        cin>>x;
        for (auto i : x) {
            dic.push_back(i);
            dic2[i]+=1;
        }

        for (int j = 0; j < abc.size(); j++) {
            if (!dic2.contains(abc[j])) {
                cout<<abc[j];
                return 0;
            }
        }
        dic2.clear();
        int k=0;
        for (int j = 1; j < m; j++) {
            dic2[dic[k] + dic[k+1]];
            k++;
        }
        for (int j = 0; j < abc.size(); j++) {
            for (int k = 0; k < abc.size(); k++) {
                if (!dic2.contains(abc[j] + abc[k])) {
                    cout<<abc[j] + abc[k];
                    return 0;
                }
            }
        }
        dic2.clear();
         k=0;
        for (int j = 1; j < m-1; j++) {
            dic2[dic[k] + dic[k+1]+ dic[k+2]];
            k++;
        }
        for (int j = 0; j < abc.size(); j++) {
            for (int k = 0; k < abc.size(); k++) {
                for (int l = 0; l < abc.size(); l++) {
                    if (!dic2.contains(abc[j] + abc[k] + abc[l])) {
                    cout<<abc[j] + abc[k] + abc[l];
                    return 0;
                }
                }

            }
        }


    }


    return 0;
};