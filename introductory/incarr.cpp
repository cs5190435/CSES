#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char* argv[]){
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for(int i= 0; i< n; i++){
        cin >> arr[i];
    }
    
    int curr = arr[0]; 
    ll res = 0;
    for(int i= 1; i< n; i++){
        if( arr[i] < curr){
            res += (ll)(curr-arr[i]);
        }
        else{
            curr = arr[i];
        }
    }

    cout << res << "\n";
    return 0;
}
