class Solution {
public:

    void dfs(vector<vector<int>>&grid,int i,int j,int row,int col)
    {
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j] == 1)
            return;
        
        grid[i][j] = 1;
        
        dfs(grid,i+1,j,row,col);
        dfs(grid,i-1,j,row,col);
        dfs(grid,i,j+1,row,col);
        dfs(grid,i,j-1,row,col);

    }
    
    int closedIsland(vector<vector<int>>& grid) 
    {
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        //making all boundary 0's as 1
        //because they can't be a closed island
        //at max they can be surrounded 3-directionally by water 
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == 0 && (i == 0 || j == 0 || i == row-1 || j == col-1))
                    dfs(grid,i,j,row,col);
            }
        }
        
        //counting the number of closed island
        //since we have made all the boundary island(open island) as 1 
        //therefore the total number of island left are nothing but closed island
        for(int i = 0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 0)
                {
                    dfs(grid,i,j,row,col);
                    ans++;
                }
            }
        }
    return ans;
    }
};
