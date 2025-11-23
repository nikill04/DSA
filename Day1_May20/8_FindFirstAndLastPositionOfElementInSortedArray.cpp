/*
FIND FIRST AND LAST POSITION OF ELEMENT IN SORTED ARRAY: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109                 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        
        int ans1 = -1;
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + ((end - start) / 2);
        while(start <= end) {
            if(target == nums[mid]) {
                ans1 = mid;
                end = mid - 1;
            } else if(target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            mid = start + ((end - start) / 2);
        }

        int ans2 = -1;
        start = 0;
        end = nums.size() - 1;
        mid = start + ((end - start) / 2);
        while(start <= end) {
            if(target == nums[mid]) {
                ans2 = mid;
                start = mid + 1;
            } else if(target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            mid = start + ((end - start) / 2);
        }

        return {ans1, ans2};

        // int start1 = 0;
        // int end1 = nums.size() - 1;
        // int mid1 = start1 + ((end1 - start1) / 2);
        // while(start1 < end1) {
        //     if(target == nums[mid1]) {
        //         break;
        //     } else if(target < nums[mid1]) {
        //         end1 = mid1 - 1;
        //     } else {
        //         start1 = mid1 + 1;
        //     }
        //     mid1 = start1 + ((end1 - start1) / 2);
        // }
        // if(target != nums[mid1]) return {-1, -1};
        // else{
        //     start1 = end1 = mid1;
        //     for( ; start1 >= 0 && nums[start1] == target; start1--);
        //     for( ; end1 < nums.size() && nums[end1] == target; end1++);
        //     return {++start1, --end1};
        // }
    }
};