/* MAXIMUM SQUARE AREA BY REMOVING FENCES FROM A FIELD : https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/?envType=daily-question&envId=2026-01-17

There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.

Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).

Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.

Since the answer may be large, return it modulo 109 + 7.

Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.

 

Example 1:



Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
Output: 4
Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.
Example 2:



Input: m = 6, n = 7, hFences = [2], vFences = [4]
Output: -1
Explanation: It can be proved that there is no way to create a square field by removing fences.
 

Constraints:

3 <= m, n <= 109
1 <= hFences.length, vFences.length <= 600
1 < hFences[i] < m
1 < vFences[i] < n
hFences and vFences are unique.                                                 */





class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        
        long long MOD = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(), hFences.end());
        
        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(), vFences.end());

        // 2. Instead of iterating 'm' down to 1, store all possible 
        // Horizontal Gaps in a HashSet.
        // Complexity: O(H^2) where H is number of hFences (small)
        unordered_set<int> hGaps;
        for(int i = 0; i < hFences.size(); i++) {
            for(int j = 0; j < i; j++) {
                hGaps.insert(hFences[i] - hFences[j]);
            }
        }
        
        // 3. Check Vertical Gaps against the Horizontal Set
        // Complexity: O(V^2) where V is number of vFences (small)
        long long maxSide = -1;
        for(int i = 0; i < vFences.size(); i++) {
            for(int j = 0; j < i; j++) {
                int vGap = vFences[i] - vFences[j];

                // if this vertical gap exists as a horizontal gap, then it's a square.
                if(hGaps.count(vGap)) {
                    maxSide = max(maxSide, (long long)vGap);
                }
            }
        }

        if(maxSide == -1) return -1;
        return (maxSide * maxSide) % MOD;






        

        // if(m == n) return (m - 1) * (n - 1);

        // const int MOD = 1e9 + 7;

        // sort(hFences.begin(), hFences.end());
        // sort(vFences.begin(), vFences.end());

        // hFences.insert(hFences.begin(), 1);
        // hFences.push_back(m);

        // vFences.insert(vFences.begin(), 1);
        // vFences.push_back(n);

        // // unordered_set<int> verticalFences;
        // // for(int j = 0; j < vFences.size(); j++) {
        // //     verticalFences.insert(vFences[j]);
        // // }
        // // OR simply the below one
        // unordered_set<int> horizontalFences(hFences.begin(), hFences.end());

        // // unordered_set<int> horizontalFences;
        // // for(int i = 0; i < hFences.size(); i++) {
        // //     horizontalFences.insert(hFences[i]);
        // // }
        // // oR simply the below syntax
        // unordered_set<int> verticalFences(vFences.begin(), vFences.end());

        // int ans = -1;


        // for(int i = m; i > 1; i--) {
        //     int temp = i - 1;
        //     for(int p = 0; p < hFences.size(); p++) {
        //         if(horizontalFences.find(hFences[p] + temp) != horizontalFences.end()) {
        //             for(int j = 0; j < vFences.size(); j++) {
        //                 if(verticalFences.find(vFences[j] + temp) != verticalFences.end()) {
        //                     ans = temp * temp;
        //                     return ans;
        //                 }
        //             }
        //         }
        //     }
        // }

        // return ans == -1 ? -1 : ans % MOD;
    }
};