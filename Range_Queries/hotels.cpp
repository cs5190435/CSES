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


vector<pi> tree;
vector<int> a;

void build(int v, int l, int r){
    if(l ==r){
        tree[v] = {a[l], l};
        return;
    }
    int mid = (l+r)/2;
    build(2*v, l, mid);
    build(2*v+1, mid+1, r);
    if(tree[2*v].first >= tree[2*v+1].first){
        tree[v] = tree[2*v];
    }
    else{
        tree[v] = tree[2*v+1];
    }
}

int query(int v, int l, int r, int val){
    if(tree[v].first < val)return 0;
    if(l == r){
        return tree[v].second;
    }
    int mid = (l+r)/2;
    if(tree[2*v].first >= val){
        int res = query(2*v, l, mid, val);
        return res;
    }
    else{
        int res = query(2*v+1, mid+1, r, val);
        return res;
    }
}

void update(int v, int l, int r, int i, int curr){
    if(l == r && l != i)return;
    if(l == r && l == i){
        tree[v].first -= curr;
        return;
    }
    int mid = (l+r)/2;
    if(mid < i){
        update(2*v+1, mid+1, r, i, curr);
        tree[v] = max(tree[2*v], tree[2*v+1]);
    }
    else{
        update(2*v, l, mid, i, curr);
        tree[v] = max(tree[2*v], tree[2*v+1]);
    }
}


signed main () {
    speed_;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n, m;
    cin >> n >> m;

    a.resize(n+1);
    for(int i= 1; i<= n; i++) cin >> a[i];
    
    tree.resize(4*n+1);

    build(1, 1, n);

    for(int i= 0; i<m; i++){
        int curr;
        cin >> curr;
        int res = query(1, 1, n, curr);
        cout << res << "\n";
        if(res != 0){
            a[res] -= curr;
            update(1, 1, n, res, curr);
        }
    }

    return 0;
}
