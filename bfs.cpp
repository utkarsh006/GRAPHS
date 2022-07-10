class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
       vector<int> vis(V+1,0);  //Visited Array
       queue<int> q;          //Queue
       vector<int> ans;       //To store the traversal
       
       ans.push_back(0);
       q.push(0);
       vis[0]=1;
       
       while(!q.empty())
       {
           int front = q.front();
           q.pop();
           for(auto child:adj[front])
           {
               if(vis[child]) continue;
               
               vis[child]=1;
               q.push(child);
               ans.push_back(child);
           }
       }
       
       return ans;
   }
    
};
