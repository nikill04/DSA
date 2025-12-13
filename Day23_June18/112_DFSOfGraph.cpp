/* DEPTH FIRST TRAVERSAL FOR A GRAPH : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.

Examples:

Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

Output: [0, 2, 4, 3, 1]
Explanation: Starting from 0, the DFS traversal proceeds as follows:
Visit 0 → Output: 0 
Visit 2 (the first neighbor of 0) → Output: 0, 2 
Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 
Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 
Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1
Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]

Output: [0, 1, 2, 3, 4]
Explanation: Starting from 0, the DFS traversal proceeds as follows: 
Visit 0 → Output: 0 
Visit 1 (the first neighbor of 0) → Output: 0, 1 
Visit 2 (the first neighbor of 1) → Output: 0, 1, 2 
Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3 
Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4
Constraints:
1 ≤ V = adj.size() ≤ 104
0 ≤ adj[i][j] ≤ 104                           */




class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        
        vector<int> graph;
        
        vector<int> traversed(adj.size(), 0);
        
        stack<int> st;
        st.push(0);
        
        // The below commented code doesn't work properly. 
        // while(!st.empty()) {
        //     int u = st.top();
        //     st.pop();
            
            
        //     graph.push_back(u);
            
        //     for(int i = adj[u].size() - 1; i >= 0 && traversed[u] != 1; i--) {
        //         int neighbor = adj[u][i];
                
        //         if(traversed[neighbor] != 1) {  // This if check only prevents pushing neighbors that have already been marked visited — it does not prevent pushing neighbors that are already in the stack but not yet popped and marked.
        //             st.push(neighbor);
        //         }
        //     }
            
        //     traversed[u] = 1;
        // }
        
        
        // APPROACH 1
        // DFS stack-based approach(non-recursive)
        // while(!st.empty()) {
        //     int u = st.top();
        //     st.pop();
            
        //     if(traversed[u] != 1) {
        //         graph.push_back(u);
            
        //         for(int i = adj[u].size() - 1; i >= 0; i--) {
        //             int neighbor = adj[u][i];
                    
        //             if(traversed[neighbor] != 1) {
        //                 st.push(neighbor);
        //             }
        //         }
                
        //         traversed[u] = 1;
        //     }
        // }
        
        // return graph;
        
        
        
        // Approach 2
        dfs(adj, graph, traversed, 0);
        return graph;
    }
    
    
    void dfs(vector<vector<int>> & adj, vector<int> & graph, vector<int> & traversed, int node) {
        graph.push_back(node);
        traversed[node] = 1;
        
        for(int i = 0; i < adj[node].size(); i++) {
            if(traversed[adj[node][i]] != 1) {
                dfs(adj, graph, traversed, adj[node][i]);
            }
        }
        
        return;
    }  
};