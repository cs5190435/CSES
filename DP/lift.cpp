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
    int n; int x;
    cin >> n >> x;
    vi arr(n);
    for(int i= 0; i< n; i++) cin >> arr[i];

    vector<pair<int, int>> dp(1 << n);
    dp[0] = {1, 0};

    for(int i= 1; i< (1 << n); i++){
        dp[i] = {n+1, 0};
        for(int j= 0; j< n; j++){
            if(i & (1 << j)){
                auto temp = dp[i^(1<<j)];
                if(temp.second + arr[j] <= x){
                    temp.second += arr[j];
                }
                else{
                    temp.first++;
                    temp.second = arr[j];
                }
                dp[i] = min(dp[i], temp);
            }
        }
    }
    cout << dp[(1 << n)-1].first << "\n";

    return 0;
}
