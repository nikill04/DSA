#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
        string name;

        Student() {
            cout << "non-parameterized\n";
        }

        Student(string name) {
            this -> name = name;
            cout << "parameterized\n";
        }
};

int main() {
    Student s1;
    
    return 0;
}



/*
PS C:\Users\vasir\CPP\OOPS> g++ 4_1_constructorOverloading.cpp -o 4_1_constructorOverloading
PS C:\Users\vasir\CPP\OOPS> ./4_1_constructorOverloading
*/
