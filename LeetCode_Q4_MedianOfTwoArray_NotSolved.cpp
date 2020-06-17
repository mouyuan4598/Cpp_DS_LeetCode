#include <iostream>
#include <vector>
using namespace std;

int main(){
     vector<int> nums1{1,3};
     vector<int> nums2{2};
     int size = nums1.size() + nums2.size();
     int nums[size] = {};
     int x = 0, y = 0;
     for(int i = 0; i < size; ++i){
         if(nums1[x] < nums2[y]){
             nums[i] = nums1[x];
             ++x;
         }else{
             nums[i] = nums2[y];
             ++y;
         }
     }
     float median;
     if(size%2 ==0){
         median = (nums[size/2] + nums[(size/2) -1])/(2.0);
     }else{
         median = nums[size/2];
     }

     cout << median;


    return 0;
}