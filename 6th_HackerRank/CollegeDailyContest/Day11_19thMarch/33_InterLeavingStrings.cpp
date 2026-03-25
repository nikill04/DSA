/* INTERLEAVING STRINGS : https://www.hackerrank.com/contests/iiits-ytp2026-2003/challenges/interleaving-strings-1-1

You are given three strings s1, s2, and s3. Determine whether s3 is formed by an interleaving of s1 and s2.

Definition An interleaving of two strings s1 and s2 is formed such that:

All characters of s1 and s2 are used exactly once
The relative order of characters in both strings is preserved
image

Input Format

Three strings s1, s2 and s3.

Constraints

0 <= len(s1), len(s2) <= 100
0 <= len(s3) <= 200
s1, s2, and s3 consist of lowercase English letters.
Output Format

Print a string true or false
Sample Input 0

a
b
ab
Sample Output 0

true
Sample Input 1

a
b
ba
Sample Output 1

true                                            */






bool check(string & s1, string & s2, string & s3, int i, int j, int k, int & ns1, int & ns2, int & ns3) {
    if(k == ns3) return true;
    
    while(i < ns1 && j < ns2) {
        if(s3[k] != s1[i] && s3[k] != s2[j]) 
            return false;
        
        if(s3[k] == s1[i] && s3[k] == s2[j])
            return (check(s1, s2, s3, i + 1, j, k + 1, ns1, ns2, ns3) || check(s1, s2, s3, i, j + 1, k + 1, ns1, ns2, ns3));
            
        if(s3[k] == s1[i]) 
            i++;
        else if(s3[k] == s2[j]) 
            j++;
        
        k++;
    }
    
    while(i < ns1) {
        if(s3[k] == s1[i]) {
            i++;
            k++;
        }
        else return false;
    }
    while(j < ns2) {
        if(s3[k] == s2[j]) {
            j++;
            k++;
        }
        else return false;
    }
    
    return true;
}

string isInterleave(string s1, string s2, string s3) {
    int ns1 = s1.size();
    int ns2 = s2.size();
    int ns3 = s3.size();
    
    if(ns3 != ns1 + ns2) return "false";
    
    if(check(s1, s2, s3, 0, 0, 0, ns1, ns2, ns3)) return "true";
    return "false";
}