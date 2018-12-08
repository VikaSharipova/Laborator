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
		cout << "1 - �������� ���������� � �������\n2 - ������� ���������� �� ��������\n3 - �������� �������\n4 - ������������� ������ �����������\n5 - ��������� ������� � ����\n6 - ��������� ������� �� �����\n7 - ��������� ������\n\n��������: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			AddAgain:
			cout << "�������� ��� �����������\n1 - ��������\n2 - �������\n3 - �������\n4 - ������\n\n��������: ";
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
					cout << "��������� � ���������� ������ ���� �������������� ����������\n";
					goto newS;
				}
				o->add(s);
				cout << "\n���������� ��������\n\n";
				goto MainAgain;
			case 2:
				b = new Brass();
			    newB:
				try {
					b->create_new();
				}
				catch (std::invalid_argument& ex) {
					cout << "��������� � ���������� ������ ���� �������������� ����������\n";
					goto newB;
				}
				o->add(b);
				cout << "\n���������� ��������\n\n";
				goto MainAgain;
			case 3:
				p = new Percussion();
			    newP:
				try {
					p->create_new();
				}
				catch (std::invalid_argument& ex) {
					cout << "��������� � ���������� ������ ���� �������������� ����������\n";
					goto newP;
				}
				o->add(p);
				cout << "\n���������� ��������\n\n";
				goto MainAgain;
			case 4:
				break;
			default:
				cout << "�������� �������\n��������� ����\n\n";
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
			cout << "�������� �������\n��������� ����\n\n";
			goto MainAgain;
		}
	exit:
		break;
	}
	system ("pause");
    return 0;
}