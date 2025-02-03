#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QDate>
//#include <QSqlDatabase>
using namespace std;

bool itemDoubleClicked = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dbManager("C:\\Users\\esaberbari\\Desktop\\my files\\referenzprojekt\\database\\library_database.db")
{
    ui->setupUi(this);


    // Set up the input fields (add these in your UI or construct them programmatically)
    lineEdit_name = new QLineEdit(this);
    lineEdit_lname = new QLineEdit(this);
    lineEdit_age = new QLineEdit(this);
    lineEdit_address = new QLineEdit(this);
    lineEdit_grade = new QLineEdit(this);
    /*
    if (ui->stackedWidget->currentIndex() == 1) {
        cout<<"currentIndex() == 1\n";
    }*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

//======================================================================= Pages
//======================================================================= Page1
void MainWindow::on_pushButton_page1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);


}
//======================================================================= Page2
void MainWindow::on_pushButton_page2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);



    ui->tableWidget_members->setRowCount(0);
    ui->tableWidget_members->setColumnCount(6);
    ui->tableWidget_members->setHorizontalHeaderLabels({"ID", "Name", "Email", "Phone", "Date", "Status"});

    // Make headers bold
    QFont font = ui->tableWidget_members->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget_members->horizontalHeader()->setFont(font);

    // Make table row indices bold
    font = ui->tableWidget_members->verticalHeader()->font();
    font.setBold(true);
    ui->tableWidget_members->verticalHeader()->setFont(font);

    dbManager.setTableWidget(ui->tableWidget_members);
    dbManager.createTable("Members");
    //dbManager.deleteData();
    //dbManager.updateData();
    /*
    dbManager.insertData("Members", "Alice Johnson", "alice.johnson@email.com", "1234567890", "2024-02-01", "Active");
    dbManager.insertData("Members", "Bob Smith", "bob.smith@email.com", "9876543210", "2024-02-02", "Active");
    dbManager.insertData("Members", "Charlie Brown", "charlie.brown@email.com", "5556667777", "2024-02-03", "Inactive");
    dbManager.insertData("Members", "David White", "david.white@email.com", "1112223333", "2024-02-04", "Active");
    dbManager.insertData("Members", "Emma Green", "emma.green@email.com", "4445556666", "2024-02-05", "Active");
    dbManager.insertData("Members", "Frank Harris", "frank.harris@email.com", "7778889999", "2024-02-06", "Inactive");
    dbManager.insertData("Members", "Grace Wilson", "grace.wilson@email.com", "2223334444", "2024-02-07", "Active");
    dbManager.insertData("Members", "Henry Lewis", "henry.lewis@email.com", "9990001111", "2024-02-08", "Active");
    dbManager.insertData("Members", "Isabella Martinez", "isabella.martinez@email.com", "6667778888", "2024-02-09", "Active");
    dbManager.insertData("Members", "Jack Robinson", "jack.robinson@email.com", "3334445555", "2024-02-10", "Inactive");
    */
    dbManager.printData("Members");
}
//======================================================================= Page3
void MainWindow::on_pushButton_page3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);



    ui->tableWidget_books->setRowCount(0);
    ui->tableWidget_books->setColumnCount(6);
    ui->tableWidget_books->setHorizontalHeaderLabels({"ID", "Title", "Author", "ISBN", "Genre", "Status"});

    // Make headers bold
    QFont font = ui->tableWidget_books->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget_books->horizontalHeader()->setFont(font);

    // Make table row indices bold
    font = ui->tableWidget_books->verticalHeader()->font();
    font.setBold(true);
    ui->tableWidget_books->verticalHeader()->setFont(font);

    dbManager.setTableWidget(ui->tableWidget_books);
    dbManager.createTable("Books");
    //dbManager.deleteData();
    //dbManager.updateData();
    /*
    dbManager.insertData("Books", "The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", "Fiction", "Available");
    dbManager.insertData("Books", "To Kill a Mockingbird", "Harper Lee", "9780061120084", "Fiction", "Available");
    dbManager.insertData("Books", "1984", "George Orwell", "9780451524935", "Dystopian", "Available");
    dbManager.insertData("Books", "The Catcher in the Rye", "J.D. Salinger", "9780316769488", "Fiction", "Available");
    dbManager.insertData("Books", "Moby-Dick", "Herman Melville", "9781853260087", "Adventure", "Available");
    dbManager.insertData("Books", "Pride and Prejudice", "Jane Austen", "9780141439518", "Romance", "Available");
    dbManager.insertData("Books", "The Hobbit", "J.R.R. Tolkien", "9780345339683", "Fantasy", "Available");
    dbManager.insertData("Books", "The Lord of the Rings", "J.R.R. Tolkien", "9780618640157", "Fantasy", "Available");
    dbManager.insertData("Books", "War and Peace", "Leo Tolstoy", "9780140447934", "Historical Fiction", "Available");
    dbManager.insertData("Books", "The Odyssey", "Homer", "9780140268867", "Classics", "Available");
    */
    dbManager.printData("Books");
}
//======================================================================= Page4
void MainWindow::on_pushButton_page4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}
//======================================================================= Page5
void MainWindow::on_pushButton_page5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);



    ui->tableWidget_borrowed_books->setRowCount(0);
    ui->tableWidget_borrowed_books->setColumnCount(6);
    ui->tableWidget_borrowed_books->setHorizontalHeaderLabels({"borrow id", "member id", "book id", "borrow date", "return date", "member_id"});

    // Make headers bold
    QFont font = ui->tableWidget_borrowed_books->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget_borrowed_books->horizontalHeader()->setFont(font);

    // Make table row indices bold
    font = ui->tableWidget_borrowed_books->verticalHeader()->font();
    font.setBold(true);
    ui->tableWidget_borrowed_books->verticalHeader()->setFont(font);

    dbManager.setTableWidget(ui->tableWidget_borrowed_books);
    dbManager.createTable("Borrowed_Books");

    dbManager.printData("Borrowed_Books");

}
//=============================================================================

