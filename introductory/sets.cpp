#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char* argv[]){
    ll n;
    cin >> n;
    
    if(n%4 != 0 && (n+1)%4 != 0){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";
        ll sum = (n*(n+1))/4;
        
        ll tmp = n;
        vector<bool> arr(n+1, false);
        while(sum > 0){
            if(tmp > sum){
                tmp = sum;
            }
            arr[tmp] = true;
            sum -= tmp;
            tmp -= 1;
        }
        
        int c1 = 0;
        for(ll i= 1; i<=n; i++){
            if(arr[i])c1++;
        }
        cout << c1 << "\n";

        for(ll i= 1; i<=n; i++){
            if(arr[i]) cout << i << " ";
        }
        cout << "\n";

        cout << n-c1 << "\n";
        for(ll i =1; i<= n; i++){
            if(arr[i] == false) cout << i << " ";
        }
        cout << "\n";
    }
    
}
