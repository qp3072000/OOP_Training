#ifndef H_PAPER_H
#define H_PAPER_H

#include"document.h"

class Paper :public Document {
private:
    string publicationDate;
public:
    Paper(const string& _documentCode, const string& _publisherName, int _numberOfCopies, const string& _publicationDate);

    string getDocumentType();
    void displayInfo();
};

#endif