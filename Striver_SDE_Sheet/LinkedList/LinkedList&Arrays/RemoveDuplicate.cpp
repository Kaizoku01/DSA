#include <bits/stdc++.h>
using namespace std;

//! Brute 
//* TC = O(N)   SC = O(N)
// int removeDuplicates(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> ans;
//     // int count = 0;
//     ans.push_back(nums[0]);

//     for(int i=1;i<n-1;i++){
//         if(nums[i] < nums[i+1])
//         ans.push_back(nums[i+1]);
//         else if(nums[i] == nums[i+1]) continue;
//     }
//     // for(auto it: ans) count++;
//     return ans.size();
// }

//! Optimized
//* TC = O(N)   SC = O(1)
int removeDuplicates(vector<int>& nums){
    int k = 0;
    for(int i=1;i<nums.size();i++){
        if(nums[k] != nums[i]){
            k++;
            nums[k] = nums[i];
        }
    }
    return k+1;
}


int main(){
    vector<int> nums = {1,1,2};
    int ans = removeDuplicates(nums);
    cout<<ans;
    // for(auto it: ans) cout<<it<<" ";
}