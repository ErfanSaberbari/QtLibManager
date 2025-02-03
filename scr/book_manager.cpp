#include "book_manager.h"
#include <iostream>
#include <QDebug>
using namespace std;

void BookManager::addBook(const string& book)
{
    books.push_back(book);
    cout    << "Book added: " << book << "\n";
    qDebug()<< "Book added: " << book << "\n";
}

vector<string> BookManager::listBooks() const
{
    return books;
    qDebug() << "\nBooks: ";
    for (const auto& book : books)
    {
        cout << "Book: " << book << "\n";
        qDebug() << book;
    }
}
