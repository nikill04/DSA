/*
DUPLICATE IN ARRAY

Problem statement
You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

For example:

Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.
Note :
A duplicate number is always present in the given array.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <=  T  <= 10
2 <=  N <= 10 ^ 5
1 <=  ARR[i]  <= N - 1

Where 'T' denotes the number of test cases, 'N' denotes the number of elements in the array, and 'ARR[i]' denotes the 'i-th' element of the array 'ARR'.

Time limit: 1 sec
Sample Input 1:
2
5
4 2 1 3 1
7
6 3 1 5 4 3 2
Sample Output 1:
1
3
Explanation of sample input 1:
For the first test case, 
The duplicate integer value present in the array is 1. Hence, the answer is 1 in this case.

For the second test case,
The duplicate integer value present in the array is 3. Hence, the answer is 3 in this case.
Sample Input 2:
2
6 
5 1 2 3 4 2  
9
8 7 2 5 4 7 1 3 6
Sample Output 2:
2
7                    */

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr) 
{
    // Write your code here
    int ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        ans = ans ^ arr[i];
    }

    for(int i = 1; i < arr.size(); i++) {
        ans = ans ^ i;
    }
	
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cout << findDuplicate(arr) << endl;
    }
    return 0;
}

/* How to run : 
1) g++ 1_DuplicateInArray.cpp -o your_executable_name
2) ./your_executable_name           */


/*

You have:

* An array of **N** numbers: it contains numbers from `1` to `N-1`, **but one number is repeated** (the duplicate).
* Let's call the array:
  `A = [1, 2, 3, ..., x, ..., N-1, x]`
  (where `x` is the duplicate, appearing twice)

You want to find this duplicate.

```
(1 ^ 2 ^ 3 ^ ... ^ x ^ ... ^ N-1 ^ x)
^
(1 ^ 2 ^ 3 ^ ... ^ N-1)
```

This looks confusing at first, but it’s super elegant.

### ✅ XOR Properties You Need to Know:

| Property               | Meaning                              |
| ---------------------- | ------------------------------------ |
| `a ^ a = 0`            | Any number XORed with itself is zero |
| `a ^ 0 = a`            | Any number XORed with zero is itself |
| XOR is **commutative** | `a ^ b == b ^ a`                     |
| XOR is **associative** | `(a ^ b) ^ c == a ^ (b ^ c)`         |

arr = [1, 2, 3, 4, 2] // N = 5

So `N-1 = 4`, and numbers from 1 to 4 should be present.
But `2` is duplicated.

---

### Step 1: XOR all elements in the array:

```
xorArr = 1 ^ 2 ^ 3 ^ 4 ^ 2
```

### Step 2: XOR all numbers from 1 to N-1:

```
xorExpected = 1 ^ 2 ^ 3 ^ 4
```

### Step 3: XOR both results:

```
Result = xorArr ^ xorExpected
= (1 ^ 2 ^ 3 ^ 4 ^ 2) ^ (1 ^ 2 ^ 3 ^ 4)
```

Now group terms using commutativity and associativity:

```
= (1 ^ 1) ^ (2 ^ 2 ^ 2) ^ (3 ^ 3) ^ (4 ^ 4)
= 0     ^    0  ^ 2   ^    0     ^   0
= 2
```

**Only the duplicate remains!**
*/