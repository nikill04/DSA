#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        string name;
        int age;

        // Person(string name, int age) {
        //     this -> name = name;
        //     this -> age = age;
        // }

        Person() {
            cout << "parent constructor.. \n";
        }
};

class Student : public Person {  // We will different modes of inheritance like public, private, protected.
    public: 
        int rollno;

        Student() {
            cout << "Child class constructor..\n";
        }

        void getInfo() {
            cout << "name : " << name << endl;
            cout << "age : " << age << endl;
            cout << "rollno : " << rollno << endl;
        }
};

int main() {
    Student s1;
    s1.name = "rahul kumar";
    s1.age = 21;
    s1.rollno = 101;

    s1.getInfo();
    return 0;
}



/*
PS C:\Users\vasir\CPP\OOPS> g++ 3_1.cpp -o 3_1
PS C:\Users\vasir\CPP\OOPS> ./3_1      
*/