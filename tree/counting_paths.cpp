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

vector<vector<int>> dp;
vector<int> depth;
vector<int> prefix;
vector<int> req;

void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, int p){
    depth[i] = depth[p]+1;
    vis[i] = true;
    dp[0][i] = p;
    for(auto j: adj[i]){
        if(!vis[j]) dfs(j, adj, vis, i);
    }
    return;
}


int lca(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    int diff = depth[b]-depth[a];
    while(diff > 0){
        int k = log2(diff);
        b = dp[k][b];
        diff -= pow(2, k);
    }
    if(a == b) return a;
    for(int i = 31; i>= 0; i--){
        int ta = dp[i][a];
        int tb = dp[i][b];
        if(ta != tb){
            a = ta;
            b = tb;
        }
    }
    return dp[0][a];
}


void dfs2(int i, vector<vector<int>>& adj, vector<bool>& vis){
    vis[i] = true;
    int sum = prefix[i];
    for(auto j: adj[i]){
        if(!vis[j]){
            dfs2(j, adj, vis);
            sum += req[j];
        }
    }
    req[i] = sum;
}


signed main () {
    speed_;
    int n, m;
    cin >> n>> m;

    vector<vector<int>> adj(n+1);
    for(int i= 1; i< n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp.resize(32, vector<int>(n+1));
    depth.resize(n+1);
    
    vector<bool> vis(n+1, false);
    dfs(1, adj, vis, 0);
    
    for(int i= 1; i< 32; i++){
        for(int j= 1; j<= n; j++){
            int temp = dp[i-1][j];
            dp[i][j] = dp[i-1][temp];
        }
    }
    prefix.resize(n+1);

    for(int i= 0; i< m; i++){
        int a, b;
        cin >> a >> b;
        prefix[a]++;
        prefix[b]++;

        int anc = lca(a, b);
        prefix[anc]--;
        prefix[dp[0][anc]]--;
    }

    req.resize(n+1);
    for(int i= 1; i<= n; i++) vis[i] = false;

    dfs2(1, adj, vis);

    for(int i= 1; i<= n; i++) cout << req[i] << " ";

    return 0;
}
