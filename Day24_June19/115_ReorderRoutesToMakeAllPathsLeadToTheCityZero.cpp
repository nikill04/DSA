/* REORDER ROUTES TO MAKE ALL PATHS LEAD TO THE CITY ZERO : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

 

Example 1:


Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
Example 2:


Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
Example 3:

Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
 

Constraints:

2 <= n <= 5 * 104
connections.length == n - 1
connections[i].length == 2
0 <= ai, bi <= n - 1
ai != bi                                               */






class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Given, this network forms a tree, that means there won't any connection or edge that forms a loop or even like some kind of closed thing(Only way to travel between two cities). For example, take example 1, there cannot be a testcase where connection from (1 to 4) or (4 to 1). I think now it is clear.

        // Given edge list, we have to make it as adjacency list(AL).
        vector<vector<int>> OrgGraph(n);  
        vector<vector<int>> BackGraph(n); 
        /* 
        1) OrgGraph (Original Graph):
           Stores edges exactly as given in input. If we traverse an edge from OrgGraph, it means
           the edge is pointing away from city 0 and must be reversed.

        2) BackGraph (Reverse Graph):
           Stores the reverse of each edge. If we traverse using BackGraph, the edge already points
           towards city 0, so no reversal is needed. 

           traversing OrgGraph and making the edges reverse, it is simple. but we also need to go to the nodes from where we are receiving the edge, because it might be possible, the node is also pointing away to other node i.e., opposite direction. 
           so, OrgGraph says from where we are pointing away and simply reverse it.
           BackGraph says from where we are getting pointed. So, we also go there for not leaving any nodes that are pointing away.

           In example 1 only, 4 to 0 there is an edge no need to reverse it, but 4 is also pointing away to 5
        */

        /* 
        OR WE CAN ALSO USE
        unordered_map<int, unordered_set<int>> OrgGraph;  
        unordered_map<int, unordered_set<int>> BackGraph; 

        BUT in vector<vector<int>> we are more optimized as:
        Nodes are numbered 0 to n-1, so we can use direct indexing
        vector gives O(1) direct access with low constant time
        unordered_map adds hashing + extra memory overhead
        vector is cache-friendly, simpler, and faster
        That’s why vector<vector<int>> is the more optimized choice here        */

        for(int i = 0; i < connections.size(); i++) {
            int a = connections[i][0];
            int b = connections[i][1];

            OrgGraph[a].push_back(b);

            BackGraph[b].push_back(a);
        }

        vector<bool> visited(n, false);
        int reversedEdges = 0;

        // Start DFS from city 0
        int node = 0;
        
        dfs(OrgGraph, BackGraph, visited, reversedEdges, node);

        return reversedEdges;
    }

    void dfs(vector<vector<int>> & orgGraph, vector<vector<int>> & backGraph, vector<bool> & visited, int & reversedEdges, int node) {

        visited[node] = true;

         /*
        Traverse original edges (node -> neighbor):

        If we move along an original edge,
        it means the road is pointing AWAY from city 0,
        so this road MUST be reversed.
        */
        for(auto num : orgGraph[node]) {
            if(!visited[num]) {
                reversedEdges++;
                dfs(orgGraph, backGraph, visited, reversedEdges, num);
            }
        }

        /*
        Traverse reverse edges (neighbor -> node):

        These edges already point TOWARDS city 0,
        so no reversal is required.
        */
        for(auto num : backGraph[node]) {
            if(!visited[num]) {

                dfs(orgGraph, backGraph, visited, reversedEdges, num);
            }
        }

        return;
    }

};