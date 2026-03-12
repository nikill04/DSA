/* FIND PEAK ELEMENT : https://www.hackerrank.com/contests/iiits-ytp2026-0903/challenges/find-peak-element-18/problem

A peak element is an element that is strictly greater than its neighbors.

You are given a 0-indexed integer array nums. Find a peak element and return its index. If the array contains multiple peak elements, return the index of any one of them.

For this problem, assume that the elements outside the array boundaries are negative infinity.

Input Format

The first line contains a single integer N, the size of the array. The second line contains N space-separated integers representing the elements of the array.

Constraints

1 <= N <= 100000
-2^31 <= nums[i] <= 2^31 - 1
nums[i] != nums[i+1] for all valid i

Output Format

Print a single integer, the index of any peak element in the array.

Sample Input 0

4
1 2 3 1
Sample Output 0

2
Explanation 0

At index 2, the value is 3.

Its left neighbor is 2 and its right neighbor is 1. Since 3 is strictly greater than both neighbors, index 2 is a peak element.

Sample Input 1

7
1 3 5 7 9 6 4
Sample Output 1

4
Explanation 1

At index 4, the value is 9.

Its left neighbor is 7 and its right neighbor is 6. Since 9 is strictly greater than both neighbors, index 4 is a peak element.       */






int findPeakElement(vector<int> nums) {
//     int n = nums.size();

//     if(n == 1) return 0;
//     if(nums[0] > nums[1]) return 0;
//     if(nums[n - 1] > nums[n - 2]) return n - 1;
    
//     for(int i = 1; i < n - 1; i++) {
//         if(nums[i] < nums[i - 1]) continue;
//         if(nums[i] < nums[i + 1]) continue;
        
//         return i;
//     }
    
//     return 0;
    
    int n = nums.size();
    
    int start = 0;
    int end = n - 1;
    
    int mid = start + ((end - start) / 2);
    
    while(start < end) {
        if(nums[mid] < nums[mid + 1]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
        
        mid = start + ((end - start) / 2);
    }
    
    return mid;
}