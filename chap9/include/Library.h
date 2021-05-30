#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

namespace Lib{

enum class Genre_t {sports, comedy, romantic, selfhelp, food, adventure};

class ISBN_t
{
    public:
        ISBN_t(int _n1 = 0, int _n2 = 0, int _n3 = 0, char _x = 'x'); // initialize and check for valid isbn
        string get_ISBN() const; // return ISBN as a string, non-modifying

    private:
        int n1, n2, n3;
        char x;
};

class Book{
    public:
        Book(ISBN_t _ISBN = ISBN_t{}, 
            string _title = "Deep Work",  
            string _author = "Cal Newport", 
            int _copy_date = 2021, 
            Genre_t genre = Genre_t::selfhelp); 

        // Non-modifying operations:
        string get_ISBN() const { return ISBN; };
        string get_title() const { return title; };
        string get_author() const { return author; };
        string get_genre() const;
        int get_date() const { return copyright_date; };
        bool get_status() const { return checked_out; }; 

        // Modifying operations:
        void checkout(); // check out book
        void checkin(); // check in book

    private:
        string ISBN, title, author;
        Genre_t genre;
        int copyright_date;
        bool checked_out; 
};

class Patron
{
    public: 
        Patron(string _username = "NA", int _library_num = 0, double _fees = 0);

        // Non-modifying functions: 
        string get_username() const { return username; };
        int get_librarynum() const { return library_num; };
        double get_libraryfees() const { return fees; };

        // Modifying functions:
        void update_fee(double fee);

    private: 
        string username;
        int library_num;
        double fees;
        bool owes_fee;
};

typedef struct
{
    Book book;
    Patron patron;
} Transaction;

class Library
{
    public:
        Library() { std::cout << "Created a library!" << '\n'; } 
        void add_book(const Book& book) { books.push_back(book); }
        void add_patron(const Patron& patron) { patrons.push_back(patron); }
        bool checkout_book(const string& username, const string& book_title); // checkout book by book_title
        const vector<string>& whoOwesFees(); 

        const vector<Book>& get_books() const { return books; };
        const vector<Patron>& get_patrons() const { return patrons; };
        const vector<Transaction>& get_transactions() const { return transactions;}

    private:
        vector<Book> books;
        vector<Patron> patrons;
        vector<Transaction> transactions;
};

/* Operator overloads */
bool operator==(const Book& book1, const Book& book2);
bool operator!=(const Book& book1, const Book& book2);
std::ostream& operator<<(std::ostream& os, const Book& b);
std::ostream& operator<<(std::ostream& os, const Patron& b);

/* Helper functions */
void areSame(const Book& book1, const Book& book2);
bool owesFee(const Patron& p);
}




#endif 