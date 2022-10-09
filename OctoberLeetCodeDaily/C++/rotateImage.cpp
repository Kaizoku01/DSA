class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // szie of the matrix
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // transposing of matrix : rows become column vice versa
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse of elements of row to reach to the OUTPUT
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};