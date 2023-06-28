#include <stdio.h>
#include "Queue.c"
#include "Stack.c"

//int main() {
//    Add_end_Queue(1); Add_end_Queue(2);
//    Add_end_Queue(3); Add_end_Queue(4);
//
//    printf("FIRST IS: %d\n", Get_first());
//
//    Del_first_Queue(); Del_first_Queue();
//    Del_first_Queue(); //Del_first_Queue();
//
//    Deinit();
//
//    if (Is_empty()) { printf("EMPTY"); }
//
//    else { printf("NAH EMPTY"); }
//}

int main() {
    struct stack* pointer = Init(5);
    Add_head(pointer, 1);
    Add_head(pointer, 2);
    Add_head(pointer, 3);

    printf("FIRST IS: %d\n", Get_head(pointer));
    printf("STACK SIZE IS: %d\n", Size_struct(pointer));

    Del_head(pointer);
    Del_head(pointer);

    printf("FIRST IS: %d\n", Get_head(pointer));
    printf("SIZE IS: %d\n", Size_struct(pointer));

    Del_head(pointer);

    printf("FIRST IS: %d\n", Get_head(pointer));
    printf("SIZE IS: %d\n", Size_struct(pointer));
}
