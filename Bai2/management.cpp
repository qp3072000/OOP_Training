#include"management.h"
#include<iostream>

DocumentManager::DocumentManager() {}

void DocumentManager::addNewDocument(shared_ptr<Document> document) {
    documentList.push_back(document);
}

void DocumentManager::removeDocument(const string& documentCode) {
    // Iterate through the vector using a manual iterator
    for (vector<shared_ptr<Document>>::iterator it = documentList.begin(); it != documentList.end(); ++it) {
        if ((*it)->getDocumentCode() == documentCode) {
            // Document found, erase it
            it = documentList.erase(it);
            cout << "Document with code " << documentCode << " has been removed." << endl;
            return;
        }
    }

    // Document not found
    cout << "Document with code " << documentCode << " not found." << endl;
}


void DocumentManager::displayDocumentInfo(const string& documentCode) {
    for (const auto& document : documentList) {
        if (document->getDocumentCode() == documentCode) {
            document->displayInfo();
            return;
        }
    }
    std::cout << "Document with code " << documentCode << " not found." << std::endl;
}

void DocumentManager::searchByType(const string& type) {
    for (const auto& document : documentList) {
        if (document->getDocumentType() == type) {
            document->displayInfo();
            cout << endl;
        }
    }
}

void DocumentManager::exitProgram() {
    cout << "Exiting the program." << endl;
}
