//Cpp coding template
#include <algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi               vector<int>


int best(map<int, int>& bk, int v){
    auto it = bk.lower_bound(v);
    if(it == bk.begin())return 0;
    it--;
    return it->second;
}

void insert(map<int, int>& bk, int v, int adv){

    if(bk[v] > adv) return;
    
    bk[v] = adv;
    auto it = bk.find(v);
    it++;
    while(it != bk.end() && it->second <= adv){
        auto temp = it;
        it++;
        bk.erase(temp);
    }
    return;
}


signed main () {
    speed_;

    int n;
    cin >> n;
    vi arr(n);
    for(int i= 0; i< n; i++)cin >> arr[i];

    vector<int> dp(n, 0);
    dp[0] = 1;
    map<int, int> bk;
    bk[arr[0]] = dp[0];
    for(int i= 1; i< n; i++){
        dp[i] = 1 + best(bk, arr[i]);
        insert(bk, arr[i], dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}
