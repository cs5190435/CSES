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

vector<vector<int>> dp;
vector<int> levels;

void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, int p){
    levels[i] = levels[p]+1;
    vis[i]= true;

    for(auto j: adj[i]){
        if(!vis[j]) dfs(j, adj, vis, i);
    }
    return;
}

signed main () {
    int n;int q;
    cin >> n >> q;

    vector<vector<int>> adj(n+1);
    dp.resize(32, vector<int>(n+1));
    levels.resize(n+1);

    for(int i=2; i<= n; i++){
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
        dp[0][i] = a;
    }

    vector<bool> vis(n+1, false);
    dfs(1, adj, vis, 0);



    for(int i= 1; i< 32; i++){
        for(int j= 1; j<= n; j++){
            int temp = dp[i-1][j];
            dp[i][j] = dp[i-1][temp];
        }
    }

    for(int i= 0; i< q; i++){
        int a, b;
        cin >> a >> b;
        if(levels[a] < levels[b]) swap(a, b);
        int diff = levels[a]-levels[b];
        while(diff > 0){
            int d = (int)log2(diff);
            a = dp[d][a];
            diff -= pow(2, d);
        }

        if(a == b) cout << a << "\n";
        else{
            for(int i= 20; i>=0; i--){
                int at = dp[i][a];
                int bt = dp[i][b];
                if(at != bt){
                    a = at;
                    b = bt;
                }
            }
            cout << dp[0][a] << "\n";
        }

    }

    return 0;
}
