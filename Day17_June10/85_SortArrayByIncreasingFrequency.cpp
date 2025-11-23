/*
SORT ARRAY BY INCREASING FREQUENCY: https://leetcode.com/problems/sort-array-by-increasing-frequency/description/

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100                               */








class Solution {
public:
    static bool comparator(pair<int, int> a, pair<int, int> b) {  // use static here, don't forget
        if(a.second < b.second) return true;        
        else if(a.second > b.second) return false;
        else if(a.first > b.first) return true;
        else return false;
    }

    vector<int> frequencySort(vector<int>& nums) {  
        // unordered_map<int, int> mp;
        // for(int i : nums) {
        //     mp[i]++;
        // }

        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // for(auto [num, count] : mp) {
        //     pq.push({count, -num});
        // }

        // int index = 0;
        // while(!pq.empty()) {
        //     for(int i = pq.top().first; i > 0; i--) {
        //         nums[index++] = -pq.top().second;
        //     }
        //     pq.pop();
        // }

        // return nums;




        unordered_map<int, int> mp;

        for(auto i : nums) {
            mp[i]++;
        }

        vector<pair<int, int>> vec(mp.begin(), mp.end());
        /*
        // OR
        vector<pair<int, int>> vec;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            vec.push_back(*it);
        }     

        // OR
        vector<pair<int, int>> vec(mp.size());
        copy(mp.begin(), mp.end(), vec.begin());

        // OR
        vector<pair<int, int>> vec;
        vec.insert(vec.end(), mp.begin(), mp.end());  

        // OR
        vector<pair<int, int>> vec;
        for (const auto &p : mp) {
            vec.push_back(p);
        }


        for (auto p : mp) { ... }
            p is a copy of each pair.
            For each iteration, the compiler copies the pair.
        for (auto &p : mp) { ... }
            Now p is a reference to the pair inside the map.
            No copy is made.
            
        const → “I won’t modify it”
        const says: “I promise I won’t change this pair.”
        This helps the compiler optimize — and it prevents bugs.
        If you try to do p.first = 10; it will now give an error       
        */

        sort(vec.begin(), vec.end(), comparator);
        // OR you can use comparator like lambda function as like below
        // sort(vec.begin(), vec.end(), [](pair<int,int> a, pair<int,int> b) {
        //     if (a.second < b.second) return true;
        //     else if (a.second > b.second) return false;
        //     else return a.first > b.first;
        // });


        int i = 0;
        for(auto k : vec) {
            for(int j = 0; j < k.second; j++) {
                nums[i++] = k.first;
            }
        }

        return nums;




        // unordered_map<int, int> freq;

        // for(int i : nums) {
        //     freq[i]++;
        // }

        // sort(nums.begin(), nums.end(), [&](int a, int b) {
        //     if(freq[a] == freq[b]) {
        //         return a > b;
        //     } else {
        //         return freq[a] < freq[b];
        //     }
        // });
        // /*
        // In C++, when you write a lambda, the part inside [] is called the capture list.
        // It tells the compiler which variables from the surrounding scope the lambda can access, and how.
        // [&] → Capture all variables from the enclosing scope by reference.
        // [=] → Capture all variables by value (makes a copy).
        // [&freq] → Capture only freq by reference.
        // [freq] → Capture only freq by value.

        // If you write [=] or [freq], you are capturing freq by value, so the lambda gets a copy of freq.
        // This is fine for reading — because freq is not modified inside the lambda.

        // [] → capture nothing → you can only use variables that are:
        // Passed as lambda arguments (a and b are fine).
        // Or global variables (not the case here).*/

        // return nums;
    }
};