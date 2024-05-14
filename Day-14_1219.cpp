/*
1219. Path with Maximum Gold
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

    Every time you are located in a cell you will collect all the gold in that cell.
    From your position, you can walk one step to the left, right, up, or down.
    You can't visit the same cell more than once.
    Never visit a cell with 0 gold.
    You can start and stop collecting gold from any position in the grid that has some gold.

*/
class Solution
{
public:
    int n, m, ans=0;
    vector<vector<int>>check;
    int call(int i, int j, vector<vector<int>>& grid)
    {
        if(i>=n or i<0 or j>=m or j<0 or !grid[i][j] or check[i][j]) return 0;
        int res=grid[i][j];
        check[i][j]=1;
        res+=max(call(i+1, j, grid), max(call(i-1, j, grid), max(call(i, j+1, grid), call(i, j-1, grid))));
        check[i][j]=0;
        return res;
    }
    int getMaximumGold(vector<vector<int>>& grid)
    {
        n=grid.size(), m=grid[0].size();
        check=vector<vector<int>>(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j])
                {
                    ans=max(ans, call(i, j, grid));
                }
            }
        }
        return ans;
    }
};

