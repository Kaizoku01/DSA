

#include "bits/stdc++.h"
using namespace std;

//! Naive Approach    
// O(n3)

// int maxSubArray(vector<int> &nums){
//     int n = nums.size();
//     int maxSum = 0;
//     vector<int> subArray;

//     if (n==1)
//         return nums[0];
    
//     int i,j,k;

//    for ( i = 0; i <= n-1; i++){
//         for ( j = i; j <= n-1; j++){
//             int sum = 0;
//             for ( k = i; k <= j; k++)
//                 sum+=nums[k];
//             if (sum>maxSum){
//                 subArray.clear();
//                 maxSum = sum;
//                 subArray.push_back(i);
//                 subArray.push_back(j);
//             } 
//         }
//    }
//    return maxSum;         
// }

//! Better Approach
// O(n2)

// int maxSubArray(vector<int> &nums){
//     vector<int> subArray;
//     int maxSum = INT16_MIN;
//     int i,j;
//    for ( i = 0; i < nums.size(); i++){
//         int currentMax = 0;
//         for ( j = i; j < nums.size(); j++){
//             currentMax+=nums[j];
//             if (currentMax>maxSum){
//                 subArray.clear();
//                 maxSum = currentMax;
//                 subArray.push_back(i);
//                 subArray.push_back(j);
//             } 
//         }
//    }
//    return maxSum;         
// }

//! Kadane's Algo
// O(n)

int maxSubArray(vector<int> &nums){
    int sum = 0;
    int max = nums[0];
    int s = 0;
    vector<int> subArray;
    for(int i=0;i<nums.size();i++){
        sum +=nums[i];
        if(sum>max){
            // subArray.clear();
            max = sum;
            // subArray.push_back(s);
            // subArray.push_back(i);
        }
        if(sum<0){
            sum=0;
            s = i+1;
        }
    }   
    return max;     
}



int main(){
    vector<int> nums  = {-1,-1,-2};
    int lon = maxSubArray(nums);
    cout << "The longest subarray with maximum sum is " << lon << endl;
    // cout << "The subarray is " << endl;
    // for (int i = subArray[0]; i <= subArray[1]; i++) {
    //     cout << nums[i] << " ";
    // }
}



