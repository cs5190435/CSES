#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    vi arr(n,0);
    for(int i= 0; i< n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int res= 1;
    for(int i= 1; i< arr.size(); i++){
        if(arr[i] != arr[i-1]) res++;
    }

    cout << res << "\n";

    return 0;
}
