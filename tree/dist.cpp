//Cpp coding template
#include<iostream>
#include<algorithm>
#include<limits>
#include<vector>
#include<bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define pb push_back
using namespace std;

#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
vector<vector<int>> dp;
vector<int> dep;

void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, int p){
    vis[i]= true;
    dp[0][i] = p;
    dep[i] = dep[p]+1;

    for(auto j: adj[i]){
        if(!vis[j]) dfs(j, adj, vis, i);
    }
    return;
}

signed main () {
    speed_;
    int n; int q;
    cin >> n >> q;

    vector<vector<int>> adj(n+1);
    dp.resize(32, vector<int>(n+1));
    dep.resize(n+1);

    for(int i=1; i< n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    dfs(1, adj, vis, 0);

    for(int i= 1; i< 21; i++){
        for(int j= 1;j<= n; j++){
            int temp = dp[i-1][j];
            dp[i][j] = dp[i-1][temp];
        }
    }

    for(int i= 0; i< q; i++){
        int a, b;
        cin >> a >> b;
        if(dep[a] > dep[b]) swap(a, b);
        int r1 = dep[a];
        int r2 = dep[b];
        int diff = dep[b] - dep[a];

        while(diff > 0){
            int k = (int)log2(diff);
            b = dp[k][b];
            diff -= pow(2, k);
        }
        if(a == b){
            cout << r2 -r1 << "\n";
        }
        else{
            for(int i= 20; i>= 0; i--){
                int ta = dp[i][a];
                int tb = dp[i][b];
                if(ta != tb){
                    a = ta;
                    b = tb;
                }
            }
            a= dp[0][a];
            cout << r1 + r2 - 2*dep[a] << "\n";
        }

    }

    return 0;
}
