/*
Problem Statement: Given an array of integers A and an integer B.
Find the total number of subarrays having bitwise XOR of all elements equal to B.
*/

#include "bits/stdc++.h"
using namespace std;

//! Brute Force
//* O(N^2)  +  constant space
// int longestSubarraySum(vector<int> arr, int b){
//     int count = 0;
//     for (int i = 0; i < arr.size(); i++){
//         int currXor = 0;
//         for (int j = i; j < arr.size(); j++){
//             currXor ^= arr[j];

//             if(currXor == b) count++;
//         }
        
//     }
//     return count;
    
// }

//! Optimized
int longestSubarraySum(vector<int> arr, int b){
    int xr = 0;
    int count = 0;
    unordered_map<int,int> tempMap;

    for (int i = 0; i < arr.size(); i++){
        xr ^= arr[i];
        if(xr==b) count++;
        int y = xr^b;
        if(tempMap.find(y) != tempMap.end()){
            count += tempMap[y];
        }
        tempMap[xr]++;  
    }
    return count;
}


int main(){
    vector<int> arr = {4,2,2,6,4};
    int b = 6;
    cout<<longestSubarraySum(arr,b);
}