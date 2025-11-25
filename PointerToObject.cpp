// PointerToObject.cpp
#include <iostream>
using namespace std;

class Lecturer {
public:
    string name;
    string course;

    void display() {
        cout << "Lecturer: " << name << ", Course: " << course << endl;
    }
};

int main() {
    // Access using dot notation
    Lecturer lec1;
    lec1.name  = "Dr. Hana";
    lec1.course = "Computer Graphics";
    lec1.display();

    // Access using arrow notation (pointer to object)
    Lecturer *ptr = &lec1;
    ptr->course = "Software Engineering"; // modifying via pointer
    ptr->display();

    // Dynamically allocating an object
    Lecturer *lec2 = new Lecturer();
    lec2->name   = "Mr. Amir";
    lec2->course = "Artificial Intelligence";
    lec2->display();

    delete lec2; // free allocated memory
    return 0;
}
