#include"Book.h"
#include<iostream>

Book::Book(const string& code, const string& _publisherName, int num, const string& _authorName, int _numberOfPages)
    :Document(code, _publisherName, num) {
    authorName = _authorName;
    numbOfPages = _numberOfPages;
}
string Book::getDocumentType() {
    return "Book";
}

void Book::displayInfo() {
    cout << "Document code: " << getDocumentCode() << endl;
    cout << "Publisher name: " << getPublisherName() << endl;
    cout << "Number of Copies: " << getNumberofCopies() << endl;
    cout << "Author name: " << authorName << endl;
    cout << "Number of pages: " << numbOfPages << endl;
}