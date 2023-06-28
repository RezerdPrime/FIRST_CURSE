// Самописное гавно
#include <iostream>
#define elif else if
using namespace std;

struct node;

void nullpt(node * &pt) {
	pt = NULL;
}

struct node {
	int val; 
	bool cycled = false;
	node* next;
	

	// Установка значения и ссылки // ================================================================================================== //
	void set(int a, node* ptr = NULL) { val = a; next = ptr; }


	// Вывод списка // ================================================================================================================= //
	void print() {
		node* ptr = this;
		int count = 0;

		while (ptr != NULL and count < 1) {
			cout << ptr->val << " ";
			ptr = ptr->next;

			if (ptr == this) count++;
		} cout << endl;
	}


	// Зацикливание списка // ========================================================================================================== //
	void cycle() {
		if (cycled) return;

		node* ptr = this,
			* buf = NULL;

		cycled = true;

		while (ptr != NULL) {
			buf = ptr;
			ptr->cycled = true;
			ptr = ptr->next;
		}

		buf->set(buf->val, this);
	}


	// Вывод технической информации // ================================================================================================= //
	void info(bool full = 0) {

		if (!full) {
			cout << "Self: " << &val << endl
				<< "Value: " << val << endl
				<< "Cycled: " << cycled << endl
				<< "Next: " << next << "\n\n";
		}

		if (full) {
			node* ptr = this;
			int count = 0;

			while (ptr != NULL and count < 1) {
				ptr->info(0);
				ptr = ptr->next;

				if (ptr == this) count++;
			}
		}
	}


	// Добавление нового узла в конец // =============================================================================================== //
	void add(node& el) {

		if (!cycled) {
			node* ptr = this,
				* buf = NULL;

			while (ptr != NULL) {
				buf = ptr;
				ptr = ptr->next;
			}

			buf->next = &el;
		}

		else {
			node* ptr = this, 
				* buf = NULL;
			int count = 0;

			while (count < 1) {
				buf = ptr;
				ptr = ptr->next;

				if (ptr == this) count++;
			}

			buf->set(buf->val, &el);
			el.next = this;
		}
	}


	// Поиск узла по ключу // ========================================================================================================== //
	node* find(int key) {
		node* ptr = this,
			* buf = NULL;

		bool flg = false;

		while (ptr != NULL and ptr->val != key) {
			buf = ptr;
			ptr = ptr->next;

			if (buf == this and flg) return NULL;
			if (buf == this and !flg) flg = true;
		}

		return ptr; 
	}


	// Поиск узла по ссылке // ========================================================================================================= //
	node* find(node* link) {
		node* ptr = this,
			* buf = NULL;

		bool flg = false;

		while (ptr != NULL and ptr->next != link) {
			buf = ptr;
			ptr = ptr->next;

			if (buf == this and flg) return NULL;
			if (buf == this and !flg) flg = true;
		}

		return ptr;
	}


	// Удаление узла по ключу // ======================================================================================================= //
	void del(int key) {
		node* p = find(key); node* a = p;

		if (p == NULL) { return; }

		elif (p == this and p->next != NULL and p->next != this) { set(next->val, next->next); return; }

		elif (p == this and (p->next == NULL or p->next == this)) { delete a; return; }

	    elif (p->next == NULL or p->next == this) {

			node* buf = find(p);

			if (!(this)->cycled) {
				buf->next = NULL;
				delete p;
			}

			else {
				buf->next = this;
				delete p;
			}

			return;
		}

		node* prev_pt = find(p);
		prev_pt->next = p->next;

		delete p;
	}


	// Удаление узла по ссылке // ====================================================================================================== //
	void del(node* link) {
		node* p = find(link);

		if (p == NULL) { return; }

		elif (p == this and p->next != NULL and p->next != this) { set(next->val, next->next); return; }

		elif(p == this and (p->next == NULL or p->next == this)) { delete p; return; }

		elif (p->next == NULL or p->next == this) {

			node* buf = find(p);

			if (!(this)->cycled) {
				buf->next = NULL;
				delete p;
			}

			else {
				buf->next = this;
				delete p;
			}

			return;
		}

		node* prev_pt = find(p);
		prev_pt->next = p->next;

		delete p;
	}
};

// ===================================================================================================================================== //


int main() {

	node* head = new node; head->set(0);
	node* a = new node; a->set(1);
	node* b = new node; b->set(2);
	node* c = new node; c->set(3);
	node* d = new node; d->set(4);

	head->add(*a); head->add(*b); head->add(*c); head->add(*d);

	head->print();
	head->del(b->val);
	head->print();
	nullpt(b);
	cout << b;

	/*for (int i = 1; i <= 5; i++) {
		node* a = new node; a->set(i);
		head->add(*a);
	} head->cycle();*/

	//int N, step;
	//cin >> N >> step;

	//node* pt = head;

	//head->info(1);

	/*while (--step + 1) {
		cout << step << endl;
	}*/

	/*while (pt) {
		int count = step;

		while (--count + 1) {
			pt = pt->next;
		}

		head->del(pt);

		head->print();
	}*/
}


/*
спиздил у дины

#include <iostream>
using namespace std;


struct Node {
    int val;
    Node* next;
};

Node* Init(int key) {
    Node* newNode = new Node;
    newNode->val = key;
    newNode->next = NULL;
    return newNode;
}

Node* Add(Node* head, int key) {

    if (!head) return Init(key); // если хэд пустой, то инициализируем первый элемент

    if (key < head->val) { // добавление с проверкой, ну типа зачем мне писать что-то лишнее для сортировки лол
        Node* NewNode = Init(key);
        NewNode->next = head;
        return NewNode;
    }

    head->next = Add(head->next, key); // обновление ссылок
    return head;
}

void print(Node* head) {

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int RDVALUE_ = 1;
#define RAND RD()

int RD(void) {
    int A;
    RDVALUE_ = (RDVALUE_ + (int)(&A)) * 1103515245 + 12345;
    return RDVALUE_ / 31;
}
*/
