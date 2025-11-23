/*
PERMUTATION WITH SPACES: https://www.geeksforgeeks.org/problems/permutation-with-spaces3627/1

Given a string s, you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings.

Example 1:

Input:
s = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".
Example 2:

Input:
s = "BBR"
Output: (B B R)(B BR)(BB R)(BBR)

Your Task:  
You don't need to read input or print anything. Your task is to complete the function permutation() which takes the string s as input parameters and returns the sorted array of the string denoting the different permutations (DON'T ADD '(' and ')' it will be handled by the driver code only).

Expected Time Complexity: O(2s)
Expected Auxiliary Space: O(1)

 

CONSTRAINTS:
1 <= |s| < 10
s only contains lowercase and Uppercase English letters.           */




class Solution {
  public:

    vector<string> permutation(string s) {
        // Code Here
        vector<string> vec;
        if(s.empty()) return vec;
        
        // string outputString = s[0];  // => We can't do this as s[0] is a char and can't directly assign it to a string. So,
        // string outputString(1, s[0]); // This creates a string of 1 character with s[0]. Clean and efficient.
        // OR
        string outputString;
        outputString.push_back(s[0]);
        string inputString = s;
        inputString.erase(0, 1);
        
        solve(inputString, outputString, vec);
    }
    
    void solve(string inputString, string outputString, vector<string> &vec) {
        if(inputString == "") {
            vec.push_back(outputString);
            return;
        }
        char ch = inputString[0];
        inputString.erase(0, 1);
        
        solve(inputString, outputString + " " + ch, vec);
        solve(inputString, outputString + ch, vec);
    }
};