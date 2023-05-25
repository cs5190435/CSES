#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void tower(int n, int source, int destination, int inter){
    if(n==1){
        cout << source << " " << destination << "\n";
        return;
    }

    tower(n-1,source, inter, destination);
    
    cout << source << " " << destination << "\n";

    tower(n-1, inter, destination, source);

    return;;
}

int main (int argc, char *argv[]) {
    int n;
    cin >> n;

    cout << pow(2,n) -1 << "\n";

    tower(n,1,3,2) ;
    return 0;
}
