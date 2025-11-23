#include <bits/stdc++.h>
using namespace std;

int main() {
    //int arr[5];
    //cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

    int arr[3][5];
    arr[1][3] = 70;
    cout << arr[1][3];
    cout << arr[1][2]; // Will be 'garbage value' as not initialized.

    return 0;
}