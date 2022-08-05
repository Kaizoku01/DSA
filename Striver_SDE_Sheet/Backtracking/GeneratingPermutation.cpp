#include <bits/stdc++.h>
using namespace std;

//! STL
//* TC = O(n! * n)   SC = O(n)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        
        return ans;
    }
};




//!RECURSION    
//* TC = O(n! * n)   SC = O(n) + O(n) + O(n)
class Solution {
public:
    static void fn(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, vector<int> &freq){
        //exit condition
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        
        for(int i=0;i<nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                fn(nums, ds, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        vector<vector<int>> ans;
        fn(nums, ds, ans, freq);
        return ans;
    }
};

//! Backtracking ---> Swapping mwthod
//* TC = O(n! * n)   SC = O(n)
class Solution {
public:
    void fn(int ind, vector<int> &nums, vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ind; i < nums.size(); i++){
            swap(nums[ind], nums[i]);
            fn(ind + 1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        fn(0, nums, ans);
        return ans;
    }
};

int main(){
    return 0;
}