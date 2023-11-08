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

vi arr;

signed main () {
    speed_;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    arr.resize(n);
    for(int i= 0; i<n; i++)cin >> arr[i];

    vector<vector<pi>> dp(n, vector<pi>(n));
    
    for(int i= 0; i< n; i++)dp[i][i] = {arr[i], 0};

    int l = 1;
    int i = 1;
    int j = i+1;

    while(l < n){
        i= 0;
        j = i+l;
        while(j < n){
            if(arr[i] + dp[i+1][j].second >= arr[j] + dp[i][j-1].second){
                dp[i][j] = {arr[i]+dp[i+1][j].second, dp[i+1][j].first};
            }
            else{
                dp[i][j] = {arr[j]+dp[i][j-1].second, dp[i][j-1].first};
            }
            i += 1;
            j += 1;
        }
        l += 1;
    }
    cout << dp[0][n-1].first << "\n";

    return 0;
}
