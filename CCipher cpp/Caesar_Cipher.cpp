// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int main() {
    int choice;
    cout << "1. Encryption" << endl << "2. Decryption" << endl << "Enter choice(1,2): ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
		char message[100], ch;
		int i, key;
		cout << "Enter a message to encrypt: ";
		cin.getline(message, 100);
		cout << "Enter key: ";
		cin >> key;
		for (i = 0; message[i] != '\0'; ++i) {
			ch = message[i];
			if (ch >= 'a' && ch <= 'z') {
				ch = ch + key;
				if (ch > 'z') {
					ch = ch - 'z' + 'a' - 1;
				}
				message[i] = ch;
			}
			else if (ch >= 'A' && ch <= 'Z') {
				ch = ch + key;
				if (ch > 'Z') {
					ch = ch - 'Z' + 'A' - 1;
				}
				message[i] = ch;
			}
		}
		cout << "Encrypted message: " << message;
		return 0;
    }
	else if (choice == 2) {
		char message[100], ch;
		int i, key;
		cout << "Enter a message to decrypt: ";
		cin.getline(message, 100);
		cout << "Enter key: ";
		cin >> key;
		for (i = 0; message[i] != '\0'; ++i) {
			ch = message[i];
			if (ch >= 'a' && ch <= 'z') {
				ch = ch - key;
				if (ch < 'a') {
					ch = ch + 'z' - 'a' + 1;
				}
				message[i] = ch;
			}
			else if (ch >= 'A' && ch <= 'Z') {
				ch = ch - key;

				if (ch > 'a') {
					ch = ch + 'Z' - 'A' + 1;
				}
				message[i] = ch;
			}
		}
		cout << "Decrypted message: " << message;
		return 0;
	}
}