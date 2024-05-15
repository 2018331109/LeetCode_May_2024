/*
2812. Find the Safest Path in a Grid
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

    A cell containing a thief if grid[r][c] = 1
    An empty cell if grid[r][c] = 0

You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.
*/
class Solution
{
public:
    int dx[4]= {1, 0, -1, 0}, dy[4]= {0, 1, 0, -1};
    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        int n=grid.size();
        vector<vector<int>>safety(n, vector<int>(n, INT_MAX));
        queue<vector<int>>q;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j])
                    q.push({i, j}), safety[i][j]=0;
        while(!q.empty()){
            auto p=q.front(); q.pop();
            int x=p[0], y=p[1];
            for(int k=0; k<4; k++){
                int nx=x+dx[k], ny=y+dy[k];
                if(nx>=0 and ny>=0 and nx<n and ny<n and safety[nx][ny]>safety[x][y]+1){
                    safety[nx][ny]=safety[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }
        priority_queue<pair<int, pair<int, int>>>pq;
        pq.push({safety[0][0], {0, 0}});
        vector<vector<int>>vis(n, vector<int>(n, 0));
        while(!pq.empty()){
            auto p=pq.top(); pq.pop();
            int safe=p.first, i=p.second.first, j=p.second.second;
            if(i==n-1 and j==n-1) return safe;
            for(int k=0; k<4; k++){
                int ni=i+dx[k], nj=j+dy[k];
                if(ni>=0 and ni<n and nj>=0 and nj<n and !vis[ni][nj]){
                    pq.push({min(safe, safety[ni][nj]), {ni, nj}});
                    vis[ni][nj]=1;
                }
            }
        }
        return 0;
    }
};

