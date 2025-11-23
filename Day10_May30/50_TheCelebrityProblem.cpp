/*
THE CELEBRITY PROBLEM: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
Output: 1
Explanation: 0th and 2nd person both know 1st person. Therefore, 1 is the celebrity person. 
Input: mat[][] = [[1, 1], [1, 1]]
Output: -1
Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.
Input: mat[][] = [[1]]
Output: 0
Constraints:
1 <= mat.size()<= 1000
0 <= mat[i][j]<= 1
mat[i][i] == 1     */




class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here

        // MY CODE 1
        // stack<int> st;
        // int n1, n2, k = 0;
        // for(int i = 0; i < mat.size(); i++) {
        //     if(st.empty()) {
        //         n1 = i;
        //         if(!(i + 1 < mat.size())) {
        //             st.push(n1);
        //             break;
        //         }
        //         n2 = ++i;
        //         if(mat[n1][n2] == 0) st.push(n1);
        //         if(mat[n2][n1] == 0) st.push(n2);
        //     } else {
        //         int count;
        //         st.push(i);
        //         do {
        //             count = 0;
        //             n1 = st.top();
        //             st.pop();
        //             n2 = st.top();
        //             st.pop();
        //             if(mat[n1][n2] == 0) {
        //                 st.push(n1);
        //                 count++;
        //             }
        //             if(mat[n2][n1] == 0) {
        //                 st.push(n2);
        //                 count++;
        //             }
        //         } while(count < 2 && st.size() >= 2);
        //     }
        // }
        
        // if(st.empty()) return -1;   
        
        // // // int candidate = st.top();
        // // // for (int j = 0; j < mat.size(); j++) {
        // // //     if (j == candidate) continue;
        // // //     if (mat[candidate][j] == 1 || mat[j][candidate] == 0) return -1;
        // // // }
        // // // return candidate;
        
        // for(int j = 0; j < mat.size(); j++) {
        //     if(j == st.top()) continue;
        //     else k = k | mat[st.top()][j];
        //     if(mat[j][st.top()] == 0) {
        //         k = 1;
        //         break;
        //     }
        // }
        // if(k == 0) return st.top();
        // return -1;

        
        
        
        
        // CORRECTLY OPTIMIZED CODE
        int n = mat.size();
        stack<int> st;

        // Step 1: Push all people into the stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Step 2: Find a potential celebrity
        while (st.size() > 1) {
            int A = st.top(); st.pop();
            int B = st.top(); st.pop();

            if (mat[A][B] == 1) {
                // A knows B => A can't be celebrity
                st.push(B);
            } else {
                // A doesn't know B => B can't be celebrity
                st.push(A);
            }
        }

        if (st.empty()) return -1; // No potential celebrity

        int candidate = st.top();

        // Step 3: Verify candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // Candidate must not know anyone
                if (mat[candidate][i] == 1) return -1;
                // Everyone must know candidate
                if (mat[i][candidate] == 0) return -1;
            }
        }

        return candidate;
        
        
        
        
        
        // My CODE 2 (BRUTE FORCE APPROACH)
        // int celeb = -1;
        // for(int i = 0; i < mat.size(); i++) {
        //     int k = 1;
        //     for(int j = 0; j < mat[i].size(); j++) {
        //         k = k & mat[j][i];
        //     }
        //     if(k == 1) {
        //         k = 0;
        //         for(int a = 0; a < mat[i].size(); a++) {
        //             if(a != i) {
        //                 k = k | mat[i][a];
        //             } else continue;
        //         }
        //         if(k == 0) celeb = i; 
        //     }
        // }
        // return celeb;
    }
};