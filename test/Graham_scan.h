#ifndef __GRAHAM_SCAN_H__
#define __GRAHAM_SCAN_H__
#include "stack_da_str.h"
coodinate* input_coodinate(int n);
coodinate min_y(coodinate* c, int length);
void cacul_cos(coodinate* c, coodinate c0, int length);
void sort_cos(coodinate* c, int length);
void swap(coodinate* a, coodinate* b);
stack* find_convex(coodinate* c, int length);
int ccw(coodinate a, coodinate b, coodinate c);
stack* hull_convex(coodinate* c, int length);
#endif