#include "header.h"
#include <iostream>
using namespace std;
//Code page with all the functions to make the program run

//creating initial date funciton
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

//function that adds days whenever it is called
void Date::add_days(int days) {
    day += days;
}

//default employee
Employee::Employee(string n) : name(n) {}

//compares the employee queue to see their priority
bool Employee::operator<(const Employee& other) const {
    return (waiting_time - retaining_time) < (other.waiting_time - other.retaining_time);
}

Book::Book(string n, Date start_date) : name(n), circulation_start_date(start_date) {}

//circulates book
void Book::circulate_book(Date circulation_end) {
    circulation_end_date = circulation_end;
}

//removes book
void Book::archive_book() {
    archived = true;
}

//add book to lib
void Library::add_book(string book_name) {
    books[book_name] = new Book(book_name, Date(0, 0, 0)); //temp start date
    cout << "Added book: " << book_name << endl;
}

//Add an employee to the lib
void Library::add_employee(string employee_name) {
    employees[employee_name] = new Employee(employee_name);
    cout << "Added employee: " << employee_name << endl;
}

//circulates a book given book and date
void Library::circulate_book(string book_name, Date start_date) {
    Book* book = books[book_name];
    book->circulate_book(start_date);
    cout << "Book being circulated." << endl;
}

//function that gives the book to the next person in the queue or delents it if neede.
void Library::pass_on(string book_name, Date current_date) {
    Book* book = books[book_name];
    if (!book->queue.empty()) {
        Employee* employee = book->queue.front();
        book->queue.pop();
        employee->retaining_time += current_date.day - book->circulation_start_date.day;
        employee->waiting_time += current_date.day - book->circulation_start_date.day;
        if (book->queue.empty()) {
            book->archive_book();
        }
    }
}

//Adds the employee to a queue for a book
void Library::add_to_queue(string book_name, string employee_name) {
    Book* book = books[book_name];
    Employee* employee = employees[employee_name];
    book->queue.push(employee);
}