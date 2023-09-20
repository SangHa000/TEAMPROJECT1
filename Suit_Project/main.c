// 성인 남성 정장(계절별)을 주문하는 프로그램 (상의, 하의)

#include <stdio.h>
#include <Windows.h> // win32 api 사용 (윈도우 환경에서만 사용 가능)
#include <conio.h>  // _getch 함수 사용 
#include <stdlib.h>	// exit()
#include "intro.h" 
#include "menu.h"
#include "data.h"
#include "file.h"
#include "msg.h"

void main()
{
	int num = 0;
	//콘솔창 크기 조절.
	system("mode con cols=75 lines=29");
	// 인트로 
	// 제목 : 성인용 남성 정장구매 숍(쇼핑몰 로고)
	set_cursor_type(NOCURSOR);
	//font_color(YELLOW);
	//showIntro();
	//_getch();

	//system("cls");
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);

	while (1) {
		// 메인 메뉴
		num = main_menu();
		switch (num) {
		case FIRST_NUM: {  // 계절별 정장 목록 선택할 수 있게
			system("cls");
			int choiceSeasonNum = search_season_suit_menu();
			choice_suit_season(choiceSeasonNum);
			break;
		}
		case SECOND_NUM:   // 관리자 메뉴
			//register_manage(); // 프로그램 관리자 새로 등록하는곳 프로그램 배포할 때 해당 메소드 제거해야함
			check_management();
			break;		
		case THIRD_NUM:  // 프로그램 종료
			printf("프로그램 종료!\n");
			exit(0);
		default:
			printf(WRONG_MENU);
			system("pause");
		}
		system("cls");
	}
}