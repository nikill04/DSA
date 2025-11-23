#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        string name;
        int age;
};

class Student : public Person {  // We will different modes of inheritance like public, private, protected.
    public: 
        int rollno;
};

class GradStudent : public Student {
    public:
        string researchArea;
};

int main() {
    GradStudent s1;
    s1.name = "tony stark";
    s1.researchArea = "quantum physics";
    cout << s1.name << endl;
    cout << s1.researchArea << endl;
    return 0;
}



/*
PS C:\Users\vasir\CPP\OOPS> g++ 3_4.cpp -o 3_4
PS C:\Users\vasir\CPP\OOPS> ./3_4 
*/