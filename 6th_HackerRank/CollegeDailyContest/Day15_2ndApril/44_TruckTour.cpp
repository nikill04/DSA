/* TRUCK TOUR : https://www.hackerrank.com/contests/iiits-ytp2026-0204/challenges/truck-tour 

Suppose there is a circle. There are N petrol pumps on that circle. Petrol pumps are numbered 0 to N-1 (both inclusive). You have two pieces of information corresponding to each of the petrol pump: (1) the amount of petrol that particular petrol pump will give, and (2) the distance from that petrol pump to the next petrol pump.

Initially, you have a tank of infinite capacity carrying no petrol. You can start the tour at any of the petrol pumps. Calculate the first point from where the truck will be able to complete the circle. Consider that the truck will stop at each of the petrol pumps. The truck will move one kilometer for each litre of the petrol.

Input Format

The first line will contain the value of N.
The next N lines will contain a pair of integers each, i.e. the amount of petrol that petrol pump will give and the distance between that petrol pump and the next petrol pump.

Constraints:
1 <= N <= 10^5
1 <= Amount of petrol, distance <= 10^9

Output Format

An integer which will be the smallest index of the petrol pump from which we can start the tour.

Sample Input

3
1 5
10 3
3 4
Sample Output

1
Explanation

We can start the tour from the second petrol pump.                                 */






// The below code works only if a solution exists.
int truckTour(vector<vector<int>> petrolpumps) {
    int n = petrolpumps.size();
    
    int i = 0;
    for( ; i < n; i++) {
        bool isBreak = false;
        
        int petrol = 0;
        int count = 0;
        int j = i;
        while(count < n) {
            petrol += (petrolpumps[j][0] - petrolpumps[j][1]); 
            
            if(petrol < 0) {    // i.e., if next pump is greater than the available petrol
                isBreak = true;
                i = j; // => This one line makes it O(n) instead of O(n ^ 2), becuase, think, if we started at particular j = i, but now after travelling some pumps, now it is petrol going -ve, means then with common sense, we can say that no starting point works in between the i current j. So, we can directly make i jump to j.
                break;
            }
            
            j = (j + 1) % n;
            count++;
        }
        
        if(!isBreak) break;   
    }
    
    return i;
}