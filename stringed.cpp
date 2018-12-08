#include "stringed.h"

Stringed::Stringed() {
    Mus_Instrument();
    description = "����������";
    manufacturer = "����������";
}

void Stringed::set_description(const string& s) {
    description = s;
}

string Stringed::get_description() const {
    return description;
}

ostream &operator<< (ostream & os, const Stringed& a) {
    os << "��������: " << a.get_name() << endl << "\t�������������: " << a.get_manufacturer() << endl << "\t��� ���������: " << a.get_owner() << endl << "\t���������: " << a.get_cost() << endl << "\t���������� ������ � ��������: " << a.get_quantity() << endl << "\t�������� ��������: " << a.get_description() << endl;
    return os;
}

void Stringed::create_new () {
    string buff;
    cout << "\n���������� ������ ��������� �����������" << endl;
    cout << "������� ��������: ";
    cin >> buff;
    this->set_name (buff);
    cout << "������� �������� �������������: ";
    cin >> buff;
    this->set_manufacturer (buff);
    cout << "������� ��� ���������: ";
    cin >> buff;
    this->set_owner (buff);
    cout << "������� ���������: ";
    cin >> buff;
    this->set_cost (stoi(buff));
    cout << "������� ���������� ������ � ��������: ";
    cin >> buff;
    this->set_quantity (stoi(buff));
    cout << "������� �������� ��������: ";
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
	f << "��������: " << this->get_name() << "\n" << "\t�������������: " << this->get_manufacturer() << "\n" << "\t��� ���������: " << this->get_owner() << "\n" << "\t���������: " << this->get_cost() << "\n" << "\t���������� ������ � ��������: " << this->get_quantity() << "\n" << "\t�������� ��������: " << this->get_description() << "\n";
}

