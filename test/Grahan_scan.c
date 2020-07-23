#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack_operate.h"
#include "Graham_scan.h"

coodinate* input_coodinate(int n)
{
	coodinate* c;
	c = (coodinate*)malloc(n * sizeof(coodinate));
	for (int i = 0; i < n; i++)
	{
		scanf_s("%f%f", &c[i].x, &c[i].y);
		c[i].s = 0;
	}
	return c;
}

coodinate min_y(coodinate* c, int length)
{
	for (int i = 1; i < length; i++)
	{
		if (c[i].y < c[0].y)
			swap(&c[i], &c[0]);
	}
	return c[0];
}

void cacul_cos(coodinate* c, coodinate c0, int length)
{
	float r;
	for (int i = 1; i < length; i++)
	{
		r = sqrt(pow((c[i].y - c0.y), 2) + pow((c[i].x - c0.x), 2));
		c[i].s = (c[i].x - c0.x) / r;
	}
}

void sort_cos(coodinate* c, int length)
{
	int h = 1;
	double temp_h;
	temp_h = (double)(length) / 3.0;
	while (h < temp_h) h = 3 * h + 1;
	while (h > 0)
	{
		for (int i = 1; i < length - h; i++)
		{
			for (int j = i + h; j > h; j -= h)
			{
				if (-c[j - h].s > -c[j].s)
					swap(&c[j - h], &c[j]);
				else
					break;
			}
		}
		h = h / 3;
	}
}

void swap(coodinate* a, coodinate* b)
{
	coodinate temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

stack* find_convex(coodinate* c, int length)
{
	stack* sta;
	coodinate top;
	sta = creat_stack(10);
	push(sta, c[0]);
	push(sta, c[1]);
	for (int i = 2; i < length; i++)
	{
		top = pop(sta);
		while (ccw(sta->data[sta->head - 1], top, c[i]) == 0)
			top = pop(sta);
		push(sta, top);
		push(sta, c[i]);
	}
	return sta;
}

int ccw(coodinate a, coodinate b, coodinate c)
{
	float area;
	area = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	if (area <= 0)
		return 0;
	else
		return 1;
}

stack* hull_convex(coodinate* c, int length)
{
	
	coodinate c0;
	stack*  sta;
	c0 = min_y(c, length);
	cacul_cos(c, c0, length);
	sort_cos(c, length);
	sta = find_convex(c, length);
	return sta;
}