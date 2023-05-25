#include "iostream"
#include<bits/stdc++.h>
#include <thread>
using namespace std;
typedef long long ll;

int main (int argc, char *argv[]) {
    string s;
    cin >> s;

    vector<int> arr(26,0);
    for(int i= 0; i< s.size(); i++){
        arr[s[i]-'A']++;
    }
    
    int cnt = 0;
    for(int i= 0; i< 26; i++){
        if(arr[i]%2 != 0) cnt++;
    }

    if(s.size()%2 == 0){
        if(cnt != 0) cout << "NO SOLUTION\n";
        else{
            string res = "";
            for(int i=0; i< 26; i++){
                int temp= arr[i]/2;
                int curr = (int)('A') + i;
                res = string(temp, curr) + res;
                res = res + string(temp, curr);
            }
            cout << res << "\n";
        }
    }
    else{
        if(cnt >1) cout << "NO SOLUTION\n";
        else{
            string res = "";
            int index = 0;
            for(int i=0; i< 26; i++){
                int temp= arr[i]/2;
                int curr = (int)('A') + i;
                res = string(temp, curr) + res;
                res = res + string(temp, curr);
                
                if(arr[i]%2 != 0) index = i;
            }
            res = res.substr(0, s.size()/2) + static_cast<char>( (int)'A' + index)  + res.substr(s.size()/2, s.size()/2);
            cout << res << "\n";
        }
    }



    return 0;
}
