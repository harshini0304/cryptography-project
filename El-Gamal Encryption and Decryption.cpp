#include <iostream>
using namespace std;

int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int p, e1, d, r, plaintext;
    cout << "Enter prime p, base e1, private key d: ";
    cin >> p >> e1 >> d;
    int e2 = modExp(e1, d, p);
    cout << "Enter random number r and plaintext: ";
    cin >> r >> plaintext;
    int c1 = modExp(e1, r, p);
    int c2 = (plaintext * modExp(e2, r, p)) % p;
    cout << "Ciphertext: (" << c1 << ", " << c2 << ")\n";
    int decrypted = (c2 * modExp(c1, p - 1 - d, p)) % p;
    cout << "Decrypted plaintext: " << decrypted << endl;
    return 0;
}
