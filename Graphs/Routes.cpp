//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi  vector<int>
#define pi  pair<int, int>
#define vb               vector<bool>
#define pb               push_back

vector<int> dp;
int inf = 1e17;
int mod = 1e9 + 7;

void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis){
    vis[i] = true;

    for(auto j: adj[i]){
        dp[j] += dp[i];
        dp[j] = dp[j]%mod;
        if(vis[j]) continue;
        dfs(j, adj, vis);
    }
    return;
}


signed main () {
    speed_;
    int n; int m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i= 0; i< m ; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dp.resize(n+1);
    vector<bool> vis(n+1, false);
    dp[1] =1;

    dfs(1, adj, vis);
    
    cout << dp[n] <<"\n";


    return 0;
}
