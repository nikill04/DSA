/* JUMP GAME : https://www.hackerrank.com/contests/iiits-ytp2026-1003/challenges/jump-game-37-2

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position. Return true if you can reach the last index, or false otherwise.

Input Format

A single integer N representing the size of the array.

N space-separated integers representing the array elements.

Constraints

1<=N<=10^5

0<=nums[i]<=10^5

Time limit : 1 second

Output Format

A single line containing true or false

Sample Input 0

5
2 3 1 1 4
Sample Output 0

true
Sample Input 1

5
3 2 1 0 4
Sample Output 1

false                                                       */







// bool travel(vector<int> & nums, int ind, vector<pair<bool, bool>> & results) {
//     int n = nums.size();
    
//     if(ind >= n - 1) return true;
    
//     // if(results[ind].first) return true;
//     // if(results[ind].second) return false;
//     if(results[ind].second) return results[ind].first;
    
//     if(nums[ind] == 0) {
//         results[ind] = {false, true};
//         return false;
//     }
    
//     for(int i = min(nums[ind], n - ind - 1); i >= 1; i--) {
//         // if(i + ind >= n - 1) {
//         //     // results[ind].first = true;
//         //     // results[ind].second = true;
//         //     results[ind] = {true, true};
//         //     return true;
//         // }
        
//         if(travel(nums, ind + i, results)) {
//             results[ind] = {true, true};
//             return true;
//         }
//     }
    
//     results[ind] = {false, true};
//     return false;
// }

bool canJump(vector<int> nums) {

// APPROACH - 1(RECURSIVE APPROACH) O(N ^ 2)
    // vector<pair<bool, bool>> results(nums.size(), {false, false}); // First one is answer is found or not, second one is for whether visisted or not.
    // return travel(nums, 0, results);
    
    
    
// APPROACH - 2(GREEDY APPROACH)    O(N)
    int n = nums.size();
    
    int maxReach = 0;
    
    for(int i = 0; i < n; i++) {
        if(i > maxReach) 
            return false;
        
        maxReach = max(maxReach, i + nums[i]);
        
        if(maxReach >= n - 1)
            return true;
    }
    
    return true;

}