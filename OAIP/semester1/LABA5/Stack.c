#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#define False 0
#define True 1
typedef int t_value;

struct stack {
    int maxsize;
    int top;
    int *items;
};

///////////////////////////////////////////////////////////////////////////////////

struct stack *Init(int maxsize) { // инициализация
    struct stack *pt = (struct stack *) malloc(sizeof(struct stack));
    pt->maxsize = maxsize;
    pt->top = -1;
    pt->items = (int *) malloc(sizeof(int) * maxsize);
    if (pt != 0)
        return pt;
    else {
        return NULL;
    }
};

///////////////////////////////////////////////////////////////////////////////////

//int Del_struct(struct stack* pt){ // удаление структуры
//    if (pt == NULL){
//        return False;
//    }
//    for (int i = 1; i <= pt -> maxsize; i++){
//        free(pt->top + i);
//    }
//    free(pt);
//    return True;
//}

///////////////////////////////////////////////////////////////////////////////////

int Size_struct(struct stack *pt) { // взятие размера
    return pt->top + 1;
}

///////////////////////////////////////////////////////////////////////////////////

int Is_Empty(struct stack *pt) { // проверка на пустоту
    return pt->top == -1;
}

///////////////////////////////////////////////////////////////////////////////////

int Is_Full(struct stack *pt) { // проверка на заполненность
    return pt->top == pt->maxsize - 1;
}

///////////////////////////////////////////////////////////////////////////////////

void Add_head(struct stack *pt, int x) { // добавление в начало

    if (Is_Full(pt)) {
        printf("STACK IS FULL");
        exit(EXIT_FAILURE);
    }
    pt->items[++pt->top] = x;
}

///////////////////////////////////////////////////////////////////////////////////

int Get_head(struct stack *pt) { // вывод начала (первого элемента)
    if (!Is_Empty(pt)) {
        return pt->items[pt->top];
    } else {
        printf("EMPTY");
        exit(EXIT_FAILURE);
    }
}

///////////////////////////////////////////////////////////////////////////////////

int Del_head(struct stack *pt) { // удаление первого элемента
    if (Is_Empty(pt)) {
        printf("NOT ELEMENT");
        exit(EXIT_FAILURE);
    }
    return pt->items[pt->top--];
}







