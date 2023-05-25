#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void temp(ll n){
    ll res =1;
    ll div = 1e9 + 7;
    for(ll i= 0; i< n; i++){
        res = res*2;
        res = res%(div);
    }

    cout << res << "\n";
}

int main(){
    ll n;
    cin >> n;

    temp(n);

}
