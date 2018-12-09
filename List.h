#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <typename T>
class List {
	struct Node {
		T* data = nullptr;
		Node* prev = nullptr;
		Node* next = nullptr;
	};
private:
	Node* head;
public:
    List () {
		head = new Node;
        head->data = nullptr;
		head->prev = nullptr;
        head->next = nullptr;
    };

    ~List () {
		Node* cur = head;
		while (true) {
			if (cur->data != nullptr) delete cur->data;
			if (cur->next != nullptr) {
				cur = cur->next;
				delete cur->prev;
			}
			else {
				delete cur;
				break;
			}
		}
    };

    void add (T* obj) {
		Node* cur = head;
		while (true) {
			if (cur->data == nullptr) {
				cur->data = obj;
				break;
			}
			else if (cur->next == nullptr) {
				cur->next = new Node;
				cur->next->prev = cur;
				cur = cur->next;
			}
			else if (cur->next != nullptr) cur = cur->next;
		}
    };

	void remove (int n) {
		Node* cur = head;
		int i = 1;
		bool done = false;
		while (cur != nullptr) {
			if (i == n && cur -> data != nullptr) {
				delete cur->data;
				if (cur->prev != nullptr) cur->prev->next = cur->next;
				else head = cur->next;
				delete cur;
				done = true;
				break;
			}
			else cur = cur->next;
			++i;
		}
		if (done == false) throw exception("Ошибка удаления инструмента");
	}

    void show () {
		Node* cur = head;
		int i = 1;
		while (cur != nullptr) {
			if (cur->data != nullptr) cout << "\n№ " << i << "\t";
			cur->data->show();
			++i;
			cur = cur->next;
		}
    }

	T* get_elem (int n) {
		Node* cur = head;
		for (int i = 1; i <= n; i++) {
			if (i == n && cur->data != nullptr) return cur->data;
			if (cur->next != nullptr) cur = cur->next;
			else throw exception("Елемент не найден");
		}
		throw exception("Елемент не найден");
	}

	void show_to_file (ofstream& f) {
		Node* cur = head;
		int i = 1;
		while (cur != nullptr) {
			if (cur->data != nullptr) {
				f << "\n№ " << i << "\t";
				cur->data->to_file(f);
			}
			++i;
			cur = cur->next;
		}
	}

	bool empty() {
		if (this->head->data == nullptr) return true;
		else return false;
	}

	T* get_last() {
		Node* cur = head;
		while (cur->next != nullptr) cur = cur->next;
		return cur->data;
	}
};

#endif 

