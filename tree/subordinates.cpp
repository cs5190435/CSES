//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define int              long long
using   ll=              long long;
#define ld               long double
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define pi               pair<int, int>
#define vi               vector<int>
#define vp               vector<pair<int, int>>
#define pb               push_back
#define mp               make_pair


const int M = 1000000007;
const int MM = 998244353;
const int N=1e6+5;
const int inf=1e18;

void dfs(int i, vector<vector<int>>& adj, vector<int>& dp, vector<bool>& vis){
    vis[i] = true;
    int ans = 0;
    for(int u:adj[i]){
        if(vis[u] == false){
            dfs(u, adj, dp, vis);
            ans += 1 + dp[u];
        }
    }

    dp[i] = ans;
}

signed main () {
    speed_;

    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=2; i<=n; i++){
        int a; cin >> a;
        adj[a].push_back(i);
    }
    vector<bool> vis(n+1, false);
    vector<int> dp(n+1, 0);
    dfs(1, adj, dp, vis);

    for(int i= 1; i<=n; i++)cout << dp[i] << " ";
    return 0;
}
