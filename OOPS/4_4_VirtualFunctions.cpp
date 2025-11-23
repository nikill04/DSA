#include <iostream>
#include <string>
using namespace std;

class Parent {
    public:
        void getInfo() {
            cout << "Parent Class \n";
        }

        virtual void hello() {
            cout << "hello from parent\n";
        }
};

class Child : public Parent {
    public:
        void getInfo() {
            cout << "Child Class \n";
        }

        void hello() {
            cout << "Hello from child\n";
        }
};

int main() {
    Child c1;
    c1.hello();

    Parent p1;
    p1.hello();
    return 0;
}



/*
PS C:\Users\vasir\CPP\OOPS> g++ 4_4_VirtualFunctions.cpp -o 4_4_VirtualFunctions
PS C:\Users\vasir\CPP\OOPS> ./4_4_VirtualFunctions
*/
