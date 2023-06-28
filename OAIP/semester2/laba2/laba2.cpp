#include <iostream>
//#include <str.cpp>
using namespace std;


// #1 //==============================================================================//

//unsigned short hash_(str s) {
//    unsigned short prod = 1,
//        sum = 0;
//    for (int i = 0; i < s.size(); i++) {
//        prod *= s[i] + ~(i + s[i]) * i * i ^ s[i] * s[i];
//        sum += s[i] ^ (i * s[i]);
//    }
//
//    return prod % 4095 + ((sum % 10) << 12);
//}
//
//int main() {
//    str s; cin >> s;
//    int sz = s.size();
//    //cout << (int)s.convert()[sz] << "\n\n\n\n";
//    s = s / (sz - 1); sz--;
//
//    str s1 = "", s2 = "";
//
//
//    s1 = s / (sz / 2);
//    s2 = s / -(sz / 2);
//
//    /*str s1 = s / (sz / 2),
//        s2 = s / -(sz / 2);*/
//
//    /*cout << "strs: " << s1.convert() << " " << s2.convert() << endl;
//    cout << "sizes: " << sz << " " << s1.size() << " " << s2.size() << endl;
//    cout << "hashes: " << hash_(s1) << " " << hash_(-s2);*/
//    
//    if (hash_(s1) == hash_(-s2)) cout << "\nTRUE\n";
//    else cout << "\nFALSE\n";
//}



// #2 //==============================================================================//

/* Определение структуры узла дерева */
//struct node {
//    int data;
//    node* left;
//    node* right;
//};
//
///* Функция для создания нового узла дерева */
//node* init(int data) {
//    node* newNode = (node*)malloc(sizeof(node));
//    newNode->data = data;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//
///* Функция для вставки нового узла в дерево */
//node* add(node* node, int data) {
//    if (node == NULL) {
//        return init(data);
//    }
//    else {
//        if (data <= node->data) {
//            node->left = add(node->left, data);
//        }
//        else {
//            node->right = add(node->right, data);
//        }
//        return node;
//    }
//}
//
///* Функция для поиска элемента в дереве */
//node* find(node* node, int data) {
//    if (node == NULL or node->data == data) {
//        return node;
//    }
//    else if (data < node->data) {
//        return find(node->left, data);
//    }
//    else {
//        return find(node->right, data);
//    }
//}
//
///* Функция для удаления узла из дерева */
//node* del(node* nod, int data) {
//    if (nod == NULL) {
//        return nod;
//    }
//    else if (data < nod->data) {
//        nod->left = del(nod->left, data);
//    }
//    else if (data > nod->data) {
//        nod->right = del(nod->right, data);
//    }
//    else {
//        /* Узел с заданным значением найден */
//        /* Определяем тип удаляемого узла */
//        if (nod->left == NULL and nod->right == NULL) {
//            /* Узел не имеет потомков */
//            free(nod);
//            nod = NULL;
//        }
//        else if (nod->left == NULL) {
//            /* Узел имеет только правого потомка */
//            node* temp = nod;
//            nod = nod->right;
//            free(temp);
//        }
//        else if (nod->right == NULL) {
//            /* Узел имеет только левого потомка */
//            node* temp = nod;
//            nod = nod->left;
//            free(temp);
//        }
//        else {
//            /* Узел имеет обоих потомков */
//            /* Находим наименьший узел в правом поддереве */
//            node* temp = nod->right;
//            while (temp->left != NULL) {
//                temp = temp->left;
//            }
//            /* Заменяем удаляемый узел на найденный */
//            nod->data = temp->data;
//            /* Удаляем найденный узел */
//            nod->right = del(nod->right, temp->data);
//        }
//    }
//    return nod;
//}
//
///* Функция для обхода дерева в порядке "влево-корень-вправо" */
//void print(node* nod) {
//    if (nod != NULL) {
//        print(nod->left);
//        //printf("%d ", nod->data);
//        cout << nod->data << " ";
//        print(nod->right);
//    }
//}
//
//
//int main() {
//    node* root = NULL;
//    root = add(root, 10);
//    add(root, 5);
//    add(root, 15);
//    add(root, 2);
//    add(root, 2);
//    add(root, 12);
//    add(root, 20);
//
//    node* foundNode = find(root, 50);
//    if (foundNode != NULL) {
//        cout << "Found: " << foundNode->data << endl;
//    }
//    else {
//        cout << "Nah found\n";
//    }
//    print(root);
//
//    /* Удаляем узел со значением 10 */
//    root = del(root, 10);
//
//    cout << "\nAfter deleting node with value 10:\n";
//    print(root);
//}


// #3 //==============================================================================//

