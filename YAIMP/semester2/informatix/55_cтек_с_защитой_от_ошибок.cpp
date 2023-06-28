#include <iostream>
using namespace std;

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


void print(node* head) {
    node* pt = head;

    while (pt) {
        cout << pt->val << " ";
        pt = pt->next;
    } cout << endl;
}


void back(node* head) {

    if (head) {
        cout << head->val << endl;
        /*node* pt = head;

        while (pt->next) { pt = pt->next;}
        cout << pt->val << endl;*/
    }

    else cout << "error\n";
}


int size(node* head, bool ok = 1) {

    if (!head) { if (ok) cout << "0\n"; return 0; }

    else {
        node* pt = head;
        int k = 0;

        while (pt) {
            k++;
            pt = pt->next;
        } 
        if (ok) cout << k << endl;
        return k;
    }
}


void push(node*& head, int key, bool ok = 1) {

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

    if (ok) cout << "ok\n";
}


void pop(node*& head, bool va = 1) {

    if (!head) cout << "error\n";

    else {
        if (head->next == NULL) {
            if (va) cout << head->val << endl;
            delete head;
            head = NULL;
        }

        else {
            if (va) cout << head->val << endl;
            node* buf = head;
            head = head->next;
            buf = NULL;
        }
    }
}


void clear(node*& head, bool ok = 1) {

    if (head) {
        while (size(head, 0)) pop(head, 0);
    }

    if (ok) cout << "ok\n";
}


void exit() {
    cout << "bye";
}


int main(){

    node* head = NULL;
    int hash = 0; char c = '0';

    //push(head, 0); push(head, 1); push(head, 2); push(head, 3);
    //clear(head);
    //pop(head);

    while (1) {

        while ((c != '\n') and (c != ' ')) {
            c = cin.get(); //cout << (int)c << " ";
            hash += (int)c; //cout << hash << " ";
        }
        hash -= (int)c;
        //cout << hash << " ";

        if (hash == 443) size(head);

        if (hash == 519) clear(head);

        if (hash == 448) {
            int a; cin >> a; push(head, a);
        }

        if (hash == 335) pop(head);

        if (hash == 401) back(head);

        if (hash == 442) { cout << "bye"; return 0; }

        hash = 0; c = '0';
    }
    
    /*node* head = NULL;

    push(head, 0); push(head, 1); push(head, 2); push(head, 3);

    size(head);

    clear(head);*/


    /* 
    
    112 + 117 + 115 + 104 = 448 -> push
    112 + 111 + 112 = 335 -> pop
    98 + 97 + 99 + 107 = 401 -> back
    115 + 105 + 122 + 101 = 443 -> size
    99 + 108 + 101 + 97 + 114 = 519 -> clear
    101 + 120 + 105 + 116 = 442 -> exit

    infortamix #55
    
    */
}

// https://informatics.msk.ru/mod/statements/view.php?chapterid=55#1
