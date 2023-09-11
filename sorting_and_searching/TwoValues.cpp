#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vp;
typedef vector<ll> vl;

int main (int argc, char *argv[]) {
    int n; int x;
    cin >> n >> x;
    vp arr(n);
    for(int i= 0; i< n; i++){
        int temp ; cin >> temp;
        arr[i] = make_pair(temp, i+1);
    }

    sort(arr.begin(), arr.end());

    int i = 0; int j = n-1;

    while(i< j){
        int sum = arr[i].first + arr[j].first;
        if(sum == x){
            cout << arr[i].second << " " << arr[j].second;
            return 0;
        }
        else if(sum < x){
            i++;
        }
        else{j--;}
    }

    cout << "IMPOSSIBLE" << "\n";
    return 0;
}
