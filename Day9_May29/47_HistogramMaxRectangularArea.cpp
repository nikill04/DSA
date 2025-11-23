/*
HISTOGRAM MAX RECTANGULAR AREA: https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

You are given a histogram represented by an array arr, where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit.

Your task is to find the largest rectangular area possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.

Examples:

Input: arr[] = [60, 20, 50, 40, 10, 50, 60]
 Largest-Rectangular-Area-in-a-Histogram
Output: 100
Explanation: We get the maximum by picking bars highlighted above in green (50, and 60). The area is computed (smallest height) * (no. of the picked bars) = 50 * 2 = 100.
Input: arr[] = [3, 5, 1, 7, 5, 9]
Output: 15
Explanation:  We get the maximum by picking bars 7, 5 and 9. The area is computed (smallest height) * (no. of the picked bars) = 5 * 3 = 15.
Input: arr[] = [3]
Output: 3
Explanation: In this example the largest area would be 3 of height 3 and width 1.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 104             */


class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        // 1) This one is optimal, TIME - O(n) & SPACE - O(n)
        stack<pair<int, int>> s1, s2;
        vector<int> vec1, vec2;
        vec2.resize(arr.size());
        
        int maxi = 0;
        
        for(int i = 0 ; i < arr.size(); i++) {
            while(!s1.empty() && s1.top().first >= arr[i]) {
                s1.pop();
            }
            if(s1.empty()) vec1.push_back(i + 1);
            else vec1.push_back(i - s1.top().second);
            s1.push({arr[i], i});
        }
        
        for(int j = arr.size() - 1 ; j >= 0 ; j--) {
            while(!s2.empty() && s2.top().first >= arr[j]) {
                s2.pop();
            }
            if(s2.empty()) vec2[j] = (arr.size() - j) - 1;
            else vec2[j] = (s2.top().second - j) - 1;
            s2.push({arr[j], j});
            
            maxi = max(maxi, arr[j] * (vec1[j] + vec2[j]));
        }
        
        return maxi;
        
        
        // 2) TIME - O(n^2) & SPACE - O(1), not optimal
        // int i = 0, j = 0, z = 0, max = 0, count = 0;
        // for( ; i < arr.size(); i++) {
        //     count = 0;
        //     int height = arr[i];
        //     for(j = i ; j < arr.size(); j++) {
        //         if(arr[j] < arr[i]) {
        //             break;
        //         }
        //     }
        //     for(z = i - 1; z >= 0; z--) {
        //         if(arr[z] < arr[i]) {
        //             break;
        //         }
        //         count++;
        //     }
        //     if(height * ((j - i) + count) > max) {
        //         max = height * ((j - i) + count);
        //     }
        // }
        // return max;
    }
};





/*
long long getMaxArea(long long arr[], int n)
  {
  vector<int> left,right;
  stack<pair<int,int>> s1,s2;
  int pseudo_index =-1;
  int pseudo_index1 =n;
  for (int i=0;i<n;i++)
  {
    if (s1.size()==0)
    {
      left.push_back(pseudo_index);
    }
    else if (s1.size()>0 && s1.top().first<arr[i])
    {
      left.push_back(s1.top().second);
    }
    else if (s1.size()>0 && s1.top().first>=arr[i])
    {
       while(s1.size()>0 && s1.top().first>=arr[i])
       {
         s1.pop();
       }
      if (s1.size()==0)
      {
        left.push_back(pseudo_index);
      }
      else
      {
        left.push_back(s1.top().second);
      }
        
      }
  s1.push({arr[i],i});
}
for (int i=n-1;i>=0;i--)
{
  if (s2.size()==0)
  {
    right.push_back(pseudo_index1);
  }
  else if (s2.size()>0 && s2.top().first<arr[i])
  {
    right.push_back(s2.top().second);
  }
  else if (s2.size()>0 && s2.top().first >= arr[i])
  {
    while(s2.size()>0 && s2.top().first >= arr[i])
    {
      s2.pop();
    }
    if (s2.size()==0)
    {
      right.push_back(pseudo_index1);
    }
    else
    {
      right.push_back(s2.top().second);
    }
  }
  s2.push({arr[i],i});
}
  
reverse(right.begin(),right.end());
    long long m=INT_MIN;
    for (long long i=0;i<n;i++)
    {
      m=max(m,(right[i]-left[i]-1)*arr[i]); // taking max after finding area
    }
    return m;
  }
};    */