#include"Paper.h"
#include<iostream>

Paper::Paper(const string& _documentCode, const string& _publisherName, int _numberOfCopies, const string& _publicationDate)
    :Document(_documentCode, _publisherName, _numberOfCopies) {
        publicationDate = _publicationDate;
}

string Paper::getDocumentType() {
    return "Paper";
}

void Paper::displayInfo() {
    cout << "Document Code: " << getDocumentCode() << endl;
    cout << "Publisher Name: " << getPublisherName() << endl;
    cout << "Number of Copies: " << getNumberofCopies() << endl;
    cout << "Publication date: " << publicationDate << endl;
}