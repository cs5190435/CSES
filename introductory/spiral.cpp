#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char*argv[]){
    int t;
    cin >> t;

    while(t--){
        ll x; ll y;
        cin >> x; cin >> y;

        if(x < y){
            if(y %2 == 0) cout << (y-1)*(y-1) + x << "\n";
            else cout << y*y +1 - x << "\n";
        }
        else{
            if(x %2 == 0) cout << x*x +1 - y << "\n";
            else cout << (x-1)*(x-1) + y << "\n";
        }
    }

    return 0;
}
