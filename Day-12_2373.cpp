/*
2373. Largest Local Values in a Matrix
You are given an n x n integer matrix grid.

Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:

    maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.

In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.

Return the generated matrix.
*/
class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid)
    {
        int n=grid.size(), mx=0;
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i=0; i<n-2; i++)
        {
            for(int j=0; j<n-2; j++)
            {
                for(int x=i; x<i+3; x++)
                {
                    for(int y=j; y<j+3; y++)
                    {
                        mx=max(mx, grid[x][y]);
                    }
                }
                temp.push_back(mx);
                mx=0;
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};

