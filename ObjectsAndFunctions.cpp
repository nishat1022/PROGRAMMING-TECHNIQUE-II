// ObjectsAndFunctions.cpp
#include <iostream>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string n = "Unknown", double p = 0.0) {
        name = n;
        price = p;
    }

    void show() {
        cout << name << " = RM" << price << endl;
    }
};

// 1. Pass by value
void updateByValue(Product p) {
    p.price = 50.0;
    cout << "[updateByValue] Inside function: " << p.name << " now RM" << p.price << endl;
}

// 2. Pass by reference
void updateByReference(Product &p) {
    p.price = 60.0;
    cout << "[updateByReference] Inside function: " << p.name << " now RM" << p.price << endl;
}

// 3. Pass by pointer
void updateByPointer(Product *p) {
    p->price = 70.0;
    cout << "[updateByPointer] Inside function: " << p->name << " now RM" << p->price << endl;
}

// 4. Reassign pointer inside function (does NOT affect original pointer)
void reassignPointer(Product *p) {
    Product *temp = new Product("NewProduct", 80.0);
    cout << "[reassignPointer] Inside function: " << temp->name << " = RM" << temp->price << endl;
    delete temp; // clean up temp
}

// 5. Pointer to pointer (changes original pointer)
void changePointer(Product **p) {
    *p = new Product("ReplacedProduct", 90.0);
    cout << "[changePointer] Inside function: " << (*p)->name << " = RM" << (*p)->price << endl;
}

// 6. Return object from function
Product makeProduct(string n, double p) {
    Product temp(n, p);
    return temp;
}

int main() {
    Product *item = new Product("Laptop", 40.0);
    cout << "Initial: "; item->show();

    updateByValue(*item);
    cout << "After updateByValue: "; item->show();

    updateByReference(*item);
    cout << "After updateByReference: "; item->show();

    updateByPointer(item);
    cout << "After updateByPointer: "; item->show();

    reassignPointer(item);
    cout << "After reassignPointer: "; item->show();

    changePointer(&item);
    cout << "After changePointer: "; item->show();

    Product returned = makeProduct("ReturnedProduct", 200.0);
    cout << "Returned object: "; returned.show();

    delete item;
    return 0;
}

