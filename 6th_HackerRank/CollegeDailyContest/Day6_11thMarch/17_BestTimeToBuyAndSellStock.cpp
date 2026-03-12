/* BEST TIME TO BUY AND SELL STOCK : https://www.hackerrank.com/contests/iiits-ytp2026-1103/challenges/best-time-to-buy-and-sell-stock-68-1

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Input Format

The input consists of two lines:

The first line contains an integer n, representing the number of days (the size of the prices array)
The second line contains  space-separated integers, representing the price of the stock on each day.
Constraints

1 <= n <= 10^5
0 <= prices[i] <= 10^4
Output Format

Print a single integer representing the maximum profit possible. If no profit can be made (e.g., the price only decreases), print 0.

Sample Input 0

6
7 1 5 3 6 4
Sample Output 0

5
Sample Input 1

5
7 6 4 3 1
Sample Output 1

0                                                     */





int maxProfit(vector<int> prices) {
// BRUTE FORCE
//     int n = prices.size();
    
//     int maxProf = INT_MIN;
    
//     for(int i = 0; i < n; i++) {
//         // int profit = INT_MIN;
//         for(int j = i + 1; j < n; j++) {
//             maxProf = max(maxProf, prices[j] - prices[i]);
//         }
//     }
    
//     return (maxProf > 0) ? maxProf : 0;
    
    
// OPTIMAL APPROACH
    int n = prices.size();
    
    stack<int> st;
    st.push(prices[0]);
    
    int maxProf = 0;
    
    for(int i = 1; i < n; i++) {
        if(prices[i] - st.top() < 0) {
            st.pop();
            st.push(prices[i]);
            // maxProf = maxProf - (prices[i] - st.top());
        }
        else {
            maxProf = max(maxProf, prices[i] - st.top());
        }
    }
    
    return maxProf;
}