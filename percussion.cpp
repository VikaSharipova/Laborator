#include "percussion.h"

Percussion::Percussion() {
    Mus_Instrument();
    type = "неизвестно";
}

void Percussion::set_type(string& s) {
    type = s;
}

string Percussion::get_type() {
    return type;
}

void Percussion::to_file (ofstream & f) {
	f << "Название: " << get_name() << "\n" << "\tТип: " << get_type() << "\n" <<  "\tФИО владельца: " << get_owner() << "\n" << "\tСтоимость: " << get_cost() << "\n" << "\tКоличество единиц в оркестре: " << get_quantity() << "\n";
}

void Percussion::show () {
    cout << "Название: " << get_name() << endl << "\tТип: " << get_type() << endl <<  "\tФИО владельца: " << get_owner() << endl << "\tСтоимость: " << get_cost() << endl << "\tКоличество единиц в оркестре: " << get_quantity() << endl;
}

void Percussion::create_new () {
    string buff("");
	char c = 0;
    cout << "\nДобавление нового ударного инструмента" << endl;
    cout << "Введите тип: ";
	getchar();
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
    this->set_type(buff);
	buff.clear();
    cout << "\nВведите название: ";
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
    this->set_name (buff);
	buff.clear();
    cout << "\nВведите ФИО владельца: ";
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
    this->set_owner (buff);
	buff.clear();
	cout << "\nВведите стоимость: ";
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
	this->set_cost(stoi(buff));
	buff.clear();
	cout << "\nВведите количество единиц в оркестре: ";
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
	this->set_quantity(stoi(buff));
}


