#include <iostream>
using namespace std;

int main(){
    string s = "cbbc";
    int length = s.length();
    if (length == 0){return 0;}
    int dp[length][length] ={};
    
    int longest = 0;
    int index1=0,index2=0;
    for (int i = 0; i < length; ++i){
        for(int j = 0; j<length; ++j){
            int k = i+j;
            if(i == 0){
                dp[j][k] = 1;
            }else{
                if(k>=length){break;}

                if(s[j] == s[k]){
                    if(k==j+1){
                        
                        dp[j][k] =2 + dp[j+1][k-1];  
                        //cout <<"a:"<<j<<','<<k<<' '<< dp[j][k] << endl;
                    }
                    else if(max(dp[j][k-1],dp[j+1][k-1]) >= k-j-1){
                        dp[j][k] = 2 + dp[j+1][k-1];
                        //cout <<"b:"<<j<<','<<k<<' '<< dp[j][k] << endl;  
                    }else{
                        dp[j][k] = dp[j][k-1];
                        //cout <<"c:"<< j<<','<<k<<' '<< dp[j][k] << endl;
                    }    
                }else{
                    dp[j][k] = dp[j][k-1];
                }
            }
            
            if (dp[j][k] > longest){
                longest = dp[j][k];
                index1 = j;
                index2 = k;
            }

        //cout <<j<<','<<k <<':'<<dp[j][k]<<endl;
        }
    }
    for(int i=index1;i<index2 +1;i++){
        cout << s[i];
    }
    return 0;
}