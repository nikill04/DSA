/* MERGE STRINGS ALTERNATIVELY : https://www.hackerrank.com/contests/iiits-ytp2026-0703/challenges/merge-strings-alternately-5

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Input Format

A single string word1

A single string word2.

Constraints

word1 and word2 consist of lowercase English letters.

1<=word1.length, word2.length<=100

Output Format

A single line containing the merged string.               */






string mergeAlternately(string word1, string word2) {
    int i = 0; 
    int j = 0;
    
    string answer = "";
    
    for( ; i < word1.size() && j < word2.size(); ) {
        answer += word1[i++];
        answer += word2[j++];
    }
    
    while(i < word1.size()) {
        answer += word1[i++];
    }
    
    while(j < word2.size()) {
        answer += word2[j++];
    }
    
    return answer;

}