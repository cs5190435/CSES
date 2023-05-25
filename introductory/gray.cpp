#include <algorithm>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main (int argc, char *argv[]) {
    
    int n;
    cin >> n;

    vector<string> prev;
    string temp(n, '0');
    prev.push_back(temp);
    cout << temp << "\n";
    temp[n-1] ='1';
    prev.push_back(temp);
    cout << temp << "\n";

    int curr = 2;
    while(curr <= n){
        for(int i= prev.size()-1; i>= 0; i--){
            string tl = prev[i];
            tl[n-curr] = '1';
            cout << tl << "\n";
            prev.push_back(tl);
        }
        curr++;
    }
    
    return 0;
}
