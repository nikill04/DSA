/* MINIMUM PENALTY FOR A SHOP : https://leetcode.com/problems/minimum-penalty-for-a-shop/description/?envType=daily-question&envId=2025-12-26

You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':

if the ith character is 'Y', it means that customers come at the ith hour
whereas 'N' indicates that no customers come at the ith hour.
If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

For every hour when the shop is open and no customers come, the penalty increases by 1.
For every hour when the shop is closed and customers come, the penalty increases by 1.
Return the earliest hour at which the shop must be closed to incur a minimum penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.

 

Example 1:

Input: customers = "YYNY"
Output: 2
Explanation: 
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
Example 2:

Input: customers = "NNNNN"
Output: 0
Explanation: It is best to close the shop at the 0th hour as no customers arrive.
Example 3:

Input: customers = "YYYY"
Output: 4
Explanation: It is best to close the shop at the 4th hour as customers arrive at each hour.
 

Constraints:

1 <= customers.length <= 105
customers consists only of characters 'Y' and 'N'.                        */






class Solution {
public:
    int bestClosingTime(string customers) {
        int totYes = 0;
        int totNo = 0;

        for(char i : customers) {
            if(i == 'Y') totYes++;
            else totNo++;
        }

        pair<int, int> ans = {INT_MAX, -1}; // First one is the minimum penalty answer, second one is the index.

        int currY = 0; // Yes's until now.
        int currN = 0; // No's until now.

        ans.first = (totYes - currY) + currN;
        ans.second = 0;

        for(int i = 1; i < customers.size(); i++) {
            if(customers[i - 1] == 'Y') currY++;
            else currN++;

            int a = (totYes - currY) + currN;

            if(a < ans.first) {
                ans.first = a;
                ans.second = i;
            }
        }
        
        // Still we have to calculate for another one.
        if(totNo < ans.first) {
            ans.first = totNo;
            ans.second = customers.size();
        }

        return ans.second;
    }
};