/* DETECT CYCLE IN A DIRECTED GRAPH : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]



Output: true
Explanation: The diagram clearly shows a cycle 0 → 1 → 2 → 0
Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]


Output: false
Explanation: no cycle in the graph
Constraints:
1 ≤ V ≤ 105
0 ≤ E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V                           */





class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        // adjacency list
        vector<vector<int>> orgGraph(V);
        vector<vector<int>> backGraph(V);
        
        for(auto i : edges) {
            int a = i[0];
            int b = i[1];
            
            orgGraph[a].push_back(b);
            // backGraph[b].push_back(a);
        }
        
        vector<bool> visited(V, false);
        vector<bool> Current_Path(V, false);
        
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(orgGraph, backGraph, visited, Current_Path, i)) return true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<int>> & orgGraph, vector<vector<int>> & backGraph, vector<bool> & visited, vector<bool> & Current_Path, int node) {
        visited[node] = true;
        Current_Path[node] = true;
        
        for(int nghbr : orgGraph[node]) {
            if(!visited[nghbr]) {
                if(dfs(orgGraph, backGraph, visited, Current_Path, nghbr)) return true;
            } 
            else if(Current_Path[nghbr]) return true;
            // else {  
            //     if(dfs(orgGraph, backGraph, visited, Current_Path, nghbr)) return true;
            // }
            /* The above else means if(visited[nghbr] && !Current_Path[nghbr]), actually this is not needed, because this case is : That node has already been completely explored in a previous DFS call, and it did NOT lead to a cycle. if uncommented, You are forcing DFS into an already completed node. Which is actually unnecessary. */
        }
        Current_Path[node] = false;
        
        // for(int nghbr : backGraph[node]) {
        //     if(!visited[nghbr]) {
        //         if(dfs(orgGraph, backGraph, visited, Current_Path, nghbr)) return true;
        //     }
        // }
        
        /* Why adding backGraph, may gives errors in the results
            What your orgGraph is
            0 → 1
            Correct: no cycle.
            
            What your backGraph adds
            1 → 0
            
            Now during DFS:
            Start DFS at 0 and  Visit 1
            Current_Path[0] = true, Current_Path[1] = true
            From 1, backGraph allows 1 → 0, 0 is already in Current_Path
            💥 FALSE CYCLE DETECTED
            But the original graph has NO cycle.
            
            By traversing backGraph, you are allowing paths like: 0 → 1 → 0
            But that path does not exist in the directed graph. You created a cycle by adding reverse edges.
            
            Even though we don't add, the unvisited nodes will be covered by the for loop from which actually this dfs is being called.
        */
        
        return false;
    }
    
  
};