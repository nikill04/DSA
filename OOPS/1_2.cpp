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
    Teacher t1;  
    t1.name = "Shradha";
    t1.subject = "C++";
    t1.dept = "Computer Science";
    t1.setSalary(25000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;
    return 0;
}





/* How to RUN
PS C:\Users\vasir\CPP\OOPS> g++ 1_2.cpp -o 1_2                                    
PS C:\Users\vasir\CPP\OOPS> ./1_2
*/