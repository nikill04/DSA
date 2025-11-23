/*
TOP K FREQUENT ELEMENTS: https://leetcode.com/problems/top-k-frequent-elements/description/

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.          */








class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    //     vector<int> vec;
    //     unordered_map<int, int> mp;
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //     for(int i = 0; i < nums.size(); i++) {
    //         mp[nums[i]]++;
    //     }

    //     for(auto it: mp) {
    //         pq.push({it.second, it.first});

    //         if(pq.size() > k) pq.pop();
    //     }

    //     // for(auto it: pq) {
    //     //     vec.push_back(pq.top().second);
    //     // }
    //     // A priority_queue does not support begin() and end() iterators. You can’t use a range-based for loop on it!

    //     while(!pq.empty()) {
    //        vec.push_back(pq.top().second);
    //        pq.pop(); 
    //     }

    //     return vec;



        vector<int> vec;
        priority_queue<int> pq;
        unordered_map<int, int> mp;

        for(auto it: nums) {
            mp[it]++;   // not mp[nums[it]]++
        }

        for(auto it = mp.begin(); it != mp.end(); it++) {    // it < mp.end() throws error
            pq.push(it -> second);   // it.second throws error
            /* When using iterators, you must use the '->' operator to access members, not the '.' operator.
                it is an iterator object, not the actual key-value pair, so you need to dereference it first.
                "it->second" is correct syntax for accessing the value part of the key-value pair. */
        }
        /* 
        unordered_map iterators are not random-access.
        They’re more like list iterators — they can be incremented with ++ and compared for equality (== or !=), but they do not support < or >.
        
        In C++, containers provide iterators, but not all iterators are the same!
        They fall into categories:
        Random-access iterators → can do <, >, <=, >=, +, -.
        Bidirectional iterators → can only ++ and --.
        Forward iterators → can only ++.
        Input/Output iterators → very limited.
        So:
        Category	            Examples	          Supports < ?
        Random-access	vector, array, deque	        ✅ Yes
        Bidirectional	list, set, map, unordered_map	❌ No
        Forward	        forward_list	                ❌ No
        Input/Output	istream_iterator	            ❌ No

        📌 2️⃣ Why does unordered_map fail for < ?
        unordered_map provides bidirectional iterators.
        Bidirectional means: you can move forward (++) and backward (--), and check equality (==, !=).
        But there’s no ordering between iterators because the elements are not stored in contiguous memory — they’re spread in buckets (hash table).
        So it < mp.end() is invalid because the iterators have no “less than” relationship.      */

        int minFre = 0;
        while(k-- && !pq.empty()) {
            minFre = pq.top();

            pq.pop();
        }

        for(auto it = mp.begin(); it != mp.end(); it++) {    // it < mp.end() throws error.
            if(it -> second >= minFre) {   
                vec.push_back(it -> first);    // similarly as above it.first throws error
            }
        }

        return vec;
    }
};