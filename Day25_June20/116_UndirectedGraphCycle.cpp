/* DETECT CYCLE IN AN UNDIRECTED GRAPH : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V              */






class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        // First let's create an adjacency list.
        vector<vector<int>> graph(V);  // as     0 ≤ edges[i][0], edges[i][1] < V

        
        for(auto i : edges) {
            int a = i[0];
            int b = i[1];
            
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<bool> visited(V, false);

        
        for(int node = 0; node < V; node++) {  // if it is a connected graph, it will just complete in one iteration, if not then remaining nodes still be false in visited array, then in next iterations of this loop covers those.
            if(!visited[node]) {
                if(dfsHelper(graph, visited, -1, node)) {  // -1 is parent for first node;
                    return true;
                }
            }
        }
        
        return false;
        
        
        // vector<int> parent(V, -2); // Initially i am setting all the nodes parents as -2. Because, -1 i am setting as first node's(from the node where we start the traversal) parent
        // // Here, this parent is simultaneously, visited and parent array.
        
        // queue<int> q;
        
        // for(int i = 0; i < V; i++) {  // if it is a connected graph, it will just complete in one iteration, if not then remaining nodes still be false in parent array, then in next iterations of this loop covers those.
        //     if(parent[i] == -2) {
        //         q.push(i);
        //         parent[i] = -1; // Because, we are starting from this.
                
        //         if(bfsHelper(graph, parent, q)) return true;
        //     }
        // }
        
        // return false;
        
    }

    bool dfsHelper(vector<vector<int>> & graph, vector<bool> & visited, int parent, int node) {
        
        visited[node] = true;
         
        
        for(int nghbr : graph[node]) {
            if(!visited[nghbr]) {
                if(dfsHelper(graph, visited, node, nghbr)) {
                    return true;
                }
                
            }
            else if(nghbr != parent) {
                return true;
            }
        }
        
        return false;
    }  
    
    // bool bfsHelper(vector<vector<int>> & graph, vector<int> & parent, queue<int> & q) {
                
    //     while(!q.empty()) {
    //         int u = q.front();
    //         q.pop();
                    
    //         for(auto nghbr : graph[u]) {
    //             if(parent[nghbr] == -2) {
    //                 q.push(nghbr);
    //                 parent[nghbr] = u;
    //             }
    //             else if(nghbr != parent[u]) {
    //                 return true;
    //             }
    //         }
    //     }
        
    //     return false;
    // }
    

    
};