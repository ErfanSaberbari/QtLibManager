#include "dbmanager.h"
using namespace std;

DBManager::DBManager(const string& dbPath) : dbPath(dbPath), DB(nullptr)
{
    if (sqlite3_open(dbPath.c_str(), &DB)) {
        cerr << sqlite3_errmsg(DB) << endl;
        DB = nullptr;
    }
}

DBManager::~DBManager()
{
    if(DB) {
        sqlite3_close(DB);
    }
}

void DBManager::setTableWidget(QTableWidget* &tableWidget)
{
    this->tableWidget = tableWidget;
}

int DBManager::executeSQL(const string& sql) {
    if (!DB) return -1;

    char* messageError = nullptr;
    int exit = sqlite3_exec(DB, sql.c_str(), nullptr, nullptr, &messageError);
    if (exit != SQLITE_OK) {
        cerr << messageError << endl;
        sqlite3_free(messageError);
        return -1;
    }
    return 0;
}

int DBManager::createTable(const string& tableName) {
    string sql;
    if (tableName == "Members") {
        sql = "CREATE TABLE IF NOT EXISTS " + tableName +
              " ("
              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
              "name TEXT NOT NULL, "
              "email TEXT UNIQUE NOT NULL, "
              "phone_number TEXT NOT NULL, "
              "membership_date DATE NOT NULL, "
              "status TEXT CHECK(status IN ('Active', 'Inactive')) DEFAULT 'Active'"
              ");";
        return executeSQL(sql);
    }
    else if (tableName == "Books") {
        sql = "CREATE TABLE IF NOT EXISTS " + tableName +
              " ("
              "id INTEGER PRIMARY KEY AUTOINCREMENT,"
              "title TEXT NOT NULL,"
              "author TEXT NOT NULL,"
              "isbn TEXT UNIQUE NOT NULL,"
              "genre TEXT NOT NULL,"
              "status TEXT CHECK(status IN ('Available', 'Borrowed')) DEFAULT 'Available'"
              ");";
        return executeSQL(sql);
    }
    else if (tableName == "Borrowed_Books") {
        sql = "CREATE TABLE IF NOT EXISTS " + tableName +
              " ("
              "borrow_id INTEGER PRIMARY KEY AUTOINCREMENT,"
              "member_id INTEGER NOT NULL,"
              "book_id INTEGER NOT NULL,"
              "borrow_date DATE NOT NULL,"
              "return_date DATE,"
              "FOREIGN KEY (member_id) REFERENCES Members(member_id),"
              "FOREIGN KEY (book_id) REFERENCES Books(book_id)"
              ");";
        return executeSQL(sql);
    }
    else {
        cerr << "createTable() error: Unknown table name " << tableName << endl;
        return -1;
    }
}

int DBManager::insertData(const string& tableName,
                          const string& col1,
                          const string& col2,
                          const string& col3,
                          const string& col4,
                          const string& col5)
{

    string sql;
    if (tableName == "Members") {
        sql = "INSERT INTO Members (name, email, phone_number, membership_date, status) VALUES ('"
              + col1 + "', '" + col2 + "', '" + col3 + "', '" + col4 + "', '" + col5 + "');";
    }
    else if (tableName == "Books") {
        sql = "INSERT INTO Books (title, author, isbn, genre, status) VALUES ('"
              + col1 + "', '" + col2 + "', '" + col3 + "', '" + col4 + "', '" + col5 + "');";
    }
    else if (tableName == "Borrowed_Books") {
        sql = "INSERT INTO Books (borrow_id, author, isbn, genre, status) VALUES ('"
              + col1 + "', '" + col2 + "', '" + col3 + "', '" + col4 + "', '" + col5 + "');";
    }
    else {
        cerr << "Error: Unknown table name " << tableName << endl;
        return -1;
    }

    return executeSQL(sql);
}

int DBManager::updateData(const string& tableName,
                          const int& ID,
                          const string& col1,
                          const string& col2,
                          const string& col3,
                          const string& col4,
                          const string& col5)
{
    string sql;
    if (tableName == "Members") {
        sql = "UPDATE Members SET name = '" + col1 + "', "
                       "email = '" + col2 + "', "
                       "phone_number = '" + col3 + "', "
                       "membership_date = '" + col4 + "', "
                       "status = '" + col5 + "' "
                       "WHERE id = " + to_string(ID) + ";";
    }
    else if (tableName == "Books") {
        sql = "UPDATE Books SET title = '" + col1 + "', "
                       "author = '" + col2 + "', "
                       "isbn = '" + col3 + "', "
                       "genre = '" + col4 + "', "
                       "status = '" + col5 + "' "
                       "WHERE id = " + to_string(ID) + ";";
    }
    else {
        cerr << "Error: Unknown table name " << tableName << endl;
        return -1;
    }

    return executeSQL(sql);
}

int DBManager::deleteData() {
    return executeSQL("DELETE FROM Members;");
}

