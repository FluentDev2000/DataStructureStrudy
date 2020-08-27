/* int�� ���� IntStack (�ҽ�) */
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

/*--- ���� �ʱ�ȭ ---*/
//����ü �����Ϳ� int�ϳ��� �޴´�, int�� ������ ũ��
int Initialize(IntStack* s, int max)
{
	//����ü ������ s�� ����Ű�� ����ü ������ ptr�� 0���� �ʱ�ȭ
	s->ptr = 0;

	//calloc���� intũ���� �޸𸮸� max����ŭ �Ҵ�ް� ù �ּҷ� s->stk�� �ʱ�ȭ
	if ((s->stk = calloc(max, sizeof(int))) == NULL)
	{
		//�ʱ�ȭ ����
		s->max = 0;
		return -1;
	}
	//�ʱ�ȭ ������ s�� max���� �μ� max�� �ʱ�ȭ
	s->max = max;

	//�ʱ�ȭ ����
	return 0;
}

/*--- ���ÿ� �����͸� Ǫ��---*/
int Push(IntStack* s, int x)
{
	//���� �����Ͱ� ������ �ƽ����� Ŭ ��� = ������ ������ ���
	if (s->ptr >= s->max)
		//����
		return -1;

	//������ ������ ���� ���
	//���� ù ����� ������[���� ������]�� ���� �μ� x�� �ʱ�ȭ ���� ���� ������ 1����
	s->stk[s->ptr++] = x;
	return 0;
}

/*--- ���ÿ��� �����͸� �� ---*/
int Pop(IntStack* s, int* x)
{
	//���� �����Ͱ� 0������ �� = ������ ��� ���� ��
	if (s->ptr <= 0)
		//����
		return -1;

	//x�� ���������ؼ� ���� ������ ���� -1 �� �ּ� �ȿ� �ִ� ������ �ʱ�ȭ
	*x = s->stk[--(s->ptr)];
	return 0;
}

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const IntStack* s, int* x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

/*--- ���� ���� ---*/
void Clear(IntStack* s)
{
	s->ptr = 0;
}

/*--- ���� �뷮 ---*/
int Capacity(const IntStack* s)
{
	return s->max;
}

/*--- ���ÿ� �׿� �ִ� ������ �� ---*/
int Size(const IntStack* s)
{
	return s->ptr;
}

/*--- ������ ��� �ִ°�? ---*/
int IsEmpty(const IntStack* s)
{
	return s->ptr <= 0;
}

/*--- ������ ���� á�°�? ---*/
int IsFull(const IntStack* s)
{
	return s->ptr >= s->max;
}

/*--- ���ÿ��� �˻� ---*/
int Search(const IntStack* s, int x)
{
	int i;

	for (i = s->ptr - 1; i >= 0; i--)	/* �����(top) �� �ٴ�(bottom)���� ���� �˻� */
		if (s->stk[i] == x)
			return i;		/* �˻� ���� */
	return -1;				/* �˻� ���� */
}

/*--- ��� ������ ǥ�� ---*/
void Print(const IntStack* s)
{
	int i;

	for (i = 0; i < s->ptr; i++)		/* �ٴ�(bottom) �� �����(top)�� ��ĵ */
		printf("%d ", s->stk[i]);
	putchar('\n');
}

/*--- ���� ���� ---*/
void Terminate(IntStack* s)
{
	if (s->stk != NULL)
		free(s->stk);		/* �迭�� ���� */
	s->max = s->ptr = 0;
}
