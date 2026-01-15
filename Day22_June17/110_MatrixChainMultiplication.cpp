/* MATRIX CHAIN MULTIPLICATION : https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

Examples:

Input: arr[] = [2, 1, 3, 4]
Output: 20
Explanation: There are 3 matrices of dimensions 2 × 1, 1 × 3, and 3 × 4, Let this 3 input matrices be M1, M2, and M3. There are two ways to multiply: ((M1 x M2) x M3) and (M1 x (M2 x M3)), note that the result of (M1 x M2) is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix. 
((M1 x M2) x M3)  requires (2 x 1 x 3) + (2 x 3 x 4) = 30 
(M1 x (M2 x M3))  requires (1 x 3 x 4) + (2 x 1 x 4) = 20. 
The minimum of these two is 20.
Input: arr[] = [1, 2, 3, 4, 3]
Output: 30
Explanation: There are 4 matrices of dimensions 1 × 2, 2 × 3, 3 × 4, 4 × 3. Let this 4 input matrices be M1, M2, M3 and M4. The minimum number of multiplications are obtained by ((M1 x M2) x M3) x M4). The minimum number is (1 x 2 x 3) + (1 x 3 x 4) + (1 x 4 x 3) = 30.
Input: arr[] = [3, 4]
Output: 0
Explanation: As there is only one matrix so, there is no cost of multiplication.
Constraints: 
2 ≤ arr.size() ≤ 100
1 ≤ arr[i] ≤ 200                          */





class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        if(arr.size() < 3) return 0;
        
        // We will have arr.size() - 1 matrices, as we can't start from index 0. Because we if start from index 0, that matrix dimensions will be arr[0 - 1] x arr[0] i.e., arr[-1] x arr[0] which is not defined. So, our first matrix will start from index 1 of arr[].
        int matrixStartInd = 1; 
        int matrixEndInd = arr.size() - 1;
        vector<vector<int>> memorization(arr.size(), vector<int>(arr.size(), -1));
        
        return helper(arr, matrixStartInd, matrixEndInd, memorization);
    }
    
    int helper(vector<int> & arr, int startInd, int endInd, vector<vector<int>> & memorization) {
        if(startInd >= endInd) return 0;
        int mini = INT_MAX;
        
        for(int k = startInd; k <= endInd - 1; k++) { // k is nothing but, at where we are dividing into the subproblem
            
            if(memorization[startInd][endInd] != -1) {
                return memorization[startInd][endInd];
            } 
            else {
                int subProblemA = helper(arr, startInd, k, memorization);
                int subProblemB = helper(arr, k + 1, endInd, memorization);
                
                int multiplySubASubB = arr[startInd - 1] * arr[k] * arr[endInd]; // Whenever we multiply two matrices of (m x n) and (n x t), the resultant matrix will be (m x t). And if we you observe here, (m x n x t) multiplications will takes place.
                // Here above multiply is nothing but, no. of multiplication operations when multiplying subProblemA and subProblemB matrices.
                
                int multiply = subProblemA + subProblemB + multiplySubASubB;
                
                mini = min(mini, multiply);
            }

        }
        
        memorization[startInd][endInd] = mini;
        return mini;
    }
};