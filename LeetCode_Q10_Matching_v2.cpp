#include <iostream>
using namespace std;

int main(){
    string s = "a";
    string p = "ab*a";
    int size_s = s.length();
    int size_p = p.length();
    int i = 0, j = 0, k = 0;
    bool a = true;
    int dp[size_s][size_p] = {};
    char temp = ' ';
    bool b = false;
    while (i<size_s || j<size_p){
        cout <<i<< s[i] << ' ' <<j<< p[j] << endl;
        cout <<dp[i][j-1] << ' ' <<dp[i-1][j-1] << endl;

        if(i >= size_s){
            i = size_s -1;
            cout << 'w'<<endl;
            bool isStar = false;
            int y = j;
            while(y<size_p){
                cout <<'!'<<  p[y] << endl;
                if(p[y]=='*'){isStar = true; break;}
                ++y;
            }
            if(!isStar){cout <<"wtf"<< dp[i][j-1]<<endl;}
            if(!isStar) {cout << 'y';a = false; break;}
            
            if((dp[i][j-1] == 2 || dp[i][j-1] == -2 ) && j>=size_p){
                a = true; break; 
            }else if(dp[i][j-1] != 2 && dp[i][j-1] != 1 && dp[i][j-1]!= -2){
                a= false; break;
            }
            b = true;
            ++i;
        }
        if(j >= size_p){
            if(i==size_s-1 && b){a = true; break;}
            j = size_p -1;
            if(dp[i-1][j] != 2){
               a = false; break; 
            }
        }
        
        

        if(true){
            if(s[i] == p[j] || p[j] == '.'){
                dp[i][j] = 1;
                ++i;
                ++j;
            }else if(p[j+1] == '*'){
                dp[i][j] = -1;
                cout << i << ' ' << j <<','<<  dp[i][j] << endl;
                ++j;
                dp[i][j] = -2;
                ++j;
            }else if(p[j] == '*'){
                if(p[j-1] == s[i] || p[j-1] == '.'){
                    int count1 = 1;
                    while(s[i+count1] == p[j-1] ){
                        ++count1;
                    }
                    int count2 = 0;
                    while(p[j+count2+1] == p[j-1]){
                        ++count2;
                    }
                    dp[i][j] = 2;
                    temp = p[j-1];
                    i = i + count1 - count2;
                    ++j;
                    cout << "lol:" << i << ' ' << j<< endl;
                }else if(p[j-1] != s[i] ){
                    ++j;
                }
            }else{a = false; break;}        
        }
        // if(dp[i][j-1] == 2){
        //     cout << 'o';
        // }
        
    }
    if(a==false){

        cout << 'g';
        
        return 0;
    }
    
    cout << 'k';
    
    return 0;
}