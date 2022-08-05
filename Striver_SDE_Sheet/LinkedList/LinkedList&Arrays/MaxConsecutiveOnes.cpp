#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, ones = 0;

    for(int it: nums){
        if(it == 1) ones++;
        else ones = 0;

        count = max(count,ones);
    }
    return count;
}

int main(){
    vector<int> nums = {1,0,0,1,1,1,1,0,0,0,1};
    cout<<findMaxConsecutiveOnes(nums);
}