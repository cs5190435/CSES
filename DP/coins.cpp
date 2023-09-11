//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;




signed main () {

    int n; int x;
    cin >> n >> x;
    vector<int> arr(n, 0);
    for(int i= 0; i< n; i++) cin >> arr[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for(int i=1; i<= x; i++){
        dp[0][i] = -1;
    }

    for(int i= 1; i<= n; i++){
        for(int j= 1; j<=x ; j++){
            if(j >= arr[i-1]){
                int r1 = dp[i][j-arr[i-1]];
                int r2 = dp[i-1][j];
                if(r1 == -1 && r2 == -1){
                    dp[i][j] = -1;
                }
                else if(r1 == -1){

                    dp[i][j] = r2;
                }
                else if(r2 == -1){

                     dp[i][j] =1+ r1;
                }
                else{

                dp[i][j] = min(1 +r1, r2);}
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][x] << "\n";

    return 0;
}
