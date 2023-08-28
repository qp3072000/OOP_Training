#include "document.h"
#include"common.h"
#include <iostream>

using namespace std;

int main() {
    Document document;
    int choice;
    bool quit = false;

    while (!quit) {
        cout << "Menu:" << endl;
        cout << "1. Enter text" << endl;
        cout << "2. Count words" << endl;
        cout << "3. Count 'A' characters" << endl;
        cout << "4. Normalize text" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        documentMenu c = static_cast<documentMenu>(choice);

        switch (c) {
            case documentMenu::ENTER: {
                document.enterText();
                break;
            }
            case documentMenu::COUNT: {
                cout << "Number of words: " << document.countWords() << endl;
                break;
            }
            case documentMenu::COUNTA: {
                cout << "Number of 'A' characters: " << document.countACharacters() << endl;
                break;
            }
            case documentMenu::NORMALIZE: {
                document.normalizeText();
                cout << "Normalized text: " << document.getText() << endl;
                break;
            }
            case documentMenu::EXIT:
                cout << "Goodbye!" << endl;
                quit = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
