#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    ll res = 0;
    while(n > 0){
        res += (n/5);
        n = (ll)n/5;
    }

    cout << res << "\n";
}
