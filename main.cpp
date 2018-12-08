#include "orchestra.h"

int main() {
	setlocale (LC_ALL, "Russian");
	Orchestra* o = new Orchestra();
	Orchestra* o2 = 0;
	Stringed* s = 0;
	Brass* b = 0;
	Percussion* p = 0;
	int choice = 0;
	while (true) {
		MainAgain:
		cout << "1 - Добавить инструмент в оркестр\n2 - Удалить инструмент из оркестра\n3 - Показать оркестр\n4 - Редактировать данные инструмента\n5 - Сохранить оркестр в файл\n6 - Загрузить оркестр из файла\n7 - Завершить работу\n\nДействие: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			AddAgain:
			cout << "Выберите вид инструмента\n1 - Струнный\n2 - Духовой\n3 - Ударный\n4 - Отмена\n\nДействие: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				s = new Stringed();
				newS:
				try {
					s->create_new();
				}
				catch (std::invalid_argument& ex) {
					cout << "Стоимость и количество должны быть целочисленными значениями\n";
					goto newS;
				}
				o->add(s);
				cout << "\nИнструмент добавлен\n\n";
				goto MainAgain;
			case 2:
				b = new Brass();
			    newB:
				try {
					b->create_new();
				}
				catch (std::invalid_argument& ex) {
					cout << "Стоимость и количество должны быть целочисленными значениями\n";
					goto newB;
				}
				o->add(b);
				cout << "\nИнструмент добавлен\n\n";
				goto MainAgain;
			case 3:
				p = new Percussion();
			    newP:
				try {
					p->create_new();
				}
				catch (std::invalid_argument& ex) {
					cout << "Стоимость и количество должны быть целочисленными значениями\n";
					goto newP;
				}
				o->add(p);
				cout << "\nИнструмент добавлен\n\n";
				goto MainAgain;
			case 4:
				break;
			default:
				cout << "Неверная команда\nПовторите ввод\n\n";
				goto AddAgain;
			}
			cout << endl;
			goto MainAgain;
		case 3:
			o->show();
			goto MainAgain;
		case 7:
			goto exit;
		default:
			cout << "Неверная команда\nПовторите ввод\n\n";
			goto MainAgain;
		}
	exit:
		break;
	}
	system ("pause");
    return 0;
}