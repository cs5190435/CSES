//Cpp coding template
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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n+1, 0);
    for(int i= 1; i<= n; i++) cin >> arr[i];
    int i =0; int j= 0;
    int sum = 0;
    int cnt = 0;
    while(i <= j && j <= n){
        sum += arr[j];
        if(sum == x){
            cnt++;
            j++;
        }
        else if(sum < x)j++;
        else{
            while(sum > x){
                i++;
                sum -= arr[i];
            }
            if(sum == x){
                cnt++;
            }
            j++;
        }
    }
    cout << cnt << "\n";

    return 0;
}
