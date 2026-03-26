/* OPTIMAL BINARY ARRANGEMENT : 

You are given an integer N, an array A of length N, and an array B of length N.

You have N blocks of 1 bits with sizes A[1...N], and N blocks of 0 bits with sizes B[1... N]. You must arrange these blocks so that no two adjacent blocks have the same bit value.

Among all possible valid arrangements, find the maximum possible number obtained by interpreting the resulting binary string as a decimal integer. Print the result modulo 10^9+7. 

Find the maximum possible number obtained by interpreting the optimally arranged binary string as a decimal integer. Print the result modulo 10^9 + 7. 

Notes:
    All blocks in A and B must be used exactly once.
    Blocks must strictly alternate between 0 and 1.
    The arrangement may start with either block type.
    The objective is is to maximize the decimal value of the final binary string.

Input Format
The first line contains an integer, N, denoting the number of elements in A and B.
Each line i of the N subsequent lines (where 0 ≤ i < N) contains an integer describing A[i].
Each line i of the N subsequent lines (where 0 ≤ i < N) contains an integer describing B[i].

Constraints
1 <= N <= 10^5
1 <= A <= 10^6
1 <= B[i] <=10^6

Sample Test Cases

Case 1
Input:
1
2
1
Output:
6
Explanation:
N=1
A=2
B=1

The best arrangement is A[0] then B[0], giving the binary string 110, which is equivalent to 6 in decimal.            

Case 2
Input:
2
1
1
1
2
Output:
20
Explanation:
N=2
A=1, 1
B=1, 2
The best arrangement is A [1] then B[0] then A [1] then B[1], giving the binary string 10100 which is equivalent to 20 in decimal.

Case 3
Input:
3
2
1
2
2
2
1
Output:
868

Explanation:
N=3
A=2,1,2
B=2,2,1
The best arrangement is A[2] then B[2] then A[0] then B[1] then A[1] then B[0], giving the binary string 1101100100, which is equivalent to 868 in decimal.                                   */






long long power(long long base, long long exp) {
    long long res = 1;
    long long MOD = 1000000007;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int ans(int N, vector<int> A, vector<int> B) {
    long long MOD = 1000000007;
    
    // Sort A in descending order to put largest 1-blocks at the most significant bits
    sort(A.begin(), A.end(), greater<int>());
    
    // Sort B in ascending order to put smallest 0-blocks right after the 1-blocks
    sort(B.begin(), B.end());
    
    // Calculate total length (needs long long to prevent overflow)
    long long total = 0;
    for (int x : A) total += x;
    for (int x : B) total += x;
    
    long long finalAns = 0;
    
    for (int i = 0; i < N; i++) {
        // A block of 1s of length A[i] ending at position (total - A[i]) 
        // has the value 2^(total) - 2^(total - A[i])
        long long val1 = power(2, total);
        long long val2 = power(2, total - A[i]);
        
        // Add modulo to prevent negative numbers before taking modulo
        long long block_val = (val1 - val2 + MOD) % MOD;
        finalAns = (finalAns + block_val) % MOD;
        
        // Subtract the lengths of the current A and B blocks to shift the position for the next iteration
        total -= A[i];
        total -= B[i];
    }
    
    return (int)finalAns;
}



/* Your intuition is mathematically spot on! In pure mathematics, 2^(total) is absolutely always greater than 2^(total - A[i]). 

However, we aren't doing pure math here; we are doing modular arithmetic, which changes the rules a bit. Let's break down exactly why both of these concepts—modulo subtraction and fast exponentiation—work the way they do.

---

### 1. Why (val1 - val2 + MOD) % MOD?

The issue arises because val1 and val2 do not hold the actual massive mathematical values. They hold the values after the modulo operation has already been applied by the power() function. 

Because we take the modulo at every step to prevent integer overflow, a mathematically larger number can map to a smaller modulo value.

A Simple Example:
Let's pretend our MOD is 7.
* Let the actual mathematical value of val1 be 8.
* Let the actual mathematical value of val2 be 4.

Mathematically, 8 > 4. 
But in our code, the power() function would return them modulo 7:
* val1 = 8 % 7 = 1
* val2 = 4 % 7 = 4

Now, look at what happens when we subtract them in C++:
val1 - val2 -> 1 - 4 = -3.

In C++ (unlike Python), the modulo operator % on a negative number returns a negative result. So -3 % 7 in C++ gives -3. But we need a positive remainder in the range [0, MOD-1]. 

To fix this and "wrap" the negative number back around to the correct positive value, we add MOD before taking the final modulo:
* -3 + 7 = 4
* 4 % 7 = 4

So, (val1 - val2 + MOD) % MOD is a standard competitive programming trick to safely subtract two numbers that have already been modulo'd, guaranteeing you never end up with a negative answer!

---

### 2. The power() Function (Fast Exponentiation)

If you need to calculate 2^100000, a standard loop would multiply 2 by itself 100,000 times. That's an O(N) operation. In your problem, total can be up to 10^11, so a standard loop would definitely cause a Time Limit Exceeded (TLE).

The power() function uses a technique called Binary Exponentiation (or Exponentiation by Squaring). It cuts the time complexity down from O(N) to O(log N) by jumping in powers of 2.

Here is the logic it follows:
If you want to calculate b^exp, you look at whether exp is even or odd.

* If exp is Even: b^10 = (b^2)^5. You can just square the base and cut the exponent in half.
* If exp is Odd: b^11 = b * b^10. You multiply your current result by the base once. That makes the remaining exponent even, and you can go back to the even rule.

Let's trace an example: Calculate 3^5 % 10
Initial state: res = 1, base = 3, exp = 5, MOD = 10

Step 1: exp (5) is odd.
* We multiply res by base: res = (1 * 3) % 10 -> 3
* We square the base: base = (3 * 3) % 10 -> 9
* We divide exp by 2: exp = 5 / 2 -> 2 (integer division)

Step 2: exp (2) is even.
* (exp % 2 == 1 is false, so we don't change res)
* We square the base: base = (9 * 9) % 10 = 81 % 10 -> 1
* We divide exp by 2: exp = 2 / 2 -> 1

Step 3: exp (1) is odd.
* We multiply res by base: res = (3 * 1) % 10 -> 3
* We square the base: base = (1 * 1) % 10 -> 1
* We divide exp by 2: exp = 1 / 2 -> 0

Step 4: exp is now 0. The while (exp > 0) loop breaks.
* Return res, which is 3. (And mathematically, 3^5 = 243, and 243 % 10 is indeed 3).

By squaring the base and halving the exponent at every step, the loop only runs about 35-40 times even if your exponent is a massive 10^11!       */