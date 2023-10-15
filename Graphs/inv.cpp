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
int mod = 1e9 + 7;

signed main () {
    speed_;
    int n; int m;
    cin >> n >> m;

    vector<vector<pi>> adj(n+1);
    for(int i= 0; i< m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }


    vector<int> a(n+1, inf);
    vector<int> b(n+1, 0);
    vector<int> c(n+1, inf);
    vector<int> d(n+1, ninf);

    a[1] = 0;
    b[1] = 1;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});
    c[1] = 0;
    d[1] = 0;

    while(pq.size() > 0){
        auto top = pq.top();
        int u = top.second;
        int v = top.first;
        pq.pop();

        if(a[u] < v) continue;


        for(auto j : adj[u]){
            int x = j.first;
            int y = j.second;

            if(a[x] > v+y){
                a[x] = v+y;
                b[x] = b[u];
                c[x] = 1 + c[u];
                d[x] = 1 + d[u];
                pq.push({v+y, x});
            }
            else if(a[x] == v+y){
                b[x] += b[u];
                b[x] = b[x]%mod;
                c[x] = min(c[x], 1+ c[u]);
                d[x] = max(d[x], 1+ d[u]);
            }
        }
    }

    cout << a[n] << " " << b[n] << " " << c[n] << " " << d[n] << "\n";
    return 0;
}
