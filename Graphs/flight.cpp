//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi  vector<int>
#define pi  pair<int, int>
#define vb               vector<bool>
#define pb               push_back

int inf = 1e17;

vector<int> sssp(int i, vector<vector<pi>>& adj, int n, int m){
    vector<int> dist(n+1, inf);

    dist[i] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, i});

    vector<bool> vis(n+1, false);
    vector<int> anc(n+1);

    while(pq.size() > 0){
        auto top = pq.top();
        int a = top.second;
        int b = top.first;
        pq.pop();
        if(vis[a]) continue;
        for(auto j : adj[a]){
            int c = j.first;
            int d = j.second;
            //dist[c] = min(dist[c], a + d);
            if(dist[c] > b + d){
                dist[c] = b +d;
                anc[c] = a;
            }
            if(vis[c] == false) pq.push({dist[c], c});
        }
        vis[a] = true;
    }

    return dist;

}



signed main () {
    speed_;

    int n, m;
    cin >> n >> m;
    vector<vector<pi>> adj(n+1);
    vector<vector<pi>> adj2(n+1);
    for(int i= 0; i< m; i++){
        int a; int b; int c;
        cin >> a>> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj2[b].push_back(make_pair(a, c));
    }


    vector<int> d0 = sssp(1, adj, n, m);
    vector<int> d1 = sssp(n, adj2, n, m);

    int res = inf;

    for(int i= 1; i<= n; i++){
        if(d0[i] == inf) continue;
        for(auto j : adj[i]){
            int a = j.first;
            int b = j.second;
            if(d1[a] == inf) continue;
            int curr = d0[i] + floor(b/2) + d1[a];
            res = min(res, curr);
        }
    }
    
    cout << res << "\n";

    return 0;
}
