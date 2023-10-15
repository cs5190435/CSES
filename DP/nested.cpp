//Cpp coding template
#include<iostream>
#include<algorithm>
#include<limits>
#include<vector>
#include<map>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define pb push_back
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)

bool compare(vi a1, vi a2){
    if(a1[0] < a2[0])return false;
    else if(a1[0] > a2[0])return true;
    else return a1[1] < a2[1];
}

bool c2(vi a1, vi a2){
    if(a1[0] < a2[0]) return true;
    else if(a1[0] > a2[0])return false;
    else return a1[1] > a2[1];
}

signed main () {
    speed_;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    vector<vi> a(n, vi(3, 0));
    for(int i= 0;i <n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end(), c2);
    int rmax = a[0][1];
    vi v1(n, 0);
    vi v2(n, 0);
    for(int i= 1; i< n; i++){
        if(rmax >= a[i][1])v2[a[i][2]] = 1;
        rmax = max(rmax, a[i][1]);
    }
    sort(a.begin(), a.end(), compare);
    rmax = a[0][1];
    for(int i=1; i< n; i++){
        if(rmax <= a[i][1])v1[a[i][2]] = 1;
        rmax = min(rmax, a[i][1]);
    }
    for(int i= 0; i< n; i++)cout << v1[i] << " ";
    cout << endl;
    for(int i= 0; i< n; i++)cout << v2[i] << " ";
    cout << endl;

    return 0;
}
