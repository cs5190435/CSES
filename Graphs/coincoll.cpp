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

vector<int> o;
vector<int> comp;
vector<int> dp;

void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis){
    vis[i] = true;
    for(auto j: adj[i]){
        if(!vis[j]) dfs(j, adj, vis);
    }
    o.push_back(i);
    return;
}

void dfs2(int i, vector<vector<int>>& adj, vector<bool>& vis, int c){
    comp[i] = c;
    vis[i] = true;
    for(auto j: adj[i]){
        if(!vis[j]) dfs2(j, adj, vis, c);
    }
    return;
}

int rec(int i, vector<int>& cost, vector<vector<int>>& adj){
    if(dp[i] != -1) return dp[i];
    
    dp[i] = cost[i];
    for(auto j: adj[i]){
        dp[i] = max(dp[i], dp[j]+ cost[i]);
    }
    return dp[i];
}



signed main () {

    int n, m;
    cin >> n >> m;
    
    vi gold(n+1, 0);
    for(int i=1; i<= n; i++) cin >> gold[i];

    vector<vector<int> > a1(n+1);
    vector<vector<int> > a2(n+1);

    for(int i= 0; i< m; i++){
        int a, b;
        cin >> a >> b;
        a1[a].push_back(b);
        a2[b].pb(a);
    }
    
    o.resize(0);

    vector<bool> vis(n+1, false);
    for(int i= 1; i<= n; i++){
        if(!vis[i])dfs(i, a1, vis);
    }

    //reverse(o.begin(), o.end());
    
    comp.resize(n+1);

    for(int i= 0; i<= n; i++) vis[i] = false;
    
    int cp = 0;
    for(int i= o.size()-1; i>= 0; i--){
        int c = o[i];
        if(!vis[c]){
            cp++;
            dfs2(c, a2, vis, cp);
        }
    }
    
    vector<vector<int>> na(cp+1);

    for(int i= 1; i<= n; i++){
        for(auto j: a1[i]){
            int c1 = comp[i];
            int c2 = comp[j];
            if(c1 != c2) na[c2].push_back(c1);
        }
    }

    dp.resize(cp+1);
    for(int i= 0; i<= cp; i++) dp[i] =-1;


    vector<int> cost(cp+1, 0);
    for(int i= 1; i<= n; i++) cost[comp[i]] += gold[i];

    int maxi = 0;
    for(int i= 1; i<= cp; i++) maxi = max(maxi, rec(i, cost, na));

    cout << maxi << "\n";
    
    return 0;
}
