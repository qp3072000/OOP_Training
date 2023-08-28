#pragma once

#include "borrowcard.h"
#include <vector>

class Library {
public:
    void addBorrowCard(const BorrowCard& borrowCard);
    void removeBorrowCard(int borrowCode);
    void displayBorrowCards();

private:
    vector<BorrowCard> borrowCardList;
};