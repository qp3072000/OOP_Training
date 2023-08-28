#include "Journal.h"
#include<iostream>

Journal::Journal(const string& code, const string& _publisherName, int num, int _issueNumber, int _publicationMonth)
        : Document(code, _publisherName, num) {
    issueNumber = _issueNumber;
    publicationMonth = _publicationMonth;
}

string Journal::getDocumentType() {
    return "Journal";
}

void Journal::displayInfo() {
    cout << "Document Code: " << getDocumentCode() << endl;
    cout << "Publisher Name: " << getPublisherName() << endl;
    cout << "Number of Copies: " << getNumberofCopies() << endl;
    cout << "Issue Number: " << issueNumber << endl;
    cout << "Publication Month: " << publicationMonth << endl;
}