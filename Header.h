#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

//Date class with functions
class Date {
public:
    int day, month, year;
    Date(int d = 1, int m = 1, int y = 2000);
    bool operator<(const Date& other) const;
    void add_days(int days);
};

//Employee class with functions
class Employee {
public:
    string name;
    int waiting_time = 0;
    int retaining_time = 0;
    Employee(string n);
    bool operator<(const Employee& other) const;
};

//Book class with functions
class Book {
public:
    string name;
    Date circulation_start_date;
    Date circulation_end_date;
    bool archived = false;
    queue<Employee*> queue;
    Book(string n, Date start_date);
    void circulate_book(Date circulation_end);
    void archive_book();
};

//Library class with functios
class Library {
private:
    unordered_map<string, Book*> books;
    unordered_map<string, Employee*> employees;
public:
    void add_book(string book_name);
    void add_employee(string employee_name);
    void circulate_book(string book_name, Date start_date);
    void pass_on(string book_name, Date current_date);
    void add_to_queue(string book_name, string employee_name);
};

#endif