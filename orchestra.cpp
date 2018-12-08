#include "orchestra.h"

Orchestra::Orchestra() {
	data_s = new List<Stringed>;
	data_b = new List<Brass>;
	data_p = new List<Percussion>;
}

void Orchestra::add(Stringed * obj) {
	data_s->add(obj);
}

void Orchestra::add(Brass * obj) {
	data_b->add(obj);
}

void Orchestra::add(Percussion * obj) {
	data_p->add(obj);
}

void Orchestra::remove(int type, int n) {
	switch (type)
	{
	case 0:
		data_s->remove(n);
		break;
	case 1:
		data_b->remove(n);
		break;
	case 2:
		data_p->remove(n);
		break;
	}
}

Orchestra::~Orchestra() {
	data_s->~List();
	data_b->~List();
	data_p->~List();
}

void Orchestra::show() const {
	cout << "\nCостав оркестра\n\n";
	if (!data_s->empty()) {
		cout << "Струнные инструменты:\n";
		data_s->show();
		cout << "\n\n";
	}
	if (!data_b->empty()) {
		cout << "Духовые инструменты:\n";
		data_b->show();
		cout << "\n\n";
	}
	if (!data_p->empty()) {
		cout << "Ударные инструменты:\n";
		data_p->show();
		cout << "\n\n";
	}
}

void Orchestra::save (const string s) const {
	ofstream file (s, ios_base::trunc);
	if (file.is_open()) {
		file << "Состав оркестра\n\n";
		if (!data_s->empty()) {
			file << "Струнные инструменты:\n";
			data_s->show_to_file(file);
			file << "\n";
		}
		if (!data_b->empty()) {
			file << "Духовые инструменты:\n";
			data_b->show_to_file(file);
			file << "\n";
		}
		if (!data_p->empty()) {
			file << "Ударные инструменты:\n";
			data_p->show_to_file(file);
			file << "\n";
		}
		cout << "Оркестр успешно записан в файл " << s << endl;
		file.close();
	}
	else throw exception("Ошибка записи в файл\n");
}

void Orchestra::read(const string s) {
	ifstream file(s);
	int type = 3;
	string buff("");
	string field("");
	char c = 0;
	if (file.is_open()) {
		while (!file.eof()) {
			file >> buff;
			if (buff == "Струнные") type = 0;
			else if (buff == "Духовые") type = 1;
			else if (buff == "Ударные") type = 2;
			switch (type)
			{
			case 0:
				if (buff == "№") data_s->add(new Stringed());
				else if (buff == "Название:") {
					getline (file, field);
					data_s->get_last()->set_name(field);
					field.clear();
				}
				else if (buff == "Производитель:") {
					getline(file, field);
					data_s->get_last()->set_manufacturer(field);
					field.clear();
				}
				else if (buff == "владельца:") {
					getline(file, field);
					data_s->get_last()->set_owner(field);
					field.clear();
				}
				else if (buff == "Стоимость:") {
					getline(file, field);
					data_s->get_last()->set_cost(stoi(field));
					field.clear();
				}
				else if (buff == "оркестре:") {
					getline(file, field);
					data_s->get_last()->set_quantity(stoi(field));
					field.clear();
				}
				else if (buff == "описание:") {
					getline(file, field);
					data_s->get_last()->set_description(field);
					field.clear();
				}
				buff.clear();
				break;
			case 1:
				if (buff == "№") data_b->add(new Brass());
				else if (buff == "Название:") {
					getline(file, field);
					data_b->get_last()->set_name(field);
					field.clear();
				}
				else if (buff == "Производитель:") {
					getline(file, field);
					data_b->get_last()->set_manufacturer(field);
					field.clear();
				}
				else if (buff == "владельца:") {
					getline(file, field);
					data_b->get_last()->set_owner(field);
					field.clear();
				}
				else if (buff == "Стоимость:") {
					getline(file, field);
					data_b->get_last()->set_cost(stoi(field));
					field.clear();
				}
				else if (buff == "оркестре:") {
					getline(file, field);
					data_b->get_last()->set_quantity(stoi(field));
					field.clear();
				}
				else if (buff == "Дефекты:") {
					getline(file, field);
					data_b->get_last()->set_defects(field);
					field.clear();
				}
				buff.clear();
				break;
			case 2:
				if (buff == "№") data_p->add(new Percussion());
				else if (buff == "Название:") {
					getline(file, field);
					data_p->get_last()->set_name(field);
					field.clear();
				}
				else if (buff == "Тип:") {
					getline(file, field);
					data_p->get_last()->set_type(field);
					field.clear();
				}
				else if (buff == "владельца:") {
					getline(file, field);
					data_p->get_last()->set_owner(field);
					field.clear();
				}
				else if (buff == "Стоимость:") {
					getline(file, field);
					data_p->get_last()->set_cost(stoi(field));
					field.clear();
				}
				else if (buff == "оркестре:") {
					getline(file, field);
					data_p->get_last()->set_quantity(stoi(field));
					field.clear();
				}
				buff.clear();
				break;
			default:
				break;
			}
		}
		file.close();
	}
	else throw exception("Ошибка чтения файла");
}
