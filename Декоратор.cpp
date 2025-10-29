// Декоратор
#include <iostream>
#include <string>
using namespace std;

class Beverage {
public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Beverage() {}
};

class Espresso : public Beverage {
public:
    string getDescription() const override { return "Espresso"; }
    double cost() const override { return 500.0; }
};

class Tea : public Beverage {
public:
    string getDescription() const override { return "Tea"; }
    double cost() const override { return 300.0; }
};

class Latte : public Beverage {
public:
    string getDescription() const override { return "Latte"; }
    double cost() const override { return 650.0; }
};

class Mocha : public Beverage {
public:
    string getDescription() const override { return "Mocha"; }
    double cost() const override { return 700.0; }
};

class BeverageDecorator : public Beverage {
protected:
    Beverage* beverage;
public:
    BeverageDecorator(Beverage* b) : beverage(b) {}
    virtual ~BeverageDecorator() { delete beverage; }
};

class Milk : public BeverageDecorator {
public:
    Milk(Beverage* b) : BeverageDecorator(b) {}
    string getDescription() const override { return beverage->getDescription() + " + Milk"; }
    double cost() const override { return beverage->cost() + 100.0; }
};

class Sugar : public BeverageDecorator {
public:
    Sugar(Beverage* b) : BeverageDecorator(b) {}
    string getDescription() const override { return beverage->getDescription() + " + Sugar"; }
    double cost() const override { return beverage->cost() + 50.0; }
};

class WhippedCream : public BeverageDecorator {
public:
    WhippedCream(Beverage* b) : BeverageDecorator(b) {}
    string getDescription() const override { return beverage->getDescription() + " + Whipped Cream"; }
    double cost() const override { return beverage->cost() + 150.0; }
};

class Chocolate : public BeverageDecorator {
public:
    Chocolate(Beverage* b) : BeverageDecorator(b) {}
    string getDescription() const override { return beverage->getDescription() + " + Chocolate"; }
    double cost() const override { return beverage->cost() + 200.0; }
};

int main() {
    Beverage* order1 = new Espresso();
    order1 = new Milk(order1);
    order1 = new Sugar(order1);

    cout << "Order 1: " << order1->getDescription() << endl;
    cout << "Total: " << order1->cost() << " KZT\n" << endl;
    delete order1;

    Beverage* order2 = new Latte();
    order2 = new WhippedCream(order2);
    order2 = new Chocolate(order2);
    order2 = new Sugar(order2);

    cout << "Order 2: " << order2->getDescription() << endl;
    cout << "Total: " << order2->cost() << " KZT\n" << endl;
    delete order2;

    Beverage* order3 = new Mocha();
    order3 = new Milk(order3);
    order3 = new Chocolate(order3);
    order3 = new WhippedCream(order3);

    cout << "Order 3: " << order3->getDescription() << endl;
    cout << "Total: " << order3->cost() << " KZT\n" << endl;
    delete order3;

    return 0;
}

