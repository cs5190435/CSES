#include<iostream>
#include<bits/stdc++.h>
#include <utility>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int> > vp;

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    vp cust(2*n);

    for(int i= 0; i< n; i++){
        int a; int b;
        cin >> a >> b;
        cust[2*i] = make_pair(a, 0);
        cust[2*i + 1] = make_pair(b, 1);
    }

    sort(cust.begin(), cust.end());

    int res = INT_MIN;
    int curr= 0;

    for(int i= 0; i< 2*n ; i++){
        if(cust[i].second == 0){
            curr++;
            res = max(res, curr);
        }
        else{
            curr--;
        }
    }

    cout << res << "\n";
    return 0;
}
