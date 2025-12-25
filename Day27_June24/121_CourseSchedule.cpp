/* COURSE SCHEDULE : https://leetcode.com/problems/course-schedule/description/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.                               */






// It's nothing but a simple cycle detection in a directed graph.
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);

        for(auto i : prerequisites) {
            int a = i[0];
            int b = i[1];

            graph[b].push_back(a);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> currPath(numCourses, false);

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(dfsCycleDetect(graph, visited, currPath, i)) return false;
            }
        }

        return true;
    }

    bool dfsCycleDetect(vector<vector<int>> & graph, vector<bool> & visited, vector<bool> & currPath, int node) {
        visited[node] = true;
        currPath[node] = true;

        for(int nghbr : graph[node]) {
            if(!visited[nghbr]) {
                if(dfsCycleDetect(graph, visited, currPath, nghbr)) return true;
            }
            else if(currPath[nghbr]) {
                return true;
            }
        }

        currPath[node] = false;

        return false;
    }
};