/* ASSIGN COOKIES : https://www.hackerrank.com/contests/iiits-ytp2026-1303/challenges/assign-cookies-9

Assume you are an awesome parent and want to give your children some cookies. However, you should give each child at most one cookie.Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with. Each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.Your goal is to maximize the number of content children and return that maximum number.

Input Format

The first line contains an integer N, the number of children.

The second line contains N space-separated integers representing the greed factor of each child (g).

The third line contains an integer M, the number of available cookies.The fourth line contains M space-separated integers representing the size of each cookie (s).

Constraints

image

Output Format

A single integer representing the maximum number of children that can get a cookie.

Sample Input 0

3
1 2 3
2
1 1
Sample Output 0

1
Sample Input 1

2
1 2
3
1 2 3
Sample Output 1

2                                           */






int findContentChildren(vector<int> g, vector<int> s) {
    int ng = g.size();
    int sg = s.size();
    
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int sPoint = 0;
    // int gPoint = 0;
    
    int count = 0;
    
    for(int i = 0; i < ng; i++) {
        for(int j = sPoint; j < sg; j++) {
            if(s[j] >= g[i]) {
                count++;
                sPoint = j + 1;
                break;
            }
        }
        
        if(sPoint == sg) break;
    }
    
    return count;
}
