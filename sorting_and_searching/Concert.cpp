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


const int M = 1000000007;
const int MM = 998244353;
const int N=1e6+5;
const int inf=1e18;


signed main () {
    speed_;
    int n; int m;
    cin >> n >>  m;
    vector<int> prices;
    for(int i=0; i< n; i++){
        int temp; cin >> temp;
        prices.push_back(temp);
    }
    sort(prices.begin(), prices.end());
    
    for(int i= 0; i< m; i++){
        int temp; cin >> temp;
        auto it = prices.upper_bound(temp);
        if(it == prices.begin()){
            cout << -1 << " ";
        }
        else{
            cout << *it << " ";
            prices.erase(it);
        }
    }


    return 0;
}
