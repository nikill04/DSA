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
            cgpaPtr = new double;
            *cgpaPtr = *obj.cgpaPtr; // deep copy
        }

        void getInfo () {
            cout << "name : " << name << endl;
            cout << "cgpa: " << *cgpaPtr << endl;
        }
};

int main() {
    Student s1("rahul kumar", 8.9);
    
    Student s2(s1);  

    s1.getInfo();
    *(s2.cgpaPtr) = 9.2;
    s1.getInfo(); 

    s2.name = "neha";
    s2.getInfo();
    
    // But for deep copy, no default copy constructor is there. We have to write our own custom copy constructor.

    return 0;
}


/*
PS C:\Users\vasir\CPP\OOPS> g++ 2_7_3.cpp -o 2_7_3
PS C:\Users\vasir\CPP\OOPS> ./2_7_3        
*/