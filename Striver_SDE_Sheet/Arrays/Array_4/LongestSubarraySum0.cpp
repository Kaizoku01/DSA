#include "bits/stdc++.h"
using namespace std;

int longestSubarraySum(vector<int> arr){
    int sum = 0;
    int maxi = 0;

    map<int,int> tempmap;
    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
        if(sum==0){
            maxi = i+1;
        }
        else{
            if(tempmap.find(sum) != tempmap.end()){
                maxi = max(maxi, i - tempmap[sum]);
            }
            else{
                tempmap[sum] = i;
            }
        }
    }
    return maxi;
}

int main(){
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4, -10};
    cout<<longestSubarraySum(arr);
}