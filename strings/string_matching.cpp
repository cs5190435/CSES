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
    string a;
    string b;
    cin >> a >> b;

    string temp = b+ "#" + a;
    vector<int> dp(temp.size(), 0);
    int res = 0;
    int j= 0;
    for(int i= 1; i< temp.size(); i++){
        while(j > 0 && temp[j] != temp[i]) j = dp[j-1];
        if(temp[i] == temp[j])j++;
        dp[i] = j;
        if(dp[i] == b.size())res++;
    }
    cout << res << "\n";

    return 0;
}
