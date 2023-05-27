#include<iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

ll apple(vector<ll> arr, int index, ll lsum , ll rsum){
    if(index == arr.size()){
        return abs(lsum-rsum);
    }

    ll r1 = apple(arr, index+1, lsum+arr[index], rsum);
    ll r2 = apple(arr, index+1, lsum, rsum+arr[index]);

    return min(r1, r2);
}

int main (int argc, char *argv[]) {
    
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i= 0; i < n; i++) cin >> arr[i];

    cout << apple(arr, 0, 0, 0) << "\n";

    return 0;
}
