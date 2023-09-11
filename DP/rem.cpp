//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi               vector<int>


int rec(int n, unordered_map<int,int>& dp){
    if(n == 0)return 0;
    if(dp[n] != 0)return dp[n];

    vector<int> dig(10, 0);
    int help = n;
    while(n != 0){
        int temp = n%10;
        dig[temp] = 1;
        n = n/10;
    }
    n = help;
    int res = INT_MAX;
    for(int i= 1; i< 10; i++){
        if(dig[i] == 1){
            int temp = rec(n-i, dp);
            if(temp != -1) res = min(res, temp);
        }
    }
    if(res == INT_MAX) return dp[n] = -1;
    else return dp[n] = 1+res;

}


signed main () {
    speed_;
    
    int n; 
    cin >> n;
    unordered_map<int, int> dp = {};
    cout << rec(n, dp) << "\n";

    return 0;
}
