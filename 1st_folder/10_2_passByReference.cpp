#include <bits/stdc++.h>
using namespace std;

// Pass By VALUE
void doSomething(int num) {
    cout << num << endl;
    num += 5;
    cout << num << endl;
    num += 5;
    cout << num << endl;
}

// Pass By VALUE
void doSomething2(string s) {
    s[0] = 't';
    cout << s << endl;
}

// Pass By REFERENCE
void doSomething3(string &s) {
    s[0] = 't';
    cout << s << endl;
}

void doSomething4(int arr[], int n) {
    arr[0] += 100;
    cout << "Value inside function: " << arr[0] << endl;
}

// Pass By REFERENCE
void doSomething4(int &num) {
    cout << num << endl;
    num += 5;
    cout << num << endl;
    num += 5;
    cout << num << endl;
}

int main() {
    int num = 10;
    doSomething(num);
    cout << num << endl;

    string s = "raj";
    doSomething2(s);
    cout << s << endl;

    doSomething3(s);
    cout << s << endl;

    doSomething4(num);
    cout << num << endl;

    int n = 5;
    int arr[n];
    for(int i = 0, i < n; i++) {
        cin >> arr[i];
    }
    doSomething4(arr, n);

    cout << "Value inside int main: " << arr[0] << endl;
    return 0;
}