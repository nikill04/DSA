#include <iostream>
#include <string>
using namespace std;

void func() {
    int x = 0;
    cout << "x : " << x << endl;
    x++;
};

void func2() {
    static int x = 0; // initialization statement will be executed only once.  
    cout << "x : " << x << endl;
    x++;
};

int main() {
    func();
    func();
    func();

    func2();
    func2();
    func2();
    return 0;
}

/*
PS C:\Users\vasir\CPP\OOPS> g++ 6_1_StaticVariable.cpp -o 6_1_StaticVariable
PS C:\Users\vasir\CPP\OOPS> ./6_1_StaticVariable
*/
