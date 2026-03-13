/* KOKO EATING BANANAS : https://www.hackerrank.com/contests/iiits-ytp2026-1303/challenges/koko-eating-bananas-23/problem

Description: Koko loves to eat bananas. There are N piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in H hours.Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Input Format

The first line contains an integer N, the number of piles.

The second line contains N space-separated integers representing the piles array.

The third line contains an integer H, the number of hours the guards are away.

Constraints

image

Output Format

A single integer representing the minimum eating speed k.

Sample Input 0

4
3 6 7 11
8
Sample Output 0

4
Sample Input 1

5
30 11 23 4 20
5
Sample Output 1

30                                                */





int minEatingSpeed(vector<int> piles, int h) {
// BRUTE FORCE APPROACH O(N ^ 2)
//     int n = piles.size();
    
//     if(h < n) return -1;
    

//     long long totalSum = 0;
//     for(int i = 0; i < n; i++) {
//         totalSum += piles[i];
//     }
//     if(h >= totalSum) return 1;
//     /* piles[i] <= 10^9
//        n <= 10^4

//         So worst case: totalSum = 10^9 * 10^4 = 10^13
//         But int can only store up to: 2,147,483,647
//         So overflow occurs.

//         Example overflow behavior:
//         totalSum = 10000000000
//         stored as int -> becomes negative or garbage

//         Now this condition becomes wrong:
//         if(h >= totalSum) return 1;
//         Because totalSum may become negative, so the condition becomes true unexpectedly, returning 1 incorrectly.
//         So, that's why use "long long" for "totalSum" instead of "int". */
//     // Instead of the above all, you can simply start the "for" loop from "i = 1".
    
    
//     int maxi = *max_element(piles.begin(), piles.end());
    
//     for(int i = 2; i <= maxi; i++) {
//         int count = 0;
//         for(int j = 0; j < n; j++) {
//             count += ceil((double)piles[j] / i);
            
//             if(count > h) break;
//         }
//         if(count <= h) {
//             return i;
//         }
//     }
    
//     return maxi; 
    
    
    
// OPTIMAL APPROACH(BINARY SEARCH) - O(log(N));
    
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    
    int ans = high;
    
    while(low <= high) {
        int mid = low + ((high - low) / 2);
    
        int hours = 0;
        
        for(int p : piles) {
            hours += (ceil((double)p / mid));
        }
        
        if(hours > h) 
            low = mid + 1;
        else {
            high = mid - 1;
            ans = mid;
        }
    }
    
    return ans;
}