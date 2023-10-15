#include<iostream>
#include<bits/stdc++.h>

using namespace std;


vector<int> s;
vector<int> l;

int find(int a){
    while(a != l[a]){
        a = l[a];
    }
    return a;
}

bool same(int a , int b){
    if(find(a) == find(b)) return true;
    else return false;
}

bool unite(int a, int b){
    int t1 = find(a);
    int t2 = find(b);
    if(t1 == t2) return false;
    if(s[t1] < s[t2]) swap(t1, t2);
    s[t1] += s[t2];
    l[t2] = t1;
    return true;
}


int main(int arc, char* argv[]){
    int n; int m;
    cin >> n>> m;
    vector<vector<int> > edges(m, vector<int>(3, 0));

    for(int i= 0;i < m; i++){
        cin >> edges[i][1];
        cin >> edges[i][2];
        cin >> edges[i][0];
    }
    
    sort(edges.begin(), edges.end());

    s.resize(n+1);
    l.resize(n+1);
    for(int i= 0; i<= n; i++){
        s[i] = 1;
        l[i] = i;
    }

    long long cost = 0;
    int ed = 0;
    for(int i= 0; i< edges.size(); i++){
        bool curr = unite(edges[i][1], edges[i][2]);
        if(curr == true){
            cost += (long long)edges[i][0];
            ed++;
        }
    }

    if(ed != n-1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    else{
        cout << cost << "\n";
        return 0;
    }

    return 0;
}
