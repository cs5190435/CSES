#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ios::sync_with_stdio(0);
cin.tie(0);

int main(){
    ll n;
    cin >> n;
    
    while(true){
        cout << n << " ";
        if(n==1) break;
        else if(n%2 == 0) n= n/2;
        else n = 3*n +1;
    }

    return 0;
}
