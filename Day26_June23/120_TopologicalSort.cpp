/* TOPOLOGICAL SORT : https://www.geeksforgeeks.org/problems/topological-sort/1

Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

Examples:

Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5, 2]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]
Constraints:
2  ≤  V  ≤  5 x 103
1  ≤  E = edges.size()  ≤  min[105, (V * (V - 1)) / 2]
0 ≤ edges[i][0], edges[i][1] < V                            */





class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<int> ans;
        
        // Adjacency List
        vector<vector<int>> graph(V);
        
        vector<int> dependencies(V, 0);  // For, BFS Approach. This is nothing but order a particular node i.e., no. of parents for a particular node.
        
        for(auto i : edges) {
            int a = i[0];
            int b = i[1];
            
            graph[a].push_back(b);
            
            
            dependencies[b]++;           // For BFS.    
        }
        
        bfs(graph, ans, dependencies);
        
        
        // DFS Approach.
        // vector<bool> visited(V, false);
        // stack<int> st;
        
        // for(int i = 0; i < V; i++) {
        //     if(!visited[i]) {
        //         dfs(graph, visited, st, i);
        //     }
        // }
        
        // while(!st.empty()) {
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        
        return ans;
    }
    
    
    void bfs(vector<vector<int>> & graph, vector<int> & ans, vector<int> & dependencies) {
        
        queue<int> q; // keeps nodes whose order is zero i.e., no parents or no dependencies right now.
        
        int v = graph.size();
        for(int i = 0; i < v; i++) {
            if(dependencies[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(int i = 0; i < graph[node].size(); i++) {
                int a = graph[node][i];
                
                dependencies[a]--;
                if(dependencies[a] == 0) q.push(a);
            }
        }
        
        return;
    }
    
    
    
    // void dfs(vector<vector<int>> & graph, vector<bool> & visited, stack<int> & st, int node) {
    //     visited[node] = true;
        
    //     for(int nghbr : graph[node]) {
    //         if(!visited[nghbr]) {
    //             dfs(graph, visited, st, nghbr);
    //         }
    //     }
        
    //     st.push(node);
        
    //     return;
    // }
};