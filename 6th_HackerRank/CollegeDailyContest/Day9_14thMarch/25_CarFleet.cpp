/* CAR FLEET : https://www.hackerrank.com/contests/iiits-ytp2026-1403/challenges/car-fleet-3/problem

There are N cars traveling to the same destination, which is target miles away.You are given two integer arrays position and speed, both of length N, where position[i] is the starting position of the i^th car and speed[i] is its speed in miles per hour.A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. The faster car will slow down to match the slower car's speed. The distance between these two cars is ignored (they are treated as having the exact same position).A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also considered a car fleet.If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet. Return the total number of car fleets that will arrive at the destination.

Input Format

The first line contains an integer, target.

The second line contains an integer N, the number of cars.

The third line contains N space-separated integers representing the position array.

The fourth line contains an integer M (which will equal N), followed by M space-separated integers on the fifth line representing the speed array.

Constraints

image

Output Format

A single integer representing the number of car fleets.

Sample Input 0

12
5
10 8 0 5 3
5
2 4 1 1 3
Sample Output 0

3
Sample Input 1

10
1
3
1
3
Sample Output 1

1                                                                */






int carFleet(int target, vector<int> position, vector<int> speed) {
 
    int n = position.size();
    
    vector<pair<pair<int, int>, double>> vec;
    for(int i = 0; i < n; i++) {
        double time = ((double)(target - position[i])) / speed[i];
        vec.push_back({{position[i], speed[i]}, time}); // Actually, the speed[i] is not needed, just position[i] and time are sufficient.
    }
    
    sort(vec.begin(), vec.end());
    
    int fleet = 0;
    
    for(int i = n - 1; i >= 0; i--) {
        int j = n - 1;
        for( ; vec[j].second <= vec[i].second; j--);
        
        fleet += 1;
        
        i = j + 1;
    }
    
    return fleet;
}