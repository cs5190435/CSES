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


int N = -1*1e17;
int inf = 1e17;


signed main () {
    speed_;

    int n; int m;
    cin >> n >> m;
    
    vector<vector<int>> edges(m);
    for(int i= 0; i< m; i++){
        int a; int b; int c;
        cin >> a >> b >> c;
        edges[i] = {a, b, -1*c};
    }

    if(n==1) {cout<< -1 << "\n"; return 0;}


    //bellman ford with adding the -1*edge weights

    vector<int> dist(n+1, inf);
    dist[1]= 0;

    for(int i= 1; i<= n-1; i++){
        for(int j= 0; j< edges.size(); j++){
            int a, b, c;
            a = edges[j][0];
            b = edges[j][1];
            c = edges[j][2];
            if(dist[a] == inf) continue;
            dist[b] = min(dist[b], dist[a]+c);

            dist[b] = max(N, dist[b]);
        }
    }

    for(int i= 1; i<= n-1; i++){
        for(int j= 0; j< edges.size(); j++){
            int a, b, c;
            a = edges[j][0];
            b = edges[j][1];
            c = edges[j][2];
            if(dist[a] == inf) continue;
            dist[b] = max(N, dist[b]);
            if(dist[b] > dist[a] + c) dist[b] = N;

        }
    }



    if(dist[n] == N) cout << -1 << "\n";
    else cout << -1*dist[n] << "\n";



    return 0;
}
