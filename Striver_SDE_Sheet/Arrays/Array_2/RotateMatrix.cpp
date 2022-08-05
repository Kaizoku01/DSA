#include "bits/stdc++.h"
using namespace std;

void rotate(vector<vector<int>> &matrix){

    int n = matrix.size();
    // transposing the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reversing each row of the matrix
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int size = matrix.size();

    rotate(matrix);

    for (int i = 0; i <= size - 1; i++)
    {
        for (int j = 0; j <= size - 1; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}