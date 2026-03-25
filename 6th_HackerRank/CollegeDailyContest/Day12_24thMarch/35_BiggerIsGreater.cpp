/* BIGGER IS GREATER : https://www.hackerrank.com/contests/iiits-ytp-2403/challenges/bigger-is-greater

Lexicographical order is often known as alphabetical order when dealing with strings. A string is greater than another string if it comes later in a lexicographically sorted list.

Given a word, create a new word by swapping some or all of its characters. This new word must meet two criteria:

It must be greater than the original word
It must be the smallest word that meets the first condition
Example

The next largest word is .

Complete the function biggerIsGreater below to create and return the new string meeting the criteria. If it is not possible, return no answer.

Function Description

Complete the biggerIsGreater function in the editor below.

biggerIsGreater has the following parameter(s):

string w: a word
Returns
- string: the smallest lexicographically higher string possible or no answer

Input Format

The first line of input contains , the number of test cases.
Each of the next  lines contains .

Constraints

 will contain only letters in the range ascii[a..z].
Sample Input 0

5
ab
bb
hefg
dhck
dkhc
Sample Output 0

ba
no answer
hegf
dhkc
hcdk
Explanation 0

Test case 1:
ba is the only string which can be made by rearranging ab. It is greater.
Test case 2:
It is not possible to rearrange bb and get a greater string.
Test case 3:
hegf is the next string greater than hefg.
Test case 4:
dhkc is the next string greater than dhck.
Test case 5:
hcdk is the next string greater than dkhc.
Sample Input 1

6
lmno
dcba
dcbb
abdc
abcd
fedcbabcd
Sample Output 1

lmon
no answer
no answer
acbd
abdc
fedcbabdc                                         */





string biggerIsGreater(string w) {
    /*
    APPROACH:
    1. Traverse from right to find the first index (pivot) where w[i] > w[i-1].
    2. From the suffix (right side), pick the smallest character strictly greater than w[i-1].
    3. Replace pivot with that character.
    4. Rebuild the remaining suffix in sorted order -> gives next lexicographical string.
    */

    int n = w.size();
    string ans = "";

    map<int, int> mp;   // First one is the character and second "int" is the count how many times it appeared until now(while we traverse in the below for loop).
    vector<int> vec;    // suffix elements for searching next greater

    for(int i = n - 1; i >= 0; i--) {
        mp[(int)w[i]]++;

        if(i > 0 && w[i] > w[i - 1]) {   // => i.e., if suppose the element is found(where current character is greater than it's previous character)
            mp[(int)w[i - 1]]++;         // Now increase the count of the before the character also.

            ans = w.substr(0, i - 1);    // Now create a string which is same as until 0 to i - 1 characters of the original string.

            sort(vec.begin(), vec.end());

            int k = 0;
            while(k < (int)vec.size() && w[i - 1] >= vec[k]) {    // Find smallest character until now(from (i + 1) to end of the w)) where that element is greater than the (i - 1)th character.
                k++;
            }

            if(k < (int)vec.size()) {       // If such a character is found(The above while loop).
                ans += (char)vec[k];
                mp[vec[k]]--;
            } else {                        // If such a character is not found
                ans += w[i];
                mp[(int)w[i]]--;
            }

            // rebuild suffix in sorted order
            for(auto &p : mp) {
                while(p.second > 0) {
                    ans += p.first;
                    p.second--;
                }
            }

            break;
        }

        vec.push_back((int)w[i]);
    }

    if(ans.size() < w.size()) return "no answer";
    return ans;
}