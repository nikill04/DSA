#include<iostream>
#include<string>
using namespace std;

class Student {
    public:
        string name;
        double* cgpaPtr;

        Student(string name, double cgpa) {
            this -> name = name;
            cgpaPtr = new double; // heap memory allocation or dynamic memory allocation.
            *cgpaPtr = cgpa;
        }

        Student(Student &obj) {
            this -> name = obj.name;
            this -> cgpaPtr = obj.cgpaPtr;
        }

        void getInfo () {
            cout << "name : " << name << endl;
            cout << "cgpa: " << *cgpaPtr << endl;
        }
};

int main() {
    Student s1("rahul kumar", 8.9);
    
    Student s2(s1);  // Here, we are doing shallow copy.

    s1.getInfo();
    *(s2.cgpaPtr) = 9.2;
    s1.getInfo(); 
    // Here, if we observe s1's cgpa also changes to 9.2 because both the objects are sharing the same memory location for cgpaPtr. This is happening because of shallow copy. 
    // This happens even if we use default copy constructor. To avoid this, we have to use deep copy. 
    // But for deep copy, no default copy constructor is there. We have to write our own custom copy constructor.

    return 0;
}


/*
PS C:\Users\vasir\CPP\OOPS> g++ 2_7_2.cpp -o 2_7_2
PS C:\Users\vasir\CPP\OOPS> ./2_7_2        
*/