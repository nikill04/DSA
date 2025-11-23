/*
Given a set of arrays of size  and an integer , you have to find the maximum integer for each and every contiguous subarray of size  for each of the given arrays.

Input Format

First line of input will contain the number of test cases T. For each test case, you will be given the size of array N and the size of subarray to be used K. This will be followed by the elements of the array Ai.

Output Format

For each of the contiguous subarrays of size  of each array, you have to print the maximum integer.

Sample Input

2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10
Sample Output

4 6 6 4
8 8 8 10
*/

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    // for(int i = 0; i < n - k + 1; i++) {
    //     int max = -999999999;
    //     for(int j = 0; j < k; j++) {
    //         int min = arr[i + j];
    //         if(max < min) max = min;
    //     }
    //     cout << max << " ";
    // }
    // cout << endl;


    
    // To reduce the time, we are going to use a deque
    /*
    It stores indices of array elements.
    The elements whose indices are stored in the deque are always in decreasing order of their value.
    The front of the deque always stores the index of the maximum element for the current window.         */
    deque<int> dq;  // stores indices
    for (int i = 0; i < n; i++) {
        // Remove elements smaller than current from the back
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i); // push current index

        // Remove the element at front if it’s outside the current window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Print the max element of the current window
        if (i >= k - 1)
            cout << arr[dq.front()] << " ";
    }
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}