class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) 
    {
        unordered_map<int,int> outgoing;
        unordered_map<int,int> incoming;
        
        for(int i=0; i<n ; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(M[i][j]==1) 
                {
                    outgoing[i]++;
                    incoming[j]++;
                }
                  
            }
        }
          
        for(int i=0; i<n; i++)
        {
            if(outgoing[i] ==0 && incoming[i] ==n-1)
                return i;
        }
        return -1;
    }
};
