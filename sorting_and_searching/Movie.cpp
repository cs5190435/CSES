#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    vp arr(n);
    for(int i= 0; i< n; i++){
        int a; int b;
        cin >> a ;
            cin >> b;
        arr[i] = make_pair(b,a);
    }
    
    sort(arr.begin(), arr.end());

    int prev = arr[0].first;
    int i= 1, res =1;

    while(i < n){
        if(arr[i].second >= prev){
            res++;
            prev = arr[i].first;
        }
        i++;
    }

    cout << res << "\n";
    return 0;
}
