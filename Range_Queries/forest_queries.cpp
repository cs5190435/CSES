//Cpp coding template
#include <cinttypes>
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
    
    int n, q;
    cin >> n >> q;
    vector<vi> a(n+1, vi(n+1, 0));
    for(int i= 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            char curr;
            cin >> curr;
            if(curr == '*')a[i][j] = 1;
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i= 1; i<= n; i++){
        for(int j= 1; j<= n; j++){
            dp[i][j] = a[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    for(int i= 0; i< q; i++){
        int y1,x1,y2,x2;
        cin >> x1 >> y1 >> x2 >> y2;
        int res = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
        cout << res << "\n";
    }
    return 0;
}
