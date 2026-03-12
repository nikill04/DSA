/* MERGE TRIPLETS TO FORM TARGET TRIPLET : https://www.hackerrank.com/contests/iiits-ytp2026-1103/challenges/merge-triplets-to-form-target-triplet-1 

You are given a 2D integer array triplets, where triplets[i] = [a,b,c], and an integer array target = [x,y,z].

You can perform the following operation any number of times (possibly zero):

Choose two indices i and j, and update triplets[j] to become [max(a_i, a_j), max(b_i, b_j), max(c_i, c_j)].

Return true if it is possible to obtain the target triplet [x, y, z] as an element of triplets, or false otherwise.

Input Format

Rows in triplets

Columns in triplets (always 3)

Target array size (always 3)

The 3 integers of the target

Constraints

image

Output Format

A single line containing true or false.

Sample Input 0

3
3
2 5 3
1 8 4
1 7 5
3
2 7 5
Sample Output 0

true
Sample Input 1

2
3
3 4 5
4 5 6
3
3 2 5
Sample Output 1

false                                     */






bool mergeTriplets(vector<vector<int>> triplets, vector<int> target) {
    int n = triplets.size();
      
    vector<int> vec(3, -1);
     
    for(int i = 0; i < n; i++) {
        int isBreak = false;
        bool isFound = true;
        
        vector<int> temp(3);
        for(int j = 0; j < 3; j++) {
            if(triplets[i][j] <= target[j]) {
                temp[j] = max(triplets[i][j], vec[j]);
                if(temp[j] != target[j]) isFound = false;
            }
            else {
                isBreak = true;
                if(target[j] != vec[j]) isFound = false;
            }
        }
        
        if(!isBreak) swap(vec, temp);
        if(isFound) return true;
    }
    
    
    return false;
}