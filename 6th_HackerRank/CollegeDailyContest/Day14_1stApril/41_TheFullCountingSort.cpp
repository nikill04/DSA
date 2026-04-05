/* THE FULL COUNTING SORT : https://www.hackerrank.com/contests/iiits-ytp2026-0104/challenges/countingsort4

Use the counting sort to order a list of strings associated with integers. If two strings are associated with the same integer, they must be printed in their original order, i.e. your sorting algorithm should be stable. There is one other twist: strings in the first half of the array are to be replaced with the character - (dash, ascii 45 decimal).

Insertion Sort and the simple version of Quicksort are stable, but the faster in-place version of Quicksort is not since it scrambles around elements while sorting.

Design your counting sort to be stable.

Example
arr = [[0, 'a'], [1, 'b'], [0, 'c'], [1, 'd']]
The first two strings are replaced with '-'. Since the maximum associated integer is 1, set up a helper array with at least two empty arrays as elements. The following shows the insertions into an array of three empty arrays.

i	string	converted	list
0				[[],[],[]]
1 	a 	-		[[-],[],[]]
2	b	-		[[-],[-],[]]
3	c			[[-,c],[-],[]]
4	d			[[-,c],[-,d],[]]
The result is then printed: - c - d .

Function Description

Complete the countSort function in the editor below. It should construct and print the sorted strings.

countSort has the following parameter(s):

string arr[n][2]: each arr[i] is comprised of two strings, x and s
Returns
- Print the finished array with each element separated by a single space.

Note: The first element of each arr[i], x , must be cast as an integer to perform the sort.

Input Format

The first line contains n, the number of integer/string pairs in the array arr.
Each of the next n contains x[i] and s[i], the integers (as strings) with their associated strings.

Constraints
1 <= n <= 10^6
n is even
1 <= |s| <= 10
0 <= x < 100, x belongs to arr


s[i] consists of characters in the range ascii[a-z].

Output Format

Print the strings in their correct order, space-separated on one line.

Sample Input

20
0 ab
6 cd
0 ef
6 gh
4 ij
0 ab
6 cd
0 ef
6 gh
0 ij
4 that
3 be
0 to
1 be
5 question
1 or
2 not
4 is
2 to
4 the
Sample Output

- - - - - to be or not to be - that is the question - - - -
Explanation

The correct order is shown below. In the array at the bottom, strings from the first half of the original array were replaced with dashes.

0 ab
0 ef
0 ab
0 ef
0 ij
0 to
1 be
1 or
2 not
2 to
3 be
4 ij
4 that
4 is
4 the
5 question
6 cd
6 gh
6 cd
6 gh
sorted = [['-', '-', '-', '-', '-', 'to'], ['be', 'or'], ['not', 'to'], ['be'], ['-', 'that', 'is', 'the'], ['question'], ['-', '-', '-', '-'], [], [], [], []]                                                */








/* QUESTION EXPLANATION :

### **The Goal**
You are given a list of pairs. Each pair contains a number and a string (a word). Your goal is to sort this list based on the numbers, but with a specific "twist" applied to the strings before you finish. 

### **The Three Rules**

**1. The "First-Half Twist" (The Dash Rule)**
Before you worry about sorting, you have to modify the data. 
* Count the total number of pairs you have (let's call this $n$). 
* Cut that list exactly in half. 
* For every pair in the **first half** of the list, throw away the string and replace it with a single dash (`"-"`). 
* The strings in the **second half** of the list stay exactly as they are.

**2. The Sort**
Now, sort the entire list in ascending order based **only** on the number in each pair. 

**3. The "Stability" Rule**
"Stable" is just a fancy computer science term that means: **respect the original line order**. 
* If two pairs have the exact same number, they must stay in the same relative order they were in before you sorted them. 
* For example, if you have `[0, "-"]` and `[0, "apple"]`, and the dash came first in the original list, the dash must still come first in your final sorted list.

### **The Final Output**
Once the list is sorted according to the numbers, you ignore the numbers entirely. You just take the strings (and your newly placed dashes) and print them all out on a single line, separated by spaces.

---

### **Looking at the Example**
Let's look at the very first small example they gave you to see these rules in action:
`arr = [[0, 'a'], [1, 'b'], [0, 'c'], [1, 'd']]`

* **Apply Rule 1 (The Twist):** There are 4 pairs. The first half is the first 2 pairs. Replace 'a' and 'b' with dashes. 
  * *Modified List:* `[[0, '-'], [1, '-'], [0, 'c'], [1, 'd']]`
* **Apply Rule 2 & 3 (The Sort & Stability):** Sort by the numbers (0s first, then 1s). Keep ties in their original order.
  * *The 0s:* `[0, '-']` came before `[0, 'c']`, so they stay in that order.
  * *The 1s:* `[1, '-']` came before `[1, 'd']`, so they stay in that order.
  * *Sorted List:* `[[0, '-'], [0, 'c'], [1, '-'], [1, 'd']]`
* **Apply the Output Rule:** Drop the numbers and print the strings.
  * *Result:* `- c - d`*/

/*
 * Complete the 'countSort' function below.
 *
 * The function accepts 2D_STRING_ARRAY arr as parameter.
 */


