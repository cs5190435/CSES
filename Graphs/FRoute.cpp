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
int ninf = -1*inf;

signed main () {
    speed_;

    int n; int m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> ind(n+1, 0);
    for(int i= 0; i< m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    for(int i= 1; i<= n; i++){
        pq.push({ind[i], i});
    }

    vector<int> dp(n+1, inf);
    vector<int> res;
    while(pq.size() > 0){
        auto top = pq.top();
        pq.pop();
        int a = top.second;
        int b = top.first;
        if(dp[a] <= b) continue;
        res.push_back(a);
    
        dp[a] = b;

        for(auto j: adj[a]){
            ind[j]--;
            pq.push({ind[j], j});
        }
    }

    vector<int> dist(n+1, ninf);
    dist[n] = 0;

    int hp = 0;
    for(int i= res.size()-1; i>= 0; i--){
        if(res[i] == n){hp = i; break;}
    }
    
    vector<int> anc(n+1, -1);

    for(int i= hp-1; i>= 0; i--){
        int curr = res[i];
        for(auto j: adj[curr]){
            if(dist[curr] < dist[j]){
                anc[curr] = j;
                dist[curr] = dist[j];
            }
        }
        if(dist[curr] != ninf) dist[curr]++;
    }
    
    if(dist[1] == ninf){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << dist[1]+ 1 << "\n";
        int curr =1;
        while(curr != n){
            cout << curr << " ";
            curr = anc[curr];
        }
        cout << n ;
    }

    return 0;
}
