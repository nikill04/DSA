/*
Kth SMALLEST ELEMENT: https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

Given an array arr[] and an integer k where k is smaller than the size of the array, your task is to find the kth smallest element in the given array.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [2, 3, 1, 20, 15], k = 4 
Output: 15
Explanation: 4th smallest element in the given array is 15.
Constraints:
1 <= arr.size <= 106
1<= arr[i] <= 106
1 <= k <= n                                   */





// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        /* 1st Method 
            You can do by sorting the array(nlogn) and travel the array upto kth index and find it
        */
        
        
        // If you decide to you priority queue, and if they ask kth smallest use max heap, else if asked kth largest consider using min heap 
        priority_queue<int> pq;
        
        for(int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
            
            if(i + 1 > k) pq.pop();
        }
        // Here time complexity is only nlogk which is smaller than before nlogn
        
        return pq.top();
    }
};