#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll a; ll b;
        cin >> a; cin >> b;

        if( a == 0 && b != 0) cout << "NO" << "\n";
        else if( a != 0 && b == 0) cout << "NO" << "\n";
        else if( (2*a-b) < 0 || (2*b -a) < 0) cout << "NO" << "\n";
        else if((2*a-b)%3 ==0 && (2*b-a)%3 == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
