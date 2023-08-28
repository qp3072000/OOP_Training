#ifndef H_DOCUMENT_H
#define H_DOCUMENT_H

#include<string>
#include<memory>

using namespace std;

class Document {
private:
    string documentCode;
    string publisherName;
    int numberOfCopies;
public:
    Document(const string& code, const string& name, int num);
    virtual ~Document();

    string getDocumentCode();
    string getPublisherName();
    int getNumberofCopies();
    virtual string getDocumentType() = 0;
    virtual void displayInfo() = 0;
};

#endif