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

    for(auto j : adj[i]){
        if(!vis[j]){
            dfs(j, adj, vis);
            pq.push({f[j], j});
            if(pq.size() > 2) pq.pop();
        }
    }

    if(pq.size() == 0) f[i] = 1;
    if(pq.size() == 1){f[i] =1+pq.top().first; c[i] = pq.top().second;}
    else if(pq.size() == 2){
        h[i] = 1 + pq.top().first;
        pq.pop();
        f[i] = 1+ pq.top().first; c[i] = pq.top().second;
    }
    return;
}

signed main () {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);

    for(int i= 1; i< n; i++){
        int a ; int b;
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

    for(int i= 1; i<= n; i++) cout << f[i] << " ";


    return 0;
}
