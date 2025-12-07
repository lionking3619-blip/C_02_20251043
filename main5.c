/******************************************************************************

완성

*******************************************************************************/

#include <stdio.h>

#define ITEM 5
#define NAME 100

void input(char itname[ITEM][NAME], int* incoming, int* price, int* judge);
void output(int* incoming, int* sale);
void prtstock(int* stock, int* incoming, int* sale);
void total(int* incoming, int* sale);
void itminmax(int* sale, char itname[ITEM][NAME]);
void stocklack(int* stock, char itname[ITEM][NAME]);
void inputname(char itname[ITEM][NAME], int id);
void itemInfo(char itname[ITEM][NAME], int incoming[ITEM], int sale[ITEM], int price[ITEM]);

int main()
{
	int menu = 0;
	int incoming[ITEM] = { 0 };	//입고수량
	int sale[ITEM] = { 0 };	//판매수량
	int stock[ITEM] = { 0 };	//재고수량
	int price[ITEM] = { 0 };
	int judge[ITEM] = { 0 };
	char itname[ITEM][100] = { 0 };

	printf("[쇼핑몰 관리 프로그램]\n");

	while (menu != 5)
	{
		printf("원하는 메뉴를 선택하세요.(1.입고, 2.판매, 3.개별상품정보, 4.전체상품정보, 5.종료)\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			input(itname, incoming, price, judge);
			break;

		case 2:
			output(incoming, sale);
			break;

		case 3:
			itemInfo(itname, incoming, sale, price);
			break;

		case 4:
			prtstock(stock, incoming, sale);
			total(incoming, sale);
			itminmax(sale, itname);
			stocklack(stock, itname);
			break;

		case 5:
			printf("[프로그램 종료됨]\n");
			break;

		default:
			printf("옳바른 숫자를 입력해주세요.\n");
			break;
		}
	}

	return 0;
}

void input(char itname[ITEM][NAME], int* incoming, int* price, int* judge)	//1.입고
{
	int id = 0;

	printf("상품ID : ");
	scanf("%d", &id);

	id = id - 1;

	inputname(itname, id);

	do
	{
		printf("입고량 : ");
		scanf("%d", &incoming[id]);

		if (incoming[id] < 0)
		{
			printf("입고 수량은 0 이상이여야 합니다.\n");
		}
	} while (incoming[id] < 0);

	do
	{
		printf("판매가격 : ");
		scanf("%d", &price[id]);

		if (price[id] < 0)
		{
			printf("판매가격은 0 이상이여야 합니다.\n");
		}
	} while (price[id] < 0);

	judge[id] = 1;
}

void output(int* incoming, int* sale)	//2.판매
{
	int id = 0;

	printf("상품 ID : ");
	scanf("%d", &id);

	id -= 1;

	do
	{
		printf("판매수량 : ");
		scanf("%d", &sale[id]);

		if (sale[id] < 0 || sale[id] > incoming[id])
		{
			printf("판매 수량은 0 이상, 입고 수량 이하여야 합니다.\n");
		}
	} while (sale[id] < 0 || sale[id] > incoming[id]);
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

void itminmax(int* sale, char itname[ITEM][NAME])	//최대, 최소로 판매된 상품 출력
{
	int max = sale[0];
	int min = sale[0];
	int max_id = 1;
	int min_id = 1;

	for (int i = 0; i < ITEM; i++)
	{
		int j = 0;

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

	printf("가장 많이 판매된 상품 ID : %d, 상품명 %s: , 판매량 : %d\n", max_id, itname[max_id], max);
	printf("가장 적게 판매된 상품 ID : %d, 상품명 %s: , 판매량 : %d\n", min_id, itname[min_id], min);
}

void stocklack(int* stock, char itname[ITEM][NAME])	//부족한 재고 출력
{
	int id = 0;

	for (int i = 0; i < ITEM; i++)
	{
		int j = 0;

		if (stock[i] <= 2)
		{
			id = i + 1;
			printf("상품 ID : %d, 상품명 : %s, 재고부족(%d)\n", id, itname[i], stock[i]);
		}
	}
}

void inputname(char itname[ITEM][NAME], int id)	//4.상품명입력
{
	int ch;
	int j = 0;

	getchar();

	printf("상품명 : ");

	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		itname[id][j++] = ch;
	}

	itname[id][j] = '\0';
}

void itemInfo(char itname[ITEM][NAME], int incoming[ITEM], int sale[ITEM], int price[ITEM])
{
	int id;
	int total_sal;

	printf("상품 ID : ");
	scanf("%d", &id);

	id -= 1;
	total_sal = price[id] * sale[id];

	printf("상품명 : %s\n", itname[id]);
	printf("상품가격 : %d\n", price[id]);
	printf("입고량 : %d\n", incoming[id]);
	printf("판매량 : %d\n", sale[id]);
	printf("총판매금액 : %d\n", total_sal);
}
