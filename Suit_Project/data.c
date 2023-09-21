#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit(), system() 메소드사용
#include <Windows.h> // Sleep 메소드 사용
#include "menu.h"
#include "file.h"
#include "data.h"
#include "msg.h"
#include "intro.h"

#define LEN 2 // SEASON season[LEN] 구조체 배열의 총 길이 2개 데이터 save

// 고객이 선택하였을 때
// 정장을 계절별로 선택하였을 때 데이터를 출력하도록  
void choice_suit_season(int choiceSeasonNum)
{
	int cNum = 0;
	system("cls");

	switch (choiceSeasonNum) {
	case FIRST_NUM: {
		cNum = 1;
		// 파일에서 불러온 데이터(봄, 가을용 정장)를 보여준다.
		printf("구매할 수 있는 (봄 · 가을)용 정장 목록\n");
		get_suit_data_spring_autumn();
		puchase_suit(cNum);

		//printf(RETURN_MAIN);
		//Sleep(1000);
		// 구매 수량 선택하고 구매한 고객이름과 돈입금하면 구매해주셔서 감사합니다. 
		// 고객 이름과 고객이 구매한 금액은 관리자 파일에 전송
		break;
	}
	case SECOND_NUM: {
		cNum = 2;
		// 파일에서 불러온 데이터(여름용 정장)를 보여준다.
		printf("구매할 수 있는 여름용 정장 목록\n");
		get_suit_data_summer();
		puchase_suit(cNum);
		//printf(RETURN_MAIN);
		//Sleep(1000);
		break;
	}
	case THIRD_NUM: {
		// 파일에서 불러온 데이터(겨울용 정장)를 보여준다. 
		cNum = 3;
		printf("구매할 수 있는 겨울용 정장 목록");
		get_suit_data_winter();
		puchase_suit(cNum);

		//printf(RETURN_MAIN);
		//Sleep(1000);
		break;
	}
	case FOURTH_NUM:
		// 파일에서 불러온 데이터(겨울용 정장)를 보여준다. 

		printf(RETURN_MAIN);

		break;
	}
	//}

	system("pause");
}

//구매하는 메소드
void puchase_suit(int cNum)
{
	//int quantity = 0;
	//char suitModel[50];
	//int moneyBalance = 0;
	//int receiveNum = 0;
	char fileName[100];
	purchase_suit_menu();

	//while (getchar() != '\n') {}
	//char input = getchar();
	//int money = 0;

	//봄, 가을
	if (cNum == 1) {



		strcpy(fileName, "spring_autumn_suit.bin");

		extradite(fileName);

		//if (input == 'S' || input == 's') {
		//	//구매 수량 입력 
		//	printf("구매 하시려는 상의 모델을 입력하여 주세요.\n");
		//	printf("상의 : ");
		//	while (getchar() != '\n') {}
		//	scanf("%[^\n]s", suitModel);

		//	while (getchar() != '\n') {}
		//	printf("수량 선택 : ");
		//	scanf("%d", &quantity);// 숫자만 선택하도록

		//	if (quantity > 0) {
		//		suit_puchse_file(quantity, suitModel, springAutumnSuitFile);

		//		while (1) {
		//			printf("금액을 입금하여 주세요.\n");
		//			while (getchar() != '\n') {}
		//			scanf("%d", &money);
		//			receiveNum = deposit_file(money, suitModel, springAutumnSuitFile);
		//			if (receiveNum == FIRST_NUM) {
		//				break;
		//			}
		//		}
		//	}
		//}
		//else if (input == 'P' || input == 'p') {
		//	printf("구매 하시려는 하의 모델을 입력하여 주세요.\n");
		//	printf("상의 : ");
		//	while (getchar() != '\n') {}
		//	scanf("%[^\n]s", suitModel);

		//	while (getchar() != '\n') {}
		//	printf("수량 선택 : ");
		//	scanf("%d", &quantity);// 숫자만 선택하도록

		//	if (quantity > 0) {
		//		suit_puchse_file(quantity, suitModel, springAutumnSuitFile);

		//		while (1) {
		//			printf("금액을 입금하여 주세요.\n");
		//			while (getchar() != '\n') {}
		//			scanf("%d", &money);
		//			receiveNum = deposit_file(money, suitModel, springAutumnSuitFile);
		//			if (receiveNum == FIRST_NUM) {
		//				break;
		//			}
		//		}
		//	}
		//}
	}
	// 여름
	else if (cNum == 2) {


	}
	// 겨울
	else if (cNum == 3) {

	}



	//else if (input == 'N' || input == 'n') {
	//	printf("이전화면으로 돌아갑니다.\n");
	//}
	//

	//else
	//	printf(WRONG_MENU);
}


