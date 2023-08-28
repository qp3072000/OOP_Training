#pragma once
#include"student.h"

class BorrowCard {
private:
    int borrowCode;
    int borrowDate;
    int dueDate;
    int bookNumber;
    Student student;
public:
    BorrowCard(int _borrowCode, int _borrowDate, int _dueDate, int _bookNumber, const Student& student);

    int getBorrowCode();
    int getBorrowDate();
    int getDueDate();
    int getBookNumber();
    const Student& getStudent();
};