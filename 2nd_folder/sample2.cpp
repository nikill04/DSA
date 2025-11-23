/* 
Given a 2d integer array arr[][] of size k*n, where each row is sorted in ascending order. Your task is to find the smallest range [l, r] that includes at least one element from each of the k lists. If more than one such ranges are found, return the first one.

Examples:
//4 7 9 12 15 0 8 10 14 20 6 12 16 30 50
Input: n = 5, k = 3, arr[][] = [[4, 7, 9, 12, 15], [0, 8, 10, 14, 20], [6, 12, 16, 30, 50]]
Output: [6, 8]
Explanation: Smallest range is formed by  number 7 from the first list, 8 from second list and 6 from the third list.
Input: n = 5, k = 3, arr[][] = [[1, 3, 5, 7, 9], [0, 2, 4, 6, 8], [2, 3, 5, 7, 11]]
Output: [1, 2]
Explanation: Smallest range is formed by number 1 present in first list and 2 is present in both 2nd and 3rd list.
Input: n = 2, k = 3, arr[][] = [[2, 4], [1, 7], [20, 40]]
Output: [4, 20]
Explanation: Smallest range is formed by number 4 from the first list, 7 from second list and 20 from the third list.
Constraints:
1 <= k, n <= 500
0 <= arr[ i ] <= 105                  */

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findSmallestRange(vector<vector<int>>& arr) {
            // code here
            vector<pair<int, int>> vec;
            for(int i = 0; i < arr.size(); i++) {
                for(int j = 0; j < arr[0].size(); j++) {
                    vec.push_back({arr[i][j], i});
                }
            }
            sort(vec.begin(), vec.end());
            for(auto it: vec) {
                cout << "(" << it.first << ", " << it.second << ")" << endl;
            }
            cout << "Our Vector Size: " << vec.size() << ", Our no. of rows in Original Array: " << arr.size() << endl;

            int y1 = arr.size();
            int arr1[y1];
            int arr2[y1];
            int arr3[vec.size() - y1 + 1];
            int arr4[y1];
            int arr5[y1];
            for(int i = 0; i <= vec.size() - y1; i++) {
                fill(arr1, arr1 + y1, 0);
                fill(arr2, arr2 + y1, 0);

                int x = 0;
                int k = 0;
                for(int j = i; j < vec.size(); j++) {
                    int y = 1;
                    auto it = vec.begin() + j;
                    if(arr1[(*it).second] != 1) arr2[x++] = (*it).first;
                    arr1[(*it).second] = 1;
                    for(int z = 0; z < y1; z++) {
                        y = y & arr1[z]; 
                    }
                    if(y == 1) {
                        k = 1;
                        break;
                    }
                }
                if(k == 1) arr3[i] = arr2[--x] - arr2[0];
                else arr3[i] = 99999999; // max possible number
            }
            int min = *min_element(arr3, arr3 + (sizeof(arr3) / sizeof(arr3[0])));
            int a;
            for(a = 0; a <= vec.size() - y1; a++) {
                if(arr3[a] == min) break;
            }
            int x = 0;
            fill(arr4, arr4 + y1, 0);
            fill(arr5, arr5 + y1, 0);

            for(int j = a; j < vec.size(); j++) {
                int y = 1;
                auto it2 = vec.begin() + j;
                if(arr4[(*it2).second] != 1) arr5[x++] = (*it2).first;
                arr4[(*it2).second] = 1;
                for(int z = 0; z < y1; z++) {
                    y = y & arr4[z];
                }
                if(y == 1) break;
            }
            return {arr5[0], arr5[--x]}; 
        }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
    
    }
    return 0;
}