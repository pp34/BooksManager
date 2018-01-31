#ifndef  DATA_H
#define  DATA_H

#include <iostream>
#include <vector>
#include <string>

#include "customer.h"
#include "book.h"

class Clerk;

struct BookList{
    std::vector<Book> book;
    int total;
    void clear();
};

struct SalesData{
    std::vector<Customer> vip;
    std::vector<Loan> loan;
    std::vector<Clerk> clerk;
    void clear();
};

void BookList::clear(){
    if(!book.empty())
        book.clear();
}

void SalesData::clear(){
    if ( !vip.empty() )
        vip.clear();
    if ( !loan.empty() )
        loan.clear();
    if ( !clerk.empty() )
        clerk.clear();
}


#endif



