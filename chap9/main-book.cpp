/**
 * @file main-book.cpp
 * @author Timothy Nguyen
 * @brief Testing out Lib namespace members
 * @version 0.1
 * @date 2021-05-29
 * 
 */

#include "include/Library.h"
#include <iostream>

using Lib::Book;    // using Book class in Library namespace
using Lib::Patron;  // using Patron class in Library namespace
using Lib::Genre_t; // using Genre_t enumeration in Library namespace
using std::cout;

int main(){

    try
    {
        /* Test Book constructors */
        Book book1; // test default constructor
        Book book2{{30, 21, 3, 'm'}, "Fifty Shades of Grey", "E.L. James", 2011, Genre_t::romantic}; // OK
        Book book3{{4, 16, 19, 'f'}, "Harry Potter and the Philosopher's Stone", "JK Rowling", 1997, Genre_t::adventure};
        Book book4{{30, 21, 3, 'm'}, "Fifty Shades of Grey", "E.L. James", 2011, Genre_t::romantic};
        // Library::Book book5{{1, 2, 3, 'm'}, "Book", "Bob", 2022}; // not OK, copyright date in the future
        // Library::Book book6{{1, 2, -4, 'm'}, "Book", "Bob", 1990}; // not OK, n must be positive number
        
        /* Test Book member functions */
        book2.checkout();
        book2.checkout(); // already checked out book 2
        book2.checkin();
        book2.checkin();  // already checked in book 2

        /* Test operator overloads for Book class */
        std::cout << book1 << book2 << book3 << book4;
        Lib::areSame(book2, book3); // not the same book
        Lib::areSame(book2, book4); // same book 

        /* Test Patron constructor */
        Patron patron1;
        Patron patron2{"Timothy Nguyen", 123456789}; // 0 fees owed implicitly
        Patron patron3{"Taylor Swift", 1424343, 4.54};
        Patron patron4{"Anne Marie", 1424343, 123.4};
//      Patron patron4{"Adele", -123, 0.2}; // should raise exception, negative library num
//      Patron patron5{"Kanye", 412423, -2.45}; // should raise exception, negative fees owed

        /* Test Patron member functions */
        patron2.update_fee(200.99);
        patron3.update_fee(0);

        /* Test operator overloads for Patron class */
        std::cout << patron1 << patron2 << patron3;

        /* Test Library constructor */
        Lib::Library myLibrary;
        
        /* Test Library member functions */
        myLibrary.add_book(book1);
        myLibrary.add_book(book2);
        myLibrary.add_book(book3);
        myLibrary.add_book(book4);
        myLibrary.add_patron(patron1);
        myLibrary.add_patron(patron2);
        myLibrary.add_patron(patron3);
        myLibrary.add_patron(patron4);

        for(const Book& b : myLibrary.get_books())
            std::cout << b;
        for(const Patron& p : myLibrary.get_patrons())
            std::cout << p;
            
        myLibrary.checkout_book("Timothy Nguyen", // should not work, Timothy owes library fees
                                "Harry Potter and the Philosopher's Stone"); 
        myLibrary.checkout_book("Taylor Swift", // should work, Taylor Swift owes 0 library fees
                                "Harry Potter and the Philosopher's Stone");    

        for(const Lib::Transaction& t : myLibrary.get_transactions())
            std::cout << t.book << " " << t.patron << '\n';        

        cout << "These people owe library fees: \n";
        for(const string& name : myLibrary.whoOwesFees())
            cout << name << '\n';
                          
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        std::cout << "Unknown error\n";
        return 2;
    }

    return 0;
}


