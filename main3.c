/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define ITEM 5

void input(int* incoming);
void output(int* incoming, int* sale);
void prtstock(int* stock, int* incoming, int* sale);
void total(int* incoming, int* sale);
void itminmax(int* sale);
void stocklack(int* stock);

int main()
{
	int menu = 0;
	int incoming[ITEM] = { 0 };	//입고수량
	int sale[ITEM] = { 0 };	//판매수량
	int stock[ITEM] = { 0 };	//재고수량

	printf("[쇼핑몰 관리 프로그램]\n");

	while (menu != 4)
	{
		printf("원하는 메뉴를 선택하세요.(1.입고, 2.판매, 3.상품현황, 4.종료)\n");
		scanf("%d", &menu);

		if (menu == 1)
		{
			input(incoming);
		}
		else if (menu == 2)
		{
			output(incoming, sale);
		}
		else if (menu == 3)
		{
			prtstock(stock, incoming, sale);
			total(incoming, sale);
			itminmax(sale);
			stocklack(stock);
		}
		else if (menu == 4)
		{
			printf("[프로그램 종료됨]\n");
		}
		else
		{
			printf("옳바른 숫자를 입력해주세요.\n");
		}
	}
	
	return 0;
}

void input(int* incoming)	//1.입고
{
	int kind = 0;
	int id = 0;

	printf("입고수량 입력 : 전체 상품 입고수량 입력은 1, 개별 상품 입력은 2를 선택\n");
	scanf("%d", &kind);

	if (kind == 1)
	{
		for (int i = 0; i < ITEM; i++)
		{
			scanf("%d", &incoming[i]);
			if (incoming[i] < 0)
			{
				printf("입고 수량은 0 이상이여야 합니다.\n");
				i--;
			}
		}
	}
	else if (kind == 2)
	{
		printf("상품 ID : ");
		scanf("%d", &id);

		printf("입고수량 : ");
		scanf("%d", &incoming[id - 1]);
		if (incoming[id - 1] < 0)
		{
			printf("입고 수량은 0 이상이여야 합니다.\n");
		}
	}
	else
	{
		printf("옳바른 숫자를 입력해주세요.\n");
	}
}

void output(int* incoming, int* sale)	//2.판매
{
	int kind = 0;
	int id = 0;

	printf("판매수량 입력 : 전체 상품 판매수량 입력은 1, 개별 상품 입력은 2를 선택\n");
	scanf("%d", &kind);

	if (kind == 1)
	{
		for (int i = 0; i < ITEM; i++)
		{
			scanf("%d", &sale[i]);
			if (sale[i] < 0 || sale[i] > incoming[i])
			{
				printf("판매 수량은 0 이상, 입고 수량 이하이여야 합니다.\n");
				i--;
			}
		}
	}
	else if (kind == 2)
	{
		printf("상품 ID : ");
		scanf("%d", &id);

		printf("입고수량 : ");
		scanf("%d", &sale[id - 1]);
		if (sale[id - 1] < 0)
		{
			printf("판매 수량은 0 이상이여야 합니다.\n");
		}
	}
	else
	{
		printf("옳바른 숫자를 입력해주세요.\n");
	}
}

//상품현황
void prtstock(int* stock, int* incoming, int* sale)	//모든 상품의 재고수량 계산 및 출력
{

	for (int i = 0; i < ITEM; i++)
	{
		stock[i] = incoming[i] - sale[i];
	}

	printf("모든 상품의 재고 수량 : ");

	for (int i = 0; i < ITEM; i++)
	{
		printf("%2d ", stock[i]);
	}

	printf("\n");

}

void total(int* incoming, int* sale)	//총 판매량 출력
{
	int total_inc = 0;	//총 입고량
	int total_sal = 0;	//총 판매량
	float sal_per = 0.0;	//판매율

	for (int i = 0; i < ITEM; i++)
	{
		total_inc += incoming[i];
		total_sal += sale[i];
	}

	sal_per = ((float)total_sal / total_inc) * 100;

	printf("총 판매량 : %d (판매율 %.2f%%)\n", total_sal, sal_per);
}

void itminmax(int* sale)	//최대, 최소로 판매된 상품 출력
{
	int max = sale[0];
	int min = sale[0];
	int max_id = 1;
	int min_id = 1;

	for (int i = 0; i < ITEM; i++)
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
}

void stocklack(int* stock)	//부족한 재고 출력
{
	int id = 0;

	for (int i = 0; i < ITEM; i++)
	{
		if (stock[i] <= 2)
		{
			id = i + 1;
			printf("상품 ID : %d, 재고부족(%d)\n", id, stock[i]);
		}
	}
}