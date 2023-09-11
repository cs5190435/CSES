//Cpp coding template
#include <algorithm>
#include<iostream>
#include<bits/stdc++.h>
#include <valarray>
using namespace std;

//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)


int best(map<int, int>& bk, int v){
    auto it = bk.lower_bound(v);
    if(it == bk.begin()) return 0;
    it--;
    return it->second;
}


void insert(map<int, int>& bk, int v, int adv){
    if(bk[v] > adv)return;

    bk[v] = adv;
    auto it = bk.lower_bound(v);
    if(it == bk.begin())return;
    it--;
    int req = it->second;
    it++;
    while(it != bk.end() && it->second <= req){
        auto temp= it;
        it++;
        bk.erase(temp);
    }
    return;
}


signed main () {
    speed_;

    int n;
    cin >> n;

    vector<vector<int>> data(n, vector<int>(3, 0));

    
    for(int i= 0; i< n; i++){
        cin >> data[i][1];
        cin >> data[i][0];
        cin >> data[i][2];
    }
    
    sort(data.begin(), data.end());

    map<int, int> bk;

    vector<int> dp(n);
    dp[0] = data[0][2];
    bk[data[0][0]] = data[0][2];

    for(int i= 1; i< n; i++){
        dp[i]= data[i][2] + best(bk, data[i][1]);
        insert(bk, data[i][0], dp[i]);
    }
    
    cout << *max_element(dp.begin(), dp.end()) << "\n";



    return 0;
}
