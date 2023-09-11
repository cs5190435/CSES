//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define int              long long
using   ll=              long long;
#define ld               long double
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define pi               pair<int, int>
#define vi               vector<int>
#define vb               vector<bool>
#define vp               vector<pair<int, int>>
#define pb               push_back
#define mp               make_pair



signed main () {
    speed_;

    int n; int x ;
    cin >> n >> x;
    vi arr(n);
    for(int i= 0; i< n; i++) {cin >> arr[i];}
    sort(arr.begin(), arr.end());

    vector<int> dp(x+1, 0);
    dp[0]=1;
    int mod = 1e9 + 7;
    for(int i= 1; i<= x; i++){
        for(auto j : arr){
            if(j > i)break;
            else{
                dp[i] += dp[i-j];
            }
        }
        dp[i] %= mod;
        
    }
    cout << dp[x] << "\n";

    return 0;
}
