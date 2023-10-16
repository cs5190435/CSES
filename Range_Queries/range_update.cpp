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

vi a;
vi res;
vi lazy;

void build(int v, int l, int r){
    if(l == r){res[v] = a[l]; return;}
    int mid = (l+r)/2;
    build(2*v, l, mid);
    build(2*v+1, mid+1, r);
    res[v] = res[2*v]+ res[2*v+1];
    return;
}

int query(int v, int ss, int se, int qs, int qe){
    if(lazy[v] != 0){
        res[v] += (se-ss+1)*lazy[v];
        if(2*v< res.size())lazy[2*v] += lazy[v];
        if((2*v +1) < res.size()) lazy[2*v+1] += lazy[v];
        lazy[v] = 0;
    }
    
    if(ss > qe || se < qs)return 0;
    if(ss >= qs && se <= qe)return res[v];
    int mid = (ss+se)/2;
    int a1 = query(2*v, ss, mid, qs, qe);
    int a2 = query(2*v+1, mid+1, se,qs, qe);
    return a1+a2;
}

void update(int v, int ss, int se, int qs, int qe, int x){
    if(lazy[v] != 0){
        res[v] += (se-ss+1)*lazy[v];
        if(2*v< res.size())lazy[2*v] += lazy[v];
        if((2*v +1) < res.size()) lazy[2*v+1] += lazy[v];
        lazy[v] = 0;
    }
    if(ss > qe || se < qs)return;
    if(ss >= qs && se <= qe){
        res[v] += (se-ss+1)*x;
        if(2*v< res.size())lazy[2*v] += x;
        if((2*v +1) < res.size()) lazy[2*v+1] += x;
        return;
    }
    int mid = (ss+se)/2;
    update(2*v, ss, mid, qs, qe, x);
    update(2*v+1, mid+1, se, qs, qe, x);
    res[v] = res[2*v] + res[2*v+1];
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
    a.resize(n+1);
    res.resize(4*n+1);
    lazy.resize(4*n+1);
    for(int i= 1; i<= n; i++) cin >> a[i];

    build(1, 1, n);

    for(int i= 0; i< q; i++){
        int t;
        cin >> t;
        if(t== 1){
            int u,v,x;
            cin >> u >> v >> x;
            update(1, 1, n, u, v, x);
        }
        else{
            int k;
            cin >> k;
            cout << query(1, 1, n, k, k) << "\n";
        }
    }
    

    return 0;
}
