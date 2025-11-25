// ArrayOfObjects.cpp
#include <iostream>
using namespace std;

class Product {
private:
    string name;
    double price;

public:
    // Default Constructor
    Product() {
        name = "Unknown";
        price = 0.0;
    }

    // Parameterized Constructor (Overloaded)
    Product(string n, double p) {
        name = n;
        price = p;
    }

    double getPrice() {
        return price;
    }

    void setProduct(string n, double p) {
        name = n;
        price = p;
    }

    void display() {
        cout << "Product: " << name << ", Price: RM" << price << endl;
    }
};

int main() {
    // Using both constructors (Overloading demonstration)
    Product items[3] = {
        Product("Keyboard", 59.9), // parameterized constructor
        Product("Mouse", 35.5),    // parameterized constructor
        Product()                  // default constructor
    };

    // Modify the 3rd product using setter
    items[2].setProduct("Headset", 99.0);

    double total = 0;

    cout << "=== Product List ===" << endl;
    for (int i = 0; i < 3; i++) {
        items[i].display();
        total += items[i].getPrice();
    }

    cout << "--------------------" << endl;
    cout << "Total Price: RM" << total << endl;

    return 0;
}
