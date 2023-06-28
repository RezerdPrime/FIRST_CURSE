#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#define False 0
#define True 1

struct Queue {
    int value;
    struct Queue* next;
} *last = NULL, *first = NULL;

//////////////////////////////////////////////////////////////////////////////////////////////

struct Queue* _init_(int item) { // выделение нового узла очереди
    
    struct Queue* Node = (struct Queue*)malloc(sizeof(struct Queue)); // выделение нового узла в куче

    if (Node != NULL) { // проверка заполненности
        
        Node->value = item;
        Node->next = NULL;
        return Node; // установка и возврат значений кучи
    }
    else { exit(EXIT_FAILURE); }
}

//////////////////////////////////////////////////////////////////////////////////////////////

int Del_first_Queue() { // удаление первого элемента

    if (first == NULL) { exit(EXIT_FAILURE); }

    struct Queue* cur = first;
    first = first->next;

    if (first == NULL) { last = NULL; }

    int item = cur->value;
    free(cur);
    return item;
}

//////////////////////////////////////////////////////////////////////////////////////////////

void Add_end_Queue(int item) { // добавление в конец

    struct Queue* node = _init_(item); // выделение узла очереди

    if (first == NULL) {
        first = node; last = node; // элемент как бы первый и последний, если узел пуст
    }
    else { last->next = node; last = node; }
}

//////////////////////////////////////////////////////////////////////////////////////////////

int Get_first() { // вывод первого элемента

    if (first != NULL) { // проверка на заполненность
        return first->value;
    }
    else { exit(EXIT_FAILURE); }
}

//////////////////////////////////////////////////////////////////////////////////////////////

int Is_empty() { return (first == NULL) and (last == NULL); } // думаю, понятно

//////////////////////////////////////////////////////////////////////////////////////////////

int Deinit() {

    if (first == NULL) { return False; }
    while (first != NULL) {
        Del_first_Queue();
    }
    return True;
}
