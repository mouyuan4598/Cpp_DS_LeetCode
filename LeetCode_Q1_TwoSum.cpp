#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums{11, 15, 7, 2};
    int target = 9;
    bool answer = false;
    int index2 = nums.size();
    int index1;
    while (!answer && !nums.empty()){
        int num1 = nums.back();
        int good = target - num1;
        nums.pop_back();
        index1 = 0;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr){
            if (*itr == good){
                answer = true;
                break;
            }
            ++index1;
        }
        --index2;
    }
    cout << index1 << ' ' << index2;
    }

    /*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool answer = false;
        int index2 = nums.size();
        int index1;
        while (!answer && !nums.empty()){
            int num1 = nums.back();
            int good = target - num1;
            nums.pop_back();
            index1 = 0;
            for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr){
                if (*itr == good){
                    answer = true;
                    break;
                }
                ++index1;
            }
            --index2;
        }
    vector<int> indices{index1,index2};
    return indices;   
    }
    
};
    */