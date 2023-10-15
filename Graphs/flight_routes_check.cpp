#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

vector<int> o1;

void dfs(int i, vector<bool>& vis, vector<vector<int> >& adj){
    vis[i] = true;

    for(auto j: adj[i]){
        if(vis[j] == false) dfs(j, vis, adj);
    }
    o1.push_back(i);
    return;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > a1(n+1);
    vector<vector<int> > a2(n+1);
    for(int i= 0; i< m; i++){
        int a, b;
        cin >> a >> b;
        a1[a].push_back(b);
        a2[b].push_back(a);
    }
    
    //kosaraju algorithm for stronlgy connected components.
    o1.resize(0);
    
    vector<bool> vis(n+1, false);

    for(int i= 1; i<= n; i++){
        if(vis[i]) continue;;
        dfs(i, vis, a1);
    }

    for(int i= 0; i<= n; i++) vis[i] = false;

    int last = o1[o1.size()-1];

    dfs(last, vis, a2);
    
    for(int i= 1; i<= n; i++){
        if(vis[i] == false){
            cout << "NO\n";
            cout << i << " " << last << "\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
