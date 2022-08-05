#include "bits/stdc++.h"
using namespace std;

//! Brute Force
//* O(2 ki power n) TC = SC

// int countPaths(int i,int j, int m, int n){
//     if(i==(n-1) && j==(m-1)) return 1;
//     if(i>=n || j>=m) return 0;
//     else return countPaths(i+1,j,m,n) + countPaths(i,j+1,m,n);
// }
// int uniquePaths(int m,int n){
//     return countPaths(0,0,m,n);
// }

//! Using DP

// int countPaths(int i,int j, int n, int m,vector<vector<int>>& dp){
//     if(i==(n-1) && j==(m-1)) return 1;
//     if(i>=n || j>=m) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     else return dp[i][j] = countPaths(i+1,j,n,m,dp) + countPaths(i,j+1,n,m,dp);
// }
// int uniquePaths(int m,int n){
//     vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

//     int num = countPaths(0,0,m,n,dp);
//     if(n==1&&m==1) return num;
//     return dp[0][0];
// }

//! Using Combination

int uniquePaths(int m,int n){
    int N = m+n - 2;
    int r = m - 1;
    double result  = 1;

    for (int i = 1; i <=r; i++){
        result = result * (N - r + i) / i;
    }
    return (int)result;
    
}

    // int uniquePaths(int m, int n) {
    //         int N = n + m - 2;
    //         int r = m - 1; 
    //         double res = 1;
            
    //         for (int i = 1; i <= r; i++)
    //             res = res * (N - r + i) / i;
    //         return (int)res;
    // }

int main(){
    int answer = uniquePaths(3,7);
    cout<<answer;
}