#include <iostream>
#include <map>
using namespace std;

int main(){
    string s = "jbpnbwwd";
    int longestLength = 1;
        if(s.length() == 0){return 0;}
    for (int i = 0; i<s.length()-1; ++i){
        int length = 1;
        map<char,int> str;
        str[s[i]] = i;
        for(int j = i+1; j< s.length(); ++j){
            if(str.count(s[j]) > 0){
                if (length > longestLength){
                    longestLength = length;
                }
                break;
            }else{
                str[s[j]] = j;
                ++length;
            }
        }
        if (length > longestLength)
            longestLength = length;
    }
    
    cout << longestLength;

    return 0;
}