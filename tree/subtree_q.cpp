//Cpp coding template
#include <cstdlib>
#include <ctime>
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

int maxn = 2e5 + 2;
vector<int> q(maxn);
vector<int> in(maxn);
vector<int> out(maxn);
vector<int> t(4*maxn);
vector<int> book(maxn);
vector<int> arr = {0};
int timer;

void dfs(int i, vector<bool>& vis, vector<vi>& adj){
    vis[i] = true;
    in[i] = timer++;
    arr.push_back(q[i]);
    book[i] = arr.size()-1;
    for(auto j: adj[i]){
        if(!vis[j]) dfs(j, vis, adj);
    }
    out[i] = timer;
    return;
}

void build(int v, int l, int r){
    if(l == r){
        t[v] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*v, l, mid);
    build(2*v+1, mid+1, r);
    t[v] = t[2*v] + t[2*v+1];
}

int query(int v, int ss, int se, int qs, int qe){
    if(ss > qe || se < qs) return 0;
    if(ss >= qs && se <= qe)return t[v];
    int mid = (ss+se)/2;
    int a = query(2*v, ss, mid, qs, qe);
    int b = query(2*v+1, mid+1, se, qs, qe);
    return a+b;
}

void update(int v, int ss, int se, int qi, int d){
    if(ss > qi || se < qi)return;
    if(ss == se){
        t[v] += d;
        return;
    }
    int mid = (ss+se)/2;
    update(2*v, ss, mid, qi, d);
    update(2*v+1, mid+1, se,  qi, d);
    t[v] = t[2*v] + t[2*v+1];
}

signed main () {
    speed_;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    int n; int t;
    cin >> n >> t;
    for(int i=1; i<= n; i++) cin >> q[i];

    vector<vi> adj(n+1);
    for(int i=1; i< n; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    dfs(1, vis, adj);

    build(1, 1, n);

    for(int i= 0; i < t; i++){
        int type;
        cin >> type;
        if(type == 2){
            int s;
            cin >> s;
            int start = book[s];
            int end = start + out[s]-in[s]-1;
            cout << query(1, 1, n, start, end) << "\n";
        }
        else{
            int s; int x;
            cin >> s >> x;
            int qi = book[s];
            int req = x-q[s];
            update(1, 1, n, qi, req);
            q[s] = x;
        }
    }
    

    return 0;
}
