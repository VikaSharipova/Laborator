#include "percussion.h"

Percussion::Percussion() {
    Mus_Instrument();
    type = "����������";
}

void Percussion::set_type(const string& s) {
    type = s;
}

string Percussion::get_type() const {
    return type;
}

void Percussion::to_file(ofstream & f) const {
	f << "��������: " << this->get_name() << "\n" << "\t���: " << this->get_type() << "\n" <<  "\t��� ���������: " << this->get_owner() << "\n" << "\t���������: " << this->get_cost() << "\n" << "\t���������� ������ � ��������: " << this->get_quantity() << "\n";
}

ostream &operator<<(ostream & os, const Percussion& a) {
    os << "��������: " << a.get_name() << endl << "\t���: " << a.get_type() << endl <<  "\t��� ���������: " << a.get_owner() << endl << "\t���������: " << a.get_cost() << endl << "\t���������� ������ � ��������: " << a.get_quantity() << endl;
    return os;
}

void Percussion::create_new () {
    string buff;
    int buff_int;
    cout << "\n���������� ������ �������� �����������" << endl;
    cout << "������� ���: ";
    cin >> buff;
    this->set_type(buff);
    cout << "������� ��������: ";
    cin >> buff;
    this->set_name (buff);
    cout << "������� ��� ���������: ";
    cin >> buff;
    this->set_owner (buff);
	cout << "������� ���������: ";
	cin >> buff;
	this->set_cost(stoi(buff));
	cout << "������� ���������� ������ � ��������: ";
	cin >> buff;
	this->set_quantity(stoi(buff));
}

