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


signed main () {
    speed_;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    vector<pi> a(n);
    for(int i= 0; i< n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int res = 0;
    int time = 0;
    for(int i= 0; i< n; i++){
        time += a[i].first;
        res += a[i].second - time;
    }
    cout << res << "\n";

    return 0;
}
