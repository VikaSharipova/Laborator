#include "brass.h"

Brass::Brass() {
    Mus_Instrument();
    manufacturer = "неизвестно";
    defects = "неизвестно";
}

void Brass::set_manufacturer(const string& s) {
    manufacturer = s;
}

string Brass::get_manufacturer() const {
    return manufacturer;
}

void Brass::to_file(ofstream & f) const {
	f << "Название: " << this->get_name() << "\n" << "\tПроизводитель: " << this->get_manufacturer() << "\n" << "\tФИО владельца: " << this->get_owner() << "\n" << "\tСтоимость: " << this->get_cost() << "\n" << "\tКоличество единиц в оркестре: " << this->get_quantity() << "\n" << "\tДефекты: " << this->get_defects() << "\n";
}

ostream &operator<< (ostream & os, const Brass& a) {
    os << "Название: " << a.get_name() << endl << "\tПроизводитель: " << a.get_manufacturer() << endl << "\tФИО владельца: " << a.get_owner() << endl << "\tСтоимость: " << a.get_cost() << endl << "\tКоличество единиц в оркестре: " << a.get_quantity() << endl << "\tДефекты: " << a.get_defects() << endl;
    return os;
}

void Brass::create_new () {
    string buff;
    int buff_int;
    cout << "\nДобавление нового духового инструмента" << endl;
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
	this->set_cost(stoi(buff));
	cout << "Введите количество единиц в оркестре: ";
	cin >> buff;
	this->set_quantity(stoi(buff));
    cout << "Введите описание дефектов: ";
    cin >> buff;
    this->set_defects(buff);
}

void Brass::set_defects(const string& s) {
    defects = s;
}

string Brass::get_defects() const {
    return defects;
}

