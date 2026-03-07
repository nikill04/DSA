/* VALID PALINDROME II : https://www.hackerrank.com/contests/iiits-ytp2026-0703/challenges/valid-palindrome-ii-1-1

You are given a string s, return true if the s can be a palindrome after deleting at most one character from it.

A palindrome is a string that reads the same forward and backward.

Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).

Input Format

A single line containing the string s.

Constraints

1<=s.length<=10^5

s consists of lowercase english letters

Output Format

A single line containing true or false.

Sample Input 0

aba
Sample Output 0

true
Sample Input 1

abca
Sample Output 1

true                                       */





bool validPalindrome(string s) {
    int n = s.size();
    if(n < 1) return true;
    
    bool isPalindrome = true;
    
    bool alreadyDeleted = false;
    int j = n - 1;
    for(int i = 0; i <= j; ) {
        if(s[i++] == s[j--]) continue;
        
        if(alreadyDeleted) {
            isPalindrome = false;
            break;
        }
        
        alreadyDeleted = true;
        i--;
        
    }
    if(isPalindrome) return true;
    
    isPalindrome = true;
    alreadyDeleted = false;
    j = n - 1;
    for(int i = 0; i <= j; ) {
        if(s[i++] == s[j--]) continue;
        
        if(alreadyDeleted) {
            isPalindrome = false;
            break;
        }
        
        alreadyDeleted = true;
        j++;
    }
    
    return isPalindrome;
}
