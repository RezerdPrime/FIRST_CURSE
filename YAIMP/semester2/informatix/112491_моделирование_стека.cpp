#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct node {
    int val;
    node* next;
};


node* init(int va, node* nex = NULL) {
    node* nnod = new node;
    nnod->val = va;
    nnod->next = nex;
    return nnod;
}


int size(node* head) {

    if (!head) return 0;

    else {
        node* pt = head;
        int k = 0;

        while (pt) {
            k++;
            pt = pt->next;
        }
        return k;
    }
}


void print(node* head) {
    node* pt = head; int in = 0;
    int* arr = new int[size(head)];

    while (pt) {
        //cout << pt->val << " ";
        arr[in] = pt->val;
        pt = pt->next;
        in++;
    } //cout << endl;

    for (int i = in - 1; i > -1; i--) {
        fout << arr[i] << " ";
    }
}


void push(node*& head, int key) {

    node* el = new node; el = init(key);

    if (!head) head = el;

    else {
        node* buf = head;

        head = el;
        head->val = el->val;
        head->next = buf;

        el = buf;
        el->val = buf->val;
        el->next = buf->next;
    }
}


bool pop(node*& head) {

    if (!head) { return true; }

    else {
        if (head->next == NULL) {
            delete head;
            head = NULL;
        }

        else {
            node* buf = head;
            head = head->next;
            buf = NULL;
        }
    }

    return false;
}


int main() {

    node* head = NULL;
    char line[12] = {};
    int num = 0; bool is_error = false;

    while (!fin.eof() and !is_error) {
        if (!fin.eof()) {

            fin.getline(line, 12);

            if (line[0] == '+') {
                is_error = (!(line[1] > 47 and line[1] < 58));
                line[0] = '0';
                num = atoi(line);
                push(head, num);
            }

            if (line[0] == '-')
                is_error = (line[1] != 0),
                is_error = pop(head);
                //cout << (int)line[1];
        }
    }

    if (is_error) {
        fout << "ERROR"; return 0;
    }

    if (!size(head)) {
        fout << "EMPTY"; return 0;
    }

    print(head);
}


//int main() {
//    char line[12] = {};
//    fin.getline(line, 12);
//    cout << line << endl;
//    line[0] = '0';
//    int a = atoi(line);
//    cout << a;
//}

/// https://informatics.msk.ru/mod/statements/view.php?chapterid=112491#1
