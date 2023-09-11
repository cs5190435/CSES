//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi               vector<int>
#define vb               vector<bool>
#define pb               push_back


int cyclestart; int cyclend;

bool dfs(int i, vector<vector<int>>& adj, vector<int>& color, vector<int>& anc){
    color[i] = 1;
    for(auto j: adj[i]){
        if(color[j] == 0){
            anc[j] = i;
            bool pres = dfs(j, adj, color, anc);
            if(pres) return true;
        }
        else if(color[j] == 1){
            if(anc[i] != j){
                cyclestart = j;
                cyclend = i;
                return true;
            }
        }
    }
    color[i] = 2;
    return false;

}

signed main () {
    speed_;

    int n;int m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i= 0; i< m; i++){
        int a ; int b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> color(n+1, 0);
    vector<int> anc(n+1, 0);
    cyclestart = -1;
    cyclend = 0;

    for(int i=1; i<= n; i++){
        if(color[i] == 0){
            bool curr = dfs(i, adj, color, anc);
            if(curr == true) break;
        }
    }

    if(cyclestart == -1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    else{
        vector<int> fin;
        fin.push_back(cyclestart);
        while(cyclend != cyclestart){
            fin.push_back(cyclend);
            cyclend = anc[cyclend];
        }
        fin.push_back(cyclestart);
        cout << fin.size() << "\n";
        for(int i= 0; i< fin.size(); i++){
            cout << fin[i] << " ";
        }
        cout << "\n";
    }


    return 0;
}
