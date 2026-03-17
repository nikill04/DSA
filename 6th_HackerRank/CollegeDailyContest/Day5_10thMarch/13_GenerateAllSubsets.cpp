/* GENERATE ALL SUBSETS : https://www.hackerrank.com/contests/iiits-ytp2026-1003/challenges/generate-all-subsets-2

You are given an integer array nums consisting of distinct elements.

Your task is to generate all possible subsets (also known as the power set) of the array.

A subset is a selection of elements that can be formed by choosing zero or more elements from the array without changing their relative order.

The solution set must not contain duplicate subsets.

Additionally:

Each subset must have its elements sorted in ascending order.

The final list of subsets must also be sorted in lexicographical (dictionary) order.

Return the list of all subsets.

Input Format

A single integer array nums of size n.

Constraints

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All elements in nums are distinct
Output Format

Return a list containing all possible subsets of the array.

Sample Input 0

3
1 2 3
Sample Output 0

1
1 2
1 2 3
1 3
2
2 3
3
Sample Input 1

1
0
Sample Output 1

0                                                                 */







void createSubsets(vector<vector<int>> & answer, vector<int> & nums, int ind, vector<int> vec) {
    
    int n = nums.size();
    
    if(ind == n) {
        answer.push_back(vec);
        return;
    }
    
    createSubsets(answer, nums, ind + 1, vec);
    
    vec.push_back(nums[ind]);
    createSubsets(answer, nums, ind + 1, vec);
    
    return;
}

vector<vector<int>> subsets(vector<int> nums) {
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    
    // For deleting Duplicate elements fromt the given array.
    for(int i = 0; i < n - 1; i++) {
        int duplicate = 0;
        for(int j = i + 1; j < n; j++) {
            if(nums[j] == nums[i]) duplicate++;
            else break;
        }
        if(duplicate != 0) nums.erase(nums.begin() + i + 1, nums.begin() + i + 1 + duplicate);
        n = nums.size();
    }
    
    
    vector<vector<int>> answer;
    vector<int> vec;
    
    createSubsets(answer, nums, 0, vec);
    
    sort(answer.begin(), answer.end());
    
    return answer;
}