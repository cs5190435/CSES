#include<iostream>
#include<bits/stdc++.h>

using namespace std; 

int main(){
    int n;
    cin >> n;
    vector<bool> array(n+1, false);
    for(int i= 0; i< n-1; i++){
        int temp; 
        cin >> temp;
        array[temp] = true;
    }

    for(int i= 1; i<= n; i++){
        if(array[i] == false){
            cout << i << "\n";
            return 0;
        }
    }
    return -1;
}
