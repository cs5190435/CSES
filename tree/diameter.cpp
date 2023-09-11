//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
#include <queue>
using namespace std;


#define int              long long
using   ll=              long long;
#define ld               long double
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define pi               pair<int, int>
#define vi               vector<int>
#define vb               vector<bool>
#define vp               vector<pair<int, int>>
#define pb               push_back
#define mp               make_pair


const int M = 1000000007;
const int MM = 998244353;
const int N=1e6+5;
const int inf=1e18;

pi dfs(int i, vector<vi>& adj, vb& vis){
    vis[i] = true;
    pi curr = {0,i};
    for(int j= 0; j< adj[i].size(); j++){
        int c = adj[i][j];
        if(vis[c])continue;
        pi temp = dfs(c, adj, vis);
        if(curr.first < 1+ temp.first){
            curr.first = 1+temp.first; curr.second = temp.second;
        }
    }
    return curr;
}

signed main () {
    speed_;
    int n;
    cin >> n;
    vector<vi> adj(n+1);
    for(int i=1; i< n; i++){
        int a ;int b; cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1, false);
    auto r1 = dfs(1, adj, vis);

    vis.assign(n+1, false);
    auto res = dfs(r1.second, adj, vis);
    cout << res.first;
    return 0;
}
