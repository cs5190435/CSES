//Cpp coding template
#include<iostream>
#include<vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi               vector<int>
#define vb               vector<bool>
#define pb               push_back


signed main () {
    speed_;

    int n; int m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i= 0; i< m; i++){
        int a ; int b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    vis[1] = true;
    queue<int> q;
    q.push(1);
     
    vector<int> anc(n+1);
    vector<int> dist(n+1, 0);

    while(q.size() > 0){
        int top = q.front();
        q.pop();
        for(auto j : adj[top]){
            if(vis[j] == false){
                vis[j] = true;
                anc[j] = top;
                dist[j] = dist[top] +1;
                q.push(j);
            }
        }
    }

    if(vis[n] == false){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dist[n]+1 << "\n";
    vector<int> fin(dist[n]+1);
    int u = n;
    for(int i= dist[n] ; i>= 0; i--){
        fin[i] = u;
        u = anc[u];
    }

    for(int i= 0; i< fin.size(); i++) cout << fin[i] << " ";
    cout << endl;

    return 0;
}
