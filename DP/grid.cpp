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

    int n; cin >> n;
    vector<vector<int>> res(n, vector<int>(n, 0));
    vector<vector<char>> arr(n, vector<char>(n));
    for(int i= 0; i< n; i++){
        for(int j= 0; j< n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '*')res[i][j] = -1;
        }
    }

    if(res[0][0] == -1){cout << 0 << "\n"; return 0;}
        
    res[0][0] = 1;
    for(int i= 1; i< n; i++){
        if(res[i][0] != -1)res[i][0] = res[i-1][0];
        if(res[0][i] != -1)res[0][i] = res[0][i-1];
    }
    int mod = 1e9 + 7;
    for(int i= 1; i< n; i++){
        for(int j= 1; j< n; j++){
            if(res[i][j] != -1){
                int r1 = res[i-1][j];
                int r2 = res[i][j-1];
                if(r1 == -1 && r2 == -1)res[i][j] = -1;
                else if(r1 == -1)res[i][j] = r2;
                else if(r2 == -1)res[i][j] = r1;
                else {
                    res[i][j] = r1 + r2;
                    res[i][j] = res[i][j]%mod;
                }
            }
        }
    
    }
    if(res[n-1][n-1] == -1)cout << 0 << "\n";
    else cout << res[n-1][n-1] << "\n";

    return 0;
}
