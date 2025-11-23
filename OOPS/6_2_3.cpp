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
        static ABC obj;  // static object will be destroyed only at the end of the program. It will be there for lifetime of the program. that's why destructor is called at the end of main function.
    }

    cout << "end of main function\n";
    return 0;
}

/*
PS C:\Users\vasir\CPP\OOPS> g++ 6_2_3.cpp -o 6_2_3
PS C:\Users\vasir\CPP\OOPS> ./6_2_3
*/
