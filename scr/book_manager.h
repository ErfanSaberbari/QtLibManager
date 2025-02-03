#pragma once
#include <vector>
#include <string>
using namespace std;

class BookManager
{
    private:
        vector<string> books;

    public:
        void addBook(const string& book);
        vector<string> listBooks() const;
};
