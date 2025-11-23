/*
STOCK SPAN PROBLEM: https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days. The span arr[i] of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the given day is less than or equal to its price on the current day.

Examples:

Input: arr[] = [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]
Explanation: Traversing the given input span 100 is greater than equal to 100 and there are no more elements behind it so the span is 1, 80 is greater than equal to 80 and smaller than 100 so the span is 1, 60 is greater than equal to 60 and smaller than 80 so the span is 1, 70 is greater than equal to 60,70 and smaller than 80 so the span is 2 and so on.  Hence the output will be 1 1 1 2 1 4 6.
Input: arr[] = [10, 4, 5, 90, 120, 80]
Output: [1, 1, 2, 4, 5, 1]
Explanation: Traversing the given input span 10 is greater than equal to 10 and there are no more elements behind it so the span is 1, 4 is greater than equal to 4 and smaller than 10 so the span is 1, 5 is greater than equal to 4,5 and smaller than 10 so the span is 2,  and so on. Hence the output will be 1 1 2 4 5 1.
Constraints:
1 ≤ arr.size()≤ 105
1 ≤ arr[i] ≤ 105             */


class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        stack<pair<int, int>> st;
        int temp;
        for(int i = 0; i < arr.size(); i++) {
            temp = arr[i];
            while(!st.empty() && arr[i] >= st.top().first) {
                st.pop();
            }
            if(st.empty()) {
                arr[i] = i + 1;
            }
            else {
                arr[i] = i - st.top().second;
            }
            st.push({temp, i});
        }
        return arr;
    }
};




/*
vector <int> calculateSpan(int price[], int n)
{
  vector <int> v; // creating vector to store result 
  stack<pair<int,int>> s; // creating the pair stack
  for (int i=0;i<n;i++)
  {
    if(s.size()==0) // when stack is empty return -1;
    {
      v.push_back(-1);
    }
    else if (s.size()>0 && s.top().first>price[i]) // when there is element in stack and stack top is greater then array element 
    {
      v.push_back(s.top().second); // take stack top in the result vector 
    }
    else if (s.size()>0 && s.top().first<=price[i] ){ // when there is element in stack and that element is less then array element 
      while (s.size()>0 && s.top().first<=price[i] )// upto when there is element and stack top is less then array's element delete the element from stack
      {
        s.pop(); // delete the element from stack
      }
      if(s.size()==0) // when stack became empty return -1
      {
        v.push_back(-1);
      }
    else
        {
          v.push_back(s.top().second); // else push stack top in the vector 
        }
      }
      s.push({price[i],i}); // take price array and index i inside pair stack
    }
    for (int i=0;i<v.size();i++)
    {
       v[i]=i-v[i]; // subtract normal index from the vector index v[i]
    }
    return v;
  }
};              */