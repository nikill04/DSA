/* IMPLEMENTING DIJKSTRA SET 1 ADJACENCY MATRIX : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.
It is guaranteed that all the shortest distance will fit in a 32-bit integer.

Examples:

Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
Output: [4, 3, 0]
Explanation:

Shortest Paths:
For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
For 2 to 1 minimum distance will be 3. By following path 2 -> 1
For 2 to 2 minimum distance will be 0. By following path 2 -> 2
Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
Output: [0, 4, 8, 10, 10]
Explanation: 

Shortest Paths: 
For 0 to 1 minimum distance will be 4. By following path 0 -> 1
For 0 to 2 minimum distance will be 8. By following path 0 -> 2
For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4
Constraints:
1 ≤ V ≤ 106
1 ≤ E = edges.size() ≤ 106
0 ≤ edges[i][0], edges[i][1] ≤ V-1
0 ≤ edges[i][2] ≤ 104
0 ≤ src < V                                      */





class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        // adj[u] will store {v, weight} meaning there is an edge u -> v with given weight
        vector<vector<pair<int, int>>> adj(V);
        
        for (vector<int> i : edges) {
            // Since the graph is undirected,
            // add edge in both directions
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        // Step 2: Distance array
        // shortDis[i] represents the shortest distance from src to node i
        vector<int> shortDis(V, INT_MAX);
        shortDis[src] = 0;
        
        // Step 3: Min-heap priority queue
        // Stores {distance_from_source, node}
        // The node with the smallest distance is always processed first
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            
            // Skipping outdated entries, because a particular node can be pushed multiple times into the pq, becuase of multiple updations.
            if (dist > shortDis[node]) continue;

            for (auto &nghbr : adj[node]) {
                int NextNode = nghbr.first;   // adjacent node
                int weight   = nghbr.second; // edge weight
                
                // If going through 'node' gives a shorter path to NextNode,
                // update the shortest distance and push into the priority queue.
                if (dist + weight < shortDis[NextNode]) {
                    shortDis[NextNode] = dist + weight;
                    
                    // Push updated distance into priority queue
                    // (Node can appear multiple times; outdated ones are skipped later)
                    pq.push({shortDis[NextNode], NextNode});
                }
            }
        }

        return shortDis;
    }
};
