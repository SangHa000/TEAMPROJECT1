#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit(), system() 메소드사용
#include "menu.h"

// 메인 메뉴
int main_menu()
{
	int menu = 0;
	printf("■■┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┓┳┓┳┓┳┓┳\n");
	printf("■■                                     ┃\n");
	printf("┃   ♠ 성인 남성용 정장 구매 프로그램 ♠ ┃\n");
	printf("┃                                        ┃\n");
	printf("┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛┻┛┻┛┻┛┛\n");
	printf(" 1. 계절별 정장 목록\n");
	printf(" 2. 관리자 메뉴\n");
	printf(" 3. 종료\n");
	//int menu;
	menu = input_only_num();
	return menu;
}

// 관리자 메뉴
int manager_menu()
{
	printf("1. 접속한 고객의 구매 목록 확인");
	printf("2. 총 판매 액수 확인");
	int num;
	num = input_only_num();
	return num;
}

// 계절별 정장 검색하는 메뉴
int search_season_suit_menu()
{
	printf("■■┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳\n");
	printf("■■                        ┃\n");
	printf("┃  ♠ Season별 정장 선택 ♠ ┃\n");
	printf("┃                           ┃\n");
	printf("┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛┻┛\n");
	printf("1. 봄 / 가을 용 정장\n");
	printf("2. 여름 용 정장\n");
	printf("3. 겨울 용 정장\n");
	printf("4. 메인 메뉴 돌아가기\n");
	int menu;
	menu = input_only_num();
	return menu;
}

// 숫자만 입력하게 
int input_only_num()
{
	int num;
	while (1) {
		//
		printf("※ 메뉴는 숫자만 선택하여 주세요!!! ※\n");
		printf("메뉴를 선택해주세요 : ");
		scanf("%d", &num);

		//printf("%d\n", num);
		//system("cls");
		while (getchar() != '\n'); // 숫자외의 값을 입력하면 무한 반복
		if (num == 1) {
			break;
		}
		break;
	}
	return num;
}