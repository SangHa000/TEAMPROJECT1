// ���� ���� ����(������)�� �ֹ��ϴ� ���α׷� (����, ����)

#include <stdio.h>
#include <Windows.h> // win32 api ��� (������ ȯ�濡���� ��� ����)
#include <conio.h>  // _getch �Լ� ��� 
#include <stdlib.h>	// exit()
#include "intro.h" 
#include "menu.h"
#include "data.h"
#include "file.h"
#include "msg.h"

void main()
{
	int num = 0;
	//�ܼ�â ũ�� ����.
	system("mode con cols=75 lines=29");
	// ��Ʈ�� 
	// ���� : ���ο� ���� ���屸�� ��(���θ� �ΰ�)
	set_cursor_type(NOCURSOR);
	//font_color(YELLOW);
	//showIntro();
	//_getch();

	//system("cls");
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);

	while (1) {
		// ���� �޴�
		num = main_menu();
		switch (num) {
		case FIRST_NUM: {  // ������ ���� ��� ������ �� �ְ�
			system("cls");
			int choiceSeasonNum = search_season_suit_menu();
			choice_suit_season(choiceSeasonNum);
			break;
		}
		case SECOND_NUM:   // ������ �޴�
			//register_manage(); // ���α׷� ������ ���� ����ϴ°� ���α׷� ������ �� �ش� �޼ҵ� �����ؾ���
			check_management();
			break;		
		case THIRD_NUM:  // ���α׷� ����
			printf("���α׷� ����!\n");
			exit(0);
		default:
			printf(WRONG_MENU);
			system("pause");
		}
		system("cls");
	}
}