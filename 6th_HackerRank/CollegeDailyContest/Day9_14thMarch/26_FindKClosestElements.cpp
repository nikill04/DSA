/* FIND K CLOSEST ELEMENTS : https://www.hackerrank.com/contests/iiits-ytp2026-1403/challenges/find-k-closest-elements-2-1/problem

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or

|a - x| == |b - x| and a < b

Input Format

The first line contains an integer N, the size of the array arr.

The second line contains N space-separated integers representing the sorted array arr.

The third line contains an integer k, the number of closest elements to find.The fourth line contains an integer x, the target value.

Constraints

image

Output Format

A single line containing k space-separated integers, representing the closest elements in ascending order.

Sample Input 0

5
1 2 3 4 5
4
3
Sample Output 0

1 2 3 4
Sample Input 1

5
1 2 3 4 5
4
-1
Sample Output 1

1 2 3 4                                      */





vector<int> findClosestElements(vector<int> arr, int k, int x) {
    int n = arr.size();
    
    vector<int> answer;
    
    int i = 0;
    for( ; i < n; i++) {
        if(x <= arr[i]) 
            break;
    }
    
    int count = 0;
    int p = i - 1;
    int q = i;
    while(p >= 0 && q < n && count < k) {
        if(abs(arr[p] - x) <= abs(arr[q] - x)) {
            answer.push_back(arr[p]);
            p--;
        }
        else {
            answer.push_back(arr[q]);
            q++;
        }
        count++;
    }
    
    while(p >= 0 && count < k) {
        answer.push_back(arr[p]);
        count++;
        p--;
    }
    
    while(q < n && count < k) {
        answer.push_back(arr[q]);
        count++;
        q++;
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}