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

bool ok(int c, int t, vi& a){
    int i = 0;
    while(t > 0 && i < a.size()){
        int temp = (c/a[i]);
        t -= temp;
        i += 1;
    }
    if(t <= 0)return true;
    else return false;
}


signed main () {
    speed_;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i= 0; i< n; i++)cin >> a[i];
    sort(a.begin(),a.end());
    int maxi = t*a[n-1];
    int x =-1;

    for(int z = maxi; z >= 1; z = z/2){
        while(!ok(z+x, t, a))x += z;
    }
    cout << x+1 << "\n";

    return 0;
}
