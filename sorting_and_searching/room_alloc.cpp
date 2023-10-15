//Cpp coding template
#include<iostream>
#include<algorithm>
#include<limits>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define pb push_back
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)


signed main(){
    speed_;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    vector<vi> a(n, vi(3, 0));
    for(int i= 0; i< n; i++){
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int r= 0;
    vector<int> res(n, 0);
    for(int i= 0; i< n; i++){
        if(pq.size() > 0){
            auto top = pq.top();
            int x = top.first;
            int y = top.second;
            if(a[i][0] > x){
                pq.pop();
                pq.push({a[i][1], y});
                res[a[i][2]] = y;
            }
            else{
                r += 1;
                pq.push({a[i][1], r});
                res[a[i][2]] = r;
            }

        }
        else{
            r += 1;
            res[a[i][2]] = r;
            pq.push({a[i][1], r});
        }
    }
    cout << r << "\n";
    for(int i= 0; i< n; i++)cout << res[i] << " ";
    
    return 0;
}
