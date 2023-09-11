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

vector<int> root;
vector<int> down;
vector<int> help;

void dfs(int v, vector<vector<int>> adj){
    if(vis[v])return;
    vis[v] = true;
    
    for(int u : adj[v]){
        root[u] = root[v]+1;
        dfs(u, adj);
    }

    if(v != 0){
        for(int u : adj[v]){
            down[v] = max(down[v],1+down[u]);
        }
    }
    else{
        for(int i= 0; i< adj[0].size(); i++){
            help[i] = 1+down[adj[0][i]];
        }
    }
}

signed main () {
    speed_;

    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i= 1; i< n; i++){
        int a ; int b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    
    root.resize(n);
    down.resize(n);
    help.resize(adj[0].size());

    dfs(0, adj);
    
    if(adj[0].size() == 1)


    vector<int> temp = help; sort(temp.begin(), temp.end(), greater<int>());
    
    
    int m1 = 0; int m2 = 0;



    return 0;
}
