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

int maxn = 2e5+1;
vector<int> val(maxn);
vector<int> in(maxn);
vector<int> out(maxn);
int timer;

void dfs(int i, vector<bool>& vis, vector<vi>& adj){
    vis[i] = true;
    in[i] = timer++;
    for(auto j: adj[i]){
        if(!vis[j]) dfs(j, vis, adj);
    }
    out[i] = timer;
    return;
}




signed main () {
    speed_;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n, q;
    cin >> n >> q;
    for(int i= 1; <= n; i++) cin  >> val[i];
    
    vector<vector<int>> adj(n+1);
    for(int i= 1; i< n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n+1, false);


    return 0;
}
