#pragma once
#include<string>

using namespace std;

class Document {
private:
    string text;
public:
    Document();
    Document(const string& st);

    void enterText();
    string getText();
    int countWords();
    int countACharacters();
    void normalizeText();
};