#ifndef __STACK_OPERATE__
#define __STACK_OPERATE__
#include "Graham_scan.h"
#include "stack_da_str.h"
stack* creat_stack(int capacity);
void push(stack* s, coodinate d);
coodinate pop(stack* s);
void del_stack(stack* s);
void printf_convex(stack* s);
#endif