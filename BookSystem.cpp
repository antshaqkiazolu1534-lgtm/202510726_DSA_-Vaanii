#include <iostream>
#include <fstream>
using namespace std;

void showHistory() {
    cout << "\n--- History of C++ ---\n";
    cout << "1. Origin of C++\n";
    cout << "2. Development Timeline\n";
    cout << "3. Evolution and Modern C++\n";
    cout << "Select chapter: ";
    int choice; cin >> choice;

    switch(choice) {
        case 1: cout << "C++ was created by Bjarne Stroustrup in 1979...\n"; break;
        case 2: cout << "C++ evolved through versions: C++98, C++11, C++14, C++17, C++20...\n"; break;
        case 3: cout << "Modern C++ emphasizes safety, concurrency, and performance...\n"; break;
        default: cout << "Invalid chapter.\n";
    }
}

void learnCpp() {
    cout << "\n--- Learn C++ Concepts ---\n";
    cout << "1. Data Types\n";
    cout << "2. Control Flow\n";
    cout << "3. Loops\n";
    cout << "4. Arrays\n";
    cout << "5. File Streams\n";
    cout << "Select chapter: ";
    int choice; cin >> choice;

    switch(choice) {
        case 1: cout << "Data Types: int, float, char, string, bool...\n"; break;
        case 2: cout << "Control Flow: if-else, switch-case...\n"; break;
        case 3: cout << "Loops: for, while, do-while...\n"; break;
        case 4: cout << "Arrays: collection of elements of same type...\n"; break;
        case 5: {
            ifstream file("chapter_file.txt");
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            } else {
                cout << "Error opening file.\n";
            }
            break;
        }
        default: cout << "Invalid chapter.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Foundations and History of C++ ---\n";
        cout << "1. View History of C++\n";
        cout << "2. Learn about C++ Concepts\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: showHistory(); break;
            case 2: learnCpp(); break;
            case 3: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
