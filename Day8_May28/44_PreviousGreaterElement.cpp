/*
PREVIOUS GREATER ELEMENT: https://www.geeksforgeeks.org/previous-greater-element/


Given an array of distinct elements, find previous greater element for every element. If previous greater element does not exist, print -1.

Examples: 

Input : arr[] = {10, 4, 2, 20, 40, 12, 30}
Output :         -1, 10, 4, -1, -1, 40, 40

Input : arr[] = {10, 20, 30, 40}
Output :        -1, -1, -1, -1

Input : arr[] = {40, 30, 20, 10}
Output :        -1, 40, 30, 20      */




class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        int n = arr.size();
  
        // initialize all PGEs as -1
        vector<int> result(n, -1); 
        
        // stack to keep track of elements
        stack<int> st; 

        // traverse the array from left to right
        for (int i = 0; i < n; i++) {
            
            // pop elements from stack which are <= current element
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // if stack is not empty, top element is PGE
            if (!st.empty()) {
                result[i] = st.top();
            }

            // push current element onto stack
            st.push(arr[i]);
        }

        return result;
    }
};