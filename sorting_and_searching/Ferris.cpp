#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

int main (int argc, char *argv[]) {
    int n; int x;
    cin >> n;
    cin >> x;
    vi wt(n,0);
    for(int i= 0; i< n; i++) cin >> wt[i];
    
    sort(wt.begin(), wt.end());


    int left = 0;
    int right = n-1;
    int res = 0;

    while(left < right){
        if(wt[left] + wt[right] <= x){
            res ++;
            left++;
            right--;
        }
        else{
            res ++;
            right--;
        }
    }

    if(left == right) res++;
    cout << res << "\n";

    return 0;
}