void MainWindow::on_pushButton_borrow_book_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget_members->selectedItems();
    int row = selectedItems[0]->row();
    QTableWidgetItem *member_id= ui->tableWidget_members->item(row, 0);
    if (selectedItems.isEmpty() or !member_id) {
        QMessageBox::warning(this, "Error", "No member selected!");
        return;
    }

    //member_id;

    ui->page_3_books->activateWindow();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_borrow_book_2_clicked()//const int member_id& = "")
{
    // Ensure a book is selected from the books table
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget_books->selectedItems();

    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Error", "No book selected!");
        return;
    }

    if (false)//(!member_id)
    {
        QMessageBox::warning(this, "Error", "No member selected!");
        //return;
        //ui->page_2_members->activateWindow();
        //ui->stackedWidget->setCurrentIndex(1);
    }
    else {
        QList<QTableWidgetItem*> selectedBook = ui->tableWidget_books->selectedItems();
        if (selectedItems.isEmpty()) {
            QMessageBox::warning(this, "Error", "No row selected!");
            return;
        }

        int row = selectedItems[0]->row();
        QTableWidgetItem *book_id = ui->tableWidget_members->item(row, 0);
        int book_idc = ui->tableWidget_books->item(book_id->row(), 0)->text().toInt();

        // Ensure member ID is passed correctly and call the borrowBook function
        if (true){//(member_id > 0) {
            QString borrow_date = QDate::currentDate().toString("yyyy-MM-dd");
            dbManager.borrowBook(3, book_idc, borrow_date.toStdString());
            dbManager.printData("Books"); // Refresh the books table
            QMessageBox::information(this, "Success", "Book borrowed successfully!");
            dbManager.printData("Books");
        } else {
            QMessageBox::warning(this, "Error", "No member selected!");
        }
    }
}


