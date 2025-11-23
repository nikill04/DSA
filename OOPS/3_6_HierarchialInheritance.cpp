#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        string name;
        int age;
};

class Student : public Person{  
    public: 
        int rollno;
};

class Teacher : public Person {
    public:
        string subject;
};

int main() {
    
    return 0;
}



/*
PS C:\Users\vasir\CPP\OOPS> g++ 3_6.cpp -o 3_6
PS C:\Users\vasir\CPP\OOPS> ./3_6
*/
