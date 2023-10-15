//Cpp coding template
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<bits/stdc++.h>
using namespace std;


#define pi  pair<int, int>


vector<int> s;
vector<int> link;

int find(int x){
    while(x != link[x]){
        x = link[x];
    }
    return x;
}

bool same(int a, int b){
    if(find(a) == find(b)) return true;
    else return false;
}

bool unite(int a, int b){
    int t1 = find(a);
    int t2 = find(b);
    if(t1 == t2) return false;
    int s1 = s[t1];
    int s2 = s[t2];
    if(s1 < s2) swap(t1 , t2);
    s[t1] += s[t2];
    link[t2] = t1;
    return true;
}

signed main () {
    int n, m;
    cin >> n >> m;

    
    map<pi, int> eds;
    for(int i=0; i< m; i++){
        int a,b,c;
        cin >> a>> b>>c;
        pi curr= { min(a, b), max(a, b)};
        if(eds[curr] == 0)eds[curr] = c;
        else eds[curr] = min(eds[curr], c);

    }

    vector<vector<int>> edges;
    for(auto i : eds){
        pi p1 = i.first;
        int p2 = i.second;
        edges.push_back({p2, p1.first, p1.second});
    }

    s.resize(n+1);
    for(int i= 0; i<= n; i++) s[i] = 1;
    link.resize(n+1);
    for(int i=0; i<= n; i++) link[i] = i;

    sort(edges.begin(), edges.end());
    int cost = 0;
    int wedges = 0;
    for(int i= 0; i< edges.size(); i++){
        if(unite(edges[i][1], edges[i][2])){
            cost += edges[i][0];
            wedges++;
        }
    }

    if(wedges != n-1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    else{
        cout << cost << "\n";
        return 0;
    }

    return 0;
}



