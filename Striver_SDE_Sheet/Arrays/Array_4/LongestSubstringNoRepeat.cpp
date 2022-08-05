#include "bits/stdc++.h"
using namespace std;

//! Brute 
//* O(N^2)

// int lengthOfLongestSubstring(string s) {
//     int maxCount = 0;
//     for(int i=0;i<s.length();i++){
//         unordered_set<int> tempSet;
//         for(int j=i;j<s.length();j++){
//             if(tempSet.find(s[j]) != tempSet.end()){
//                 maxCount = max(maxCount,j-i);
//                 break;
//             }
//             tempSet.insert(s[j]);
//         }
//     }
//     return maxCount;
// }

//! Optimzed 1
//* O(2N)

// int lengthOfLongestSubstring(string s){
//     int maxCount = 0;
//     int left=0,right = 0;
//     unordered_set<int> tempSet;
//     for ( right = 0; right < s.length(); right++){
//         if(tempSet.find(s[right]) != tempSet.end()){
//             while (left < right && tempSet.find(s[right]) != tempSet.end()){
//                 tempSet.erase(s[left]);
//                 left++;
//             }
//         }
//         tempSet.insert(s[right]);
//         maxCount = max(maxCount, right - left + 1);
//     }
//     return maxCount; 
// }

//! Optimized 2
int lengthOfLongestSubstring(string s){
    int maxCount = 0;
    int left = 0, right = 0;
    vector<int> tempArr(256,-1);
    int n = s.length();

    while(right < n){
        if(tempArr[s[right]] != -1)
            left = max(tempArr[s[right]]+1 , left);
        tempArr[s[right]] = right;

        maxCount = max(maxCount, right - left + 1);
        right++;
    }
    return maxCount;
}
int main(){
    string s = "pwwkew";
    cout<<lengthOfLongestSubstring(s);
}