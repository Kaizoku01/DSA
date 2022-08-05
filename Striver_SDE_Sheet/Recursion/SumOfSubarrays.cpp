#include <bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int> &arr, int n, vector<int> &ans, int sum){
    if(ind == n){
        ans.push_back(sum);
        return;
    }

    //if we pick
    solve(ind + 1, arr, n, ans, sum + arr[ind]);

    //if we do not pick
    solve(ind + 1, arr, n, ans, sum);
}

vector<int> subsetSum(vector<int> arr){
     int n = arr.size();
    vector<int> ans;
    solve(0, arr, n, ans, 0);
    return ans;
}

int main(){
    vector<int> arr = {5,2,1};
    vector<int> Sum = subsetSum(arr);
    for(auto it: Sum) cout<<it<<" ";
    return 0;
}