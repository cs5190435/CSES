//Cpp coding template
#include <cmath>
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

vector<int> res;


void build(int v, int l, int r, vi& a){
    if(l == r){res[v] = a[l]; return;}
    int mid = (l+r)/2;
    build(2*v, l, mid, a);
    build(2*v+1, mid+1, r, a);
    res[v] = res[2*v] + res[2*v+1];
    return;
}

int query(int v, int ss, int se, int qs, int qe){
    if(se < qs || ss > qe)return 0;
    if(ss >= qs && se <= qe)return res[v];
    int mid = (ss+se)/2;
    int a1 = query(2*v, ss, mid, qs, qe);
    int a2 = query(2*v+1, mid+1, se, qs, qe);
    return a1+a2;
}

signed main () {
    speed_;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, q;
    cin >> n >> q;
    vi a(n+1);
    for(int i =1; i<= n; i++) cin >> a[i];
    res.resize(4*n+1);
    build(1, 1, n, a);

    for(int i= 0; i< q; i++){
        int x, y;
        cin >> x >> y;
        cout << query(1, 1, n, x, y) << "\n";
    }
    return 0;
}
