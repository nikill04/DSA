/* MINIMUM COST PATH EDGE WITH EDGE REVERSALS : https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/?envType=daily-question&envId=2026-01-28

You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.

Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.

The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.

Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

 

Example 1:

Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]

Output: 5

Explanation:



Use the path 0 → 1 (cost 3).
At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
Total cost is 3 + 2 = 5.
Example 2:

Input: n = 4, edges = [[0,2,1],[2,1,1],[1,3,1],[2,3,3]]

Output: 3

Explanation:

No reversal is needed. Take the path 0 → 2 (cost 1), then 2 → 1 (cost 1), then 1 → 3 (cost 1).
Total cost is 1 + 1 + 1 = 3.
 

Constraints:

2 <= n <= 5 * 104
1 <= edges.length <= 105
edges[i] = [ui, vi, wi]
0 <= ui, vi <= n - 1
1 <= wi <= 1000                                                       */





class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> graph(n);
        vector<vector<pair<int, int>>> reverseGraph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            reverseGraph[e[1]].push_back({e[0], 2 * e[2]});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            for (auto &p : graph[u]) {
                int v = p.first, w = p.second;
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }

            for (auto &p : reverseGraph[u]) {
                int v = p.first, w = p.second;
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};


// class Solution {
// public:
//     int minCost(int n, vector<vector<int>>& edges) {
//         // Adjacency List
//         // if(n <= 1) return 0;

//         vector<vector<pair<int, int>>> graph(n);
//         vector<vector<pair<int, int>>> reverseGraph(n);
//         for(int i = 0; i < edges.size(); i++) {
//             graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
//             reverseGraph[edges[i][1]].push_back({edges[i][0], 2 * edges[i][2]});
//         }

//         vector<bool> traversed(n, false);
//         // vector<int> minNodeCost(n, -1);

//         int ans = helper(graph, reverseGraph, traversed, 0, 0);
//         if(ans == INT_MAX) return -1; // That means node "0" and node "n - 1" are not connected
//         return ans; 
//     }

//     int helper(vector<vector<pair<int, int>>> & graph,
//                vector<vector<pair<int, int>>> & reverseGraph,
//                vector<bool> & traversed,
//                int currNode,
//                int sum
//             //    vector<int> & minNodeCost
//                ) {
//         if(traversed[currNode]) return INT_MAX;
//         // if(minNodeCost[currNode] != -1) return minNodeCost[currNode];

//         traversed[currNode] = true;
//         if(currNode == graph.size() - 1) {
//             traversed[currNode] = false;
//             return sum;
//         }

//         int mini = INT_MAX;
//         for(int i = 0; i < graph[currNode].size(); i++) {
//             int currSum = helper(graph, reverseGraph, traversed, graph[currNode][i].first, sum + graph[currNode][i].second);
            
//             mini = min(mini, currSum);
//         }

//         for(int i = 0; i < reverseGraph[currNode].size(); i++) {
//             int currSum = helper(graph, reverseGraph, traversed, reverseGraph[currNode][i].first, sum + reverseGraph[currNode][i].second);

//             mini = min(mini, currSum);
//         }

//         traversed[currNode] = false;
//         // return minNodeCost[currNode] = mini;
//         return mini;
//     }
// };