#include<iostream>
#include<string>
using namespace std;

class Student {
    public:
        string name;
        double cgpa;

        Student(string name, double cgpa) {
            this -> name = name;
            this -> cgpa = cgpa;
        }

        Student(Student &obj) {
            this -> name = obj.name;
            this -> cgpa = obj.cgpa;
        }

        void getInfo () {
            cout << "name : " << name << endl;
            cout << "cgpa: " << cgpa << endl;
        }
};

int main() {
    Student s1("rahul kumar", 8.9);
    
    Student s2(s1);
    s2.getInfo();
    return 0;
}


/*
PS C:\Users\vasir\CPP\OOPS> g++ 2_7_1.cpp -o 2_7_1
PS C:\Users\vasir\CPP\OOPS> ./2_7_1    
*/