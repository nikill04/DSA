#include <iostream>
#include <string>
using namespace std;

class Shape { // class which has pure virtual function automatically becomes an abstract class.
    virtual void draw() = 0; // pure virual function.
};

class Circle : public Shape {
    public:
        void draw() {
            cout << "drawing a circle\n";
        }
};

int main() {
    // Shape s1; // This gives an error because we cannot create the object of abstract class.

    Circle c1;
    c1.draw();
    return 0;
}



/*
PS C:\Users\vasir\CPP\OOPS> g++ 5_1_AbstractClasses.cpp -o 5_1_AbstractClasses
PS C:\Users\vasir\CPP\OOPS> ./5_1_AbstractClasses
*/
