#ifndef  BOOK_H
#define  BOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include "title.h"
#include "test.h"

class Book :public Title{
public:
    static int total;

    friend class Clerk;

    Book(){  }
    Book( const std::string& bookname, const std::string& author, const std::string& isbn, 
          const double& price, const int& num );
    Book( const Title& title, const double price, const int num );
    Book( const Book& book );

    ~Book(){  }

    Book& Book::operator=( Book& obj );
    bool Book::operator==( const Book& obj );

    double getPrice() const { return price; }
    void setPrice( double p ){ price = p; }
    int getTotal() const { return Book::total; }
    void setTotal( int t ){ Book::total = t; }
    int getNum() const { return num; }
    void setNum( int t ){ num = t; }

private:
    double price{ 0.0 };
    int num{ 0 };
};

int Book::total = 0;

Book::Book( const std::string& bookname, const std::string& author, const std::string& isbn, 
    const double& price, const int& num ) :
    Title( bookname, author, isbn ), price( price ), num( num )
{
   
   // printCtorType("Book",ctor_type(0));
}
Book::Book( const Title& title, const double price, const int num ) :
    Title( title ), price( price ), num( num )
{ 
    
   // printCtorType( "Book", ctor_type( 0 ) );
}

Book::Book( const Book& book) : 
    Title( book.getBookName(), book.getAuthor(), book.getISBN()), 
    price( book.getPrice() ), num( book.getNum() )
{ 
    
   // printCtorType( "Book", ctor_type( 1 ) );
}

Book& Book::operator=( Book& obj ){

    this->setBookName( obj.getBookName() );
    this->setAuthor( obj.getAuthor() );
    this->setISBN( obj.getISBN() );
    this->setPrice(obj.getPrice());
    this->setNum( obj.getNum() );

    return *this;
}

inline bool Book::operator==( const Book & obj )
{
    if ( ( this->getBookName() == obj.getBookName() ) && \
        ( this->getAuthor() == obj.getAuthor() ) && \
        ( this->getISBN() == obj.getISBN() ) && \
        ( this->getPrice() == obj.getPrice() )  \
        )
        return TRUE;
    else
        return FALSE;
        
}







#endif



