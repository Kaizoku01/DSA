#include "bits/stdc++.h"
using namespace std;


// void setzero(vector<vector<int>> &matrix){                         //BRUTE FORCE APPROACH ..NEGATIVE INPUT TESTCASE FAILS

//     int row = matrix.size();
//     int col = matrix[0].size();
//     int ind;


//     for (int i = 0; i < row; i++){
//         for (int j = 0; j < col; j++){
//                 if(matrix[i][j]==0){
//                     int temp_col = j;
//                     int temp_row = i;
//                     for (ind=0; ind < row; ind++){
//                         if (matrix[ind][temp_col]!=0){
//                         matrix[ind][temp_col] = -1;
//                         } 
//                     }
//                     for (ind=0; ind < col; ind++){
//                         if (matrix[temp_row][ind]!=0){
//                         matrix[temp_row][ind] = -1;      
//                         }
//                     }
//                 }
//                 else{
//                     matrix[i][j] = matrix[i][j];
//                 }
//         }
//     }
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//         if (matrix[i][j] == -1) {
//         matrix[i][j] = 0;
//         }
//         }
//     }
    
// }

// void setzero(vector<vector<int>> &matrix){   //better in time ...bad in space!!

//     int row = matrix.size();
//     int col = matrix[0].size();

//     vector<int> dummyrow(row,-1);
//     vector<int> dummycol(col,-1);

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (matrix[i][j]==0)
//             {
//                 dummyrow[i] = 0;
//                 dummycol[j] = 0;
//             }
//         }
//     }
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (dummyrow[i]==0 || dummycol[j]==0)
//             {
//                 matrix[i][j]=0;
//             }
            
//         }
        
        
//     }
    
// }
void setzero(vector < vector < int >> & matrix) {   // better in time and in space too
  int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
  for (int i = 0; i < rows; i++) {
    if (matrix[i][0] == 0) col0 = 0;
    for (int j = 1; j < cols; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
 
  for (int i = rows - 1; i >= 0; i--) {
    for (int j = cols - 1; j >= 1; j--) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
    if (col0 == 0) {
      matrix[i][0] = 0;
    }

  }

}
int main(){

    vector<vector<int>> arr;
    arr={{-1,2,3},{7,5,4},{9,0,5}};

    setzero(arr);

    cout << "The Final Matrix is " << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
    }
}