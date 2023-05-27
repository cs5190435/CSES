#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<pair<int, int> > vp;

int main (int argc, char *argv[]) {
    ll n;
    cin >> n;
    vp arr(n);
    for(int i= 0; i< n; i++){
        int temp;
        cin >> temp;
        arr[i] = make_pair(temp, i);
    }

    sort(arr.begin(), arr.end());

    int res = 1;
    int prev = arr[0].second;

    for(int i = 1; i< n; i++){
        if(arr[i].second < prev){
            res ++;
            prev = arr[i].second;
        }
    }


    cout << res << "\n";

    return 0;
}
