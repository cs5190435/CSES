//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi               vector<int>




signed main () {
    speed_;

    int n; int m;
    cin >> n >> m;
    vi arr(n+1);
    for(int i= 1;i<= n; i++) cin >> arr[i];
    vector<vector<int>> dp(n+2, vector<int>(m+2, 0));
    int mod = 1e9 + 7;
        
    for(int i= 1; i<= n; i++){
        for(int j = 1; j<=m; j++){
            if( i== 1){
                if(arr[i] == 0 || arr[i] == j){
                    dp[i][j] = 1;
                }

            }
            else{
                if(arr[i] == 0 || arr[i] == j){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                    dp[i][j] %= mod;
                }
            }
        }
    }

    int res = 0;
    for(int i= 0; i<= m; i++){
        res += dp[n][i];
    }
    res = res%mod;
    cout << res << "\n";

    
    return 0;
        
}
