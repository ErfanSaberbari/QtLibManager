# QtLibManager: Library Management System
A **C++ application** built with **Qt** for managing books, members, and borrowing activities. It uses **SQLite** for persistent data storage, ensuring efficient management of library records.<br/>

![screenshot](https://github.com/user-attachments/assets/12d1e77c-0cd1-4069-860f-488e95747eda)

## Features
- **Member Management:** Allows administrators to manage member information, including adding, updating, and deleting member records. Members' details such as name, age, address, and grade are stored in the system.


- **Book Management:** Administrators can manage books, including adding new books, updating book details, and marking them as available or unavailable. Each book record contains information such as title, author, ISBN, and genre.

- **Borrowing System**: Members can borrow books, with records of borrowed books including member ID, book ID, borrow date, and return date. The system handles the relationship between members and books, ensuring proper tracking of borrowed items.

- **Search Functionality**: A search feature enables administrators to quickly find members or books based on keywords. The search results are dynamically updated as you type.

- **Database Integration**: The application interacts with an SQLite database to store and retrieve information. All member and book data is maintained within the database, ensuring persistent storage and easy access.

- **Table Management**: Member and book records are displayed in tables, making it easy to view and manage large datasets. Table rows can be selected for editing, and changes are automatically saved to the database.

- **Error Handling**: The system provides informative warnings and error messages for actions like selecting invalid rows or missing information, helping users correct mistakes quickly.

## Requirements
- Qt Creator
- SQLite (for database management)
- C++ compiler (e.g., GCC, MSVC)

## Setup<sub><sup>*</sup></sub>
1. Clone or download the repository to your local machine.
2. Open the project in Qt Creator or another compatible IDE.
3. Build the project using the provided build settings.
4. Ensure the database file (`library_database.db`) is in the correct directory, or update the path in the code to reflect your local setup.
5. Run the application and interact with the library management features.<br/>
<sub><sup>*not tested yet!</sup></sub>

## Usage
- **Managing Members:** Admin users can add new members, update existing records, or delete members from the system. Member data is stored securely in the database, with a simple interface for entering and editing information.

- **Managing Books:** Admins can add books to the library's collection, update book details (such as title and author), or mark books as unavailable.

- **Borrowing and Returning Books:** Members can borrow books by selecting them from the list of available books, and the application tracks borrowing information, including return dates.

- **Search:** Use the search bar to filter members or books based on specific keywords.

## License
This project is open-source and available under the [MIT License](https://opensource.org/license/mit/).
