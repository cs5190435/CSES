//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi               vector<int>
#define vb               vector<bool>
#define pb               push_back
#define pi               pair<int, int>

signed main () {
    speed_;
    int n; int m; int q;
    cin >> n >> m >> q;

    vector<vector<int>> edges(m);

    for(int i= 0; i<m; i++){
        int a; int b; int c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    for(int i= 0; i< m; i++){
        int a = edges[i][0];
        int b = edges[i][1];
        int c = edges[i][2];
        if(dp[a][b] != -1){
            dp[a][b] = min(dp[a][b], c);
            dp[b][a] = min(dp[b][a], c);
        }
        else{
            dp[a][b] = c;
            dp[b][a] = c;
        }
    }

    for(int i= 1; i<= n; i++) dp[i][i] = 0;

    for(int k= 1; k<=n; k++){
        for(int i= 1; i<=n; i++){
            for(int j = 1; j<= n; j++){
                int a1 = dp[i][j];
                int a2 = dp[i][k];
                int a3 = dp[k][j];
                if(a1 == -1){
                    if(a2 != -1 && a3 != -1) dp[i][j] = a2 + a3;
                }
                else{
                    if(a2 != -1 && a3 != -1) dp[i][j] = min(dp[i][j], a2 + a3);
                }
            }
        }
    }


    for(int i=0; i < q; i++){
        int a; int b;
        cin >> a >> b;
        if(dp[a][b] == -1) cout << -1 << "\n";
        else cout << dp[a][b] << "\n";
    }


    return 0;
}
