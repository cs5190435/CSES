//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi  vector<int>
#define pi  pair<int, int>
#define vb               vector<bool>
#define pb               push_back
int inf = 1e17;


signed main () {
    speed_;

    int n; int m;
    cin >> n>> m;

    vector<vector<pi>> adj(n+1);
    for(int i= 0; i< m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }


    priority_queue<pi, vector<pi>, greater<pi> > pq;

    vector<int> dist(n+1, inf);
    dist[1] = 0;
    pq.push({0, 1});

    while(pq.size() > 0){
        auto top = pq.top();
        pq.pop();
        int a = top.second;
        int b = top.first;
        if(dist[a] < b) continue;

        for(auto j : adj[a]){
            int c = j.first;
            int d = j.second;
            if(dist[c] > b + d){
                dist[c] = b+d;
                pq.push({b+d, c});
            }
        }
    }

    for(int i=1; i<= n; i++) cout << dist[i] << " ";
    cout << endl;
    
    return 0;
}
