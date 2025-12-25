/* LARGEST COLOR VALUE IN A DIRECTED GRAPH : https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/

There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

 

Example 1:



Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
Example 2:



Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.
 

Constraints:

n == colors.length
m == edges.length
1 <= n <= 105
0 <= m <= 105
colors consists of lowercase English letters.
0 <= aj, bj < n                          */





class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {  

        int V = colors.size();

        vector<vector<int>> graph(V);
        vector<int> dependencies(V, 0);
        for(vector<int> i : edges) {
            int a = i[0];
            int b = i[1];

            graph[a].push_back(b);

            dependencies[b]++;
        }

        vector<vector<int>> cCnt(V, vector<int>(26, 0)); //It is colorCount. It keeps the maximum all the colour values from all the paths until that node. As given each color is an english letter, so max 26 values.

        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(dependencies[i] == 0) {
                q.push(i);
            }
        }

        int n = 0;   // For checking if all the nodes are entering the queue.
        int ans = -1; // For answer.

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            n++;

            cCnt[node][colors[node] - 'a']++;
            ans = max(ans, cCnt[node][colors[node] - 'a']);

            for(auto nghbr : graph[node]) {
                dependencies[nghbr]--;

                if(dependencies[nghbr] == 0) {
                    q.push(nghbr);
                }

                for(int j = 0; j < 26; j++) {
                    cCnt[nghbr][j] = max(cCnt[nghbr][j], cCnt[node][j]);
                }
            }
        }

        return n == V ? ans : -1;

        


        // vector<unordered_map<char, int>> leafNodes;

        // int V = colors.size(); // no. of nodes

        // vector<vector<int>> graph(V);
        // // vector<int> dependencies(V, 0);
        // vector<pair<int, unordered_map<char, int>>> dependencies(V, {0, {}});

        // for(auto i : edges) {
        //     int a = i[0];
        //     int b = i[1];

        //     graph[a].push_back(b);

        //     dependencies[b].first++;
        // }

        // vector<bool> visited(V, false);

        // queue<int> q;
        // for(int i = 0; i < V; i++) {
        //     if(dependencies[i].first == 0) {
        //         q.push(i);
        //         dependencies[i].second[colors[i]]++;
        //         visited[i] = true;
        //     }
        // }

        // int n = 0;
        // while(!q.empty()) {
        //     int node = q.front();
        //     q.pop();
        //     n++;

        //     for(int nghbr : graph[node]) {
        //         dependencies[nghbr].first--;

        //         if(!visited[nghbr]) {
        //             visited[nghbr] = true;

        //             dependencies[nghbr].second = dependencies[node].second;
        //             dependencies[nghbr].second[colors[nghbr]]++;
        //         }
        //         else {
        //             for(auto i : dependencies[node].second) {
        //                 if(i.first == colors[nghbr]) {
        //                     if(dependencies[nghbr].second[colors[nghbr]] <= i.second) {
        //                         dependencies[nghbr].second[colors[nghbr]] = 1 + i.second;
        //                     }
        //                 } 
        //                 else {
        //                     if(dependencies[nghbr].second.find(i.first) != dependencies[nghbr].second.end()) {
        //                         dependencies[nghbr].second[i.first] = max(dependencies[nghbr].second[i.first], dependencies[node].second[i.first]);
        //                     }
        //                     else {
        //                         dependencies[nghbr].second[i.first] = i.second;
        //                     }
        //                 }

        //             }
        //         }

                
        //         if(dependencies[nghbr].first == 0) q.push(nghbr);
                
        //     }

        //     // Or Else
        //     if(graph[node].empty()) {
        //         leafNodes.push_back(dependencies[node].second);
        //     }

            
           
        // }

        // if(n != V) return -1;

        // int maxi = -1;
        // for(auto i : leafNodes) {
        //     for(auto j : i) {
        //         maxi = max(maxi, j.second);
        //     }
        // }
        // return maxi;
    }
};