#include "UI.h"
#include "Test.h"
#include "Functions.h"
#include <iostream>
using namespace std;
void UI::add() {
    char date[250], name[250];
    int price;
    cout << "Give a name: ";
    cin >> name;
    int ok = 1;
    while (ok == 1) {
        cout << "Give a date: ";
        cin >> date;
        if (except_date(date))
            ok = 0;
        else
            cout << "Invalid date! ";
        cout << "Give a price: ";
        cin >> price;
        cout << endl;
        this->service.insert_service(name, date, price);
    }
}
void UI::print() {
    for (int i = 0; i < this->service.get_len(); i++)
        cout << this->service.get_all()[i] << endl;
}
void UI::run() {
    int opt = 1;
    while (opt) {
        cout << "Chose an option " << endl;
        menu();
        cout << "Your option is: ";
        cin >> opt;
        if (opt == 1) {
            this->add();
        }
        if (opt == 2) {
            this->print();
        }
    }
}