#include <iostream>
#include <string>
using namespace std;

class ABC {
    public:
        ABC() {
            cout << "constructor\n";
        }

        ~ABC() {
            cout << "destructor\n";
        }
};

int main() {
    if(true) {
        ABC obj;
    }  // Normally object will be destroyed when it goes out of scope. that's why destructor is called here i.e., at the end of if block.

    cout << "end of main function\n";
    return 0;
}

/*
PS C:\Users\vasir\CPP\OOPS> g++ 6_2_2.cpp -o 6_2_2
PS C:\Users\vasir\CPP\OOPS> ./6_2_2
*/
