#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication qApplication(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return qApplication.exec();
}
/*
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>  // Include for debug output

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Initialize QML engine
    QQmlApplicationEngine engine;

    // Define QML file path
    QString qmlFile = "C:/Users/esaberbari/Desktop/my files/referenzprojekt/2025_02_Bibliotheksverwaltung_Qt/mainwindow.qml";

    // Load the main QML file
    engine.load(QUrl::fromLocalFile(qmlFile));

    // Check if the QML was loaded properly
    if (engine.rootObjects().isEmpty()) {
        qDebug() << "Failed to load QML file:" << qmlFile; // Debug output
        return -1;
    }

    qDebug() << "QML file loaded successfully!"; // Debug output
    return app.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <sqlite3.h>
//#include <stdio.h>
#include <iostream>

using namespace std;

static int createDB(const char* directory);
static int createTable(const char* directory);
static int deleteData(const char* directory);
static int insertData(const char* directory);
static int updateData(const char* directory);
static int selectData(const char* directory);
static int callback(void* NotUsed, int argc, char** argv, char** azColName);

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    qDebug() << QSqlDatabase::drivers();

    const char* dir = "C:\\Users\\esaberbari\\Desktop\\my files\\referenzprojekt\\database\\STUDENTS.db";

    createDB(dir);
    createTable(dir);
    deleteData(dir); // use prior to insert!
    insertData(dir); // uncomment the deleteData above to avoid duplicates
    updateData(dir);
    selectData(dir);

    return 0;
}

static int createDB(const char* directory)
{
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open(directory, &DB);
    sqlite3_close(DB);
    return 0;
}

static int createTable(const char* directory)
{
    sqlite3 *DB;
    char* messageError;

    string sql = "CREATE TABLE IF NOT EXISTS GRADES("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "NAME      TEXT NOT NULL, "
                 "LNAME     TEXT NOT NULL, "
                 "AGE       INT  NOT NULL, "
                 "ADDRESS   CHAR(50), "
                 "GRADE     CHAR(1) );";

    try
    {
        int exit = 0;
        exit = sqlite3_open(directory, &DB);
        // An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK) {
            cerr << "Error in createTable function." << endl;
            sqlite3_free(messageError);
        }
        else
            cout << "Table created Successfully" << endl;
        sqlite3_close(DB);
    }
    catch (const exception& e)
    {
        cerr << e.what();
    }

    return 0;
}

static int insertData(const char* directory)
{
    sqlite3* DB;
    char* messageError;

    string sql("INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Alice', 'Chapa', 35, 'Tampa', 'A');"
               "INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Bob',  'Lee', 20, 'Dallas', 'B');"
               "INSERT INTO GRADES (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Fred', 'Cooper', 24, 'New York', 'C');");

    int exit = sqlite3_open(directory, &DB);
    // An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error in insertData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Records inserted Successfully!" << endl;

    return 0;
}

static int updateData(const char* directory)
{
    sqlite3* DB;
    char* messageError;

    string sql("UPDATE GRADES SET GRADE = 'A' WHERE LNAME = 'Cooper'");

    int exit = sqlite3_open(directory, &DB);
    // An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error in updateData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Records updated Successfully!" << endl;

    return 0;
}

static int deleteData(const char* directory)
{
    sqlite3* DB;
    char* messageError;

    string sql = "DELETE FROM GRADES;";

    int exit = sqlite3_open(directory, &DB);
    // An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here
    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error in deleteData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Records deleted Successfully!" << endl;

    return 0;
}

static int selectData(const char* directory)
{
    sqlite3* DB;
    char* messageError;

    string sql = "SELECT * FROM GRADES;";

    int exit = sqlite3_open(directory, &DB);
    // An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here
    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

    if (exit != SQLITE_OK) {
        cerr << "Error in selectData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Records selected Successfully!" << endl;

    return 0;
}

// retrieve contents of database used by selectData()
// argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array,
static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
    for (int i = 0; i < argc; i++) {
        // column name and value
        cout << azColName[i] << ": " << argv[i] << endl;
    }

    cout << endl;

    return 0;
}
*/
