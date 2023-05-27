#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main (int argc, char *argv[]) {
    ll n;
    cin >> n;

    vl arr(n);
    for(int i= 0; i< n; i++) cin >> arr[i];

    if(n==1) {cout << 0 << "\n" ; return 0;}

    sort(arr.begin(), arr.end());

    vl psum(n+2, 0);
    vl ssum(n+2, 0);

    psum[1] = arr[0];
    for(int i= 2; i<= n; i++) psum[i] = psum[i-1] + arr[i-1];

    ssum[n] = arr[n-1];
    for(int i= n-1; i>=1 ; i--) ssum[i] = ssum[i+1] + arr[i-1];

    ll res = 9223372036854775807;

    for(int i= 1; i< n; i++){
        ll slope = (ll)(2*i - n);
        ll v1 = arr[i-1]*slope + ssum[i+1] - psum[i];
        ll v2 = arr[i]*slope + ssum[i+1] - psum[i];
        res = min(res, v1);
        res = min(res, v2);
    }

    ll v1 = ssum[1] - n*arr[0];
    ll v2 = n*arr[n-1] - psum[n];

    res = min(res, v1);
    res = min(res, v2);

    cout << res << "\n";
    return 0;
}
