#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the square: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {  // Row loop
        for (int j = 1; j <= n; j++) {  // Column loop
            if (i == 1 || i == n || j == 1 || j == n) {  
                cout << "* ";
            } else {
                cout << "  ";  // Print spaces inside the square
            }
        }
        cout << endl;
    }
    return 0;
}
