#include "stringed.h"

Stringed::Stringed() {
    Mus_Instrument();
    description = "неизвестно";
    manufacturer = "неизвестно";
}

void Stringed::set_description(const string& s) {
    description = s;
}

string Stringed::get_description() const {
    return description;
}

ostream &operator<< (ostream & os, const Stringed& a) {
    os << "Название: " << a.get_name() << endl << "\tПроизводитель: " << a.get_manufacturer() << endl << "\tФИО владельца: " << a.get_owner() << endl << "\tСтоимость: " << a.get_cost() << endl << "\tКоличество единиц в оркестре: " << a.get_quantity() << endl << "\tКороткое описание: " << a.get_description() << endl;
    return os;
}

void Stringed::create_new () {
    string buff;
    cout << "\nДобавление нового струнного инструмента" << endl;
    cout << "Введите название: ";
    cin >> buff;
    this->set_name (buff);
    cout << "Введите название производителя: ";
    cin >> buff;
    this->set_manufacturer (buff);
    cout << "Введите ФИО владельца: ";
    cin >> buff;
    this->set_owner (buff);
    cout << "Введите стоимость: ";
    cin >> buff;
    this->set_cost (stoi(buff));
    cout << "Введите количество единиц в оркестре: ";
    cin >> buff;
    this->set_quantity (stoi(buff));
    cout << "Введите короткое описание: ";
    cin >> buff;
    this->set_description(buff);
}

void Stringed::set_manufacturer(const string& s) {
    manufacturer = s;
}

string Stringed::get_manufacturer() const {
    return manufacturer;
}

void Stringed::to_file(ofstream& f) const {
	f << "Название: " << this->get_name() << "\n" << "\tПроизводитель: " << this->get_manufacturer() << "\n" << "\tФИО владельца: " << this->get_owner() << "\n" << "\tСтоимость: " << this->get_cost() << "\n" << "\tКоличество единиц в оркестре: " << this->get_quantity() << "\n" << "\tКороткое описание: " << this->get_description() << "\n";
}

