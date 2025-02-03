#pragma once
#include <QMainWindow>
#include "dbmanager.h"
#include "book_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_page1_clicked();
    void on_pushButton_page2_clicked();
    void on_pushButton_page3_clicked();

    void on_pushButton_borrow_book_clicked();
    void on_pushButton_update_clicked();
    void on_lineEdit_returnPressed();
    void on_pushButton_delete_member_clicked();

    void on_tableWidget_members_itemChanged(QTableWidgetItem *item);
    void on_tableWidget_members_doubleClicked(const QModelIndex &index);

    void on_lineEdit_search_members_textChanged(const QString &arg1);

    void on_pushButton_borrow_book_2_clicked();

    void on_pushButton_page4_clicked();

    void on_pushButton_page5_clicked();

private:
    void updateTable();
    Ui::MainWindow *ui;
    BookManager bookManager;
    DBManager dbManager;

    int currentRow = -1; // Track the currently edited row
    QLineEdit *lineEdit_name;   // Input fields for editing
    QLineEdit *lineEdit_lname;
    QLineEdit *lineEdit_age;
    QLineEdit *lineEdit_address;
    QLineEdit *lineEdit_grade;
};
