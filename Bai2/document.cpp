#include"document.h"
#include<iostream>

Document::Document(const string& code, const string& name, int num) {
    documentCode = code;
    publisherName = name;
    numberOfCopies = num;
}

Document::~Document() {}

string Document::getDocumentCode() {
    return documentCode;
}

string Document::getPublisherName() {
    return publisherName;
}

int Document::getNumberofCopies() {
    return numberOfCopies;
}