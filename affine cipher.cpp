#include <iostream>
#include <string>
using namespace std;

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1) return x;
    return -1;
}

string affineCipher(string text, int a, int b, bool encrypt) {
    string result = "";
    int a_inv = encrypt ? 1 : modInverse(a, 26);
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int shift = encrypt ? (a * (c - base) + b) : (a_inv * (c - base - b + 26));
            result += (char)((shift % 26 + 26) % 26 + base);
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text;
    int a, b;
    char choice;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter a and b: ";
    cin >> a >> b;
    cout << "Encrypt (e) or Decrypt (d)? ";
    cin >> choice;
    bool encrypt = (choice == 'e');
    cout << "Result: " << affineCipher(text, a, b, encrypt) << endl;
    return 0;
}
