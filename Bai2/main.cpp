#include <iostream>
#include <string>

#include "management.h"
#include "Book.h"
#include "Journal.h"
#include "Paper.h"
#include "common.h"

using namespace std;

int main() {
    DocumentManager manager;
    while (true) {
        cout << "Library Document Management System" << endl;
        cout << "1. Add a New Document" << endl;
        cout << "2. Remove a Document" << endl;
        cout << "3. Display Document Info" << endl;
        cout << "4. Search for Documents by Type" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        managerDocument c = static_cast<managerDocument>(choice);

        switch (c) {
        case managerDocument::ADD: {
            cout << "Select Document Type:" << endl;
            cout << "1. Book" << endl;
            cout << "2. Journal" << endl;
            cout << "3. Paper" << endl;
            int docTypeChoice;
            cin >> docTypeChoice;

            documentType select = static_cast<documentType>(docTypeChoice);

            string docCode, publisherName;
            int numberOfCopies;

            cout << "Enter Document Code: ";
            cin >> docCode;
            cout << "Enter Publisher Name: ";
            cin.ignore();
            getline(cin, publisherName);
            cout << "Enter Number of Copies: ";
            cin >> numberOfCopies;

            shared_ptr<Document> newDocument;

            switch (select) {
            case documentType::BOOK: {
                string authorName;
                int numberOfPages;
                cout << "Enter Author Name: ";
                cin.ignore(); // Clear the newline character left in the input buffer
                getline(cin, authorName);
                cout << "Enter Number of Pages: ";
                cin >> numberOfPages;

                newDocument = make_shared<Book>(docCode, publisherName, numberOfCopies, authorName, numberOfPages);
                break;
            }
            case documentType::JOURNAL: {
                int issueNumber, publicationMonth;
                cout << "Enter Issue Number: ";
                cin >> issueNumber;
                cout << "Enter Publication Month: ";
                cin >> publicationMonth;

                newDocument = make_shared<Journal>(docCode, publisherName, numberOfCopies, issueNumber, publicationMonth);
                break;
            }
            case documentType::PAPER: {
                string publicationDate;
                cout << "Enter Publication Date: ";
                cin.ignore(); 
                getline(cin, publicationDate);

                newDocument = make_shared<Paper>(docCode, publisherName, numberOfCopies, publicationDate);
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
            }

            manager.addNewDocument(newDocument);
            cout << "Document added successfully." << endl;
            break;
        }
        case managerDocument::REMOVE: {
            string docCode;
            cout << "Enter Document Code to Remove: ";
            cin >> docCode;
            manager.removeDocument(docCode);
            break;
        }
        case managerDocument::DISPLAY: {
            string docCode;
            cout << "Enter Document Code to Display Info: ";
            cin >> docCode;
            manager.displayDocumentInfo(docCode);
            break;
        }
        case managerDocument::SEARCH: {
            string docType;
            cout << "Enter Document Type to Search: ";
            cin >> docType;
            manager.searchByType(docType);
            break;
        }
        case managerDocument::EXIT:
            manager.exitProgram();
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
