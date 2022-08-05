#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool static isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--]) return false;               
        }
        return true;
    }
    
    void fn(int index, string s, vector<vector<string>> &ans, vector<string> &ds){
        if(index == s.length()){
            ans.push_back(ds);
            return;
        }
        
        for(int i = index; i< s.length(); i++){
            if(isPalindrome(s, index, i)){
                ds.push_back(s.substr(index, i - index + 1));
                fn(i+1, s, ans, ds);
                ds.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        fn(0, s, ans, ds);
        
        return ans;
    }
};