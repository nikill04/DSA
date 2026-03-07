/* MINIMUM NUMBER OF FLIPS TO MAKE THE BINARY STRING ALTERNATING : Minimum Number of Flips to Make the Binary String Alternating

You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
 

Example 1:

Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating.
Example 3:

Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.                           */






class Solution {
public:
    int minFlips(string s) {
        // 1) First of all total no. of type 1 operations possible are equal to length of the string becuase after that again our original string will reappear.

        // 2) And for any given string two types of resultant strings possible one is starting with "1" and other is stargin with "0".

        // 3) What we do is here, we append our original string to our string and we also take another two strings which are possible resultant alternating binary strings for our current appended string. Then we take a window length equal to our original string length. Then we compare this window characters with the two possible target sequences(within respective same window size), we compare as to find the number of alterations requried to match for the below two strings and take the minimum out of it. Then we slide the window for the main string and well as for the two resultant strings and again repeat the operations and finally take minimum possibile alterations value as our answer. The reason why we appended our original string again to the original string because it gives all the possible strings of operating type 1 if we slide(window size = original string length) as disscused in point 1).

        int n = s.size();
        int n1 = 2 * n;

        s = s + s;

        string target1;
        string target2;

        for(int i = 0; i < n1; i++) {
            target1 += (i % 2 ? "0" : "1");
            target2 += (i % 2 ? "1" : "0");
        }

        int mini = INT_MAX;
        int target1Comp = 0;
        int target2Comp = 0;

        // for(int i = 0; i < n; i++) {
        //     if(s[i] != target1[i]) target1Comp++;
        //     else target2Comp++;
        // }
        // mini = min(mini, min(target1Comp, target2Comp));

        // for(int i = 1; i <= n; i++) {
        //     if(s[i - 1] != target1[i - 1]) target1Comp--;
        //     else target2Comp--;

        //     if(s[i + n - 1] != target1[i + n - 1]) target1Comp++;
        //     else target2Comp++;
            
        //     mini = min({mini, target1Comp, target2Comp});
        // }
        int i = 0; 
        int j = 0;

        while(j < n1) {
            if(s[j] != target1[j]) target1Comp++;
            else target2Comp++;

            if(j - i + 1 > n) { // If window becomes greater than the original string size, shrink it from left.
                if(s[i] != target1[i]) target1Comp--;
                else target2Comp--;
                i++;
            }

            if(j - i + 1 == n) {
                mini = min({mini, target1Comp, target2Comp});
            }

            j++;
        }

        return mini;
    }
};