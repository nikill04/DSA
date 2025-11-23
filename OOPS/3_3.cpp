#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        string name;
        int age;

        Person(string name, int age) {
            this -> name = name;
            this -> age = age;
        }
};

class Student : private Person {  // We will different modes of inheritance like public, private, protected.
    public: 
        int rollno;

        Student(string name, int age, int rollno) : Person(name, age) {
            this -> rollno = rollno;
        }

        void getInfo() {
            cout << "name : " << name << endl;
            cout << "age : " << age << endl;
            cout << "rollno : " << rollno << endl;
        }
};

int main() {
    Student s1("rahul kumar", 21, 1234);
    
    s1.getInfo();

    cout << s1.name;  // This will throw an error because we have inherited the Person class in Student class using private mode of inheritance. So, all the public members of Person class become private members of Student class.
    return 0;
}



/*
PS C:\Users\vasir\CPP\OOPS> g++ 3_3.cpp -o 3_3
PS C:\Users\vasir\CPP\OOPS> ./3_3    
*/