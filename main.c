/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define Max 100

int main()
{
	int itnum;	//상품 종류의 개수
	int incoming[Max];	//입고수량
	int sale[Max];	//판매수량
	int stock[Max];	//재고수량
	int id;

	printf("상품 종류의 개수를 입력 : ");
	scanf("%d", &itnum);

	printf("입고 수량을 입력 : ");

	for (int i = 0; i < itnum; i++)
	{
		scanf("%d", &incoming[i]);
	}

	printf("판매 수량을 입력 : ");

	for (int i = 0; i < itnum; i++)
	{
		scanf("%d", &sale[i]);
	}

	for (int i = 0; i < itnum; i++)
	{
		stock[i] = incoming[i] - sale[i];
	}

	printf("상품 ID를 입력 : ");
	scanf("%d", &id);

	printf("ID : %d의 재고 수량 : %d\n", id, stock[id - 1]);

	printf("모든 상품의 재고 수량 : ");

	for (int i = 0; i < itnum; i++)
	{
		printf("%2d ", stock[i]);
	}

	return 0;
}