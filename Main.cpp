#include <iostream>
#include "header.h"

using namespace std;

//main function that does the code from the program requirement
int main() {
    Library library;

    library.add_book("Software Engineering");
    library.add_book("Chemistry");

    library.add_employee("Adam");
    library.add_employee("Sam");
    library.add_employee("Ann");

    library.circulate_book("Software Engineering", Date(1, 4, 2015));
    library.circulate_book("Chemistry", Date(1, 3, 2015));

    library.add_to_queue("Software Engineering", "Ann");
    library.add_to_queue("Software Engineering", "Sam");
    library.add_to_queue("Software Engineering", "Adam");

    library.add_to_queue("Chemistry", "Ann");
    library.add_to_queue("Chemistry", "Sam");
    library.add_to_queue("Chemistry", "Adam");

    library.pass_on("Software Engineering", Date(5, 4, 2015));
    library.pass_on("Chemistry", Date(5, 3, 2015));//tell the next employee to pass the book on March 5, 2015
    library.pass_on("Chemistry", Date(7, 3, 2015));
    library.pass_on("Chemistry", Date(15, 3, 2015)); //at this point in time, the system will archive the chemistry book.
    library.pass_on("Software Engineering", Date(10, 4, 2015));
    library.pass_on("Software Engineering", Date(15, 4, 2015));

    return 0;
}