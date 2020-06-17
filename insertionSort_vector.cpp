#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> array{31,41,59,26,41,58};
    for(vector<int>::iterator itr = array.begin() + 1; itr != array.end(); ++itr){
        int key = *itr;
        vector<int>::iterator iter = itr-1;
        while (*iter>key){
            *(iter+1) = *(iter);
            if(iter==array.begin())
                break;
            iter--;    
        }
        if(*iter>key){
            *(iter) = key;
        }else{
            *(iter+1) = key;
        }
        
    }

    for(vector<int>::iterator itr = array.begin(); itr != array.end(); ++itr){
        cout << *itr << ' ';
    }
    
    return 0;
}