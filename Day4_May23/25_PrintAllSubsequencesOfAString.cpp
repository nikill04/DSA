/*
PRINT ALL SUBSEQUENCES OF A STRING: https://www.geeksforgeeks.org/print-subsequences-string/

Print all subsequences of a string
Last Updated : 18 Oct, 2024
Given a string, we have to find out all its subsequences of it. A String is said to be a subsequence of another String, if it can be obtained by deleting 0 or more character without changing its order.

Examples: 

Input : ab
Output : "", "a", "b", "ab"

Subsequence-of-a-string
Input : abc
Output : "", "a", "b", "c", "ab", "ac", "bc", "abc"          */

#include <bits/stdc++.h>
using namespace std;

void solve(string inputString, string outputString) {  //Keep in mind that don't pass by reference here.
    if(inputString == "") {
        cout << outputString << endl;
        return;
    }

    char ch = inputString[0];
    inputString.erase(0, 1);

    solve(inputString, outputString);
    outputString = outputString + ch;
    solve(inputString, outputString);
}

void printSubsequence(string &s) {
    string inputString = s;
    string outputString = "";

    solve(inputString, outputString);
}

int main() {
    string String;
    cin >> String;

    printSubsequence(String);
    return 0;
}



/* How to RUN
PS C:\Users\vasir\CPP> g++ 25_PrintAllSubsequencesOfAString.cpp -o 25_PrintAllSubsequencesOfAString                                     
PS C:\Users\vasir\CPP> ./25_PrintAllSubsequencesOfAString
*/