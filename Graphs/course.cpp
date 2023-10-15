//Cpp coding template
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;


#define int              long long
using   ll=              long long;
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define vi  vector<int>
#define pi  pair<int, int>
#define vb               vector<bool>
#define pb               push_back

vector<bool> vis;
vector<bool> rec;

stack<int> stk;
bool flag = false;



bool dfs(int u, vector<vector<int>>& adj){
    vis[u] = true;
    stk.push(u);
    rec[u] = true;

    for(auto j : adj[u]){
        if(vis[j] == false){
            bool pre = dfs(j, adj);
            if(pre) return true;
        }

        if(rec[j]){
            stk.push(j);
            return true;
        }
    }
    stk.pop();
    rec[u] = false;
    return false;
}


void visit_all(vector<vector<int>>& adj){
    for(int i= 1; i< adj.size(); i++){
        bool curr = dfs(i, adj);
        if(curr == true){
            break;
        }
    }
    return;
}


signed main () {
    speed_;

    int n; int m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);

    vector<int> indegree(n+1, 0);

    for(int i= 0; i< m; i++){
        int a,b;
        cin >> a >> b;
        indegree[b] += 1;
        adj[a].push_back(b);
    }
    rec.resize(n+1);
    vis.resize(n+1);


    
    visit_all(adj);

    if(stk.size() > 0){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    else{
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for(int i= 1; i<= n; i++){
            pq.push({indegree[i], i});
        }

        vector<bool> vis(n+1, false);
        
        vector<int> res;
        while(pq.size() > 0){
            auto top = pq.top();
            pq.pop();
            int a = top.second;
            if(vis[a]) continue;
            res.push_back(a);

            for(auto j : adj[a]) {
                indegree[j]--;
                pq.push({indegree[j], j});
            }
            vis[a] = true;
        }
        
        for(auto k : res) cout << k << " ";
        return 0;
        
    }


    return 0;
}
