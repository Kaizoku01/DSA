#include <bits/stdc++.h>
using namespace std;

//! Naive 
//! TC = O(n+m)  sc = o(n+m)
// int Median2Array(std::vector<int> nums1, std::vector<int> nums2){
//     int n = nums2.size();
//     int m = nums1.size();
//     std::vector<int> finalarr(n+m);
//     int i = 0, j = 0, k = 0;
    
//     while (i<m && j<n){
//         if(nums1[i] < nums2[j]) finalarr[k++] = nums1[i++];
//         else
//             finalarr[k++] = nums2[j++];
//     }
//     if(i<m){
//         while (i<m){
//             finalarr[k++] = nums1[i++];
//         }
//     }
//     if (j<n){
//         while (j<n){
//             finalarr[k++] = nums2[j++];
//         }
//     }

//     n = n+m;

//     //median code

//     if(n%2 == 1)  return finalarr[((n + 1)/2) - 1];
    
//     else
//         return ((float)finalarr[(n/2)-1] + (float)finalarr[(n/2)]) / 2;
// }


//!Efficient using Binary search
int Median2Array(vector<int> &nums1, vector<int> &nums2){
    int m = nums1.size();
    int n = nums2.size();
    if(n < m)   return Median2Array(nums2 ,nums1);

    int low = 0, high = m;
    while (low <= high){
        int cut1 = (high + low) >> 1;
        int cut2 = ((n + m + 1)/2) - cut1;

        int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
        int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
        int r1 = cut1 == m ? INT_MAX : nums1[cut1];
        int r2 = cut2 == n ? INT_MAX : nums2[cut2];

        //validating partitions

        if(l1 <= r2 && l2<=r1){
            if((n+m)%2 != 0) return max(l1,l2);
            else
                return (max(l1,l2) + min(r1,r2))/2.0;
        }
        else if(l1 > r2) high = cut1 - 1;
        else low = cut1 + 1;
    }
    return 0;
}

int main(){
    std::vector<int> nums1 = {1,4,7,10,12};
    std::vector<int> nums2 = {2,3,6,15};
    std::cout<<Median2Array(nums1, nums2);
    return 0;
}