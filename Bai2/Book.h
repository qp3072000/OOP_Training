#ifndef H_BOOK_H
#define H_BOOK_H
#include"document.h"

class Book : public Document {
private:
    string authorName;
    int numbOfPages;
public:
    Book(const string& code, const string& _publisherName, int num, const string& _authorName, int _numberOfPages);
    string getDocumentType();
    void displayInfo();
};

#endif