/* GREEDY FLORIST : https://www.hackerrank.com/contests/iiits-ytp2026-2003/challenges/greedy-florist

*/





int getMinimumCost(int k, vector<int> c) {
    int n = c.size();
    
    sort(c.begin(), c.end());
    
    // if(k >= n) return accumulate(c.begin(), c.end(), 0);
    
    int cost = 0;
    int number = 0;
    for(int i = n - 1; i >= 0; ) {
        int j = i;
        while(j >= 0 && j > i - k) {
            cost += (number + 1) * c[j];
            j--;
        } 
        number++;
        
        i = i - k;
    }
    
    return cost;
}