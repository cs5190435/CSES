#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int> > vp;

int main (int argc, char *argv[]) {
    int n; int m;
    cin >> n >> m;

    vi price(n,0);
    for(int i= 0;i<n; i++) cin >> price[i];

    vp cust(m);
    for(int i= 0; i<m; i++) {
        int temp; cin >> temp;
        cust[i] = make_pair(temp, i);
    }

    //sort(price.begin(), price.end());
    //sort(cust.begin(), cust.end());

    int i= 0;
    int j= 0;

    vector<int> res(m, -1);

    while(i < n && j < m){
        if(price[i] <= cust[j].first){
            res[cust[j].second] = price[i];
            i++; j++;
        }
        else{
            i++;
        }
    }

    for(int i= 0; i< m; i++) cout << res[i] << "\n";



    return 0;
}
