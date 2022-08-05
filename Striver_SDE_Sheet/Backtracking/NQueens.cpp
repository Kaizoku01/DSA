#include <bits/stdc++.h>
using namespace std;

//! Well explained method...
//* But isSafe() have very heavy time complexity
// bool isSafe(int row, int col, vector<string> &grid, int n){
//     int tempCol = col;
//     int tempRow = row;
//     //upper diagnol direction
//     while(row >= 0 && col >= 0){
//         if(grid[row][col] == 'Q') return false;
//         row --;
//         col --;
//     }
//     row = tempRow;
//     col = tempCol;
//     //lower diagnol direction
//     while(row < n && col >=0){
//         if(grid[row][col] == 'Q') return false;
//         row ++;
//         col --;
//     }
//     row = tempRow;
//     col = tempCol;
//     //left direction
//     while(col >= 0){
//         if(grid[row][col] == 'Q') return false;
//         col --;
//     }

//     return true;
// }



// void Solve(int col, vector<string> &grid, vector<vector<string>> &ans, int n){
//     //exit condition
//     if(col == n){
//         ans.push_back(grid);
//         return;
//     }

//     for(int row = 0; row<n; row++){
//         if(isSafe(row, col, grid, n)){
//             grid[row][col] = 'Q';
//             Solve(col + 1, grid, ans, n);
//             grid[row][col] = '.';
//         }
//     }
// }

// vector<vector<string>> nQueen(int n){
//     vector<vector<string>> ans;
//     string s(n,'.');
//     vector<string> grid(n, s);
//     Solve(0, grid, ans, n);
//     return ans;
// }

//! Optimized
//* TC = O(N! * N)   SC = O(N)

void Solve(int col, vector<int> leftDirection, vector<int> lowerDiagonal, vector<int> upperDiagonal, vector<string> &grid, vector<vector<string>> &ans, int n){
    //exit condition
    if(col == n){
        ans.push_back(grid);
        return;
    }
    for(int row = 0; row<n; row++){
        bool isSafeCondition = (leftDirection[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0);
        if(isSafeCondition){
            grid[row][col] = 'Q';
            leftDirection[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            Solve(col + 1, leftDirection, lowerDiagonal, upperDiagonal, grid, ans, n);
            grid[row][col] = '.';
            leftDirection[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> nQueen(int n){
    vector<vector<string>> ans;
    string s(n,'.');
    vector<string> grid(n, s);
    vector<int> leftDirection(n,0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n - 1, 0);


    Solve(0, leftDirection, lowerDiagonal, upperDiagonal, grid, ans, n);
    return ans;
}



int main(){
    vector<vector<string>> ans = nQueen(4);
    for(int i=0;i<ans.size(); i++){
        for(int j=0;j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}