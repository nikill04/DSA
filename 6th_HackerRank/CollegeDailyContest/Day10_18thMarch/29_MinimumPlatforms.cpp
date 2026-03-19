/* MINIMUM PLATFORMS : https://www.hackerrank.com/contests/iiits-ytp2026-1803/challenges/minimum-platforms-11-1

Given the arrival arr[] and departure dep[] times of  trains on the same day at a railway station, find the minimum number of platforms needed so that no train has to wait.A platform cannot serve two trains at the same time. If a train arrives at the exact same minute that another train departs (i.e., arr[i] == dep[j]), they are considered to be overlapping, and an extra platform is needed.

Note: Time intervals are given in a 24-hour integer format (HHMM), where the first one or two digits represent the hour (0 to 23) and the last two digits represent the minutes (00 to 59). For example, 9:00 AM is represented as 900, and 11:30 PM is represented as 2330.

Input Format

The first line contains an integer , the number of trains.

The second line contains  space-separated integers representing the arrival times arr.

The third line contains  space-separated integers representing the departure times dep.

Constraints


All times are valid 24-hour times.

Output Format

A single integer representing the minimum number of platforms required.

Sample Input 0

6
900 940 950 1100 1500 1800
910 1200 1120 1130 1900 2000
Sample Output 0

3
Sample Input 1

3
900 1100 1235
1000 1200 1240
Sample Output 1

1                      */






int findPlatform(vector<int> arr, vector<int> dep) {
    int n = arr.size();
    
    vector<pair<int, int>> train;
    
    for(int i = 0; i < n; i++) {
        train.push_back({arr[i], dep[i]});
    }
    
    sort(train.begin(), train.end());
    
    stack<pair<int, int>> st;
    
    int maxi = 1;
    for(int i = 0; i < n; i++) {
        // train[i].second <= st.top().second
        if(st.empty() || train[i].first <= st.top().second) {
            st.push({train[i].first, train[i].second});
            maxi = max(maxi, (int)st.size());
        }
        else {
            stack<pair<int, int>> emptyStack;
            st.swap(emptyStack);
        }
        
    }
    
    return maxi;
}   