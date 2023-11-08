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
    
    int n, a, b;
    cin >> n >> a >> b;
    vi arr(n);
    for(int i= 0; i< n; i++) cin >> arr[i];

    int l= 0;
    int r = 0;
    int curr = 0;
    int best = INT_MIN;
    while(l <= r && r < n){
        if(r-l+1 < a){
            curr += arr[r];
            r++;
        }
        else if(r-l+1 == a){
            best = max(best, curr);
            r++;
        }
        else{
        }
    }

    return 0;
}
