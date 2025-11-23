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

        // destructor
        ~Student() {
            cout << "Hi, I delete everything\n";
            delete cgpaPtr;  // This doesn't mean, i am deleteing that pointer. I am deleting the memory pointed by that pointer.
        }

        void getInfo () {
            cout << "name : " << name << endl;
            cout << "cgpa: " << *cgpaPtr << endl;
        }
};

int main() {
    Student s1("rahul kumar", 8.9);
    s1.getInfo();

    return 0;
}


/*
PS C:\Users\vasir\CPP\OOPS> g++ 2_8.cpp -o 2_8
PS C:\Users\vasir\CPP\OOPS> ./2_8      
*/