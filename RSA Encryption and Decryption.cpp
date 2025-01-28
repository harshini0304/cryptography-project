#include <iostream>
using namespace std;

int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int p, q, e, d, n, phi;
    cout << "Enter primes p and q: ";
    cin >> p >> q;
    n = p * q;
    phi = (p - 1) * (q - 1);
    cout << "Enter public key e and private key d: ";
    cin >> e >> d;

    string text;
    cout << "Enter text to encrypt (uppercase letters): ";
    cin >> text;

    cout << "Encrypted: ";
    for (char c : text)
        cout << modExp(c - 'A', e, n) << " ";
    cout << "\nDecrypted: ";
    for (char c : text) {
        int enc = modExp(c - 'A', e, n);
        cout << (char)(modExp(enc, d, n) + 'A');
    }
    cout << endl;
    return 0;
}
