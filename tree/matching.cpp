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
#define vb               vector<bool>
#define vp               vector<pair<int, int>>
#define pb               push_back
#define mp               make_pair


const int M = 1000000007;
const int MM = 998244353;
const int N=1e6+5;
const int inf=1e18;

void dfs(int i, vector<vi>& adj, vb& vis, vp& res){
    vis[i] = true;
    int r1 = 0; int curr = INT_MIN;
    for(int j= 0; j< adj[i].size(); j++){
        int c = adj[i][j];
        if(vis[c] == false){
            dfs(c, adj, vis, res);
            r1 += res[c].first;
            curr = max(curr, res[c].second-res[c].first);
        }
    }

    if(curr != INT_MIN)res[i].first =1+r1+curr;
    res[i].second = r1;
}


signed main () {
    speed_;
    int n; 
    cin >>n;
    vector<vi> adj(n+1);
    for(int i= 1; i< n; i++){
        int a; int b;
        cin >>a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1, false);
    vp res(n+1, {0,0});
    dfs(1, adj, vis, res);
    cout << max(res[1].first, res[1].second); 
    return 0;
}
