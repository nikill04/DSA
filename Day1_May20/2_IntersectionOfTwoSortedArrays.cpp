/*
INTERSECTION OF TWO SORTED ARRAYS

Problem statement
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

Note :
1. The length of each array is greater than zero.
2. Both the arrays are sorted in non-decreasing order.
3. The output should be in the order of elements that occur in the original arrays.
4. If there is no intersection present then return an empty array.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 100
1 <= N, M <= 10^4
0 <= A[i] <= 10^5
0 <= B[i] <= 10^5

Time Limit: 1 sec
Sample Input 1 :
2
6 4
1 2 2 2 3 4
2 2 3 3
3 2
1 2 3
3 4  
Sample Output 1 :
2 2 3
3   
Explanation for Sample Input 1 :
For the first test case, the common elements are 2 2 3 in both the arrays, so we print it.

For the second test case, only 3 is common so we print 3.
Sample Input 2 :
2
3 3 
1 4 5
3 4 5
1 1
3
6
Sample Output 2 :
4 5
-1                       */

#include <bits/stdc++.h> 
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	vector<int> vec;
	
	// int *ptr1 = arr1.data();
	// int *ptr2 = arr2.data();

	// for( ;ptr1 < arr1.data() + n && ptr2 < arr2.data() + m; ) {
	// 	if(*ptr1 == *ptr2) {
	// 		vec.push_back(*ptr1);
	// 		ptr1++;
	// 		ptr2++;
	// 	} else if(*ptr1 > *ptr2) {
	// 		*ptr2++;
	// 	} else {
	// 		*ptr1++;
	// 	}
	// }

	int i = 0, j = 0;
	while (i < n && j < m) {
		if(arr1[i] == arr2[j]) {
			vec.push_back(arr1[i++]);
			j++;
		} else if(arr1[i] < arr2[j]) {
			i++;
		} else {
			j++;
		}
	}
	return vec;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr1(n), arr2(m);
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
        }

        vector<int> result = findArrayIntersection(arr1, n, arr2, m);
        if (result.empty()) {
            cout << -1 << endl;
        } else {
            for (int num : result) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    return 0;
}