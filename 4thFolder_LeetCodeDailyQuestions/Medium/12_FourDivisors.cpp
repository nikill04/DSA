/* FOUR DIVISORS : https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04

Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

 

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation: 
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
Example 2:

Input: nums = [21,21]
Output: 64
Example 3:

Input: nums = [1,2,3,4,5]
Output: 0
 

Constraints:

1 <= nums.length <= 104
1 <= nums[i] <= 105                       */






class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        // int ans = 0;
        // int N = nums.size();

        // unordered_map<int, int> ump;
        // for(int i = 0; i < N; i++) {
        //     ump[nums[i]]++;
        // } 

        // for(pair<int, int> i : ump) {
        //     int a = i.first;
        //     int b = i.first / 2;
        //     int noDiv = 2;    // no. of Divisors, this keeps track of no. of divisors a particular element has. as 1 and the number are default divisors, we initialized with 2.
        //     int tempAns = 1 + i.first;
        //     for(int j = 2; j <= b; j++) {
        //         if(a % j == 0) {
        //             noDiv++;
        //             tempAns += j;
        //             if(noDiv > 4) break;
        //         }
        //     }
        //     if(noDiv == 4) {
        //         ans += tempAns * i.second;
        //     }
        // }

        // return ans;


        int ans = 0;

        for(int i : nums) {
            int noOfDivisors = 2; 
            int DivisorSum = 1 + i;

            for(int j = 2; j * j <= i; j++) { // i.e., we are checking until it's square root.
            // We are divisors in terms of pairs because, divisor means it should have another number to which if multiplied gives our number. So, both are divisors. And both divisors can't be more than the square root of the number. So, we check until the square root of a number as we are finding the other no. of the divisor pair also we will get all the no.'s of divisors covered.
                if(i % j == 0) {
                    int other = i / j;

                    if(j == other) {
                        noOfDivisors += 1;
                        DivisorSum += j;
                    }
                    else {
                        noOfDivisors += 2;
                        DivisorSum += j + other;
                    }

                    if(noOfDivisors > 4) break;
                }
            }

            if(noOfDivisors == 4) ans += DivisorSum;
        }

        return ans;
    }
};