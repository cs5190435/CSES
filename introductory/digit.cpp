#include <cmath>
#include<iostream>
#include<bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

int main (int argc, char *argv[]) {
    int q;
    cin >> q;

    while(q--){
        ll k;
        cin >> k;
        
        if(k < 10){
            cout << k << "\n";
        }
        else{
            ll temp = 9;
            ll cnt= 1;
            while(k > temp){
                cnt++;
                k -= temp;
                temp = (ll)(pow(10, cnt) -pow(10, cnt-1))*cnt; 
            }

            ll rem = k%cnt;

            if(rem != 0) {
                string quo = to_string( (ll)pow(10, cnt-1) + (ll)(k/cnt) );
                cout << quo[rem-1] << "\n";
            }
            else{
                string quo = to_string( (ll)pow(10, cnt-1) + (ll)(k/cnt) -1);
                cout << quo[quo.size()-1] << "\n";
            }
        }

    }

    return 0;
}
