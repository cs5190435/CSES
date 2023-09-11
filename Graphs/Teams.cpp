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


signed main () {
    speed_;

    int n; int m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);

    for(int i=0; i< m; i++){
        int a; int b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> anc(n+1, -1);
    vector<bool> vis(n+1, false);

    for(int i= 1; i<= n; i++){
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        anc[i] = 0;
        while(q.size() > 0){
            int top = q.front();
            q.pop();
            for(auto j : adj[top]){
                if(vis[j] == true){
                    int temp = abs(anc[j] - anc[top]);
                    if(temp != 1){
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
                else{
                    vis[j] = true;
                    anc[j] = 1-anc[top];
                    q.push(j);
                }
            }
        }
    }

    for(int i= 1; i<= n; i++){
        cout << anc[i]+1 << " ";
    }
    cout << "\n";



    return 0;
}
