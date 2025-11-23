/*
SORT A STACK: https://www.geeksforgeeks.org/problems/sort-a-stack/1

Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
Your Task: 
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.

Constraints:
1<=N<=100                                              */





/*
void GetStack(stack<int> &s,int to)
{
    if(s.empty()||to>=s.top())
    {
        s.push(to);
        return;
    }
    
    int t=s.top();
    s.pop();
    GetStack(s,to);
    s.push(t);
    return;
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty())
   return;
   
   int to=s.top();
   s.pop();
   sort();
   GetStack(s,to);
   return;
}

class Solution {
public:
    void Solve(vector<int> &nums,int t)
    {
        if(nums.size()==0||t>=nums[nums.size()-1])
        {
            nums.push_back(t);
            return;
        }
        
        int to=nums[nums.size()-1];
        nums.pop_back();
        Solve(nums,t);
        nums.push_back(to);
            
    }
    void getSorted(vector<int> &nums)
    {
        if(nums.size()==0)
            return;
        
        int t=nums[nums.size()-1];
        nums.pop_back();
        getSorted(nums);
        Solve(nums,t);
        return;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)
            return nums;
        
        getSorted(nums);
        return nums;
    }
};                     */