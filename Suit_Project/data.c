#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit(), system() �޼ҵ���
#include <Windows.h> // Sleep �޼ҵ� ���
#include "menu.h"
#include "file.h"
#include "data.h"
#include "msg.h"
#include "intro.h"

#define LEN 2 // SEASON season[LEN] ����ü �迭�� �� ���� 10�� ������ save

// ���� �����Ͽ��� ��
// ������ �������� �����Ͽ��� �� �����͸� ����ϵ���  
void choice_suit_season(int choiceSeasonNum)
{
	system("cls");
	switch (choiceSeasonNum) {

	case FIRST_NUM: {
		// ���Ͽ��� �ҷ��� ������(��, ������ ����)�� �����ش�.
		printf("������ �� �ִ� (�� �� ����)�� ���� ���\n");
		get_suit_data_spring_autumn();


		// ���� ���� �����ϰ� ������ ���̸��� ���Ա��ϸ� �������ּż� �����մϴ�. 
		// �� �̸��� ���� ������ �ݾ��� ������ ���Ͽ� ����
		break;
	}
	case SECOND_NUM: {
		// ���Ͽ��� �ҷ��� ������(������ ����)�� �����ش�.
		printf("������ �� �ִ� ������ ���� ���\n");
		get_suit_data_summer();
		break;
	}
	case THIRD_NUM: {
		// ���Ͽ��� �ҷ��� ������(�ܿ�� ����)�� �����ش�. 
		printf("������ �� �ִ� �ܿ�� ���� ���");
		get_suit_data_winter();
		break;
	}
	default:
		printf(WRONG_MENU);
	}
	system("pause");
}

// ������ ���� �޴� 
// ���Խ� ���̵�, �н������ �α��� �� �� �ֵ��� �Ѵ�
void choice_management_num(int manageNum)
{
	while (1) {
		switch (manageNum) { //��, ���� ���� ��� ä���
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
			else if (input == 'N' || input == 'n')
				break;
			break;
		}
		case SECOND_NUM: { // ���� ���� ��� ä���
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
		case THIRD_NUM: { // �ܿ� ���� ��� ä���
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
		default:
			printf("�߸��� �޴� ����!!\n");
		}
		break;
	}
}

void set_suit()
{
	SEASON season[LEN] = { 0 }; // �ִ� ���� �� �ִ� ���� �����ϴ� ��
	while (1) {
		int count = 0; // ��� ��ȣ ī��Ʈ 
		int len = sizeof(season) / sizeof(SEASON); // ������ ������ ���� ������ �����ϴ��� ������

		for (int i = 0; i < len; i++) {

			printf("����ȣ %d\n", count += 1); //��� ��ȣ ī��Ʈ 1������ ����
			printf("���� : ");
			while (getchar() != '\n') {}
			scanf("%[^\n]s", season[i].customer.suit.blazer);
			printf("���� : ");
			while (getchar() != '\n') {}
			scanf("%[^\n]s", season[i].customer.suit.dressPants);
			printf("-------------------------------------------\n");

			// ������ ����
			printf("�� ���� ���� : ");
			while (getchar() != '\n') {}
			scanf("%d", &season[i].customer.suit.tag.blazerCount);
			printf("�� ���� ����(���� N����) : ");
			while (getchar() != '\n') {}
			scanf("%d", &season[i].customer.suit.tag.blazerPrice);
			printf("�� ���� ���� : ");
			while (getchar() != '\n') {}
			scanf("%d", &season[i].customer.suit.tag.dressPantsCount);
			printf("�� ���� ����(���� N����) : ");
			while (getchar() != '\n') {}
			scanf("%d", &season[i].customer.suit.tag.dressPantsPrice);
			printf("===========================================��\n");
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
			printf("�� �߸� �Է��ϼ̽��ϴ�.\n");
			break;
		}
		suit_file_write(mode, len, season);
		break;
	}
}

// ������ �޴� �������� �� ���� ó��
// ��, ���� �� ��Ʈ ��� ä�� �ִ� ��
void restock_spring_autumn_suit()
{
	printf("�� (�� �� ����)�� ������ ä�� �ֽ��ϴ�.\n");
	set_suit();		
}

// ���� �� ��Ʈ ��� ä�� �ִ� ��
void restock_summer_suit()
{
	printf("�� ������ ������ ä�� �ֽ��ϴ�.\n");
	set_suit();		
}

// �ܿ� �� ��Ʈ ��� ä�� �ִ� ��
void restock_winter_suit()
{	
	printf("�� �ܿ�� ������ ä�� �ֽ��ϴ�.\n");
	set_suit();		
}

// ������ id üũ�ϴ� ��
void check_management()
{
	int flag = 0;
	char inputId[20] = { 0 };
	char inputPass[20] = { 0 };

	for (int count = 1; count <= 5; count++) {
		printf("�� ������ �޴��� �����մϴ�.\n");
		printf("�� ID : ");
		scanf("%s", inputId);
		printf("�� PW : ");
		scanf("%s", inputPass);
		flag = idPassCompare(inputId, inputPass);
		if (flag == 1) {
			//manage_ui();
			system("cls");
			int manageNum = manager_menu();
			choice_management_num(manageNum);
			break;
		}
		else if (flag == 0) {
			font_color(RED);
			printf("�α��� ���� Ƚ�� : %d\n", count);
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