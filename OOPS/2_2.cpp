#include<iostream>
#include<string>
using namespace std;

class Teacher {
    // properties / attributes
    private:        
        double salary;
    public:
        // Non-Parametarised Constructor
        Teacher() {  // Constructor if declared explicitly should be declared only as public as it goes call from main function.
            dept = "Computer Science";
        }

        string name;
        string dept;
        string subject;

        // methods / member functions
        void changeDept(string newDept) {
            dept = newDept;
        }
    
        // Setter 
        void setSalary(double s) {
            salary = s;
        }
        // Getter
        double getSalary() {
            return salary;
        }

        // Generally we use getter and getter functions to set and get private values respectively.
};

int main() {
    Teacher t1;   // constructor call
    Teacher t2;
    t1.name = "Shradha";
    t1.subject = "C++";
    t1.setSalary(25000);

    cout << t1.dept << endl;
    return 0;
}


/*
PS C:\Users\vasir\CPP\OOPS> g++ 2_2.cpp -o 2_2
PS C:\Users\vasir\CPP\OOPS> ./2_2          
*/