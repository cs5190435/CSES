//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi               vector<int>



signed main () {
    speed_;
    string a ;
    string b;
    cin >> a >> b;

    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
    for(int i= 1; i<= a.size(); i++){
        dp[i][0] = i;
    }
    for(int i= 1; i <= b.size(); i++){
        dp[0][i] = i;
    }
    for(int i=1; i<= a.size(); i++){
        for(int j= 1; j<= b.size(); j++){
            if(a[i-1] == b[j-1]){
                int curr = min(dp[i-1][j], dp[i][j-1]);
                if( dp[i-1][j-1] <= curr)dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + curr;
            }
            else{
                int curr = min(dp[i-1][j], dp[i][j-1]);
                curr = min(curr, dp[i-1][j-1]);
                dp[i][j] = curr + 1;
            }
        }
    }
    cout << dp[a.size()][b.size()] << "\n";

    return 0;
}
