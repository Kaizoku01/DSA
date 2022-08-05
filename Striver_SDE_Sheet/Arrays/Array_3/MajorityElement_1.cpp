/*
Find the Majority Element that occurs more than N/2 times
*/

#include "bits/stdc++.h"
using namespace std;

//! Frequency Array method

// int majorityElement(vector<int>& nums) {
//     int condition = floor(nums.size()/2);
//     int majorElement;

//     vector<int> freq(nums.size()+1,0);
//     for (int i = 0; i < nums.size(); i++){
//         freq[nums[i]]++;
//     }
//     // for(auto it: freq) cout<<it<<" ";
//     for (int i = 0; i < freq.size(); i++){
//         if (freq[i]>condition){
//             majorElement = i;
//         }else{
//             return 0;
//         }
//     }
//     return majorElement;
// }

//! Moore Voting Algo
int majorityElement(vector<int>& nums){
    int count = 0;
    int element = 0;

    for (int i = 0; i < nums.size(); i++){
        if(count==0) element = nums[i];
        if(nums[i]==element) count++;
        else
            count--;
    }
    return element;
    
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    cout<<majorityElement(nums);
}