//class AVL {
//public:
//    int key;
//    AVL* parent;
//    AVL* left;
//    AVL* right;
//    int balance;
//};
//
//void deinit(AVL* root) {
//    if (root != NULL) {
//        deinit(root->left);
//        deinit(root->right);
//        delete root;
//    }
//}
//
//int size(AVL* el) {
//    if (el == NULL) {
//        return 0;
//    }
//    return el->balance;
//}
//
//AVL* init(int key) {
//    AVL* node = new AVL();
//    node->key = key;
//    node->left = NULL;
//    node->right = NULL;
//    node->balance = 1;
//    return node;
//}
//
//AVL* Rrot(AVL* el) {
//    AVL* x = el->left;
//    AVL* y = x->right;
//    x->right = el;
//    el->left = y;
//    el->balance = max(size(el->left), size(el->right)) + 1;
//    x->balance = max(size(x->left), size(x->right)) + 1;
//    return x;
//
//}
//
//AVL* Lrot(AVL* el) {
//    AVL* y = el->right;
//    AVL* x = y->left;
//
//    y->left = el;
//    el->right = x;
//    el->balance = max(size(el->left), size(el->right)) + 1;
//    x->balance = max(size(x->left), size(x->right)) + 1;
//    return el;
//}
//
//int cur_balance(AVL* n) {
//    if (n == NULL) {
//        return 0;
//    }
//    return (size(n->left) - size(n->right));
//}
//
//AVL* add(AVL* node, int key) {
//
//    if (node == NULL) {
//        return (init(key));
//    }
//
//    if (key < node->key) node->left = add(node->left, key);
//
//    else if (key > node->key) node->right = add(node->right, key);
//
//    else return node;
//
//    node->balance = 1 + max(size(node->left), size(node->right));
//    int balance = cur_balance(node);
//
//    if (balance > 1 and key < node->left->key) return Rrot(node);
//
//    if (balance < -1 and key > node->right->key) return Lrot(node);
//
//    if (balance > 1 && key > node->left->key) {
//        node->left = Lrot(node->left);
//        return Rrot(node);
//    }
//
//    if (balance < -1 && key < node->right->key) {
//        node->right = Rrot(node->right);
//        return Lrot(node);
//    }
//
//    return node;
//}
//
//AVL* minval(AVL* node) {
//    AVL* cur = node;
//    while (cur->left != NULL) {
//        cur = cur->left;
//    }
//    return cur;
//}
//
//AVL* del(AVL* root, int key) {
//    if (root == NULL) return root;
//
//    if (key < root->key) root->left = del(root->left, key);
//
//    else if (key > root->key) root->right = del(root->right, key);
//
//    else {
//        if ((root->left == NULL) || (root->right == NULL)) {
//            AVL* temp = root->left ? root->left : root->right;
//            if (temp == NULL) {
//                temp = root;
//                root = NULL;
//            }
//            else {
//                *root = *temp;
//                free(temp);
//            }
//        }
//
//        else {
//            AVL* temp = minval(root->right);
//            root->key = temp->key;
//            root->right = del(root->right, temp->key);
//        }
//    }
//
//    if (root == NULL) return root;
//
//    root->balance = 1 + max(size(root->left), size(root->right));
//    int balance = cur_balance(root);
//
//    if (balance > 1 and cur_balance(root->left) >= 0) return Rrot(root);
//
//    if (balance > 1 and cur_balance(root->left) < 0) {
//        root->left = Lrot(root->left);
//        return Rrot(root);
//    }
//
//    if (balance < -1 and cur_balance(root->right) <= 0) return Lrot(root);
//
//    if (balance < -1 and cur_balance(root->right) > 0) {
//        root->right = Rrot(root->right);
//        return Lrot(root);
//    }
//
//    return root;
//}
//
//AVL* find(AVL* node, int key) {
//    if (node == NULL or node->key == key) return node;
//
//    else if (key < node->key) return find(node->left, key);
//
//    else return find(node->right, key);
//}
//
//void out(AVL* root) {
//    if (root != NULL) {
//        out(root->left);
//        cout << root->key << " ";
//        out(root->right);
//    }
//}
//
//int main() {
//    AVL* root = NULL;
//
//    root = add(root, 12);
//    root = add(root, 8);
//    root = add(root, 18);
//    root = add(root, 5);
//    root = add(root, 11);
//    root = add(root, 4);
//    root = add(root, 4);
//
//    out(root); cout << endl;
//
//    root = del(root, 4);
//
//    out(root); cout << endl;
//}


// #4 //==============================================================================//

//bool P(str s1, str s2) {
//    int sz1 = s1.size();
//    int sz2 = s2.size();
//    bool flg = 1;
//
//    if (sz1 != sz2) return 0;
//
//    for (int i = 0; (i < sz1) and flg; i++) {
//        flg = flg and (s1.count(s1[i]) == s2.count(s1[i]));
//    }
//
//    return flg;
//}
//
//int main() {
//    str a, b; 
//    cout << "Set main string: "; cin >> a;
//    cout << "Set substring: "; cin >> b;
//
//    int as = a.size(), bs = b.size();
//
//    for (int i = bs; i <= as; i++) {
//        str sub = (a / i) / -bs;
//
//        if (P(sub, b)) { 
//            cout << endl << i - bs << " " << sub.convert() << endl;
//            return 0;
//        }
//    }
//    cout << "\nNothing was found\n";
//}



// #5 //==============================================================================//

//int main() {
//	str a = input("Set main string: "),
//		b = input("old str: "),
//		c = input("new str: ");
//
//	//cout(a + " " + b + " " + c)
//	cout((str)"\n" + a.replace(b, c))
//}
