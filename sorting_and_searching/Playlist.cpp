#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int> > vp;


int main (int argc, char *argv[]) {
    
    int n;
    cin >> n;
    vi arr(n,0);
    for(int i= 0; i< n; i++) cin >> arr[i];

    set<int> holdings;
    int res = 0;
    int i = 0; int j= 0;
    while(i < n && j < n){
        if(!holdings.count(arr[j])){
            holdings.insert(arr[j]);
            j++;
        }
        else{
            holdings.erase(arr[i]);
            i++;
        }
        int size = holdings.size();
        res = max(res, size);
    }

    cout << res << "\n";
    return 0;
}

