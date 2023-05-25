#include<iostream>
#include<bits/stdc++.h>

using namespace std ;
typedef long long ll;

int main(int argc, char* argv[]){
    ll k;
    cin >> k;
    
    for(ll i= 1; i<= k; i++){
        ll res = (ll)(i*i*((i*i) -1))/2;
        ll red = (ll)4*(i-1)*(i-2);
            
        ll ans = res - red;
        cout << ans << "\n";
    }
    
}
