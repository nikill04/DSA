/* MERGE AND SORT INTERVALS : https://www.hackerrank.com/contests/software-engineer-prep-kit/challenges/merge-and-sort-intervals/problem?isFullScreen=true

Given an array of intervals [startTime, endTime], merge all overlapping intervals and return a sorted array of non-overlapping intervals.

Example

Input

intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
Output

[[1, 6], [8, 10], [15, 18]]
Explanation

- Step 1: Sort intervals by start time (already sorted). 
- Step 2: Initialize merged list with first interval [1,3]. 
- Step 3: Compare [2,6] with last merged [1,3]. They overlap (2 ≤ 3), so merge into [1,6]. Step 4: Compare [8,10] with last merged [1,6]. No overlap (8 > 6), append [8,10]. 
- Step 5: Compare [15,18] with last merged [8,10]. No overlap (15 > 10), append [15,18]. 

Result: [[1,6],[8,10],[15,18]].
Input Format

The first line contains an integer denoting the number of intervals.
The second line contains an integer denoting the length of individual interval array.
Each of the next N lines contains two space-separated integers startTime and endTime
Intervals may be provided in any order; duplicates and fully contained intervals are allowed.
Example

4
2
1 3
2 6
8 10
15 18
here, 4 is the number of intervals, 2 is the length of individual interval array, followed by the intervals.

Constraints

0 <= intervals.length <= 100000
intervals[i].length == 2 for all 0 <= i < intervals.length
0 <= intervals[i][0] < intervals[i][1] <= 10^9 for all 0 <= i < intervals.length
Output Format

Return a 2D array of two space-separated integers start and end, representing the merged intervals sorted by increasing start time.
Sample Input 0

0
0
Sample Input 1

1
2
5 10
Sample Output 1

5 10                                                  */





/*
 * Complete the 'mergeHighDefinitionIntervals' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY intervals as parameter.
 */
 
// bool comparator(vector<int> p1, vector<int> p2) {
//     if(p1[0] < p2[0]) return true;
//     if(p1[0] > p2[0]) return false;
    
//     if(p1[1] < p2[1]) return true;
//     return false;
// }

vector<vector<int>> mergeHighDefinitionIntervals(vector<vector<int>> intervals) {
    int n = intervals.size();
    
    vector<vector<int>> ans;
    
    if(n == 0) return ans;
    if(n == 1) return intervals;
    
    // sort(intervals.begin(), intervals.end(), comparator);
    sort(intervals.begin(), intervals.end());
    
    int start = intervals[0][0];
    int end = intervals[0][1];
    
    for(int i = 1; i < n; i++) {
        while(i < n && intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
            i++;
        }
        
        ans.push_back({start, end});
        
        if(i < n) {
            start = intervals[i][0];
            end = intervals[i][1];
        }
        
        i--;
/* 
    Why i-- is necessary?

    1. Your `while` loop increments `i`
    2. The `for` loop also increments `i`

    So `i` gets incremented *twice*, which can skip intervals.

    Let's walk through it step-by-step.

    ---

    # Example

    Intervals:

    ```
    [1,4]
    [2,3]
    [5,7]
    ```

    After sorting:

    ```
    [1,4] [2,3] [5,7]
    ```

    Initial values:

    ```
    start = 1
    end = 4
    ```

    ---

    # Iteration without `i--`

    ### Start of loop

    ```
    i = 1
    ```

    ### While loop

    Condition:

    ```
    intervals[1][0] <= end
    2 <= 4  -> true
    ```

    So inside while:

    ```
    end = max(4,3) = 4
    i++ -> i = 2
    ```

    Now check again:

    ```
    intervals[2][0] <= end
    5 <= 4 -> false
    ```

    Exit while.

    ---

    Now your code pushes:

    ```
    [1,4]
    ```

    Then:

    ```
    start = intervals[2][0] = 5
    end = intervals[2][1] = 7
    ```

    Now `for` loop increments `i` automatically:

    ```
    i = 3
    ```

    But `n = 3`.

    So loop ends.

    `[5,7] never gets pushed.`
*/
    }
    
    return ans;
}