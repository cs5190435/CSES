//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)



signed main () {
    speed_;

    int n; int x;
    cin >> n >> x;
    vector<int> price(n, 0);
    for(int i= 0; i< n; i++)cin >> price[i];
    vector<int> page(n, 0);
    for(int i= 0; i< n; i++) cin >> page[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for(int i=1 ; i<= n; i++){
        for(int j= 1; j<= x; j++){
            if(j >= price[i-1]){
                int r1 = dp[i-1][j];
                int r2 = dp[i-1][j-price[i-1]] + page[i-1];
                dp[i][j] = max(r1, r2);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][x] << "\n";

    return 0;
}
