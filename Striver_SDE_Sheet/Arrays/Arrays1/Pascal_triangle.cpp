#include "bits/stdc++.h"
#include <vector>
using namespace std;

vector<vector<int>> pascalTriangle(int rows){ 
    vector<vector<int>> t(rows);

    for (int  i = 0; i < rows; i++)
    {
        t[i].resize(i+1);
        t[i][0] = t[i][i] = 1;

        for (int j = 0; j < i; j++)
        {
            t[i][j] = t[i-1][j-1] + t[i-1][j];  
        }
    }
    return t;
}
