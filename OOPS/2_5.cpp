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

        // Non-Parametarised Constructor
        Teacher() {  
            dept = "Computer Science";
        }

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

    Teacher t2(t1);    // default copy constructor
    t2.getInfo();
    
    return 0;
}


/*
PS C:\Users\vasir\CPP\OOPS> g++ 2_5.cpp -o 2_5
PS C:\Users\vasir\CPP\OOPS> ./2_5          
*/