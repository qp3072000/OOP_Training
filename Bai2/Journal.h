#ifndef H_JOURNAL_H
#define H_JOURNAL_H

#include "document.h"

class Journal : public Document {
private:
    int issueNumber;
    int publicationMonth;

public:
    Journal(const string& code, const string& _publisherName, int num, int _issueNumber, int _publicationMonth);

    string getDocumentType();
    void displayInfo();
};

#endif