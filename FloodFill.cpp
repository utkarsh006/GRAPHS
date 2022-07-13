class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int row, int col, int color, int x)
    {
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j] != x) return;
        
        grid[i][j] = color;
        
        dfs(grid, i+1, j, row, col, color, x);
        dfs(grid, i-1, j, row, col, color, x);
        dfs(grid, i, j+1, row, col, color, x);
        dfs(grid, i, j-1, row, col, color, x);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) 
    {
        int row = grid.size();
        int col = grid[0].size();
        int x = grid[sr][sc];
        
        if(x != color)
            dfs(grid, sr, sc, row, col, color, x);
        return grid;
    }
};
