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
	menu = input_only_num();
	return menu;
}

// 관리자 메뉴
int manager_menu()
{
	printf("※관리자 전용 메뉴 입니다.※\n");
	printf("※시즌 교체는 남아 있는 재고를 완전히 비웁니다.※\n");
	printf("1. 봄 / 가을 용 정장 재고 채우기\n");
	printf("2. 여름 용 정장 재고 채우기\n");
	printf("3. 겨울 용 정장 재고 채우기\n");

	// 나중에 메뉴 추가
	//printf("1. 접속한 고객의 구매 목록 확인\n");
	//printf("2. 총 판매 액수 확인\n");
	//printf("3. 재고 채우기 또는 시즌 교체\n");
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
	printf("1. 봄 / 가을 용 정장\n"); // 상의 하의로 분류
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
	int num = 0;
	while (1) {
		printf("※ 숫자(양의 정수)만 선택하여 주세요!!! ※\n");
		printf("숫자(양의 정수)를 입력해주세요 : ");
		scanf("%d", &num);
 
		if (num > 0) {
			break;
		} else {
			while (getchar() != '\n'); // 숫자외의 값을 입력하면 무한 반복
		}
		//system("cls");				
	}
	return num;
}