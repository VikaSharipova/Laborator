#include "orchestra.h"

int main() {
	setlocale (LC_ALL, "Russian");
	Orchestra* o = new Orchestra();
	Orchestra* o2 = 0;
	Stringed* s = 0;
	Brass* b = 0;
	Percussion* p = 0;
	List<Stringed>* ls = 0;
	string field("");
	char c = 0;
	int index = 0;
	int choice = 0;
	while (true) {
	MainAgain:
		system("cls");
		cout << "1 - Добавить инструмент в оркестр\n2 - Удалить инструмент из оркестра\n3 - Показать оркестр\n4 - Редактировать данные инструмента\n5 - Сохранить оркестр в файл\n6 - Загрузить оркестр из файла\n7 - Завершить работу\n\nДействие: ";
		cin >> choice;
		switch (choice)
		{
		case 1: //добавление
		AddAgain:
			system("cls");
			cout << "Выберите вид инструмента для добавления\n1 - Струнный\n2 - Духовой\n3 - Ударный\n4 - Отмена\n\nДействие: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				s = new Stringed();
				newS:
				try {
					s->create_new();
				}
				catch (std::invalid_argument&) {
					cout << "Стоимость и количество должны быть целочисленными значениями\n";
					goto newS;
				}
				o->add(s);
				cout << "\nИнструмент добавлен\n\n";
				system("pause");
				goto MainAgain;
			case 2:
				b = new Brass();
			    newB:
				try {
					b->create_new();
				}
				catch (std::invalid_argument&) {
					cout << "Стоимость и количество должны быть целочисленными значениями\n";
					goto newB;
				}
				o->add(b);
				cout << "\nИнструмент добавлен\n\n";
				system("pause");
				goto MainAgain;
			case 3:
				p = new Percussion();
			    newP:
				try {
					p->create_new();
				}
				catch (std::invalid_argument&) {
					cout << "Стоимость и количество должны быть целочисленными значениями\n";
					goto newP;
				}
				o->add(p);
				cout << "\nИнструмент добавлен\n\n";
				system("pause");
				goto MainAgain;
			case 4:
				break;
			default:
				cout << "Неверная команда\nПовторите ввод\n\n";
				system("pause");
				goto AddAgain;
			}
			cout << endl;
			goto MainAgain;
		case 2: //удаление
		remAgain:
			system("cls");
			cout << "Выберите вид инструмента для удаления\n1 - Струнный\n2 - Духовой\n3 - Ударный\n4 - Отмена\n\nДействие: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				if (o->get_s()->empty() == false) {
					cout << "Струнные инструменты:\n";
					o->get_s()->show();
					cout << "\n\n";
				}
				else {
					cout << "В оркестре нет струнных инструментов\n";
					system("pause");
					goto remAgain;
				}
				cout << "Введите номер инструмента для удаления: ";
				cin >> index;
				try {
					o->remove(0, index);
				}
				catch (exception& e) {
					e.what();
					system("pause");
					goto remAgain;
				}
				cout << "\nИнструмент удален\n\n";
				system("pause");
				goto MainAgain;
			case 2:
				if (!o->get_b()->empty()) {
					cout << "Духовые инструменты:\n";
					o->get_b()->show();
					cout << "\n\n";
				}
				else {
					cout << "В оркестре нет духовых инструментов\n";
					system("pause");
					goto remAgain;
				}
				cout << "Введите номер инструмента для удаления: ";
				cin >> index;
				try {
					o->remove(1, index);
				}
				catch (exception& e) {
					e.what();
					system("pause");
					goto remAgain;
				}
				cout << "\nИнструмент удален\n\n";
				system("pause");
				goto MainAgain;
			case 3:
				if (!o->get_p()->empty()) {
					cout << "Ударные инструменты:\n";
					o->get_p()->show();
					cout << "\n\n";
				}
				else {
					cout << "В оркестре нет ударных инструментов\n";
					system("pause");
					goto remAgain;
				}
				cout << "Введите номер инструмента для удаления: ";
				cin >> index;
				try {
					o->remove(2, index);
				}
				catch (exception& e) {
					e.what();
					system("pause");
					goto remAgain;
				}
				cout << "\nИнструмент удален\n\n";
				system("pause");
				goto MainAgain;
			case 4:
				break;
			default:
				cout << "Неверная команда\nПовторите ввод\n\n";
				system("pause");
				goto remAgain;
			}
			cout << endl;
			goto MainAgain;
		case 3: //показ
			system("cls");
			o->show();
			system("pause");
			goto MainAgain;
		case 4: //редактирование
		redAgain:
			system("cls");
			cout << "Выберите вид инструмента для редактирования\n1 - Струнный\n2 - Духовой\n3 - Ударный\n4 - Отмена\n\nДействие: ";
			cin >> choice;
			switch (choice)
			{
			case 1: //редактирование струнного 
			redS:
				if (!o->get_s()->empty()) {
					cout << "Струнные инструменты:\n";
					o->get_s()->show();
					cout << "\n\n";
				}
				else {
					cout << "В оркестре нет струнных инструментов\n";
					system("pause");
					goto redAgain;
				}
				cout << "Введите номер инструмента для редактирования: ";
				cin >> index;
				try {
					s = o->get_s()->get_elem(index);
				}
				catch (exception& e) {
					e.what();
					system("pause");
					goto redS;
				}
				cout << "Выберите редактируемое поле:\n1 - Название\n2 - Производитель\n3 - ФИО владельца\n4 - Стоимость\n5 - Количество единиц в оркестре\n6 - Короткое описание\n7 - Отмена\n\nВариант: ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					s->set_name(field);
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 2:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					s->set_manufacturer(field);
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 3:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					s->set_owner(field);
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 4:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					try {
						s->set_cost(stoi(field));
					}
					catch (std::invalid_argument&) {
						cout << "Стоимость и количество должны быть целочисленными значениями\n";
						goto redS;
					}
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 5:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					try {
						s->set_quantity(stoi(field));
					}
					catch (std::invalid_argument&) {
						cout << "Стоимость и количество должны быть целочисленными значениями\n";
						goto redS;
					}
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 6:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					s->set_description(field);
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 7:
					goto MainAgain;
				default:
					cout << "Неверная команда\nПовторите ввод\n\n";
					goto redS;
				}
				cout << "\nИнструмент отредактирован\n\n";
				system("pause");
				goto MainAgain;
			case 2: // редактирование духового
			redB:
				if (!o->get_b()->empty()) {
					cout << "Духовые инструменты:\n";
					o->get_b()->show();
					cout << "\n\n";
				}
				else {
					cout << "В оркестре нет духовых инструментов\n";
					system("pause");
					goto redAgain;
				}
				cout << "Введите номер инструмента для редактирования: ";
				cin >> index;
				try {
					b = o->get_b()->get_elem(index);
				}
				catch (exception& e) {
					e.what();
					system("pause");
					goto redB;
				}
				cout << "Выберите редактируемое поле:\n1 - Название\n2 - Производитель\n3 - ФИО владельца\n4 - Стоимость\n5 - Количество единиц в оркестре\n6 - Дефекты\n7 - Отмена\n\nВариант: ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					b->set_name(field);
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 2:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					b->set_manufacturer(field);
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 3:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					b->set_owner(field);
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 4:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					try {
						b->set_cost(stoi(field));
					}
					catch (std::invalid_argument&) {
						cout << "Стоимость и количество должны быть целочисленными значениями\n";
						goto redB;
					}
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 5:
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					try {
						b->set_quantity(stoi(field));
					}
					catch (std::invalid_argument&) {
						cout << "Стоимость и количество должны быть целочисленными значениями\n";
						goto redB;
					}
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 6:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					b->set_defects(field);
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 7:
					goto MainAgain;
				default:
					cout << "Неверная команда\nПовторите ввод\n\n";
					goto redB;
				}
				cout << "\nИнструмент отредактирован\n\n";
				system("pause");
				goto MainAgain;
			case 3: //редактирование ударного
			redP:
				if (!o->get_p()->empty()) {
					cout << "Ударные инструменты:\n";
					o->get_p()->show();
					cout << "\n\n";
				}
				else {
					cout << "В оркестре нет ударных инструментов\n";
					system("pause");
					goto redAgain;
				}
				cout << "Введите номер инструмента для редактирования: ";
				cin >> index;
				try {
					p = o->get_p()->get_elem(index);
				}
				catch (exception& e) {
					e.what();
					system("pause");
					goto redP;
				}
				cout << "Выберите редактируемое поле:\n1 - Название\n2 - Тип\n3 - ФИО владельца\n4 - Стоимость\n5 - Количество единиц в оркестре\n6 - Отмена\n\nВариант: ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					p->set_name(field);
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 2:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					p->set_type(field);
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 3:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					p->set_owner(field);
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 4:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					try {
						p->set_cost(stoi(field));
					}
					catch (std::invalid_argument&) {
						cout << "Стоимость и количество должны быть целочисленными значениями\n";
						goto redP;
					}
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 5:
					cout << "Новое значение: ";
					getchar();
					while (c != '\n') {
						c = getchar();
						field.push_back(c);
					}
					field.pop_back();
					c = 0;
					try {
						p->set_quantity(stoi(field));
					}
					catch (std::invalid_argument&) {
						cout << "Стоимость и количество должны быть целочисленными значениями\n";
						goto redP;
					}
					field.clear();
					cout << "Данные успешно изменены\n";
					system("pause");
					goto MainAgain;
				case 6:
					goto MainAgain;
				default:
					cout << "Неверная команда\nПовторите ввод\n\n";
					goto redP;
				}
				cout << "\nИнструмент отредактирован\n\n";
				system("pause");
				goto MainAgain;
			case 4:
				goto MainAgain;
			default:
				cout << "Неверная команда\nПовторите ввод\n\n";
				system("pause");
				goto redAgain;
			}
		case 5: //сохранение
			system("cls");
			cout << "Введите имя файла: ";
			cin >> field;
			try {
				o->save(field);
			}
			catch (exception& e) {
				e.what();
				system("pause");
				goto MainAgain;
			}
			system("pause");
			field.clear();
			goto MainAgain;
		case 6: //чтение
			system("cls");
			cout << "Введите имя файла: ";
			cin >> field;
			o->~Orchestra();
			o = new Orchestra();
			try {
				o->read(field);
			}
			catch (exception& e) {
				e.what();
				system("pause");
				goto MainAgain;
			}
			cout << "Оркестр загружен\n\n";
			system("pause");
			field.clear();
			goto MainAgain;
		case 7:
			goto exit;
		default:
			cout << "Неверная команда\nПовторите ввод\n\n";
			system("pause");
			goto MainAgain;
		}
	    exit:
		break;
	}
	system ("pause");
    return 0;
}
