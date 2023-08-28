#include"borrowcard.h"

BorrowCard::BorrowCard(int _borrowCode, int _borrowDate, int _dueDate, int _bookNumber, const Student& _student) {
    borrowCode = _borrowCode;
    borrowDate = _borrowDate;
    dueDate = _dueDate;
    bookNumber = _bookNumber;
    student = _student;
}

int BorrowCard::getBorrowCode() {
    return borrowCode;
}

int BorrowCard::getBorrowDate() {
    return borrowDate;
}

int BorrowCard::getDueDate() {
    return dueDate;
}

int BorrowCard::getBookNumber() {
    return bookNumber;
}

const Student& BorrowCard::getStudent(){
    return student;
}