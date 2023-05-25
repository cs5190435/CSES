#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char* argv[]){
    int n;
    cin >> n;
    if(n==1){
        cout <<1 << "\n";
        return 0;
    }
    else if(n <= 3 && n >= 2){
        cout << "NO SOLUTION" << "\n";
        return 0;
    }
    else if(n == 4){
        cout << 2 << " " <<  4 << " " << 1 << " " << 3 << "\n"; 
    }
    else{
        if(n%2 != 0){
            int left = n/2;
            int right = left+2;
            
            while(left != 0){
                cout << left << " " << right << " ";
                left -= 1;
                right += 1;
            }
            cout << (n/2) + 1 << "\n";

        }

        else{
            int left = n/2 - 1;
            int right = left+ 2;

            while(left != 0){
                cout << left << " " << right << " ";
                left -= 1;
                right +=1;
            }

            cout << n/2 << " " << n << "\n";

        }
    }

    return 0;
}
