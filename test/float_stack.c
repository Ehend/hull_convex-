#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
	int capacity;
	int head;
	float *data;
}stack;

stack* creat_stack(int capacity)
{
	stack* s;
	float* d;
	int head = 0;
	s = (stack*)malloc(sizeof(stack));
	d = (float*)malloc(capacity*sizeof(float));
	if (s == NULL || d == NULL)
	{
		printf_s("ջ�ڴ����ʧ�ܣ��޷�����ջ��\n");
	}
	else
	{
		s->capacity = capacity;
		s->data = d;
		s->head = head;
	}
	return s;
}

void push(stack* s, float d)
{
	if (s->head >= s->capacity)
	{
		s->capacity = 2 * s->capacity;
		s->data = (float*)realloc(s->data, s->capacity * sizeof(float));
		printf_s("ջ��������չջ�ռ䣡\n");
	}
	s->data[s->head] = d;
	s->head++;
}

float pop(stack* s)
{
	float d;
	int capacity1_4;
	capacity1_4 = s->capacity / 4;
	if (s->head <= 0)
	{
		printf_s("ջ���ˣ��޷����г�ջ������\n");
		return -1;
	}
	if (s->head < capacity1_4)
	{
		s->capacity = capacity1_4;
		s->data = (float*)realloc(s->data, s->capacity * sizeof(float));
		printf_s("ջ���գ�����Сջ�Ĵ�С��\n");
	}
	d = s->data[s->head-1];
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

void printf_stack(stack* s)
{
	for (int i = 0; i < s->head; i++)
	{
		printf_s("%f ",s->data[i]);
	}
	printf_s("\n");
}