// RECTIFICATION 1: Fast comparison without stoi()
bool comparator(const vector<string> & vec1, const vector<string> & vec2) {
    // If one number has fewer digits, it is strictly smaller
    if (vec1[0].length() != vec2[0].length()) {
        return vec1[0].length() < vec2[0].length();
    }
    // If they have the same amount of digits, alphabetical order works!
    return vec1[0] < vec2[0];
}

// RECTIFICATION 2: Added the '&' to avoid copying the massive array
void countSort(vector<vector<string>>& arr) {
    int n = arr.size();
    
    for(int i = 0; i < n / 2; i++) {
        arr[i][1] = "-";
    }
    
    stable_sort(arr.begin(), arr.end(), comparator);
    
    for(int i = 0; i < n; i++) {
        cout << arr[i][1] << " ";
    }

    return;
}
/* 
Here in comparator, vec1[0] and vec2[0] are in string formats even though represent numbers. So, if we compare them directly, it may lead to wrong results.
For Ex: if vec1[0] = "10" and vec2 = "2", eventhough 2 is less than 10, here as it is in string format it compares the first character and which are '1' and '2' and gives the result vec1[0] < vec2[0]. 
We can use "stoi()"[string to integer] function which takes string as input and converst into integer, for a big number it adds a additional time complexity every converting and comparing. So, we did as current version of the code(in comparator function).

What is "stable_sort" function, it is also a sort function

### **1. Why `std::sort` fails (Stability)**
`std::sort` uses **QuickSort/IntroSort**. These algorithms are **unstable**, meaning they do not guarantee the relative order of elements with equal keys.
* **The Problem:** If the input has `[0, "a"]` followed by `[0, "b"]`, an unstable sort might output them as `b` then `a`.
* **The Requirement:** The problem specifically mandates that elements with the same integer must appear in their **original input order**.
* **The Solution:** Use `std::stable_sort`, which typically uses **MergeSort**. It is designed to preserve the original relative order of equal elements.

### **2. Why the Comparator is necessary**
`std::stable_sort` needs a custom comparator because the default behavior is incorrect for this data structure.
* **Default Behavior:** Without a comparator, C++ compares `vector<string>` lexicographically (alphabetically).
* **The Issue:** Alphabetically, the string `"10"` comes **before** `"2"`.
* **The Fix:** The comparator tells the algorithm to interpret the first string as a numeric value (either via `stoi` or length comparison) so that `2` correctly comes before `10`.

### **3. Why `std::sort` cannot be made stable via the Comparator**
A comparator only compares two elements at a time. It returns `true` or `false` based on which should come first. 
* **The Limitation:** If two elements have the same integer (e.g., `0` and `0`), the comparator returns `false` for both `A < B` and `B < A`. 
* **The Result:** When the comparator signals a tie, an unstable algorithm like `std::sort` is free to swap them to optimize memory or speed. Since the elements don't store their original index, the comparator has no way to tell the algorithm, "Keep these in their original spots."

### **4. If stable_sort already guarantees stability, why do we still need to pass it our comparator?
A sorting algorithm like `std::stable_sort` manages **how** to move elements, but it does not know **what** criteria to use for the comparison.

    ### **1. Data Type Compatibility**
    The default behavior of `std::stable_sort` is to use the ` < ` operator. 
    * Your data is a `vector<vector<string>>`.
    * By default, C++ compares `vector<string>` lexicographically (alphabetical order).
    * Without a comparator, the algorithm will sort your numbers as strings (e.g., `"10"` comes before `"2"`).

    ### **2. Logic vs. Stability**
    * **Stability** is a property of the **algorithm** (it ensures equal items don't swap).
    * **Comparison** is a property of the **logic** (it defines what "equal" means).

    Even though the algorithm guarantees stability for "equal" items, it needs the comparator to identify which items are equal and which are "less than" based on the integer value of the string, not the string's alphabetical order.

    ### **3. Operational Flow**
    1. **The Comparator** converts the strings to integers and tells the algorithm: "Item A is mathematically smaller than Item B."
    2. **The Algorithm (`stable_sort`)** uses that information to position the elements.
    3. **When a Tie Occurs:** If the comparator indicates that two items have the same integer value, the "stable"              nature of the algorithm kicks in and ensures their relative input order is preserved.
    
    
    
Using `const` and `&` in your comparator parameters is about two things: **Efficiency** and **Compiler Rules**.

### **1. The Ampersand (`&`) for Efficiency**
The `&` means **Pass by Reference**.
* **Without `&` (Pass by Value):** Every time the sort compares two items, C++ makes a complete copy of both `vector<string>` objects. In a list of $10^6$ items, this results in tens of millions of unnecessary memory allocations.
* **With `&`:** C++ simply points to the original data in memory. This eliminates the copying overhead and prevents **Time Limit Exceeded (TLE)** errors.

### **2. The `const` for Compiler Requirements**
The `const` means **Read-Only**.
* **The Rule:** Sorting algorithms like `std::stable_sort` often handle "temporary" or "read-only" versions of your data during the sorting process.
* **The Conflict:** If your comparator uses a regular reference (`vector<string>&`), you are telling the compiler you might **modify** the data.
* **The Error:** The compiler will refuse to pass a "read-only" item into a function that hasn't promised to keep it `const`. Adding `const` is your promise to the compiler that the comparator will only read the data, not change it.

### **Summary**
* **`&`** makes the code **faster** by avoiding copies.
* **`const`** makes the code **compile** by ensuring data safety.
*/