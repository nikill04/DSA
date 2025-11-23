#include<iostream>
#include<string>
using namespace std;

class Teacher {
    // properties / attributes
    private:        
        double salary;
    public:
        // Non-Parametarised Constructor
        Teacher() {  
            dept = "Computer Science";
        }

        // Parametarised Constructor
        Teacher(string n, string d, string s, double sal) {
            name = n;
            dept = d;
            subject = s;
            salary = sal;
        }

        string name;
        string dept;
        string subject;

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

    t1.getInfo();
    return 0;
}


/*
PS C:\Users\vasir\CPP\OOPS> g++ 2_3.cpp -o 2_3
PS C:\Users\vasir\CPP\OOPS> ./2_3          
*/