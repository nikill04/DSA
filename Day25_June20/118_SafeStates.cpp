/* EVENTUAL SAFE STATES : https://www.geeksforgeeks.org/problems/eventual-safe-states/1

Given a directed graph with V vertices numbered from 0 to V-1 and E directed edges, represented as a 2D array edges[][], where each element edges[i] = [u, v] represents a directed edge from vertex u to vertex v. Return all Safe Nodes of the graph.
A vertex with no outgoing edges is called a terminal node. A vertex is considered safe if every path starting from it eventually reaches a terminal node.

Examples: 

Input: V = 5, E = 6, edges[][] = [[1, 0], [1, 2], [1, 3], [1, 4], [2, 3], [3, 4]]
scm-history-item:c%3A%5CUsers%5Cvasir%5CCPP?%7B%22repositoryId%22%3A%22scm0%22%2C%22historyItemId%22%3A%22c961fcd713b6752fb6e95e419c3a928ee95a7f13%22%2C%22historyItemParentId%22%3A%222986c369b9bcfd9c760045ceab7073640ffbdcde%22%2C%22historyItemDisplayId%22%3A%22c961fcd%22%7D
Output: [0, 1, 2, 3, 4]
Explanation: 4 and 0 is the terminal node, and all the paths from 1, 2, 3 lead to terminal node, i.e., 4.
Input: V = 4, E = 3, edges[][] = [[1, 2], [2, 3], [3, 2]]

Output: [0]
Explanation: 0 is the terminal node, and no other node than 0 leads to 0.
Constraints:
1 ≤ V ≤ 105
0 ≤ E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V                                   */





// The question is nothing but : we have to find all the unsafe nodes, that means the nodes which are in a cycle or the even the nodes which have a path to a cycle or in any one of the paths lead to a cycle.
class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        
        // adjacency list
        vector<vector<int>> graph(V);
        
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            
            graph[a].push_back(b);
        }
        
        vector<bool> nonSafeNodes(V, false);
        vector<bool> visited(V, false);
        
        vector<int> currentPath;
        vector<int> indexInCurrPath(V, -1);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(graph, visited, currentPath, indexInCurrPath, nonSafeNodes, i);
            }
        }
        
        vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if(!nonSafeNodes[i]) safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
    
    void dfs(vector<vector<int>> & graph, vector<bool> & visited, vector<int> & currentPath, vector<int> & indexInCurrPath, vector<bool> & nonSafeNodes, int node) {
        visited[node] = true;
        
        indexInCurrPath[node] = currentPath.size();
        currentPath.push_back(node);
        
        for(int nghbr : graph[node]) {
            // if(indexInCurrPath[nghbr] == -1) {
            //     dfs(graph, visited, currentPath, indexInCurrPath, nonSafeNodes, nghbr);
            // }
            // else {
                
            //     for(int i = 0; i < currentPath.size(); i++) {
            //         nonSafeNodes[currentPath[i]] = true;
            //     }
                
            // }
            // Even this above commented code is correct, but it is not optimal and gives TIME LIMIT EXCEEDED. Also try to avoid using the find function in your code approaches as it is a costly one and takes O(n) time. If required Keep the logic same but don't use find function.
            

            if (!visited[nghbr]) {
                dfs(graph, visited, currentPath, indexInCurrPath, nonSafeNodes, nghbr);
            }
            else if (indexInCurrPath[nghbr] != -1) {
                // cycle detected
                for (int i = indexInCurrPath[nghbr]; i < currentPath.size(); i++) {  // Marking unsafe, if the nodes are present in the loop.
                    nonSafeNodes[currentPath[i]] = true;
                }
            }

            // propagate unsafeness
            if (nonSafeNodes[nghbr]) {   // Marking unsafe, even if current node leads to a unsafe node OR leads to a loop.
                nonSafeNodes[node] = true;
            }
            
            /* 
            The above else means if(visited[nghbr] && it == currentPath.end()) , here unlike in the problem detecting a cycle in directed graph, here we even have to consider this case.*/
        }
        
        indexInCurrPath[node] = -1;
        currentPath.pop_back();
        
        return;
    }
};

