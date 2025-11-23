#include <bits/stdc++.h>
using namespace std;

/*
void 
return
parameterised
non parameterised
*/

void printName1() {
    cout << "Hey Striver" << endl;
}
void printName2(string name) {
    cout << "hey " << name << endl;
}

int sum(int num1, int num2) {
    int num3 = num1 + num2;
    return num3;
}

int maxx(int num1, int num2) {
    if(num1 >= num2) return num1;
    else return num2;
}

int main () {
    printName1();

    string name;
    cin >> name;
    printName2(name);

    int num1, num2;
    cin >> num1 >> num2;
    int res = sum(num1, num2);
    cout << res;
    return 0;

    int maximum = maxx(num1, num2);
    cout << maximum;

    
}