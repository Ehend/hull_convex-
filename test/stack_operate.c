#include <stdio.h>
#include <stdlib.h>
#include "stack_da_str.h"

stack* creat_stack(int capacity)
{
	stack* s;
	coodinate* c;
	int head = 0;
	s = (stack*)malloc(sizeof(stack));
	c = (coodinate*)malloc(capacity * sizeof(coodinate));
	if (s == NULL || c == NULL)
	{
		printf_s("ջ�ڴ����ʧ�ܣ��޷�����ջ��\n");
	}
	else
	{
		s->capacity = capacity;
		s->data = c;
		s->head = head;
	}
	return s;
}

void push(stack* s, coodinate d)
{
	if (s->head >= s->capacity)
	{
		s->capacity = 2 * s->capacity;
		s->data = (coodinate*)realloc(s->data, s->capacity * sizeof(coodinate));
		printf_s("ջ��������չջ�ռ䣡\n");
	}
	s->data[s->head] = d;
	s->head++;
}

coodinate pop(stack* s)
{
	coodinate d;
	int capacity1_4;
	capacity1_4 = s->capacity / 4;
	if (s->head <= 0)
	{
		printf_s("ջ���ˣ��޷����г�ջ������\n");
	}
	if (s->head < capacity1_4)
	{
		s->capacity = capacity1_4+1;
		s->data = (coodinate*)realloc(s->data, s->capacity * sizeof(coodinate));
		printf_s("ջ���գ�����Сջ�Ĵ�С��\n");
	}
	d = s->data[s->head - 1];
	s->head--;
	return d;
}

void del_stack(stack* s)
{
	free(s->data);
	s->data = NULL;
	free(s);
	s = NULL;
	printf_s("ɾ��ջ�ɹ���\n");
}

void printf_convex(stack* s)
{
	for (int i = 0; i < s->head; i++)
	{
		printf_s("%f %f\n", s->data[i].x,s->data[i].y);
	}
	printf_s("\n");
}