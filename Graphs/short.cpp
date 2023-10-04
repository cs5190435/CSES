//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
#include <utility>
#include<vector>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define pi               pair<int, int>


signed main () {
    speed_;

    int n; int m;
    cin >> n >> m;
    vector<vector<pi>> adj(n+1);


    for(int i= 0; i< m; i++){
        int a; int b; int c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }

    vector<int> dist(n+1, 9223372036854775);

    vector<bool> vis(n+1, false);
    dist[1] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, 1});

    while(q.size() > 0){
        auto top = q.top();
        int a = top.second;
        int b = top.first;
        q.pop();
        if(vis[a]) continue;
        for(auto j : adj[a]){
            int c = j.first;
            int d = j.second;
            dist[c] = min(dist[c] , b + d);
            if(vis[c] == false) q.push({dist[c], c});
        }
        vis[a] = true;
    }
    
    for(int i = 1; i<= n; i++) cout << dist[i] << " ";
    cout << endl;

    return 0;
}
