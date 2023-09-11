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
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    ////freopen('output.txt','w',stdout);
    //#endif

    int n;
    int z = 0;
    int s = 6;
    int mod = 1e9 + 7;
    cin >> n;
    vector<int> arr(n+1, 0);
    int lim = min(n, s);
    for(int i= 1; i<= lim; i++){
        arr[i] = 1;
        int hp = min(i, s);
        for(int j= 1; j< hp; j++)arr[i] += arr[j];
    }

    for(int i= 7; i<= n; i++){
        for(int j= i-1; j >= i-6; j--)arr[i] += arr[j];
        arr[i] %= mod;
    }
    cout << arr[n] << "\n";

    return 0;
}
