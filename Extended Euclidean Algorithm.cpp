#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int modularInverse(int a, int m) {
    int x, y;
    int gcd = gcdExtended(a, m, x, y);
    if (gcd != 1) {
        cout << "GCD is not 1, so modular inverse does not exist." << endl;
        return -1;
    }
    return (x % m + m) % m; // Ensure positive result
}

int main() {
    int a, b;
    cout << "Enter two integers (a and mod): ";
    cin >> a >> b;

    int inverse = modularInverse(a, b);
    if (inverse != -1) {
        cout << "Modular Inverse: " << inverse << endl;
    }

    return 0;
}
