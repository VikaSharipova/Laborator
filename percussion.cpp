#include "percussion.h"

Percussion::Percussion() {
    Mus_Instrument();
    type = "неизвестно";
}

void Percussion::set_type(const string& s) {
    type = s;
}

string Percussion::get_type() const {
    return type;
}

void Percussion::to_file(ofstream & f) const {
	f << "Название: " << this->get_name() << "\n" << "\tТип: " << this->get_type() << "\n" <<  "\tФИО владельца: " << this->get_owner() << "\n" << "\tСтоимость: " << this->get_cost() << "\n" << "\tКоличество единиц в оркестре: " << this->get_quantity() << "\n";
}

ostream &operator<<(ostream & os, const Percussion& a) {
    os << "Название: " << a.get_name() << endl << "\tТип: " << a.get_type() << endl <<  "\tФИО владельца: " << a.get_owner() << endl << "\tСтоимость: " << a.get_cost() << endl << "\tКоличество единиц в оркестре: " << a.get_quantity() << endl;
    return os;
}

void Percussion::create_new () {
    string buff;
    int buff_int;
    cout << "\nДобавление нового ударного инструмента" << endl;
    cout << "Введите тип: ";
    cin >> buff;
    this->set_type(buff);
    cout << "Введите название: ";
    cin >> buff;
    this->set_name (buff);
    cout << "Введите ФИО владельца: ";
    cin >> buff;
    this->set_owner (buff);
	cout << "Введите стоимость: ";
	cin >> buff;
	this->set_cost(stoi(buff));
	cout << "Введите количество единиц в оркестре: ";
	cin >> buff;
	this->set_quantity(stoi(buff));
}

