#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

int main (int argc, char *argv[]) {
    int n; int m; int k;
    cin >> n >> m >> k;

    vi persons(n,0);
    for(int i= 0; i< n; i++) cin >> persons[i];
    vi apps(m,0);
    for(int i= 0; i<m; i++) cin >> apps[i];

    sort(persons.begin(), persons.end());
    sort(apps.begin(), apps.end());

    int res = 0;
    int i= 0; int j= 0;

    while(i < n && j < m){
        if( abs(persons[i]-apps[j]) <= k){
            res ++;
            i++;
            j++;
        }
        else if(persons[i] - apps[j] < k){
            i++;
        }
        else{
            j++;
        }
    }

    cout << res << "\n";

    return 0;
}
