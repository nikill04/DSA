/*
0 - 1 KNAPSACK PROBLEM : https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

Examples :

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
Constraints:
2 ≤ val.size() = wt.size() ≤ 103
1 ≤ W ≤ 103
1 ≤ val[i] ≤ 103
1 ≤ wt[i] ≤ 103                       */







class Solution {
  public:
    int noOfItems;
    int maxWeight;
    vector<vector<int>> matrix;
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        noOfItems = val.size();
        maxWeight = W;
        
        matrix.assign(noOfItems + 1, vector<int>(maxWeight + 1, -1));   // "noOfItems x maxWeight" matrix filled with -1
        // code here
        // if(W == 0 || val.size() == 0) return 0;
        
        // int n = val.size();
        
        // int a = val[n - 1];
        // int b = wt[n - 1];
        
        // wt.erase(wt.end() - 1);
        // val.erase(val.end() - 1);
        
        // if(b <= W) {
        //     return max((a + knapsack(W - b, val, wt)), knapsack(W, val, wt));
        // } 
        // else {
        //     return knapsack(W, val, wt);
        // }
        
        // The above approach is wrong, as because Because both recursive branches share the same vectors, the first branch erases a bunch of elements; when the second branch runs
        
        
        
        
        
        
        // return helper(W, val, wt, noOfItems);  // -> High TIME COMPLEXITY.
        
        
        
        
        // return helper2(W, val, wt, noOfItems);  //  -> Dynamic Programming(Memorization) => Top Down Approach
        
        
        
        
        return helper3(W, val, wt, noOfItems);     //  -> Dynamic Programming(Tabulation)   => Bottom Up Approach
        
    }
    
    
    
    // int helper(int W, vector<int> & val, vector<int> & wt, int n) {
    //     if(W == 0 || n == 0) return 0;
        
    //     if(wt[n - 1] <= W) {
    //         return max((val[n - 1] + helper(W - wt[n - 1], val, wt, n - 1)), helper(W, val, wt, n - 1));
    //     } 
    //     else {
    //         return helper(W, val, wt, n - 1);
    //     }
    
            // This is plain recursive approach, it has at the end approximatlely 2^n leaf nodes, as it goes as a tree, so, time Complexity will be O(2 ^ n)
    // }
    
    
    
    
    // int helper2(int W, vector<int> & val, vector<int> & wt, int n) {
    //     if(W == 0 || n == 0) return 0;
        
        
    //     if(matrix[n][W] != -1) return matrix[n][W];
        
    //     if(wt[n - 1] <= W) {
    //         return matrix[n][W] = max((val[n - 1] + helper2(W - wt[n - 1], val, wt, n - 1)), helper2(W, val, wt, n - 1));
    //     }
    //     else {
    //         return matrix[n][W] = helper2(W, val, wt, n - 1);
    //     }
    // }
    
    
    
    
    int helper3(int W, vector<int> val, vector<int> wt, int n) {
        //  the below code we can write similarly above from the above memorization code.
        
        int mat[n + 1][W + 1];
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= W; j++) {
                if(i == 0 || j == 0) mat[i][j] = 0;
                else if(wt[i - 1] <= j) {
                    int val1 = val[i - 1] + mat[i - 1][j - wt[i - 1]];
                    int val2 = mat[i - 1][j];
                    
                    mat[i][j] = max(val1, val2);
                }
                else {
                    mat[i][j] = mat[i - 1][j];
                }
            }
        }
        
        return mat[n][W];
        
        
        // As n x w calculations, and as above all will take O(1) time, here, time complexity will be O(n x w)
    }
    
};