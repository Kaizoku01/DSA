
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void fun(int i, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int j = i; j<arr.size();j++){
            if(j != i && arr[j] == arr[j-1]) continue;
            ds.push_back(arr[j]);
            fun(j+1, arr, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(), arr.end());
        fun(0, arr, ds, ans);
        return ans;
    }
};