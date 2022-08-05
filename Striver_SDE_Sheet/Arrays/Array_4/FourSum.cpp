#include "bits/stdc++.h"
using namespace std;

//! Brute
//* very heavy time complexity and space too
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     int n = nums.size();
        
    //     sort(nums.begin(),nums.end());
      
    //    set<vector<int>> sv;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    
    //             for(int k=j+1;k<n;k++)
    //             { 
                  
    //                int x = (long long)target - 
    //                        (long long)nums[i]-
    //                        (long long)nums[j]-(long long)nums[k];
                   
    //                     if(binary_search(nums.begin()+k+1,nums.end(),x)){
    //                         vector<int> v;
    //                         v.push_back(nums[i]);
    //                         v.push_back(nums[j]);
    //                         v.push_back(nums[k]);
    //                         v.push_back(x);
    //                         sort(v.begin(),v.end());
    //                         sv.insert(v);
    //                     }
    //             }
    //         }
    //     }
    //     vector<vector<int>> res(sv.begin(),sv.end());
    //     return res;
    // }

//! Optimal
//* O(ncube)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         
        int n = nums.size();
        vector<vector<int>> res;
        
        if(nums.empty()) return res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target_2 = target - nums[j] - nums[i];
                
                int left = j+1;
                int right = n-1;
                while(left<right){
                    int twoSum = nums[left] + nums[right];
                
                    if(target_2>twoSum) left++;
                    else if(target_2<twoSum) right--;
                    else{
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        res.push_back(quad);
                        
                        //duplicacy conditions
                        while(left<right && nums[left] == quad[2]) ++left;
                        
                        while(left<right && nums[right] == quad[3]) --right;
                    
                    }  
                }
                while(j+1<n && nums[j+1] == nums[j]) ++j;
            }
            while(i+1<n && nums[i+1] == nums[i]) ++i;
        }
        return res;
    }

int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans = fourSum(nums,target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        
    }
    
}

