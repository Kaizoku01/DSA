//! Problem statement:
// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
// Merge them in sorted order. 
// Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

#include "bits/stdc++.h"
using namespace std;

// void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
//         n = nums1.size();
//         m = nums2.size();
//         vector<int> answer;
        
//         for(int i=0;i<n;i++){
//             answer.push_back(nums1[i]);
//         }
//         for(int i=0;i<m;i++){
//             answer.push_back(nums2[i]);
//         }
//         sort(answer.begin(),answer.end());
//         nums1.clear();
//         nums2.clear();
        
//         for(int i=0;i<n;i++){
//             nums1.push_back(answer[i]);
//         }
//         for(int i=n;i<n+m;i++){
//             nums2.push_back(answer[i]);
//         }
// }

//! Optimized space approach
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    m = nums1.size();
    n = nums2.size();

    for (int i = 0; i < m; i++)
    {
        if(nums1[i]>=nums2[0]){
            swap(nums1[i],nums2[0]);
            sort(nums2.begin(),nums2.end());
        }
    }
}

//! Gap method : Most optimzed in time and space
// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){

//     int gap = ceil((floor)(m+n)/2);
//     while (gap>0){
//         int i=0;
//         int j=gap;
//         while (j<(n+m)){
//             if(j<n && nums1[i]>nums1[j]){
//                 swap(nums1[i],nums1[j]);
//             }
//             else if(j>=n && i<n && nums1[i]> nums2[j-n]){
//                 swap(nums1[i],nums2[j-n]);
//             }
//             else if(j>=n && i>=n && nums2[i-n] > nums2[j-n]){
//                 swap(nums2[i-n],nums2[j-n]);
//             }
//             j++;
//             i++;
//         }
//         if(gap == 1){
//             gap = 0;
//         }else{
//             gap = ceil((float) gap / 2);
//         }
//     } 
// }

int main(){
    vector<int> nums1{1,4,8,10};
    vector<int> nums2{2,3,9};

    merge(nums1,nums1.size(),nums2,nums2.size());

    for (int i = 0; i < nums1.size(); i++)
    {
        cout<<nums1[i];
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        cout<<nums2[i];
    }
}





