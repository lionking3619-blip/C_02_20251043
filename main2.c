/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define Max 100

int main()
{
	int itnum = 0;	//상품 종류의 개수
	int incoming[Max] = { 0 };	//입고수량
	int sale[Max] = { 0 };	//판매수량
	int stock[Max] = { 0 };	//재고수량
	int total_inc = 0;	//총 입고량
	int total_sal = 0;	//총 판매량
	float sal_per = 0.0;	//판매율
	int id = 0;

	printf("상품 종류의 개수를 입력 : ");
	scanf("%d", &itnum);

	while (itnum <= 0)
	{
		printf("상품 종류는 1개 이상 100개 이하여야 합니다.\n");
		printf("상품 종류의 개수를 입력 : ");
		scanf("%d", &itnum);
	}

	printf("입고 수량을 입력 : ");

	for (int i = 0; i < itnum; i++)
	{
		scanf("%d", &incoming[i]);
		if (incoming[i] < 0)
		{
			printf("입고 수량은 0 이상이여야 합니다.\n");
			i--;
		}
	}

	printf("판매 수량을 입력 : ");

	for (int i = 0; i < itnum; i++)
	{
		scanf("%d", &sale[i]);
		if (sale[i] < 0 || sale[i] > incoming[i])
		{
			printf("판매 수량은 0 이상, 입고 수량 이하이여야 합니다.\n");
			i--;
		}
	}

	for (int i = 0; i < itnum; i++)
	{
		stock[i] = incoming[i] - sale[i];
	}

	printf("모든 상품의 재고 수량 : ");

	for (int i = 0; i < itnum; i++)
	{
		printf("%2d ", stock[i]);
	}

	printf("\n");

	for (int i = 0; i < itnum; i++)
	{
		total_inc += incoming[i];
		total_sal += sale[i];
	}

	sal_per = ((float)total_sal / total_inc) * 100;

	printf("총 판매량 : %d (판매율 %.2f%%)\n", total_sal, sal_per);

	int max = sale[0];
	int min = sale[0];
	int max_id = 1;
	int min_id = 1;

	for (int i = 0; i < itnum; i++)
	{
		if (max < sale[i])
		{
			max = sale[i];
			max_id = i + 1;
		}
		if (min > sale[i])
		{
			min = sale[i];
			min_id = i + 1;
		}
	}

	printf("가장 많이 판매된 상품 ID : %d, 판매량 : %d\n", max_id, max);
	printf("가장 적게 판매된 상품 ID : %d, 판매량 : %d\n", min_id, min);

	for (int i = 0; i < itnum; i++)
	{
		if (stock[i] <= 2)
		{
			id = i + 1;
			printf("상품 ID : %d, 재고부족(%d)\n", id, stock[i]);
		}
	}

	return 0;
}