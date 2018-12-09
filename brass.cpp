#include "brass.h"

Brass::Brass() {
    Mus_Instrument();
    manufacturer = "неизвестно";
    defects = "неизвестно";
}

void Brass::set_manufacturer(string& s) {
    manufacturer = s;
}

string Brass::get_manufacturer() {
    return manufacturer;
}

void Brass::to_file(ofstream & f) {
	f << "Название: " << this->get_name() << "\n" << "\tПроизводитель: " << this->get_manufacturer() << "\n" << "\tФИО владельца: " << this->get_owner() << "\n" << "\tСтоимость: " << this->get_cost() << "\n" << "\tКоличество единиц в оркестре: " << this->get_quantity() << "\n" << "\tДефекты: " << this->get_defects() << "\n";
}

void Brass::show () {
    cout << "Название: " << get_name() << endl << "\tПроизводитель: " << get_manufacturer() << endl << "\tФИО владельца: " << get_owner() << endl << "\tСтоимость: " << get_cost() << endl << "\tКоличество единиц в оркестре: " << get_quantity() << endl << "\tДефекты: " << get_defects() << endl;
}

void Brass::create_new () {
    string buff("");
	char c = 0;
    cout << "\nДобавление нового духового инструмента" << endl;
    cout << "Введите название: ";
	getchar();
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
    this->set_name (buff);
	buff.clear();
    cout << "\nВведите название производителя: ";
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
    this->set_manufacturer (buff);
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
	buff.clear();
    cout << "\nВведите описание дефектов: ";
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
    this->set_defects(buff);
}

void Brass::set_defects(string& s) {
    defects = s;
}

string Brass::get_defects() {
    return defects;
}

