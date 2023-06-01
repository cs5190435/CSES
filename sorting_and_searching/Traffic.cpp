#include <algorithm>
#include<iostream>
#include<bits/stdc++.h>
#include <strings.h>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vp;

int main (int argc, char *argv[]) {
    int x; int n;
    cin >> x >> n;
    set<int> pos;
    multiset<int> len;
    pos.insert(0); pos.insert(x);
    len.insert(x);
    for(int i=0; i< n; i++){
        int temp;
        cin >> temp;
        pos.insert(temp);
        auto it = pos.find(temp);
        int pre = *prev(it);
        int nex = *next(it);
        len.erase(len.find(nex-pre));
        len.insert(temp-pre);
        len.insert(nex- temp);
        cout << *(len.rbegin()) << "\n";
    }

}
