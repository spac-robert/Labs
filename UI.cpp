#include "UI.h"
#include "Functions.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

char* allocate_memory()
{
    char* name = new char[0];
    string string_name;

    cin >> string_name;
    name = new char[string_name.size() + 1];

    strcpy_s(name, 1 + string_name.size(), string_name.c_str());

    return name;
}

bool UI::title_exist(char* titlu) {

    deque<Carte> array = this->service.get_all();

    for (int i = 0; i < this->service.get_len(); i++) {

        if (strcmp(titlu, array[i].get_titlu()) == 0)
            return false;
    }

    return true;
}

bool UI::status_exist(string status) {

    if (status.size() == 1)
    {
        if (status[0] == '0' or status[0] == '1')
            return true;
    }
    return false;
}

void UI::add() {

    char* autor = new char[0], * titlu = new char[0];
    string variable;
    bool status{};

    cout << "Give a titlu: ";
    do {
        titlu = allocate_memory();

        if (!this->title_exist(titlu))
            cout << "This title exist, give another title: ";

    } while (!this->title_exist(titlu));

    cout << "Autor: ";
    autor = allocate_memory();

    do {

        cout << "Give a statut: ";
        cin >> variable;

        if (!this->status_exist(variable))
            cout << "Status invalid! Try (0 or 1): ";
        else
            status = variable[0] - '0';

    } while (!this->status_exist(variable));

    cout << endl;
    this->service.insert_service(titlu, autor, status);
}

void UI::print() {

    int n = this->service.get_len();
    deque<Carte> array = this->service.get_all();

    for (int i = 0; i < n; i++)
        cout << endl << array[i];
}

void UI::update() {

    char* autor = new char[0], * titlu = new char[0];
    bool status;

    cout << "Dati un titlu pentru update: ";
    titlu = allocate_memory();

    cout << "Autor: ";
    autor = allocate_memory();

    cout << "Give a statut: ";
    cin >> status;
    cout << endl;

    this->service.update_carte(titlu, autor, status);
}

void UI::delete_book_by_title() {

    char* titlu = new char[0];

    cout << "Dati un titlu pentru stergere: ";
    titlu = allocate_memory();

    this->service.delete_book(titlu);
}

void UI::carte_imprumutata() {

    char* titlu = new char[0];
    int contor = 0, ok = 1;
    std::deque<Carte> array;

    do {

        cout << "Dati un titlu pentru imprumutare: ";

        titlu = allocate_memory();
        this->service.borrowed_book(titlu, contor);

        if (contor == 1) {

            cout << "Succes" << endl;
        }
        else
            if (contor == 0) {

                cout << endl << "Cartea este indisponibila " << endl;
                array = this->service.find_all_books_by_author_available(titlu);
                if (array.size() >= 0) {
                    cout << endl << "Autorul are aceste carti: " << endl;
                    for (int i = 0; i < int(array.size()); i++)
                        cout << endl << array[i];
                }
            }
            else
                if (contor == 2)
                    cout << endl << "Nu exista alte carti disponibile scrise de acest autor " << endl;
                else
                    if (contor == 4)
                        cout << endl << "Cartea nu exista" << endl;
        cout << endl << "Doriti sa alegeti alta carte?(1 pentru DA , 0 pentru NU): ";
        cin >> ok;

    } while (ok == 1);
}

void UI::return_book() {

    char* titlu = new char[0];
    int contor = 0, ok = 1;

    do {

        cout <<endl<< "Dati un titlu pentru returnarea unei carti: ";
        titlu = allocate_memory();
        this->service.carte_returnata(titlu, contor);

        if (contor == 1) {

            cout << "Succes" << endl;
            ok = 0;
        }
        else
            if (contor == 0) {

                cout << "Cartea cu titlul: "<<titlu<<" nu este imprumutata " << endl;
            }
            else
                if (contor == 2)
                    cout << "Nu exista nicio carte cu titlul: "<<titlu << endl;

        cout << endl << "Doriti sa alegeti alta carte?(1 pentru DA , 0 pentru NU): ";
        cin >> ok;

    } while (ok == 1);
}

void UI::run() {

    string opt;
    bool ok = true;

    do {

        cout << endl << "Chose an option " << endl;
        menu();
        cout << "Your option is: ";
        cin >> opt;

        if (opt.size() == 1)
        {
            if (opt[0] == '1') {

                this->add();
            }
            else
                if (opt[0] == '2') {

                    this->print();
                }
                else
                    if (opt[0] == '3') {

                        this->update();
                    }
                    else
                        if (opt[0] == '4') {

                            this->delete_book_by_title();
                        }
                        else
                            if (opt[0] == '5') {

                                this->service.load_from_file("Biblioteca_load.txt");
                            }
                            else
                                if (opt[0] == '6') {

                                    this->carte_imprumutata();
                                }
                                else
                                    if (opt[0] == '7') {

                                        this->service.save_to_file("Biblioteca_save.txt");
                                    }
                                    else
                                        if (opt[0] == '8') {

                                            this->return_book();
                                        }
                                        else
                                            if (opt[0] == 'x') {

                                                ok = false;
                                            }
                                            else
                                                cout << endl << "Invalid option!" << endl;
        }
        else
            cout << endl << "Invalid option!" << endl;

    } while (ok);
}