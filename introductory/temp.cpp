#include <string>
string recadd(string a , string b, int carry){
    if(a.size() == 1){
        if(b.size() ==1){
            int res = (a[a.size()-1] - '0') + (b[b.size()-1] - '0') + carry;
            if(res > 1){
                return to_string(res/2) + to_string(res%2);
            }
            else{
                to_string(res);
            }
        }
        else{
            int res = (a[a.size()-1] - '0') + (b[b.size()-1] - '0') + carry;
            if(res > 1){
                return recadd( a.substr(0, a.size()-1) , "0", 1) + to_string(res%2);
            }
            else{
                return a.substr(0, a.size()-1) + std::to_string(res);
            }
        }
    }
    else{
        if(b.size() ==1){
            int res = (a[a.size()-1] - '0') + (b[b.size()-1] - '0') + carry;
            if(res > 1){
                return recadd( a.substr(0, a.size()-1) , "0", 1) + to_string(res%2);
            }
            else{
                a.substr(0, a.size()-1) + to_string(res);
            }
        }
        else{
            int res = (a[a.size()-1] - '0') + (b[b.size()-1] - '0') + carry;
            if(res > 1){
                return recadd( a.substr(0, a.size()-1) , b.substr(0. b.size()-1), 1) + to_string(res%2);
            }
            else{
                return recadd( a.substr(0, a.size()-1), b.substr(0, b.size()-1) , 0) + std::to_string(res%2);
            }
        }
    }
}
