class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        
          for(int currRow=0; currRow<m; currRow++)
          {
              for(int currCol=0; currCol<n; currCol++)
              {
                  if(board[currRow][currCol] == word[0])
                  {
                      if(dfs(currRow, currCol, m, n, board, 0, word))
                          return true;
                  }
              }
          }
        return false;
    }
    
bool dfs(int currRow, int currCol, int m, int n, vector<vector<char>>& board, int x, string &word)
{
    if(x>=word.size()) return true;
    if(currRow<0 || currCol<0 || currRow==m || currCol==n||board[currRow][currCol]!=word[x]) 
         return false;
    
        char current = board[currRow][currCol];
        board[currRow][currCol] = '#';
    
        bool up =  dfs  (currRow-1, currCol, m, n, board, x+1, word);
        bool down = dfs (currRow+1, currCol, m, n, board, x+1, word);
        bool left = dfs (currRow, currCol-1, m, n, board, x+1, word);
        bool right = dfs(currRow, currCol+1, m, n, board, x+1, word);
        
        
        board[currRow][currCol] = current;
        
        return (up|| down|| left|| right) ;
}
    
};
