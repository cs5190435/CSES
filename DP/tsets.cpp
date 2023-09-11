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

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i= 0; i< n; i++)arr[i] = i+1;
    
    int sum = (n*(n+1))/2;
    int mod = 1e9 + 7;

    if(sum%2 != 0){
        cout << 0 << "\n";
        return 0;
    }
    else{
        sum = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int i= 0; i<= n; i++)dp[i][0] = 1;

        for(int i= 1; i<= n; i++){
            for(int j= 1; j<= sum; j++){
                if(j >= arr[i-1]){
                    int r1 = dp[i-1][j];
                    int r2 = dp[i-1][j-arr[i-1]];
                    dp[i][j]= (r1+r2);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
                dp[i][j] = dp[i][j]%mod;
            }
        }
        int curr = (dp[n][sum]* 500000004)%mod;
        cout << curr << "\n";
    }

    

    return 0;
}
