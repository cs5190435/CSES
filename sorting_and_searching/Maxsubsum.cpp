#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vl;

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    vl arr(n);
    for(int i= 0; i< n; i++) cin >> arr[i];
    
    ll curr = 0;
    ll res = INT_MIN;
    for(int i= 0; i< n; i++){
        curr += (ll)arr[i];
        res = max(res, curr);
        if(curr < 0) curr = 0;
    }

    if(res > 0) cout << res << "\n";
    else{
        sort(arr.begin(), arr.end());
        cout << arr[arr.size()-1] << "\n";
    }
    
    return 0;
}
