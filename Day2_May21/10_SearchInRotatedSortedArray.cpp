/*
SEARCH IN ROTATED SORTED ARRAY: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104       */



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + ((end - start) / 2);
        while(start < end) {
            if(nums[mid] >= nums[0]) {
                start = mid + 1;
            } else {
                end = mid;
            }
            mid = start + ((end - start) / 2);
        }

        if(target == nums[mid]) return mid;
        else if(mid == nums.size() - 1) { // i.e., mid is pointing to the last element of the array i.e., array is an completely sorted array
            start = 0;
            end = nums.size() - 1;
        }
        // OtherWise in the other case here, mid will point to the lowest element in the array which is immidiate next to the highest element. For that the next two "else if" statments.
        else if(target > nums[mid] && target <= nums[nums.size() - 1]) {
            start = mid + 1;
            end = nums.size() - 1;
        }
        else if(mid > 0 && target > nums[nums.size() - 1] && target <= nums[mid - 1]) {
            start = 0;
            end = mid - 1;
        } else return - 1;

        mid = start + ((end - start) / 2);
        while(start <= end) {
            if(target == nums[mid]) return mid;
            else if(target < nums[mid]) end = mid - 1;
            else start = mid + 1;
            mid = start + ((end - start) / 2);
        }

        return -1;
    }
};


/* 
  
int getPivot(vector<int>& arr, int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}
int binarySearch(vector<int>& arr, int s, int e, int key) {

    int start = s;
    int end = e;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}

int findPosition(vector<int>& arr, int n, int k)
{
    int pivot = getPivot(arr, n);
    if( k >= arr[pivot] && k <= arr[n-1])
    {//BS on second line
        return binarySearch(arr, pivot, n-1, k);
    }
    else
    {//BS on first line
        return binarySearch(arr, 0, pivot - 1, k);
    }
    
}  */