void extradite(char fileName[])
{


	//char fileName[50] = { 0 };
	int quantity = 0;
	char suitModel[50];
	int moneyBalance = 0;
	int receiveNum = 0;


	while (getchar() != '\n') {}
	char input = getchar();
	int money = 0;

	if (input == 'S' || input == 's') {
		//구매 수량 입력 
		printf("구매 하시려는 상의 모델을 입력하여 주세요.\n");
		printf("상의 : ");
		while (getchar() != '\n') {}
		scanf("%[^\n]s", suitModel);

		while (getchar() != '\n') {}
		printf("수량 선택 : ");
		scanf("%d", &quantity);// 숫자만 선택하도록

		if (quantity > 0) {

			
			suit_shirts_puchse_file(quantity, suitModel, fileName);

			while (1) {
				printf("금액을 입금하여 주세요.\n");
				while (getchar() != '\n') {}
				scanf("%d", &money);
				receiveNum = deposit_file(money, suitModel, fileName);
				if (receiveNum == FIRST_NUM) {
					break;
				}
			}
		}
	}
	else if (input == 'P' || input == 'p') {
		printf("구매 하시려는 하의 모델을 입력하여 주세요.\n");
		printf("상의 : ");
		while (getchar() != '\n') {}
		scanf("%[^\n]s", suitModel);

		while (getchar() != '\n') {}
		printf("수량 선택 : ");
		scanf("%d", &quantity);// 숫자만 선택하도록

		if (quantity > 0) {
			suit_pants_puchse_file(quantity, suitModel, fileName);

			while (1) {
				printf("금액을 입금하여 주세요.\n");
				while (getchar() != '\n') {}
				scanf("%d", &money);
				receiveNum = deposit_file(money, suitModel, fileName);
				if (receiveNum == FIRST_NUM) {
					break;
				}
			}
		}
	}

	else if (input == 'N' || input == 'n') {
		printf("이전화면으로 돌아갑니다.\n");
	}


	else
		printf(WRONG_MENU);












}




















// 관리자 전용 메뉴 
// 진입시 아이디, 패스워드로 로그인 할 수 있도록 한다
void choice_management_num(int manageNum)
{
	//while (1) {
	switch (manageNum) { //봄, 가을 정장 재고 채우기
	case FIRST_NUM: {
		system("cls");
		printf(CALL_INVENTORY);
		Sleep(1000);
		get_suit_data_spring_autumn();
		ask_management_menu();
		while (getchar() != '\n') {}
		char input = getchar();
		if (input == 'Y' || input == 'y') {
			restock_spring_autumn_suit();
		}
		else if (input == 'N' || input == 'n') // 이전화면으로
			break;
		break;
	}
	case SECOND_NUM: { // 여름 정장 재고 채우기
		system("cls");
		printf(CALL_INVENTORY);
		Sleep(1000);
		get_suit_data_summer();
		ask_management_menu();
		while (getchar() != '\n') {}
		char input = getchar();
		if (input == 'Y' || input == 'y') {
			restock_summer_suit();
		}
		else if (input == 'N' || input == 'n')
			break;
		break;
	}
	case THIRD_NUM: { // 겨울 정장 재고 채우기
		system("cls");
		printf(CALL_INVENTORY);
		Sleep(1000);
		get_suit_data_winter();
		ask_management_menu();
		while (getchar() != '\n') {}
		char input = getchar();
		if (input == 'Y' || input == 'y') {
			restock_winter_suit();
		}
		else if (input == 'N' || input == 'n')
			break;
		break;
	}
	case FOURTH_NUM:
		// 파일에서 불러온 데이터(겨울용 정장)를 보여준다. 
		printf(RETURN_MAIN);
		break;
	default:
		printf("잘못된 메뉴 선택!!\n");
	}
	system("pause");
	system("cls");
}

