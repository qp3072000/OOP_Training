#include<iostream>
#include"document.h"

Document::Document() {
    text = "";
}

Document::Document(const string& st) {
    text = st;
}

void Document::enterText() {
    cout << "Enter text: ";
    cin.ignore();
    getline(cin, text);
    int startPos = text.find_first_not_of(" \t\r\n");
    if (startPos != string::npos) {
        text = text.substr(startPos);
    }
    int endPos = text.find_last_not_of(" \t\r\n");
    if (endPos != string::npos) {
        text = text.substr(0, endPos + 1);
    }
}

string Document::getText() {
    return text;
}

int Document::countWords() {
    int wordCount = 0;
    bool inWord = false;
    
    for(char c : text) {
        if((c >= 'a' && c <= 'z') || (c >='A' && c <= 'Z')) {
            if(!inWord) {
                inWord = true;
                wordCount++;
            } 
        } else {
                inWord = false;
        }
    }
    return wordCount;
}

int Document::countACharacters() {
    int count = 0;
    for(char c: text) {
        if(toupper(c) == 'A') {
            count++;
        }
    }
    return count;
}

void Document::normalizeText() {
    int firstNonSpace = text.find_first_not_of(" \t\r\n");
    int lastNonSpace = text.find_last_not_of(" \t\r\n");

    if (firstNonSpace == string::npos || lastNonSpace == string::npos) {
        text = "";
    } else {
        text = text.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
    }

    int position = 0;
    while ((position = text.find("  ", position)) != string::npos) {
        text.replace(position, 2, " ");
    }
}
