//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
#include <utility>
#include<vector>
using namespace std;


#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)


vector<pair<int,int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(int i, int j, vector<vector<char>>& grid){
    int n= grid.size(); int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    pair<int, int> us = {i, j};
    queue<pair<int, int>> q;
    q.push(us);
    vis[us.first][us.second] = true;
    vector<vector<int>> dist_a(n, vector<int>(m, INT_MAX));
    dist_a[us.first][us.second] = 0;
    while(q.size() > 0){
        auto top= q.front();
        int x = top.first;
        int y = top.second;
        q.pop();
        for(int i= 0; i< 4; i++){
            int cx = x+ moves[i].first;
            int cy = y + moves[i].second;
            if(cx <0 || cy < 0 || cx >= n || cy >= m) continue;
            if(grid[cx][cy] != '#' && vis[cx][cy] == false){
                vis[cx][cy] = true;
                dist_a[cx][cy] = dist_a[x][y] +1;
                q.push({cx, cy});
            }

            if(grid[cx][cy] == 'M'){
                return dist_a[cx][cy];
            }
        }
    }
    return INT_MAX;       
}



signed main () {
    speed_;


    int n; int m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    
    pair<int, int> us;

    for(int i=0; i< n; i++){
        for(int j= 0; j< m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A') us = {i, j};
        }
    }

    if(us.first == 0 || us.first == n-1 || us.second == 0 || us.second == m-1){
        cout << "YES\n";
        cout << 0 << "\n";
        return 0;
    }

        
    vector<vector<pair<int, int> >> anc(n, vector<pair<int, int>>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push(us);
    vis[us.first][us.second] = true;
    vector<vector<int>> dist_a(n, vector<int>(m, INT_MAX));
    dist_a[us.first][us.second] = 0;
    while(q.size() > 0){
        auto top= q.front();
        int x = top.first;
        int y = top.second;
        q.pop();
        for(int i= 0; i< 4; i++){
            int cx = x+ moves[i].first;
            int cy = y + moves[i].second;
            if(cx <0 || cy < 0 || cx >= n || cy >= m) continue;
            if(grid[cx][cy] == '.' && vis[cx][cy] == false){
                vis[cx][cy] = true;
                dist_a[cx][cy] = dist_a[x][y] +1;
                anc[cx][cy] = top;
                q.push({cx, cy});
            }
        }
    }



    vector<vector<int>> dist_m(n, vector<int>(m, INT_MAX));
    
    for(int i= 0; i< n; i++){
        if(grid[i][0] != '.') continue;
        dist_m[i][0] = bfs(i, 0, grid); 

        if(dist_a[i][0] < dist_m[i][0]){
            string fin = "";
            pair<int, int> pres = {i, 0};
            while(pres != us){
                auto temp = anc[pres.first][pres.second];
                if(temp.first - pres.first == 1) fin += "U";
                else if(temp.first - pres.first == -1) fin += "D";
                else if(temp.second - pres.second == 1) fin += "L";
                else if(temp.second - pres.second == -1) fin += "R";
                pres = temp;
            }
            cout << "YES\n";
            cout << fin.size() << "\n";
            reverse(fin.begin(), fin.end());
            cout <<  fin << "\n" ;
            return 0;

        }
    }

    for(int i= 0; i< n; i++){
        if(grid[i][m-1] != '.') continue;
        dist_m[i][m-1] = bfs(i, m-1, grid); 

        if(dist_a[i][m-1] < dist_m[i][m-1]){
            string fin = "";
            pair<int, int> pres = {i, m-1};
            while(pres != us){
                auto temp = anc[pres.first][pres.second];
                if(temp.first - pres.first == 1) fin += "U";
                else if(temp.first - pres.first == -1) fin += "D";
                else if(temp.second - pres.second == 1) fin += "L";
                else if(temp.second - pres.second == -1) fin += "R";
                pres = temp;
            }
            cout << "YES\n";
            cout << fin.size() << "\n";
            reverse(fin.begin(), fin.end());
            cout <<  fin << "\n" ;
            return 0;

        }
    }

    for(int i= 0; i< m; i++){
        if(grid[0][i] != '.') continue;
        dist_m[0][i] = bfs(0, i, grid); 

        if(dist_a[0][i] < dist_m[0][i]){
            string fin = "";
            pair<int, int> pres = {0, i};
            while(pres != us){
                auto temp = anc[pres.first][pres.second];
                if(temp.first - pres.first == 1) fin += "U";
                else if(temp.first - pres.first == -1) fin += "D";
                else if(temp.second - pres.second == 1) fin += "L";
                else if(temp.second - pres.second == -1) fin += "R";
                pres = temp;
            }
            cout << "YES\n";
            cout << fin.size() << "\n";
            reverse(fin.begin(), fin.end());
            cout <<  fin << "\n" ;
            return 0;

        }
    }

        
    for(int i= 0; i< m; i++){
        if(grid[n-1][i] != '.') continue;
        dist_m[n-1][i] = bfs(n-1, i, grid); 

        if(dist_a[n-1][i] < dist_m[n-1][i]){
            string fin = "";
            pair<int, int> pres = {n-1, i};
            while(pres != us){
                auto temp = anc[pres.first][pres.second];
                if(temp.first - pres.first == 1) fin += "U";
                else if(temp.first - pres.first == -1) fin += "D";
                else if(temp.second - pres.second == 1) fin += "L";
                else if(temp.second - pres.second == -1) fin += "R";
                pres = temp;
            }
            cout << "YES\n";
            cout << fin.size() << "\n";
            reverse(fin.begin(), fin.end());
            cout <<  fin << "\n" ;
            return 0;

        }
    }



    cout << "NO\n";


    return 0;
}
