/*
NEARLY SORTED: https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.
Note: You need to change the given array arr[] in place.

Examples:

Input: arr[] = [6, 5, 3, 2, 8, 10, 9], k = 3
Output: [2, 3, 5, 6, 8, 9, 10]
Explanation: The sorted array will be 2 3 5 6 8 9 10
Input: arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: The sorted array will be 1 2 3 4 5 6 7 8 9 10
Don't use the inbuilt sort() function for this question.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ k < arr.size()
1 ≤ arri ≤ 106                           */





class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        // Here, use priority queue(use min heap), We know that the  element is maximum at the k position outside, so maintain the size of k. And create a new array with popped out elements, then it will be in sorted manner.
        
        int index = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
            
            if(pq.size() > k) {
                arr[index++] = pq.top();
                pq.pop();
            }
        }
        
        while(!pq.empty()) {
            arr[index++] = pq.top();
            pq.pop();
        }
    }
};