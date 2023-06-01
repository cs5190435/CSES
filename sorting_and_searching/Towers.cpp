#include <algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vp;


int main (int argc, char *argv[]) {
    int n;
    cin >> n;

    vi arr(1);
    cin >> arr[0];
    
    for(int i= 1; i< n; i++){
        int temp;
        cin >> temp;
        int help = upper_bound(arr.begin(), arr.end(), temp) - arr.begin();
        if(help < arr.size()) arr[help] = temp;
        else arr.push_back(temp);
    }

    cout << arr.size() << "\n";
    return 0;
}
