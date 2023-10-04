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

vector<int> f;
vector<int> h;
vector<int> g;
vector<int> c;

void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis){
    vis[i] = true;
    priority_queue<pi, vector<pi>, greater<pi> > pq;

    for(auto j: adj[i]){
        if(!vis[j]) {
            dfs(j, adj, vis);
            pq.push({f[j], j});
            if(pq.size() > 2) pq.pop();
        }
    }

    if(pq.size() == 1){ f[i] =1+ pq.top().first; c[i] = pq.top().second;}
    else if(pq.size() == 2){
        h[i] = 1+pq.top().first;
        pq.pop();
        f[i] = 1+ pq.top().first; c[i] = pq.top().second;
    }
    return;
}


void dfs2(int i, vector<vector<int>>& adj, vector<bool>& vis, int p){
    vis[i] = true;
    if(c[p] == i) g[i] = max(g[p]+1, h[p]+1);
    else g[i] = max(g[p]+1, f[p]+1);

    for(auto j: adj[i]){
        if(!vis[j]) dfs2(j, adj, vis,i);
    }
    return;
}


signed main () {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);

    for(int i= 1; i< n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    f.resize(n+1);
    h.resize(n+1);
    g.resize(n+1);
    c.resize(n+1);
    
    
    vector<bool> vis(n+1, false);

    dfs(1, adj, vis);
    g[0] = -1;
    h[0] = -1;
    f[0] = -1;

    for(int i= 0; i<= n; i++) vis[i] = false;

    dfs2(1, adj,vis,0);

    for(int i=1; i<= n; i++) cout << max(f[i], g[i]) << " ";
    return 0;
}
