//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;


void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& map){
    if(i >= map.size() || j >= map[0].size() || i <0 || j <0) return;
    if(vis[i][j] == true || map[i][j] == '#') return;
    vis[i][j] = true;
    dfs(i+1, j, vis, map);
    dfs(i, j+1, vis, map);
    dfs(i-1, j, vis, map);
    dfs(i, j-1, vis, map);
    return;
}

signed main () {
    int n; int m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    for(int i= 0; i< n; i++){
        for(int j= 0; j< m; j++){
            cin >> map[i][j];
        }
    }
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    int cnt = 0;
    for(int i= 0; i< n; i++){
        for(int j= 0; j< m; j++){
            if(map[i][j] == '#') continue;
            else{
                if(vis[i][j] == false){
                    cnt++;
                    dfs(i, j, vis, map);
                }
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}
