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

vector<int> cnt;
vector<int> st;
vector<bool> vis;

void dfs1(int v, vector<vector<int>>& adj) {
    if (vis[v]) return;
    vis[v] = true;
    for (int u : adj[v]) {
        dfs1(u, adj); 
    }

    for(int u : adj[v]){
        cnt[v] += cnt[u];
        st[v] += st[u] + cnt[u];
    }
    cnt[v]++;


    return; 
}

signed main () {
    speed_;
    
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> res(n, 0);
    for(int i= 1; i< n; i++){
        int a ; int b; 
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    cnt.resize(n);
    st.resize(n);
    vis.resize(n);

    dfs1(0,adj);

    res[0] = st[0];
    vis.assign(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while(q.size() > 0){
        int v = q.front();
        q.pop();
        for(auto i : adj[v]){
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
                res[i] = res[v] + n - 2*cnt[i];
            }
        }
    }


    for(int i= 0; i< n; i++) cout << res[i] << " ";
    cout << endl;

    return 0;
}
