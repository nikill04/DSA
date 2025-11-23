/*
FIND PEAK ELEMENT

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.           */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + ((end - start) / 2);
        while(start < end) {
            if(nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid; 
                // Here, like in B.S we are not doing "end = mid - 1" because if "if condition" is false now the mid has two possibilities of 1) either being in decreasing part or 2) at directly peak itself. if We keep "mid - 1" then we miss the peak if it is 2) possibility.
            }
            mid = start + ((end - start) / 2);
        }
        if(mid <= end && mid >= start) return mid;
        else return -1;
    }
};

/*
As here monotonous behaviour(i.e., either from start to end strictly increasing OR strictly decreasing OR if there is a clear pattern of strict increasing and decreasing(peak) as like in this case) is visible, we go with the binary search to reduce the time complexity.

NORMAL BINARY SEARCH ALGORITHM

int binarySearch(int arr[], int key) {
    int start = 0;
    int end = arr.size();
    int mid = start + ((end - start) / 2);
    while(start < end) {
        if(key == arr[mid]) {
        return mid;
        } else if(key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + ((end - start) / 2);
    }
    return -1;
}
*/