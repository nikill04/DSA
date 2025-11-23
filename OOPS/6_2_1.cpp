#include <iostream>
#include <string>
using namespace std;

class A {
    public:
        int x;

        void incX() {
            x = x + 1;
        }
};

int main() {
    A obj1, obj2;
    obj1.x = 100;
    obj2.x = 200;
    cout << obj1.x << endl;
    obj1.incX();
    cout << obj1.x << endl;

    cout << obj2.x << endl;
    return 0;
}

/*
PS C:\Users\vasir\CPP\OOPS> g++ 6_2_1.cpp -o 6_2_1
PS C:\Users\vasir\CPP\OOPS> ./6_2_1
*/
