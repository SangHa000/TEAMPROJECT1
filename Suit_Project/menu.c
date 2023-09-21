#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit(), system() 메소드사용
#include "menu.h"
#include "intro.h"
#include "msg.h"

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
	font_color(RED);
	printf("※관리자 전용 메뉴 입니다.※\n");
	printf("※시즌 교체는 남아 있는 재고를 완전히 비웁니다.※\n");
	font_color(LIGHT_GRAY);
	printf("1. 봄 / 가을 용 정장 재고 채우기\n");
	printf("2. 여름 용 정장 재고 채우기\n");
	printf("3. 겨울 용 정장 재고 채우기\n");
	printf("4."RETURN_MAIN);

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
	printf("4."RETURN_MAIN);
	int menu;
	menu = input_only_num();
	return menu;
}

// 숫자만 입력하게 
int input_only_num()
{
	// scanf scanf함수의 문제 버퍼의 맨앞에만 값이 맞으면 넘어감
	int num = 0;
	while (1) {	
		font_color(LIGHT_RED);
		printf("※ 숫자(양수)만 선택하여 주세요!!! ※\n");
		font_color(LIGHT_GRAY);
		printf("숫자(양수)를 입력해주세요 : ");
		//char input = getchar();
		//scanf("%d", &num);
		//printf(input);
		scanf("%d", &num);

		if (num > 0) {
			break;
		}
		else {
			while (getchar() != '\n'); // 숫자외의 값을 입력하면 무한 반복
		}
		//system("cls");				
	}
	return num;
	//	if (input == 49 ||	input == 50 || input == 51 || input == 52 || input == 53 || input == 54) {
	//		returnNum = input - 48;
	//		break;
	//	} 
	//	else {
	//		while (getchar() != '\n'); // 숫자외의 값을 입력하면 무한 반복
	//	}
	//	//system("cls");				
	//}
	//while (getchar() != '\n') {}
	//return returnNum;
}

void purchase_suit_menu()
{
	font_color(LIGHT_YELLOW);
	printf("정장을 구매하시겠습니까?\n");
	printf("▷ S - 상의 구매를 진행 합니다.\n");
	printf("▷ P - 하의 구매를 진행 합니다.\n");
	printf("▷ N -정장목록으로 돌아갑니다.\n");
	font_color(LIGHT_GRAY);
}

void check_Y_or_N_menu()
{
	font_color(LIGHT_YELLOW);
	printf("▶ 위 정보로 입력합니다.\n");
	printf("▶ 새로 저장 할까요? [Y/N]\n");
	printf("▷ Y - 시즌 교체\n");
	printf("▷ N - 재고 채워 넣기\n");
	font_color(LIGHT_GRAY);
}

void ask_management_menu()
{
	font_color(LIGHT_YELLOW);
	printf("▷ Y - 재고를 채워 넣으시겠습니까?\n");
	printf("▷ N - 이전화면으로 빠져 나갑니다.\n");
	font_color(LIGHT_GRAY);
}