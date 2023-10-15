#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;


queue<int> q;
int paths;
vector<int> dist;

void dfs(int i, vector<int>& adj, vector<bool>& vis){
    q.push(i);
    if(vis[i] == true){
        paths += dist[i];
        return;
    }
    vis[i] = true;
    paths += 1;
    dfs(adj[i], adj, vis);
}


int main(int argc,char* argv[]){
    int n;
    cin >> n;
    vector<int> adj(n+1, 0);

    for(int i=1; i<= n; i++){
        cin >> adj[i];
    }

    vector<bool> vis(n+1, false);
    dist.resize(n+1);
    for(int i= 0; i<= n; i++) dist[i] = 0;


    for(int i= 1; i<= n; i++){
        if(vis[i]) continue;
        paths = 0;
        dfs(i, adj, vis);
        int dec = 1;
        while(q.size() > 0){
            if(q.front() == q.back()){dec = 0;}
            dist[q.front()] = paths;
            paths -= dec;
            q.pop();
        }
    }
    for(int i=1; i<= n; i++) cout << dist[i] << " ";
    return 0;
}
