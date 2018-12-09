#include "stringed.h"

Stringed::Stringed() {
    Mus_Instrument();
    description = "неизвестно";
    manufacturer = "неизвестно";
}

void Stringed::set_description(string& s) {
    description = s;
}

string Stringed::get_description() {
    return description;
}

void Stringed::show () {
    cout << "Название: " << get_name() << endl << "\tПроизводитель: " << get_manufacturer() << endl << "\tФИО владельца: " << get_owner() << endl << "\tСтоимость: " << get_cost() << endl << "\tКоличество единиц в оркестре: " << get_quantity() << endl << "\tКороткое описание: " << get_description() << endl;
}

void Stringed::create_new () {
    string buff("");
	char c = 0;
    cout << "\nДобавление нового струнного инструмента\nВведите название: ";
	getchar();
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
    set_name (buff);
	buff.clear();
    cout << "\nВведите название производителя: ";
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
    set_manufacturer (buff);
	buff.clear();
    cout << "\nВведите ФИО владельца: ";
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
    set_owner (buff);
	buff.clear();
    cout << "\nВведите стоимость: ";
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
    set_cost (stoi(buff));
	buff.clear();
    cout << "\nВведите количество единиц в оркестре: ";
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
    set_quantity (stoi(buff));
	buff.clear();
    cout << "\nВведите короткое описание: ";
	while (c != '\n') {
		c = getchar();
		buff.push_back(c);
	}
	buff.pop_back();
	c = 0;
    set_description(buff);
}

void Stringed::set_manufacturer(string& s) {
    manufacturer = s;
}

string Stringed::get_manufacturer() {
    return manufacturer;
}

void Stringed::to_file(ofstream& f) {
	f << "Название: " << this->get_name() << "\n" << "\tПроизводитель: " << this->get_manufacturer() << "\n" << "\tФИО владельца: " << this->get_owner() << "\n" << "\tСтоимость: " << this->get_cost() << "\n" << "\tКоличество единиц в оркестре: " << this->get_quantity() << "\n" << "\tКороткое описание: " << this->get_description() << "\n";
}


