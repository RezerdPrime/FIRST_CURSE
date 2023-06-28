#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

struct stack *Init(int maxsize); 
int Del_first_Queue(); 
void Add_end_Queue(int item);
int Get_first();
int Is_empty();
int Deinit();

#endif //QUEUE_QUEUE_H
