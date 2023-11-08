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
vi tree;

int query(int v, int ss, int se, int qs, int qe){
    if(ss > qe || se < qs)return 0;
    if(ss >= qs && se <= qe)return tree[v];
    int mid = (ss+se)/2;
    int r1 = query(2*v, ss, mid, qs, qe);
    int r2 = query(2*v+1, mid+1, se, qs, qe);
    return r1 + r2;
}

void update(int v, int ss, int se, int i){
    if(ss == se && ss == i){
        tree[v] += 1;
        return;
    }
    int mid = (ss+se)/2;
    if(mid < i){
        update(2*v+1, mid+1, se, i);
    }
    else{
        update(2*v, ss, mid, i);
    }
    tree[v] = tree[2*v] + tree[2*v+1];
}


signed main () {
    speed_;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n;
    cin >> n;
    a.resize(n+1);
    tree.resize(4*n+1);

    for(int i= 1; i<= n; i++) cin >> a[i];

    for(int i= 1; i<= n; i++){
        int curr;
        cin >> curr;
        int lo= 1;
        int hi= n;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            int res = query(1, 1, n, 1, mid);
            int comp = mid - res;
            if(comp ==  curr){
                cout << a[mid] << "\n";
                update(1, 1, n, mid);
                break;
            }
            else if(comp > curr)hi = mid;
            else lo= mid+1;
        }
    }

    return 0;
}
