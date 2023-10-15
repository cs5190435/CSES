//Cpp coding template
#include<iostream>
#include<algorithm>
#include<limits>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define pb push_back
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)


signed main () {
    speed_;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0; int r= 0;
    for(int i=1; i< n; i++){
        if(i < r) z[i] = min(r-i, z[i-l]);
        while(i + z[i] < n && s[z[i]] == s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i] > r){
            l = i;
            r = i+z[i];
        }
    }

    for(int i= 1; i< n; i++){
        if(i+z[i] >= n) cout << i << " ";
    }
    cout << n << "\n";


    return 0;
}
