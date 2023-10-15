#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> s;
vector<int> l;

int components;
int max_size;

int find(int a){
    while(a != l[a]){
        a = l[a];
    }
    return a;
}

void unite(int a, int b){
    int t1 = find(a);
    int t2 = find(b);
    if(t1 == t2) return;
    if(s[t1] < s[t2]) swap(t1, t2);
    s[t1] += s[t2];
    max_size = max(max_size, s[t1]);
    components--;
    l[t2] = t1;
    return;
}


int main(){
    int n; int m;
    cin >> n >> m;
    
    s.resize(n+1);
    l.resize(n+1);
    components = n;
    max_size = 1;

    for(int i= 0; i<= n; i++){
        s[i] = 1;
        l[i] = i;
    }

    for(int i= 0; i< m; i++){
        int a, b;
        cin >> a >> b;

        unite(a, b);
        cout << components << " " << max_size << "\n";
        


    }

}

