#include <iostream>
#include <map>
using namespace std;

int main(){
    string s = "pwwkew";
    int longestLength = 1;
    if(s.length() == 0){return 0;}
    int start = 0,end = 1;
    int length = 1;
    map<char,int> str;
    str[s[start]] = start;
    while (start <s.length()-1 && end < s.length()){
        //cout <<end<< s[end] <<' ' << str.count(s[end])<< endl;
        // while(str.count(s[end])<1){
        //     ++length;
        //     str[s[end]] = end;
        //     ++end;
        // }
        // if (length > longestLength)
        //     longestLength = length;
        //++length;
        //cout << 'c' << length << endl;
        while(str.count(s[end])>0){
        //    cout << "erase " <<start<< s[start] <<endl;
            str.erase(s[start]);
            --length;
            ++start; 
        //    cout << 'b' << length<<endl;   
        }    
        if(str.count(s[end])<1){
            ++length;
            str[s[end]] = end;
            ++end;
        //    cout << 'a' << length<<endl;
        }
        if (length > longestLength)
            longestLength = length;
    }
    cout << longestLength;

    return 0;
}