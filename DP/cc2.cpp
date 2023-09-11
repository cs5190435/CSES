//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi               vector<int>




signed main () {
    speed_;

    int n; int x;
    cin >> n >> x;
    vi arr(n);
    for(int i= 0; i< n; i++)cin >> arr[i];

    vector<vi> dp(n+1, vector<int>(x+1, 0));

    for(int i= 0; i<=n; i++) dp[i][0]=1;

    int mod = 1e9 +7;
    for(int i= 1; i<= n; i++){
        for(int j= 1; j<= x; j++){
            if(j >= arr[i-1]){
                dp[i][j] = dp[i-1][j] + dp[i][j-arr[i-1]];
            }
            else dp[i][j] = dp[i-1][j];
            dp[i][j] %= mod;
        }
    }

    cout << dp[n][x] << "\n";

    return 0;
}
