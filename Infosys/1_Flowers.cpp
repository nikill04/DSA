/* Flowers : https://codeforces.com/problemset/problem/474/D

We saw the little game Marmot made for Mole's lunch. Now it's Marmot's dinner time and, as we all know, Marmot eats flowers. At every dinner he eats some red and white flowers. Therefore a dinner can be represented as a sequence of several flowers, some of them white and some of them red.

But, for a dinner to be tasty, there is a rule: Marmot wants to eat white flowers only in groups of size k.

Now Marmot wonders in how many ways he can eat between a and b flowers. As the number of ways could be very large, print it modulo 1000000007 (109 + 7).

Input
Input contains several test cases.

The first line contains two integers t and k (1 ≤ t, k ≤ 105), where t represents the number of test cases.

The next t lines contain two integers ai and bi (1 ≤ ai ≤ bi ≤ 105), describing the i-th test.

Output
Print t lines to the standard output. The i-th line should contain the number of ways in which Marmot can eat between ai and bi flowers at dinner modulo 1000000007 (109 + 7).

Examples
InputCopy
3 2
1 3
2 3
4 4
Output
6
5
5
Note
For K = 2 and length 1 Marmot can eat (R).
For K = 2 and length 2 Marmot can eat (RR) and (WW).
For K = 2 and length 3 Marmot can eat (RRR), (RWW) and (WWR).
For K = 2 and length 4 Marmot can eat, for example, (WWWW) or (RWWR), but for example he can't eat (WWWR).             */




#include <bits/stdc++.h>
using namespace std;

// int solve(int i, int k) {
//     if(i < k) return 1;
//     return solve(i - 1, k) + solve(i - k, k);
// }

// int main() {
//     int t;
//     int k;
//     cin >> t >> k;
//     while(t--) {
//         int a, b;
//         cin >> a >> b;
//         int ans = 0;
//         for(int i = a; i <= b; i++) {
//             ans = ans + solve(i, k);
//         }
//         cout << ans << endl;
//     }
// }


int solve(int i, int k) {
    if(i < k) return 1;
    return solve(i - 1, k) + solve(i - k, k);
}

int main() {
    int t;
    int k;
    cin >> t >> k;
    vector<int> vec(9999999, -1);
    while(t--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for(int i = a; i <= b; i++) {
            if(vec[i] != -1) {
                ans = ans + vec[i];
            }
            vec[i] = solve(i, k);
            ans = ans + vec[i];
        }
        cout << ans << endl;
    }
}