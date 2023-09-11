//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

signed main () {

    int n; cin >> n;
    vector<int> arr(n);
    for(int i= 0; i < n; i++) cin >> arr[i];
    
    set<int> res;
    for(int i= 0; i< n; i++){
        vector<int> temp = {};
        for(auto it = res.begin(); it != res.end(); it++){
            int curr = *it;
            temp.push_back(curr);
        }
        res.insert(arr[i]);
        for(int j= 0; j< temp.size(); j++){
            res.insert(temp[j] + arr[i]);
        }
    }

    cout << res.size() << "\n";
    for(auto it = res.begin(); it != res.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
