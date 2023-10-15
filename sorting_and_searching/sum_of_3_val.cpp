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
    vector<pi> a(n);
    for(int i= 0; i< n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());

    for(int i= 0; i< n-2; i++){
        int s = a[i].first;
        if(s > x) break;
        int j = i+1;
        int k = n-1;
        while(j < k){
            int curr = a[j].first + a[k].first;
            if(curr > x-s)k--;
            else if(curr < x-s)j++;
            else{
                cout << a[i].second << " " << a[j].second << " " << a[k].second << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}
