//Cpp coding template
#include<iostream>
#include <sys/resource.h>
#include<vector>
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

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<pi>> adj(n+1);

    for(int i= 0; i< m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }

    vector<vector<int>> dist(n+1, vector<int>(k, inf));

    dist[1][0]= 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    pq.push({0, 1});

    while(pq.size() > 0){
        auto top = pq.top();
        pq.pop();
        int a = top.second;
        int b = top.first;

        if(dist[a][k-1] < b) continue;
        
        for(auto j : adj[a]){
            int c = j.first;
            int d = j.second;

            if(dist[c][k-1] > b + d){
                dist[c][k-1] = b+d;
                pq.push({b+d, c});
                sort(dist[c].begin() , dist[c].end());
            }
        }
    }

    for(int i= 0; i< k; i++) cout << dist[n][i] << " ";
    cout << endl;



    return 0;
}
