#include<bits/stdc++.h>
using namespace std;

int main() {
    // Data types are 'int', 'float', 'double', 'long', 'long long', 'string', 'char'
    string s1, s2; // If we define something as 'string' then it only takes one word as input i.e., only upto before the space
    cin >> s1 >> s2;
    cout << s1 << " " << s2 << "\n\n";

    string str;
    getline(cin, str);
    // "'string' & 'getline()' till the line break. i.e., only line"
    cout << str;
    return 0;
}

/* How to RUN
PS C:\Users\vasir\CPP> g++ 4_datatypes.cpp -o 4_datatypes                                         
PS C:\Users\vasir\CPP> ./4_datatypes 
*/