#include <iostream>
#include <string>
using namespace std;

string vigenereCipher(string text, string key, bool encrypt) {
    string result = "";
    int keyIndex = 0;
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int shift = toupper(key[keyIndex]) - 'A';
            result += (char)(((c - base + (encrypt ? shift : -shift) + 26) % 26) + base);
            keyIndex = (keyIndex + 1) % key.size();
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text, key;
    char choice;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter key: ";
    cin >> key;
    cout << "Encrypt (e) or Decrypt (d)? ";
    cin >> choice;
    bool encrypt = (choice == 'e');
    cout << "Result: " << vigenereCipher(text, key, encrypt) << endl;
    return 0;
}
