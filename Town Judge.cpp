/* Intuition :-
The town judge trusts no one => the number of outgoing edges of town judge will be 0.
Everyone trusts the town judge => the number of incoming edges of the town judge will be n-1.

1. Store the number of incoming and outgoing edges of all the vertex in two unordered maps respectively.
2. Now traverse trough all the vertex and if a vertex has 0 outgoing and n-1 incoming edges the return it.
3. Else return -1.


Time Complexity = O(n) + O(n) , for storing the number incoming & outgoing edges + traversing trough the vertices to find the town judge
Space Complexity = O(n) + O(n) , for storing the number incoming & outgoing edges */


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {

        unordered_map<int,int>out;//it stores the number of outgoing edges for a vertex
        unordered_map<int,int>in; // it stores the number of incoming edges for a vertex
        
        for(auto index : trust)
        {
            out[index[0]] ++; //outgoing edges
            in[index[1]]++;//incoming edges
        }
        
        for(int i =1;i<=n;i++)
        {
            if(out[i] == 0 && in[i] == n-1)
                return i;
        }
        return -1;
    }
};
