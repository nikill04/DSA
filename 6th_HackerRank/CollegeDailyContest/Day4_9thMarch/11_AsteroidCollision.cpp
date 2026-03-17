/* ASTEROID COLLISION : https://www.hackerrank.com/contests/iiits-ytp2026-0903/challenges/asteroid-collision-1-1

You are given an array asteroids of length N, where each integer represents an asteroid moving in a straight line.

The absolute value of an asteroid represents its size. The sign of an asteroid represents its direction: positive means moving to the right negative means moving to the left

All asteroids move at the same speed.

When two asteroids moving in opposite directions collide: - the smaller asteroid is destroyed - if both are the same size, both are destroyed - asteroids moving in the same direction never collide

Your task is to determine the state of the asteroids after all possible collisions have occurred.

Input Format

The first line contains a single integer N, the number of asteroids. The second line contains N space-separated integers representing the asteroids array.

Constraints

2 <= N <= 200000
-1000000000 <= asteroids[i] <= 1000000000
asteroids[i] != 0

Output Format

Print the remaining asteroids in their original order after all collisions.

Output them as space-separated integers on a single line. If no asteroids remain, print an empty line.

Sample Input 0

3
5 10 -5
Sample Output 0

5 10
Explanation 0

The asteroids move as follows:

5 is moving to the right
10 is moving to the right
-5 is moving to the left
The asteroid 10 and -5 will collide because they are moving toward each other.

Since |10| > |−5|, the asteroid -5 is destroyed.

The asteroid 5 does not collide with 10 because both are moving in the same direction.

So the remaining asteroids are: 5 10

Sample Input 1

2
8 -8
Explanation 1

8 and -8 collide. Since both have the same size, both are destroyed.

So no asteroids remain.                                */






vector<int> asteroidCollision(vector<int> asteroids) {
// BRUTE FORCE
//     if(asteroids.size() <= 1) return asteroids;
    
//     while(true) {
//         bool destroyed = false;
        
//         for(int i = 1; i < asteroids.size(); i++) {
            
//             if(asteroids[i] < 0 && asteroids[i - 1] > 0) {
//                 destroyed = true;
                
//                 if(abs(asteroids[i]) > abs(asteroids[i - 1])) {
//                     asteroids.erase(asteroids.begin() + (i - 1));
//                 }
//                 else if(abs(asteroids[i]) < abs(asteroids[i - 1])) {
//                     asteroids.erase(asteroids.begin() + i);
//                 }    
//                 else {
//                     asteroids.erase(asteroids.begin() + i - 1);
//                     asteroids.erase(asteroids.begin() + i - 1);
//                 }
                
//                 i--;
//             }    
//         }
        
//         if(!destroyed) break;
    
    
//     }
    
//     return asteroids;
    
    

// OPTIMAL APPROACH(USING STACK)
    stack<int> st;
    
    for(int a : asteroids) {
        bool destroyed = false;
        
        while(!st.empty() && st.top() > 0 && a < 0) {
            if(abs(st.top()) < abs(a)) {
                st.pop();
                continue;
            }
            else if(abs(st.top()) == abs(a)) {
                st.pop();
            }
            
            destroyed = true;
            break;
        }
        
        if(!destroyed) st.push(a);
    }
    
    vector<int> ans(st.size());
    for(int i = st.size() - 1; i >= 0; i--) {
        ans[i] = st.top();
        st.pop();
    }
    
    return ans;
}