#include <bits/stdc++.h>
using namespace std;

//! BRUTE
    //* TC = O(N^2)  SC = O(1)
// int trap(vector<int>& height) {
//     int n = height.size();
//     int water = 0;
//     for(int i=0;i<n;i++){
//         int j = i;
//         int leftMax = 0, rightMax = 0;

//         //leftSide
//         while(j >= 0){
//             leftMax = max(leftMax,height[j]);
//             j--;
//         }
//         j = i;

//         //rightSide
//         while(j<n){
//             rightMax = max(rightMax, height[j]);
//             j++;
//         }

//         water += min(leftMax,rightMax) - height[i];
//     }
//     return water;
// }

//! Faster But memory hefty
//* TC = O(3N)  SC = O(2N)
// int trap(vector<int>& height) {
//     int n = height.size();
    
//     vector<int> prefixMax(n);
//     vector<int> suffixMax(n);

//     prefixMax[0] = height[0];
//     //prefixMax
//     for(int i=1;i<n;i++){
//         prefixMax[i] = max(prefixMax[i-1], height[i]);
//     }
//     //suffixMax
//     suffixMax[n-1] = height[n-1];
//     for(int i=n-2;i>=0;i--){
//         suffixMax[i] = max(suffixMax[i+1], height[i]);
//     }
//     int water = 0;
//     for(int i=0;i<n;i++){
//         water += min(prefixMax[i], suffixMax[i]) - height[i];
//     }

//     return water;

// }

//! Optimized
//* TC = O(N)  SC = O(1) 
int trap(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int outcome = 0;
    int leftMax = 0, rightMax = 0;

    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= leftMax) leftMax = height[left];
            else{
                outcome += leftMax - height[left];
            }
            left++;
        }
        else{  // height[right] >= height[left]
            if(height[right] >= rightMax) rightMax = height[right];
            else{
                outcome += rightMax - height[right];
            }
            right--;
        }  
    }
    return outcome;
}




int main()
{
 return 0;
}