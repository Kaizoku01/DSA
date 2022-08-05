#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    void static comboGeneration(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        //base 
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        
        //main case
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            comboGeneration(ind, target - arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        
        comboGeneration(ind + 1, target, arr, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        comboGeneration(0, target, candidates, ans, ds);
        
        return ans;
    }
};