#include <bits/stdc++.h>
using namespace std;


int medianMatrix(vector<vector<int>> matrix, int r, int c){
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < r; i++){
        if(matrix[i][0] < min){
            min = matrix[i][0];
        }
         if(matrix[i][c-1] > max){
            max = matrix[i][c-1];
        }
    }
    int desired = (r*c + 1) / 2;
    while (min < max){
        int mid = min + (max-min)/2;
        int count = 0;

        for (int i = 0; i < r; i++){
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if(count < desired){
            min = mid + 1;
        }
        else{
            max = mid;
        }
    }
    return min;
}

int main(){
    return 0;
}