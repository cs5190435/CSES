#include <climits>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    string t;
    cin >> t;
    
    int best = 1; int curr = 1;

    for(int i= 1; i< t.size(); i++){
        if(t[i] == t[i-1]){
            curr++;
            best = max(best, curr);
        }
        else{
            curr = 1;
        }
    }

    cout << best << "\n";
    return 0;

}
