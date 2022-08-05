#include "bits/stdc++.h"
using namespace std;

bool bSearch(vector<vector<int>> &matrix, int key){
    int low = 0;
    if(matrix.empty()) return false;
    int high = (matrix.size() * matrix[0].size()) - 1;

    while (low<=high){
        int mid = (low + (high - low)/2);
        if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] == key){
            return true;
        }
        if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] > key){
            high = mid - 1;
        }   
        else{
            low = mid + 1; 
        }
            
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6}};

    cout<<bSearch(matrix,4);

}