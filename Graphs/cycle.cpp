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
    
    vector<vector<int>> edges(m+n);
    for(int i= 0; i< m; i++){
        int a; int b; int c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    for(int i= 1; i<= n; i++){
        edges[m-1+i] = {0, i, 0};
    }
    


    //bellman ford with adding the -1*edge weights

    vector<int> dist(n+1, inf);
    dist[0]= 0;
    vector<int> anc(n+1, 0);


    for(int i= 1; i<= n; i++){
        for(int j= 0; j< edges.size(); j++){
            int a, b, c;
            a = edges[j][0];
            b = edges[j][1];
            c = edges[j][2];
            if(dist[a] == inf) continue;

            if(dist[b] > dist[a] + c){
                dist[b] = dist[a] + c;
                anc[b] = a;
            }

            dist[b] = max(N, dist[b]);
        }
    }

    bool flag = false;
    int last; 
    
    for(auto j : edges){
        int a, b, c;
        a = j[0];
        b = j[1];
        c = j[2];
        if(dist[a] == inf) continue;
        dist[b] = max(dist[b], N);
        if(dist[b] > dist[a] + c){
            dist[b] = dist[a] + c;
            flag = true;
            last = b;
            anc[b] = a;
        }
    }

    if(flag == false){
        cout << "NO\n";
        return 0;
    }
    else{
        for(int i= 1; i<= n; i++){
            last = anc[last];
        }
        cout << "YES\n";
        vector<int> res = {last};
        int curr = anc[last];
        while(curr != last){
            res.push_back(curr);
            curr = anc[curr];
        }
        res.push_back(last);
        reverse(res.begin(), res.end());
        for(int i= 0; i< res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
