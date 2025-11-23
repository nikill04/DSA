/*
COUNT OCCURRENCES OF ANNAGRAMS: https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

Example 1:

Input: txt = "forxxorfxdofr", pat = "for"
Output: 3
Explanation: for, orf and ofr appears in the txt, hence answer is 3.
Example 2:

Input: txt = "aabaabaa", pat = "aaba"
Output: 4
Explanation: aaba is present 4 times in txt.
Constraints:
1 <= |pat| <= |txt| <= 105
Both strings contain lowercase English letters.    */



// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        unordered_map<char, int> mpp;
        for(int i = 0; i < pat.size(); i++) {
            // if(mpp.find(pat[i]) == mpp.end()) mpp.insert({pat[i], 1});
            // else mpp.at(pat[i]) += 1;
            mpp[pat[i]]++;
        }
        
        int ans = 0;
        int count = mpp.size(); // Total no. of unique characters OR no. of keys in the map
        for(int i = 0; i < pat.size(); i++) {
            if(mpp.find(txt[i]) != mpp.end()) {
                mpp.at(txt[i]) -= 1;
                if(mpp.at(txt[i]) == 0) count--;
            }
        }
        if(count == 0) ans++;

        
        for(int i = pat.size(); i < txt.size(); i++) {
            if(mpp.find(txt[i]) != mpp.end()) {
                mpp.at(txt[i]) -= 1;
                if(mpp.at(txt[i]) == 0) count--;
                if(mpp.find(txt[i - pat.size()]) != mpp.end()) {
                    if(mpp.at(txt[i - pat.size()]) == 0) count++;
                    mpp.at(txt[i - pat.size()]) += 1;
                }
            } else {
                if(mpp.find(txt[i - pat.size()]) != mpp.end()) {
                    if(mpp.at(txt[i - pat.size()]) == 0) count++;
                    mpp.at(txt[i - pat.size()]) += 1;
                }
            }
            if(count == 0) ans++;
        }
        return ans;
    }
};




/*
class Solution{
  public:
  
  int search(string pat, string txt) {
  unordered_map <char, int> m;
  for(auto i: pat)
  m[i]++;

  int k = pat.size();
  int count = m.size();
  int ans = 0;
  int i = 0, j = 0;

  while(j < txt.size()) {

  if(m.find(txt[j]) != m.end()) {
  m[txt[j]]--;

  if(m[txt[j]] == 0)
  count--;
  }

  if(j - i + 1 < k) j++;

  else if(j - i + 1 == k) {
  if(count == 0)
  ans++;

  if(m.find(txt[i]) != m.end()) {
  m[txt[i]]++;

  if(m[txt[i]] == 1)
  count++;
  }

  i++; j++;
  }
  }

  return ans;
  }
};                     */