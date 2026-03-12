/* MAJORITY ELEMENT : https://www.hackerrank.com/contests/iiits-ytp2026-1203/challenges/majority-element-78

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Input Format

The first line contains an integer n, the size of the array.
The second line contains n space-separated integers representing the elements of the array nums.
Constraints

n = nums.length
1 <= n <= 10^5
-10^9 <= nums[i] <= 10^9
The input is generated such that a majority element will exist in the array.
Output Format

Print a single integer representing the majority element in the array
Sample Input 0

3
3 2 3
Sample Output 0

3
Sample Input 1

7
2 2 1 1 1 2 2
Sample Output 1

2                                                     */






int majorityElement(vector<int> nums) {
    int n = nums.size();
    
    unordered_map<int, int> mp;
    
    int answer;
    
    for(int i = 0; i < n; i++) {
        mp[nums[i]]++;
        if(mp[nums[i]] > (n / 2)) {
            answer = nums[i];
            break;
        }
    }
    
    return answer;
}