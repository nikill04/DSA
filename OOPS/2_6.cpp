#include<iostream>
#include<string>
using namespace std;

class Teacher {
    // properties / attributes
    private:        
        double salary;
    public:
        string name;
        string dept;
        string subject;

        // Parametarised Constructor
        Teacher(string name, string dept, string subject, double salary) {
            // Here, in left we want it to be object's properties and in the right we want it to be the functions paramters. When both are same, then it will be confusing for the compiler. 
            // So, whenever we want to show the object's properties, we can do that using "this" pointer.
            // name = name;
            // dept = dept;
            // subject = subject;
            // salary = salary;

            this -> name = name;
            this -> dept = dept;
            this -> subject = subject;
            this -> salary = salary;
        }

        // Copy constructor
        Teacher(Teacher &orgObj) {
            cout << "i am custom copy constructor..." << endl;
            this -> name = orgObj.name;
            this -> dept = orgObj.dept;
            this -> subject = orgObj.subject;
            this -> salary = orgObj.salary;
        }

        // methods / member functions
        void changeDept(string newDept) {
            dept = newDept;
        }
    
        void getInfo() {
            cout << "name : " << name << endl;
            cout << "subject : " << subject << endl;
        }
};

int main() {
    Teacher t1("Shradha", "Computer Science", "C++", 25000); 

    // t1.getInfo();

    Teacher t2(t1);    // custom copy constructor
    t2.getInfo();
    
    return 0;
}


/*
PS C:\Users\vasir\CPP\OOPS> g++ 2_6.cpp -o 2_6
PS C:\Users\vasir\CPP\OOPS> ./2_6          
*/