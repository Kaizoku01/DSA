/*
Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array
*/


#include "bits/stdc++.h"
using namespace std;

vector<int> majorityElement(vector<int>& nums){
    int n = nums.size();
    int num1 = -1, num2=-1, count1 = 0, count2 = 0;
    int i;
    vector<int> ans;

    for (i = 0; i < n; i++){
        if(nums[i]==num1) count1++;
        else if(nums[i]==num2) count2++;
        else if(count1 == 0){
            num1 = nums[i];
            count1 = 1;
        }
        else if(count2 ==0){
            num2 = nums[i];
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1 = count2 = 0;
    for (i = 0; i < n; i++){
        if(nums[i]==num1) count1++;
        else if(nums[i]==num2) count2++;
    }
    
    if(count1>n/3) ans.push_back(num1);
    if(count2>n/3) ans.push_back(num2);
    
    return ans;
}

int main(){
    vector<int> nums = {2,2,1,3};
    vector<int> ans = majorityElement(nums);
    for(auto it: ans) cout<<it<<" ";
}