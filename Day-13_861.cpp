/*
861. Score After Flipping Matrix
You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).
*/
class Solution
{
public:
    int matrixScore(vector<vector<int>>& grid)
    {
        int n=grid.size(), m=grid[0].size();
        int ans=n*(1<<(m-1));
        for(int j=1; j<m; j++)
        {
            int cnt=0;
            for(int i=0; i<n; i++)
            {
                cnt+=grid[i][0]==0? grid[i][j]^1: grid[i][j];
            }
            cnt=max(cnt, n-cnt);
            ans+=cnt*(1<<(m-j-1));
        }
        return ans;
    }
};

