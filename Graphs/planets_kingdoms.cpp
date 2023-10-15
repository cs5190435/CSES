//Cpp coding template
#include<iostream>
#include<algorithm>
#include<limits>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;

vector<int> o;
vector<int> kdoms;

void dfs(int i, vector<vector<int> >& adj, vector<bool>& vis){
    vis[i] = true;
    for(auto j: adj[i]){
        if(vis[j] == false) dfs(j, adj, vis);
    }
    o.push_back(i);
    return;
}

void dfs2(int i, vector<vector<int> >& adj, vector<bool>& vis, int comp){
    vis[i] = true;
    kdoms[i] = comp;

    for(auto j: adj[i]){
        if(vis[j] == false)dfs2(j, adj, vis, comp);
    }
    return;
}


int main () {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > a1(n+1);
    vector<vector<int> > a2(n+1);
    
    for(int i= 0; i< m; i++){
        int a , b;
        cin >> a >> b;
        a1[a].push_back(b);
        a2[b].push_back(a);
    }


    o.resize(0);
    vector<bool> vis(n+1, false);

    for(int i=1; i<= n; i++){
        if(vis[i]) continue;
        dfs(i, a1, vis);
    }

    for(int i=0; i<= n; i++) vis[i] = false;
    kdoms.resize(n+1);
    for(int i= 0; i<= n; i++)kdoms[i] = 0;


    reverse(o.begin(), o.end());

    int comp = 0;
    for(int i= 0; i< o.size(); i++){
        int c = o[i];
        if(vis[c]) continue;
        comp++;
        dfs2(c, a2, vis, comp);
    }

    cout << comp << "\n";
    for(int i= 1; i<= n; i++)cout << kdoms[i] << " ";

    return 0;
}
