#ifndef STRUCTARRAY_LIBRARY_H
#define STRUCTARRAY_LIBRARY_H

struct stack *Init(int maxsize);
//int Del_struct(struct stack* pointer);
int Size_struct(struct stack * pointer);
int Is_Empty(struct stack * pointer);
int Is_Full(struct stack * pointer);
void Add_head(struct stack * pointer, int var);
int Get_head(struct stack * pointer);
int Del_head(struct stack * pointer);
#endif //STRUCTARRAY_LIBRARY_H
