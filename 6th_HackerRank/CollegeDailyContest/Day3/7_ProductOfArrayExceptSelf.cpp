/* PRODUCT OF ARRAY EXCEPT SELF : https://www.hackerrank.com/contests/iiits-ytp2026-0703/challenges/products-of-array-except-self

Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.

Input Format

A single integer  representing the size of the array.  space-separated integers representing the elements of the array.

Constraints

2<=N<=10^5 -30<=nums[i]<=30

Output Format

A single line containing  space-separated integers representing the result array.

Sample Input 0

4
1 2 3 4
Sample Output 0

24 12 8 6
Sample Input 1

5
-1 1 0 -3 3
Sample Output 1

0 0 9 0 0                                         */





vector<int> productExceptSelf(vector<int> nums) {
    int n = nums.size();
    
    if(n <= 1) return {};
    
    vector<int> ans;
    
    int product = 1;
    
    int isZero = 0;
    
    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) product *= nums[i];
        else isZero++;
    }
    
    for(int i = 0; i < n; i++) {
        if(isZero == 0) ans.push_back(product / nums[i]);
        else if(isZero > 1) ans.push_back(0);
        else if(isZero == 1 && nums[i] == 0) ans.push_back(product);
        else if(isZero == 1 && nums[i] != 0) ans.push_back(0);
    }
    
    return ans;

}