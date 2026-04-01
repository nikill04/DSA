/* FOOD STAMPS

You want to buy food from a store. You have a scoring system that uses a unit called taste points .

Each time you buy a type of food, you can measure its tastiness by the number of taste points you get from that food.

You have N types of food. You can buy any type any number of times, as long as the total number of meals does not exceed M.

However, you don't want to grow tired of a food if you buy it too often. Therefore, you will get v[i] − d[i] × (ti − 1) taste points when you buy the i-th type of food for the ti-th time.

Find the maximum number of taste points you can achieve.            

Input Format
The first line contains an integer, n, denoting the number of types of food you can buy.

The next line contains an integer, m, denoting the maximum number of meals you can buy.

Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer describing v[i].

Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer describing d[i].

Constraints
1 <= n <= 10^5
1 <= m <= 10^9
1 <= v[i] <= 10^9
1 <= d[i] <= 10^9*/