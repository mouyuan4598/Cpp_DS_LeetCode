#include <iostream>
using namespace std;

int main(){
    string s = "aaa";
    string p = "ab*a*c*a";
    int size_s = s.length();
    int size_p = p.length();
    int i = 0, j = 0;
    bool a = true;
    int dp[size_s][size_p] = {};
    char temp = ' ';
    while (i<size_s || j<size_p){
        if(j >= size_p) {a = false; break;}
        if(i >= size_s) {
            int z = j-1;
            while(dp[i-1][z]!=0){
                if(dp[i-1][z] == -1){
                    --z;
                }else if(dp[i-1][z] == 1){

                }
            }
        }
        cout <<i<< s[i] << ' ' <<j<< p[j] << endl;
        cout << "+1:" << p[j+1]<< "-1:" << p[j-1]  << endl;
        cout << dp[i][j-1] << endl;

        if (a == false) break;
        if (j > 0 && dp[i][j-1] == -1){ ///*******important  j>0
            if(p[j] != '*' && p[j] != '.' ){
                a = false;
            }else if(p[j] == '*'){
                if(p[j-1] != s[i]){
                    dp[i][j] = -1;
                    ++j;
                }else if(p[j-1] == '.'){
                    ++j;
                    ++i;
                }
            }/*else if(p[j] == '.'){
                ++i;
                ++j;
            }*/
        }
        else if(s[i] == p[j] || p[j] == '.'){
            ++i;
            ++j;
        }else{
            if(p[j] == '*'){
                if(p[j-1] == s[i] || p[j-1] == '.'){
                    int count1 = 1;
                    while(s[i+count1] == p[j-1] ){
                        ++count1;
                    }
                    int count2 = 0;
                    while(p[j+count2+1] == p[j-1]){
                        ++count2;
                    }
                    dp[i][j] = 1;
                    temp = p[j-1];
                    i = i + count1 - count2;
                    ++j;
                    cout << "lol:" << i << ' ' << j<< endl;
                }
            }
            else if(p[j+1] == '*' || p[j+1] == '.' ){
                dp[i][j] = -1;
                cout << i << ' ' << j <<','<<  dp[i][j] << endl;
                ++j;
                
            }
            else{a= false;}
        }
        
    }
    if(a==false){

        cout << 'g';
        
        return 0;
    }
    
    cout << 'k';
    
    return 0;
}