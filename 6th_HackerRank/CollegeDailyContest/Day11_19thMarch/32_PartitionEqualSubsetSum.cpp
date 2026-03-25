/* PARTITION EQUAL SUBSET SUM : https://www.hackerrank.com/contests/iiits-ytp2026-2003/challenges/partition-equal-subset-sum-4

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal, or false otherwise.

Input Format

The first line contains an integer N, the number of elements in the array.

The second line contains N space-separated integers representing the nums array.

Constraints
1 ≤ N ≤ 200
1 ≤ nums[i] ≤ 100


Output Format

A single line containing true if the array can be partitioned equally, or false otherwise.

Sample Input 0

4
1 5 11 5
Sample Output 0

true
Sample Input 1

4
1 2 3 5
Sample Output 1

false                                      */





// bool helper(vector<int> & nums, int & isPossible, int sum, int ind) {
//     if(sum == isPossible) return true;
//     if(ind < 0) return false;
    
//     return (helper(nums, isPossible, sum, ind - 1) || helper(nums, isPossible, sum + nums[ind], ind - 1));
// }

bool canPartition(vector<int> nums) {
//     int Range = accumulate(nums.begin(), nums.end(), 0);
    
//     int n = nums.size();
    
//     if(Range % 2 != 0 || n <= 1) return false;
    
//     int isPossible = Range / 2;
    
//     return helper(nums, isPossible, 0, n - 1);
    
    
    int Range = accumulate(nums.begin(), nums.end(), 0);
    
    int n = nums.size();
    
    if(Range % 2 != 0 || n <= 1) return false;
    
    int isPossible = Range / 2;
    
    vector<vector<bool>> mat(n + 1, vector<bool>(isPossible + 1));
    
    for(int j = 1; j <= isPossible; j++) {
        mat[0][j] = true;
    }
    
    for(int i = 0; i <= n; i++) {
        mat[i][0] = false;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= isPossible; j++) {
            if(nums[i - 1] <= j) {
                bool take = mat[i - 1][j - nums[i - 1]];
                bool notTake = mat[i - 1][j];
                mat[i][j] = take || notTake;
            }
            else {
                mat[i][j] = mat[i - 1][j];
            }
        }
    }
    
    return mat[n][isPossible];
}