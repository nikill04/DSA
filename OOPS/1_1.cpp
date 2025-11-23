#include<iostream>
#include<string>
using namespace std;

// class Teacher {                                          class Teacher {
//     // properties / attributes                               private:
//     string name;                                                 string name;
//     string dept;                            SAME AS              string dept;
//     string subject;                       ==========>            string subject;
//     double salary;                                               double salary;

//     // methods / member functions
//     void changeDept(string newDept) {                            void changeDept(string newDept) {
//         dept = newDept;                                              dept = newDept;
//     }                                                            }
// };                                                        };       

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
};

int main() {
    Teacher t1;
    t1.name = "Shradha";
    t1.subject = "C++";
    t1.dept = "Computer Science";
    // t1.salary = 25000;    // Throws error.

    cout << t1.name << endl;
    return 0;
}



/* How to RUN
PS C:\Users\vasir\CPP\OOPS> g++ 1_1.cpp -o 1_1                                    
PS C:\Users\vasir\CPP\OOPS> ./1_1
*/