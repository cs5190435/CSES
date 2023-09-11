//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi               vector<int>


signed main () {
    speed_;

    int n;
    cin >> n;
    vi arr(n);
    for(int i= 0; i< n; i++) cin >> arr[i];

    int a1 = 0; int b1 = 0;
    int a2 = 0; int b2 = 0;

    int i= 0; int j = n-1;
    while(i < j){
        int t1 = a1 + arr[j];
        int t3 = a2 + arr[i];
        a2 = t1;
        a1 = t3;

        int t2 = b2 + arr[0];
        int t4 = b1 + arr[j];
        a2 = t1;
        a1 = t3;
        b2 = t4;
        b1 = t2;
        i++;
        j--;
    }

    
    cout << max(a1, a2) << "\n";

    return 0;
}
