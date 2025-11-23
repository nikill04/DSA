/*
ALLOCATE MINIMUM PAGES: https://www.geeksforgeeks.org/allocate-minimum-number-pages/

Given an array arr[] and an integer k, where arr[i] denotes the number of pages of a book and k denotes total number of students. All the books need to be allocated to k students in contiguous manner, with each student getting at least one book.

The task is to minimize the maximum number of pages allocated to a student. If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Books can be distributed in following ways:

[12] and [34, 67, 90] - The maximum pages assigned to a student is  34 + 67 + 90 = 191.
[12, 34] and [67, 90] - The maximum pages assigned to a student is 67 + 90 = 157.
[12, 34, 67] and [90] - The maximum pages assigned to a student is 12 + 34 + 67 = 113.
The third combination has the minimum pages assigned to a student which is 113.

Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.

Input: arr[] = [22, 23, 67], k = 1
Output: 112
Explanation: Since there is only 1 student, all books are assigned to that student. So, maximum pages assigned to a student is 22 + 23 + 67 = 112.  */




class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size()) return -1;
        int max = 999999999;
        vector<int> vec;
        possibility(arr, vec, 0, k, 0, max);
        return max;
        
    }
    
    void possibility(vector<int> &arr, vector<int> &vec, int k1, int k, int currTotal, int &max) {
        // currTotal is upto now how many total books were allocated.
        // k1 => no. of students got allocation done, until now.
        if(k - k1 > arr.size() - currTotal) return;
        if(k1 == k) {
            if(arr.size() == currTotal) {    // We are also checking alsp this one because, if all the students completed and some books shouldn't be left out
                int currMax = *max_element(vec.begin(), vec.end());
                if(max > currMax) max = currMax;
            }
            return;
        }
        else {
            for(int i = currTotal; i < arr.size(); i++) {
                int presentKTotal = 0;
                for(int j = currTotal; j <= i; j++) {
                    presentKTotal += arr[j];
                }
                vec.push_back(presentKTotal);
                possibility(arr, vec, k1 + 1, k, i + 1, max);
                vec.pop_back();     
            }
        } 
    }
};



/*
bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid ) {
            return false;
        }
            pageSum = arr[i];
        }
        if(studentCount > m) {
int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}                          */