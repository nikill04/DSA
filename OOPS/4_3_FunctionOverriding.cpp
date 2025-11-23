#include <iostream>
#include <string>
using namespace std;

class Parent {
    public:
        void getInfo() {
            cout << "Parent Class \n";
        }
};

class Child : public Parent {
    public:
        void getInfo() {
            cout << "Child Class \n";
        }
};

int main() {
    Child c1;
    c1.getInfo();

    Parent p1;
    p1.getInfo();
    return 0;
}



/*
PS C:\Users\vasir\CPP\OOPS> g++ 4_3_FunctionOverriding.cpp -o 4_3_FunctionOverriding
PS C:\Users\vasir\CPP\OOPS> ./4_3_FunctionOverriding
*/
