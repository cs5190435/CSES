//Cpp coding template
#include<iostream>
#include<algorithm>
#include<limits>
#include <thread>
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

    vector<int> dp(s.size(), 0);
    for(int i= 1; i< s.size(); i++){
        int j = dp[i-1];
        while(j > 0 && s[i] != s[j]) j = dp[j-1];
        if(s[i] == s[j])j++;
        dp[i] = j;
    }

    int j = s.size()-1;
    vector<int> res;
    while(j > 0){
        if(dp[j] > 0)res.push_back(dp[j]);
        else break;
        j = dp[j]-1;
    }
    sort(res.begin(), res.end());
    for(auto j:res) cout << j << " ";

    return 0;
}
