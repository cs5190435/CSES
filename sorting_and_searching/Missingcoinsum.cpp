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

    sort(arr.begin(), arr.end());
    ll res = 1;

    for(int i=0; i< n; i++){
        if(arr[i] > res){
            cout << res << "\n";
            return 0;
        }
        else{
            res += arr[i];
        }
    }

    cout << res << "\n";
    return 0;
}
