#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string choice;
    string sentence;

    cout << "Enter 'up' to convert to UPPERCASE or 'down' for lowercase: ";
    cin >> choice;
    cin.ignore();  // To ignore leftover newline character

    cout << "Enter your sentence: ";
    getline(cin, sentence);

    if (choice == "up") {
        for (char& c : sentence) {
            c = toupper(c);
        }
    } else if (choice == "down") {
        for (char& c : sentence) {
            c = tolower(c);
        }
    } else {
        cout << "Invalid choice. Use 'up' or 'down'." << endl;
        return 1;
    }

    cout << "Converted sentence: " << sentence << endl;

    return 0;
}
