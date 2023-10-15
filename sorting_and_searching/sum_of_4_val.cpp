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
    for(int i= 0; i< n-3; i++){
        if(a[i].first > x)break;
        for(int j= i+1; j< n-2; j++){
            int s = a[i].first + a[j].first;
            if(s > x)break;
            int k = j+1;
            int l = n-1;
            while(k < l){
                int curr = a[k].first + a[l].first;
                if(curr > x-s)l--;
                else if(curr < x-s)k++;
                else{
                    cout << a[i].second << " "<< a[j].second << " " << a[k].second << " " << a[l].second << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
