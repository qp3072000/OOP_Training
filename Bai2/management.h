#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <vector>
#include <memory>
#include "document.h"

class DocumentManager {
public:
    DocumentManager();

    void addNewDocument(shared_ptr<Document> document);
    void removeDocument(const string& documentCode);
    void displayDocumentInfo(const string& documentCode);
    void searchByType(const string& type);
    void exitProgram();

private:
    vector<shared_ptr<Document>> documentList;
};

#endif
