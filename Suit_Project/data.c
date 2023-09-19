#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit(), system() 메소드사용
#include <Windows.h> // Sleep 메소드 사용
#include "menu.h"
#include "file.h"
#include "data.h"

#define LEN 2 // SEASON season[LEN] 구조체 배열의 총 길이 10개 데이터 save

// 정장을 계절별로 선택하였을 때 데이터를 출력하도록  
void choice_suit_season(int choiceSeasonNum)
{
	while (1) {

		switch (choiceSeasonNum) {
		case FIRST_NUM: {
			// 파일에서 불러온 데이터(봄, 가을용 정장)를 보여준다. 
			//char springAutumnSuitFile[] = SPRING_AUTUMN_SUIT; 
			get_suit_data_spring_autumn();



			break;
		}
		break;


		case SECOND_NUM: {
			// 파일에서 불러온 데이터(여름용 정장)를 보여준다. 

			get_suit_data_summer();



			break;
		}
		case THIRD_NUM: {

			// 파일에서 불러온 데이터(겨울용 정장)를 보여준다. 
			//char winterSuitFile[] = WINTER_SUIT;
			get_suit_data_winter();


			break;
		}

		case FOURTH_NUM:
			// 메인 메뉴로 돌아간다.

			break;




		default:
			printf("잘못된 메뉴 선택!!\n");
		}



		//break;
	}
}

// 관리자 전용 메뉴 
// 진입시 아이디, 패스워드로 로그인 할 수 있도록 한다
void choice_management_num(int manageNum)
{
	while (1) {

		switch (manageNum) { //봄, 가을 정장 재고 채우기
		case FIRST_NUM: {
			restock_spring_autumn_suit();
			get_suit_data_spring_autumn(); // 테스트용으로 호출
			system("pause");
			break;
		}

		

		case SECOND_NUM: { // 여름 정장 재고 채우기
			



			break;
		}
		case THIRD_NUM: { // 겨울 정장 재고 채우기

			


			break;
		}

		case FOURTH_NUM:
			

			break;




		default:
			printf("잘못된 메뉴 선택!!\n");
		}
		break;
	}



}

// 관리자 메뉴 선택했을 때 파일 처리
// 봄, 가을 용 수트 재고 채워 넣는 곳
void restock_spring_autumn_suit()
{
	SEASON season[LEN] = { 0 }; // 최대 넣을 수 있는 숫자 조절하는 곳
	while (1) {
		printf("▶ 봄, 가을 용 정장을 채워 넣습니다.\n");

		int len = sizeof(season) / sizeof(SEASON); // 컴파일 오류로 버퍼 오버런 빌생하는지 봐야함
		//printf(len);

		for (int i = 0; i < len; i++) {
			printf("상의 : ");
			// 버퍼 비워주는 방법
			while (getchar() != '\n') {}
			//rewind(stdin);
			scanf("%[^\n]s", season[i].customer.suit.blazer);

			printf("하의 : ");
			while (getchar() != '\n') {}
			//rewind(stdin);
			scanf("%[^\n]s", season[i].customer.suit.dressPants);
		}
		char mode = ' ';
		// 버퍼 비워주는 방법
		while (getchar() != '\n') {}
		//rewind(stdin);
		printf("▶ 위 정보로 입력합니다.\n");
		printf("▶ 새로 저장 할까요? [Y/N]\n");
		printf("▷ Y - 현재 모델 비우고 새로 채우기\n");
		printf("▷ N - 재고 채워 넣기\n");

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

//// 여름 용 수트 재고 채워 넣는 곳
//void restock_summer_suit()
//{
//
//
//
//}
//
//// 겨울 용 수트 재고 채워 넣는 곳
//void restock_winter_suit()
//{
//
//
//
//}





// 관리자 id 체크하는 곳
void check_management()
{
	//system("cls");
	int flag = 0;

	while (1) {
		char inputId[20] = { 0 };
		char inputPass[20] = { 0 };

		printf("▶ 관리자 메뉴로 진입합니다.\n");
		printf("▷ ID : ");
		scanf("%s", inputId);
		printf("▷ PW : ");
		scanf("%s", inputPass);

		flag = idPassCompare(inputId, inputPass);
		if (flag == 1) {
			//manage_ui();
			int manageNum = manager_menu();
			choice_management_num(manageNum);
			break;
		}
		else if (flag == 0) {
			system("pause");
			break;
		}
	}
	//Sleep(2000);
}