void MainWindow::on_lineEdit_returnPressed()
{
    QString BookID = ui->lineEdit->text();
    if (!BookID.isEmpty()) {
        bookManager.addBook(BookID.toStdString());
        dbManager.insertData("Members",
                             BookID.toStdString(),
                             BookID.toStdString(),
                             BookID.toStdString(),
                             BookID.toStdString(),
                             BookID.toStdString());
        dbManager.printData("Members");
    }
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_update_clicked()
{
    itemDoubleClicked = false;
    dbManager.printData("Members");
}

void MainWindow::on_tableWidget_members_doubleClicked(const QModelIndex &index)
{
    itemDoubleClicked = true;
    //qDebug() << "doubleClicked";
}

void MainWindow::on_tableWidget_members_itemChanged(QTableWidgetItem *item)
{
    // Ensure the signal was triggered by user input
    if (!itemDoubleClicked) {
        //qDebug() << "item not clicked";
        itemDoubleClicked = false;
        return;
    }
    itemDoubleClicked = false;

    QTableWidgetItem *idItem =      ui->tableWidget_members->item(item->row(), 0);
    QTableWidgetItem *nameItem =    ui->tableWidget_members->item(item->row(), 1);
    QTableWidgetItem *lnameItem =   ui->tableWidget_members->item(item->row(), 2);
    QTableWidgetItem *ageItem =     ui->tableWidget_members->item(item->row(), 3);
    QTableWidgetItem *addressItem = ui->tableWidget_members->item(item->row(), 4);
    QTableWidgetItem *gradeItem =   ui->tableWidget_members->item(item->row(), 5);

    if (!idItem)
    {
        if (nameItem != nullptr) {
            QString name = ui->tableWidget_members->item(item->row(), 1)->text();
        }

        if (lnameItem != nullptr) {
            QString lname = ui->tableWidget_members->item(item->row(), 2)->text();
        }

        if (ageItem != nullptr) {
            QString age = ui->tableWidget_members->item(item->row(), 3)->text();
        }

        if (addressItem != nullptr) {
            QString address = ui->tableWidget_members->item(item->row(), 4)->text();
        }

        if (gradeItem != nullptr) {
            QString grade = ui->tableWidget_members->item(item->row(), 5)->text();
        }

        if (nameItem != nullptr && lnameItem != nullptr && ageItem != nullptr && addressItem != nullptr && gradeItem != nullptr)
        {
            QString name =    ui->tableWidget_members->item(item->row(), 1)->text();
            QString lname =   ui->tableWidget_members->item(item->row(), 2)->text();
            QString age =     ui->tableWidget_members->item(item->row(), 3)->text();
            QString address = ui->tableWidget_members->item(item->row(), 4)->text();
            QString grade =   ui->tableWidget_members->item(item->row(), 5)->text();

            dbManager.insertData("Members",
                                 name.toStdString(),
                                 lname.toStdString(),
                                 age.toStdString(),
                                 address.toStdString(),
                                 grade.toStdString());

            dbManager.printData("Members");
        }
    }
    else {
        int id = ui->tableWidget_members->item(item->row(), 0)->text().toInt();
        QString name =    ui->tableWidget_members->item(item->row(), 1)->text();
        QString lname =   ui->tableWidget_members->item(item->row(), 2)->text();
        QString age =     ui->tableWidget_members->item(item->row(), 3)->text();
        QString address = ui->tableWidget_members->item(item->row(), 4)->text();
        QString grade =   ui->tableWidget_members->item(item->row(), 5)->text();

        if (!name.isEmpty() && !lname.isEmpty() && !age.isEmpty() && !address.isEmpty() && !grade.isEmpty()) {
            dbManager.updateData("Members",
                                 id,
                                 name.toStdString(),
                                 lname.toStdString(),
                                 age.toStdString(),
                                 address.toStdString(),
                                 grade.toStdString());
        }
        else
            dbManager.printData("Members");
    }
}

void MainWindow::on_pushButton_delete_member_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget_members->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Error", "No row selected!");
        return;
    }

    int row = selectedItems[0]->row();
    QTableWidgetItem *idItem = ui->tableWidget_members->item(row, 0);

    if (!idItem) {
        QMessageBox::warning(this, "Error", "Cannot delete row without an ID!");
        return;
    }

    if (!dbManager.deleteRowById("Members", idItem->text().toInt())) {
        ui->tableWidget_members->removeRow(row);
        dbManager.printData("Members");
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete row from the database!");
    }

}



void MainWindow::on_lineEdit_search_members_textChanged(const QString &searchKeyword)
{
    dbManager.printData("Members", searchKeyword.toStdString());
}
