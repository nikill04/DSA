/* PARTITIONS WITH GIVEN DIFFERENCE : https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

Examples :

Input: arr[] =  [5, 2, 6, 4], d = 3
Output: 1
Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
Input: arr[] = [1, 1, 1, 1], d = 0 
Output: 6 
Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in sum1 and remaning two 1's in sum2.
Thus there are total 6 ways for partition the array arr. 
Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
Output: 2                          */






class Solution {
  public:
    int count = 0;
    
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        // int Range = accumulate(arr.begin(), arr.end(), 0);
        // helper(arr, arr.size() - 1, d, Range, 0);
        // return count;
        
        int count1 = helper1(arr, d);
        return count1;
    }
    
    int helper1(vector<int> & arr, int & d) {
        int count1 = 0;
        
        int Range = accumulate(arr.begin(), arr.end(), 0);
        
        int mat[arr.size() + 1][Range + 1];  // Here we have to check how many possible partitions for SUM value, but not just whether that sum is possible or not. That's why we are using 'int' so we add all possibilities as down not 'bool'.
        
        for(int j = 1; j <= Range; j++) {
            mat[0][j] = 0;
        }
        
        mat[0][0] = 1;
        
        for(int i = 1; i <= arr.size(); i++) {
            for(int j = 0; j <= Range; j++) {
                if(arr[i - 1] <= j) {
                    mat[i][j] = mat[i - 1][j - arr[i - 1]] + mat[i - 1][j];
                }
                else {
                    mat[i][j] = mat[i - 1][j];   
                }
            }
        }
        
        for(int j = 0; j <= Range; j++) {
            if(mat[arr.size()][j] > 0 && 2 * j - Range == d) count1 += mat[arr.size()][j];
            // First for what SUM(j) values are possible that one's only we are taking. and then for that possible value of one subset, we are checking whether the difference is equal to d(given condition). and then if yes, we are adding not how many possible j values for that difference, but how many possible different paritions i.e., all possibile values at the satisfied j values.
        }
        
        return count1;
    }
    
    
    // void helper(const vector<int> & arr, int n, const int & d, int & Range, int S1) {
    //     if(n < 0) {
    //         if(S1 - (Range - S1) == d) count++;
    //         return;
    //     }
        
    //     helper(arr, n - 1, d, Range, S1 + arr[n]);
    //     helper(arr, n - 1, d, Range, S1);
    // }
};