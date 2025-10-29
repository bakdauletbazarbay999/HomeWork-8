// Адаптер
#include <iostream>
using namespace std;

class IPaymentProcessor {
public:
    virtual void ProcessPayment(double amount) = 0;
    virtual ~IPaymentProcessor() {}
};

class PayPalPaymentProcessor : public IPaymentProcessor {
public:
    void ProcessPayment(double amount) override {
        cout << "PayPal: Payment successful! Amount: "
            << amount << " KZT" << endl;
    }
};

class StripePaymentService {
public:
    void MakeTransaction(double totalAmount) {
        cout << "Stripe: Transaction completed! Amount: "
            << totalAmount << " KZT" << endl;
    }
};

class StripePaymentAdapter : public IPaymentProcessor {
private:
    StripePaymentService stripe;
public:
    void ProcessPayment(double amount) override {
        stripe.MakeTransaction(amount);
    }
};

class KaspiPayService {
public:
    void SendMoney(double sum) {
        cout << "Kaspi: Payment done via KaspiRed. Amount: "
            << sum << " KZT" << endl;
    }
};

class KaspiPaymentAdapter : public IPaymentProcessor {
private:
    KaspiPayService kaspi;
public:
    void ProcessPayment(double amount) override {
        kaspi.SendMoney(amount);
    }
};


int main() {
    IPaymentProcessor* paypal = new PayPalPaymentProcessor();
    IPaymentProcessor* stripe = new StripePaymentAdapter();
    IPaymentProcessor* kaspi = new KaspiPaymentAdapter();

    cout << "--- Testing Payment System ---" << endl;

    paypal->ProcessPayment(1200.0);
    stripe->ProcessPayment(2500.0);
    kaspi->ProcessPayment(3000.0);

    delete paypal;
    delete stripe;
    delete kaspi;

    return 0;
}

