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


signed main () {
    speed_;

    // binary lifting
    int n; int q;
    cin >> n >> q;
    
    vector<vector<int>> adj(n+1);

    vector<vector<int>> anc(32, vector<int>(n+1, 0));

    for(int i= 2; i<= n; i++){
        int a; cin >> a;
        adj[a].push_back(i);
        anc[0][i] = a;
    }

    for(int i= 1; i< 32; i++){
        for(int j= 1; j<= n; j++){
            int temp = anc[i-1][j];
            anc[i][j] = anc[i-1][temp];
        }
    }


    for(int i=0; i< q; i++){
        int x, k;
        cin >> x >> k;
        int fin = x;
        while(k > 0){
            int temp = (int)(log2(k));
            fin = anc[temp][fin];
            k -= pow(2, temp);
        }
            
        if(fin == 0) cout << -1 << "\n";
        else cout << fin  << "\n";
    }




    return 0;
}