bool DBManager::deleteRowById(const string& tableName, const int& id) {
    return executeSQL("DELETE FROM " + tableName + "WHERE id = " + to_string(id) + ";") != 0;
}

int DBManager::searchData(const string& keyword)
{
    //return executeSQL("DELETE FROM Members;");



}

int DBManager::printData(const string& tableName, const string& keyword)
{
    if (!DB) return -1;
    char* messageError = nullptr;
    tableWidget->setRowCount(0);//start from row 0

    string sql;
    if (tableName == "Members") {
        sql = "SELECT * FROM Members";
        if (!keyword.empty()) {
            sql += " WHERE name LIKE '%" + keyword + "%' OR "
                               "email LIKE '%" + keyword + "%' OR "
                               "phone_number LIKE '%" + keyword + "%' OR "
                               "membership_date LIKE '%" + keyword + "%' OR "
                               "status LIKE '%" + keyword + "%'";
        }
    }
    else if (tableName == "Books") {
        sql = "SELECT * FROM Books";
        if (!keyword.empty()) {
            sql += " WHERE title LIKE '%" + keyword + "%' OR "
                               "author LIKE '%" + keyword + "%' OR "
                               "isbn LIKE '%" + keyword + "%' OR "
                               "genre LIKE '%" + keyword + "%' OR "
                               "status LIKE '%" + keyword + "%'";
        }
    }
    else if (tableName == "Borrowed_Books") {
        sql = "SELECT * FROM Borrowed_Books";
        if (!keyword.empty()) {
            sql += " WHERE title LIKE '%" + keyword + "%' OR "
                               "author LIKE '%" + keyword + "%' OR "
                               "isbn LIKE '%" + keyword + "%' OR "
                               "genre LIKE '%" + keyword + "%' OR "
                               "status LIKE '%" + keyword + "%'";
        }
    }
    else {
        cerr << "Error: Unknown table name " << tableName << endl;
        return -1;
    }

    int exit = sqlite3_exec(DB, sql.c_str(), callback, tableWidget, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error in printData function." << endl;
        sqlite3_free(messageError);
        return -1;
    }

    tableWidget->setRowCount(tableWidget->rowCount() + 1);
    return 0;
}

int DBManager::callback(void* NotUsed, int argc, char** argv, char** azColName)
{
    QTableWidget* tableWidget = static_cast<QTableWidget*>(NotUsed);

    if (tableWidget != nullptr) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);

        for (int i = 0; i < argc; i++) {
            // column name and value
            tableWidget->setItem(row, i, new QTableWidgetItem(argv[i] ? argv[i] : "NULL"));
        }
    }
    return 0;
}

int DBManager::borrowBook(int member_id, int book_id, const string& borrow_date)
{
    if (!DB) return -1;

    // Check if the book is already borrowed
    string checkSql = "SELECT status FROM Books WHERE id = " + to_string(book_id) + ";";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(DB, checkSql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Error checking book status: " << sqlite3_errmsg(DB) << endl;
        return -1;
    }

    string bookStatus = "Available";
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        bookStatus = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    }
    sqlite3_finalize(stmt);

    if (bookStatus != "Available") {
        cerr << "Book is already borrowed!" << endl;
        return -1;
    }

    // Insert into Borrowed_Books table
    string sql = "INSERT INTO Borrowed_Books (member_id, book_id, borrow_date) VALUES ("
                 + to_string(member_id) + ", " + to_string(book_id) + ", '" + borrow_date + "');";

    if (executeSQL(sql) != 0) {
        cerr << "Error borrowing book!" << endl;
        return -1;
    }

    // Update book status to "Borrowed"
    string updateSql = "UPDATE Books SET status = 'Borrowed' WHERE id = " + to_string(book_id) + ";";
    return executeSQL(updateSql);
}

int DBManager::returnBook(int borrow_id, const string& return_date)
{
    if (!DB) return -1;

    // Get the book ID associated with the borrow_id
    string book_id_sql = "SELECT book_id FROM Borrowed_Books WHERE borrow_id = " + to_string(borrow_id) + ";";
    sqlite3_stmt* stmt;
    int book_id = -1;

    if (sqlite3_prepare_v2(DB, book_id_sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            book_id = sqlite3_column_int(stmt, 0);
        }
    }
    sqlite3_finalize(stmt);

    if (book_id == -1) {
        cerr << "Error: Borrow record not found!" << endl;
        return -1;
    }

    // Update return date in Borrowed_Books table
    string sql = "UPDATE Borrowed_Books SET return_date = '" + return_date +
                 "' WHERE borrow_id = " + to_string(borrow_id) + ";";

    if (executeSQL(sql) != 0) {
        cerr << "Error updating return date!" << endl;
        return -1;
    }

    // Update book status to "Available"
    string updateSql = "UPDATE Books SET status = 'Available' WHERE id = " + to_string(book_id) + ";";
    return executeSQL(updateSql);
}
