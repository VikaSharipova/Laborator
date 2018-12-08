#include "brass.h"

Brass::Brass() {
    Mus_Instrument();
    manufacturer = "����������";
    defects = "����������";
}

void Brass::set_manufacturer(const string& s) {
    manufacturer = s;
}

string Brass::get_manufacturer() const {
    return manufacturer;
}

void Brass::to_file(ofstream & f) const {
	f << "��������: " << this->get_name() << "\n" << "\t�������������: " << this->get_manufacturer() << "\n" << "\t��� ���������: " << this->get_owner() << "\n" << "\t���������: " << this->get_cost() << "\n" << "\t���������� ������ � ��������: " << this->get_quantity() << "\n" << "\t�������: " << this->get_defects() << "\n";
}

ostream &operator<< (ostream & os, const Brass& a) {
    os << "��������: " << a.get_name() << endl << "\t�������������: " << a.get_manufacturer() << endl << "\t��� ���������: " << a.get_owner() << endl << "\t���������: " << a.get_cost() << endl << "\t���������� ������ � ��������: " << a.get_quantity() << endl << "\t�������: " << a.get_defects() << endl;
    return os;
}

void Brass::create_new () {
    string buff;
    int buff_int;
    cout << "\n���������� ������ �������� �����������" << endl;
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
	this->set_cost(stoi(buff));
	cout << "������� ���������� ������ � ��������: ";
	cin >> buff;
	this->set_quantity(stoi(buff));
    cout << "������� �������� ��������: ";
    cin >> buff;
    this->set_defects(buff);
}

void Brass::set_defects(const string& s) {
    defects = s;
}

string Brass::get_defects() const {
    return defects;
}

