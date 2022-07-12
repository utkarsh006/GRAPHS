class Solution {
public:
    void sinkIsland(vector<vector<char>>&grid, int currRow, int currCol, int m, int n)
    {
        if(currRow<0 || currRow>=m || currCol<0 || currCol>=n || grid[currRow][currCol]=='0')
            return;
        
        //mark curr cell as visited
        grid[currRow][currCol]='0';
        
        //call to neighbours
        sinkIsland(grid, currRow-1, currCol, m, n);     //up
        sinkIsland(grid, currRow+1, currCol, m, n);    //down
        sinkIsland(grid, currRow, currCol-1, m, n);   //left
        sinkIsland(grid, currRow, currCol+1, m, n);  //right
        
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
           for(int currRow=0; currRow<m; currRow++)
           {
               for(int currCol = 0; currCol<n; currCol++)
               {
                   if(grid[currRow][currCol]=='1')
                   {
                       sinkIsland(grid, currRow, currCol, m, n);
                       ans+=1;
                       
                   } 
               }
           }
        return ans;
    }
}; 
