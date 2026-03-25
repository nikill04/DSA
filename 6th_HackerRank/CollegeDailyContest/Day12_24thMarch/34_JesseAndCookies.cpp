/* JESSE AND COOKIES : https://www.hackerrank.com/contests/iiits-ytp-2403/challenges/jesse-and-cookies

Jesse loves cookies and wants the sweetness of some cookies to be greater than value . To do this, two cookies with the least sweetness are repeatedly mixed. This creates a special combined cookie with:

sweetness = Least sweet cookie + 2 * 2nd least sweet cookie.

This occurs until all the cookies have a sweetness .

Given the sweetness of a number of cookies, determine the minimum number of operations required. If it is not possible, return -1.

Example
K = 9
A = [2, 7, 3, 6, 4, 6]

The smallest values are 2 and 3.
Remove them then return 2 + 2*3 = 8 to the array. Now the array is [8, 7, 6, 4, 6].
Remove 4, 6 and return 4 + 2*6 = 16 to the array. Now the array is [16, 8, 7, 6].
Remove 6, 7 and return 6 + 2*7 = 20 to the array. Now the array is [20, 16, 8].
Finally, remove 8, 16 and return 8 + 2*16 = 40 to the array. Now the array is [20, 40].
All values are >= 9 so the process stops after 4 iterations. Return 4.

Function Description
Complete the cookies function in the editor below.

cookies has the following parameters: 

int k: the threshold value
int A[n]: an array of sweetness values
Returns

int: the number of iterations required or -1
Input Format

The first line has two space-separated integers, n  and k, the size of A[] and the minimum required sweetness respectively.

The next line contains n space-separated integers, A[i] .

Constraints
1 <= n <= 10^6
0 <= k <= 10^9  
0 <= A[i] <= 10^6



Sample Input

STDIN               Function
-----               --------
6 7                 A[] size n = 6, k = 7
1 2 3 9 10 12       A = [1, 2, 3, 9, 10, 12]  
Sample Output

2
Explanation

Combine the first two cookies to create a cookie with sweetness  = 1 + 2*2 = 5. 
After this operation, the cookies are [5, 3, 9, 10, 12].
Then, combine the cookies with sweetness 3 and sweetness 5, to create a cookie with resulting sweetness  = 3 + 2*5 = 13.
Now, the cookies are [13, 9, 10, 12].
All the cookies have a sweetness >= 7.

Thus, 2  operations are required to increase the sweetness.               */






int cookies(int k, vector<int> A) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int n = A.size();
    
    for(int i = 0; i < n; i++) {
        pq.push(A[i]);
    }
    
    int count = 0;
    while(pq.top() < k) {
        int a = pq.top();
        pq.pop();
        
        if(pq.empty()) return -1;
        int b = pq.top();
        pq.pop();
        
        int c = a + 2 * b;
        pq.push(c);
        
        count++;
    }
    
    if(pq.top() < k) return -1;
    return count;
}