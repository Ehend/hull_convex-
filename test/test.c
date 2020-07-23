#include <stdio.h>
#include <stdlib.h>
#include "stack_operate.h"
#include "Graham_scan.h"

void main() 
{
	coodinate* adrs_c;
	int n;
	stack* sta;
	scanf_s("%d", &n);
	adrs_c = input_coodinate(n);
	sta = hull_convex(adrs_c, n);
	printf_convex(sta);
	del_stack(sta);
}