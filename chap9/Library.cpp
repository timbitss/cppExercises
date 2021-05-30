/**
 * @file Book.cpp
 * @author Timothy Nguyen
 * @brief Store definitions for Book class
 * @version 0.1
 * @date 2021-05-29
 * 
 */

#include <iostream>
#include <algorithm>
#include "include/Library.h"


using std::to_string;

namespace Lib{

ISBN_t::ISBN_t(int _n1, int _n2, int _n3, char _x):
                n1(_n1), n2(_n2), n3(_n3), x(_x)
{
    // Error checking
    if(n1 < 0 || n2 < 0 || n3 < 0) 
        throw std::runtime_error("Invalid ISBN, n must be positive integer\n");
    if(!isalpha(x) && !isdigit(x))
        throw std::runtime_error("Invalid ISBN: x must be digit or letter");
}

/**
 * @brief Returns ISBN as a string
 * 
 */
string ISBN_t::get_ISBN() const
{
    string ISBN;
    ISBN = to_string(n1) + '-' + to_string(n2) + '-' + to_string(n3) + '-' + x;
    return ISBN;
}
    
Book::Book(ISBN_t _ISBN, string _title, string _author, int _copy_date, Genre_t _genre):
            ISBN{_ISBN.get_ISBN()}, title{_title}, author{_author}, copyright_date{_copy_date}, checked_out{false}, genre{_genre}
{
    if(copyright_date < 0 || copyright_date > 2021) throw std::runtime_error("Invalid date.\n");
    
    std::cout << "Added " << title << " to library\n";
}

/**
 * @brief Get book genre
 * 
 * @return string genre as a string
 */
string Book::get_genre() const
{
    switch(genre)
    {
        case Genre_t::adventure:
            return "adventure";
        case Genre_t::comedy:
            return "comedy";
        case Genre_t::food:
            return "food";
        case Genre_t::romantic:
            return "romantic";
        case Genre_t::selfhelp:
            return "selfhelp";
        case Genre_t::sports:
            return "sports";
        default:
            throw std::runtime_error("Could not identify genre.");
    }

}
/**
 * @brief Check book out
 * 
 */
void Book::checkout() 
{
    if(checked_out)
        std::cout << "Already checked out " << title << '\n';
    else
    {
        checked_out = true;
        std::cout << "Checked out " << title << '\n';
    }
}

/**
 * @brief Check book in
 * 
 */
void Book::checkin() 
{
    if(!checked_out)
        std::cout << "Already checked in " << title << '\n';
    else
    {
        checked_out = false;
        std::cout << "Checked in " << title << '\n';
    }
}

Patron::Patron(string _username, int _library_num, double _fees): 
    username{_username}, library_num{_library_num}, fees(_fees), owes_fee(_fees > 0 ? true: false) 
{
    // Error checking after initialization
    if (library_num < 0) throw std::runtime_error("Can not have negative library num");
    if (fees < 0) throw std::runtime_error("Can not have negative fees owed");
    std::cout << "Added patron " << username << " to database.\n";
}

/**
 * @brief Set or clear fee that the patron owes
 * 
 * @param fee Fee in CAD
 * @pre fee must be greater than or equal to 0
 */
void Patron::update_fee(double fee)
{
    if (fee < 0 ) throw std::runtime_error("Fee can not be negative number.");
    else if(fee == 0)
    {
        fees = 0;
        owes_fee = false;
        std::cout << username << " no longer owes money.\n";
    }
    else
    {
        fees = fee;
        owes_fee = true;
        std::cout << username << " owes fee of $" << fee << '\n';
    }
}

/**
 * @brief Checkout book
 * 
 *        Both username and book must be in library.
 *        Patron must also owe no fees to the library. 
 * 
 * @param book_title
 * @return true if book was checked out
 *         false if book could not be checked out for various reasons 
 */
bool Library::checkout_book(const string& username, const string& book_title)
{
    for(const Patron& p : patrons)
    { 
        if(p.get_username() == username && owesFee(p) == false)
        {
            for(Book& b : books)
            {
                if(b.get_title() == book_title && b.get_status() == false)
                {
                    transactions.push_back(Transaction{b, p});
                    b.checkout();
                    std::cout << "Checked out " << book_title << " for " << username << '\n';
                    return true;
                }
            }
        }
    }

    std::cout << "Could not check out " << book_title << " for " << username << '\n';
    return false;
}

/**
 * @brief Return a vector that constains the names of all patrons who owe fees
 * 
 * @return const vector<string>& Vector of names that owe fees to library 
 */
const vector<string>& Library::whoOwesFees()
{
    static vector<string> feeList; 
    for(const Patron& p : patrons)
    {
        if(owesFee(p) == true)
        {
            if(feeList.empty() || find(feeList.begin(), feeList.end(), p.get_username()) == feeList.end())
                feeList.push_back(p.get_username());
        }
    }
    return feeList;
}

/**
 * @brief Check if two books have the same ISBN
 * 
 * @param book1 Constant reference to book 1
 * @param book2 Constant reference to book 2
 * @return true if ISBNs are equal,
 *         false if ISBns are not equal
 */
bool operator==(const Book& book1, const Book& book2)
{
    return book1.get_ISBN() == book2.get_ISBN();
}

/**
 * @brief Check if two books have different ISBNs
 * 
 * @param book1 Constant reference to book 1
 * @param book2 Constant reference to book 2
 * @return true if ISBNs are not equal,
 *         false if ISBns are equal
 */
bool operator!=(const Book& book1, const Book& book2)
{
    return !(book1 == book2);
}

/**
 * @brief Print title, author, and ISBN of book on separate lines.
 * 
 * @param os Standard output stream.
 * @param b Constant reference to book object.
 * @return std::ostream& Reference to output stream
 */
std::ostream& operator<<(std::ostream& os, const Book& b)
{
    return os << "Title: " << b.get_title() << '\n'
              << "Author: " << b.get_author() << '\n'
              << "Genre: " << b.get_genre() << '\n'
              << "ISBN: " << b.get_ISBN() << '\n';
}

/**
 * @brief Print username, library number, and fees owed of patron on separate lines.
 * 
 * @param os Standard output stream.
 * @param b Constant reference to a patron object.
 * @return std::ostream& Reference to output stream
 */
std::ostream& operator<<(std::ostream& os, const Patron& p)
{
    return os << "Username: " << p.get_username() << '\n'
              << "Library Number: " << p.get_librarynum() << '\n'
              << "Owed fees: " << p.get_libraryfees() << '\n';
}  


/**
 * @brief Check if two books based on ISBN are the same and print result
 * 
 * @param book1 Constant reference to book #1
 * @param book2 Constant reference to book #2 to compare to book #1
 */
void areSame(const Book& book1, const Book& book2)
{
    if(book1 == book2)
        std::cout << "They are the same book!\n";
    else
        std::cout << "They are not the same book!\n";
}

/**
 * @brief Check if patron owes fees to the library
 * 
 * @param p a Patron object
 * @return true if patron owes fee, false otherwise 
 */
bool owesFee(const Patron& p)
{
    if(p.get_libraryfees() > 0)
        return true;
    else
        return false;
}


}



