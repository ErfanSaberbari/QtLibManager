#pragma once
#include <sqlite3.h>
#include <string>
#include <iostream>
#include <QTableWidget>
using namespace std;

class DBManager
{
private:
    QTableWidget *tableWidget; //pointer to QTableWidget
    string dbPath;
    sqlite3* DB;

    static int callback(void* NotUsed, int argc, char** argv, char** azColName);

public:
    explicit DBManager(const string& dbPath);
    ~DBManager();

    void setTableWidget(QTableWidget* &tableWidget);

    int executeSQL(const string& sql);
    int createTable(const string& tableName);

    int insertData(const string& tableName,
                   const string& col1,
                   const string& col2,
                   const string& col3,
                   const string& col4,
                   const string& col5);

    int updateData(const string& tableName,
                   const int& ID,
                   const string& col1,
                   const string& col2,
                   const string& col3,
                   const string& col4,
                   const string& col5);
    int deleteData();
    bool deleteRowById(const string& tableName, const int& id);
    int printData(const string& tableName, const string& keyword = "");
    int searchData(const string& keyword = "");

    int borrowBook(int member_id, int book_id, const string& borrow_date);
    int returnBook(int borrow_id, const string& return_date);
};