void set_suit()
{
	SEASON season[LEN] = { 0 }; // 최대 넣을 수 있는 숫자 조절하는 곳
	while (1) {
		int count = 0; // 재고 번호 카운트 
		int len = sizeof(season) / sizeof(SEASON); // 컴파일 오류로 버퍼 오버런 빌생하는지 봐야함
		for (int i = 0; i < len; i++) {

			printf("재고번호 %d\n", count += 1); //재고 번호 카운트 1번부터 시작
			printf("상의 : ");
			while (getchar() != '\n') {}
			scanf("%[^\n]s", season[i].customer.suit.blazer);
			printf("하의 : ");
			while (getchar() != '\n') {}
			scanf("%[^\n]s", season[i].customer.suit.dressPants);
			printf("-------------------------------------------\n");

			// 수량과 가격
			printf("▷ 상의 수량 : ");
			while (getchar() != '\n') {}
			scanf("%d", &season[i].customer.suit.tag.blazerCount);
			printf("▷ 상의 가격(단위 N만원) : ");
			while (getchar() != '\n') {}
			scanf("%d", &season[i].customer.suit.tag.blazerPrice);
			printf("▷ 하의 수량 : ");
			while (getchar() != '\n') {}
			scanf("%d", &season[i].customer.suit.tag.dressPantsCount);
			printf("▷ 하의 가격(단위 N만원) : ");
			while (getchar() != '\n') {}
			scanf("%d", &season[i].customer.suit.tag.dressPantsPrice);
			printf("===========================================◆\n");
		}
		char mode = ' ';

		while (getchar() != '\n') {}
		check_Y_or_N_menu();

		char input1 = getchar();
		Sleep(1000);
		if (input1 == 'Y' || input1 == 'y') {
			mode = 'w';
		}
		else if (input1 == 'N' || input1 == 'n') {
			mode = 'a';
		}
		else {
			printf("▶ 잘못 입력하셨습니다.\n");
			break;
		}
		suit_file_write(mode, len, season);
		break;
	}
}

// 관리자 메뉴 선택했을 때 파일 처리
// 봄, 가을 용 수트 재고 채워 넣는 곳
void restock_spring_autumn_suit()
{
	printf("▶ (봄 · 가을)용 정장을 채워 넣습니다.\n");
	set_suit();
}

// 여름 용 수트 재고 채워 넣는 곳
void restock_summer_suit()
{
	printf("▶ 여름용 정장을 채워 넣습니다.\n");
	set_suit();
}

// 겨울 용 수트 재고 채워 넣는 곳
void restock_winter_suit()
{
	printf("▶ 겨울용 정장을 채워 넣습니다.\n");
	set_suit();
}

// 관리자 id 체크하는 곳
void check_management()
{
	int flag = 0;
	char inputId[20] = { 0 };
	char inputPass[20] = { 0 };

	for (int count = 1; count <= 5; count++) {
		printf("▶ 관리자 메뉴로 진입합니다.\n");
		printf("▷ ID : ");
		scanf("%s", inputId);
		printf("▷ PW : ");
		scanf("%s", inputPass);
		flag = idPassCompare(inputId, inputPass);
		if (flag == 1) {
			//manage_ui();
			system("cls");
			while (1) {
				int manageNum = manager_menu();
				choice_management_num(manageNum);			
				if (manageNum == FOURTH_NUM && flag ==1) {
					break;
				}
			}
			break;
		}
		else if (flag == 0) {
			font_color(RED);
			printf("로그인 실패 횟수 : %d\n", count);
			font_color(LIGHT_GRAY);
			system("pause");
			if (count == 5) {
				break;
			}
		}
		system("cls");
	}
	system("cls");
}