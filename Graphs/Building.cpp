//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi               vector<int>
#define vb               vector<bool>
#define pb               push_back

void dfs(int i, vector<bool>& vis, vector<vector<int>>& adj){
    if(vis[i] == true) return;
    vis[i] = true;

    for(auto j: adj[i]){
        dfs(j, vis, adj);
    }
    return;
}

signed main () {
    speed_;

    int n; int m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i= 0; i< m; i++){
        int a ; int b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    vector<bool> vis(n+1, false);
    vector<int> connect = {};

    for(int i= 1; i<= n; i++){
        if(vis[i] == false){
            connect.push_back(i);
            dfs(i, vis, adj);
        }
    }

    cout << connect.size()-1 << "\n";
    for(int i= 1; i< connect.size(); i++){
        cout << connect[i-1] << " " << connect[i] << "\n";
    }

    return 0;
}
