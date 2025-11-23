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

class Student : public Person {  // We will different modes of inheritance like public, private, protected.
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
    return 0;
}



/*
PS C:\Users\vasir\CPP\OOPS> g++ 3_2.cpp -o 3_2
PS C:\Users\vasir\CPP\OOPS> ./3_2      
*/