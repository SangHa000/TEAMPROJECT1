#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit(), system() �޼ҵ���
#include <Windows.h> // Sleep �޼ҵ� ���
#include "menu.h"
#include "file.h"
#include "data.h"
#include "msg.h"
#include "intro.h"

#define LEN 2 // SEASON season[LEN] ����ü �迭�� �� ���� 2�� ������ save

// ���� �����Ͽ��� ��
// ������ �������� �����Ͽ��� �� �����͸� ����ϵ���  
void choice_suit_season(int choiceSeasonNum)
{
	int cNum = 0;
	system("cls");

	switch (choiceSeasonNum) {
	case FIRST_NUM: {
		cNum = 1;
		// ���Ͽ��� �ҷ��� ������(��, ������ ����)�� �����ش�.
		printf("������ �� �ִ� (�� �� ����)�� ���� ���\n");
		get_suit_data_spring_autumn();
		puchase_suit(cNum);

		//printf(RETURN_MAIN);
		//Sleep(1000);
		// ���� ���� �����ϰ� ������ ���̸��� ���Ա��ϸ� �������ּż� �����մϴ�. 
		// �� �̸��� ���� ������ �ݾ��� ������ ���Ͽ� ����
		break;
	}
	case SECOND_NUM: {
		cNum = 2;
		// ���Ͽ��� �ҷ��� ������(������ ����)�� �����ش�.
		printf("������ �� �ִ� ������ ���� ���\n");
		get_suit_data_summer();
		puchase_suit(cNum);
		//printf(RETURN_MAIN);
		//Sleep(1000);
		break;
	}
	case THIRD_NUM: {
		// ���Ͽ��� �ҷ��� ������(�ܿ�� ����)�� �����ش�. 
		cNum = 3;
		printf("������ �� �ִ� �ܿ�� ���� ���");
		get_suit_data_winter();
		puchase_suit(cNum);

		//printf(RETURN_MAIN);
		//Sleep(1000);
		break;
	}
	case FOURTH_NUM:
		// ���Ͽ��� �ҷ��� ������(�ܿ�� ����)�� �����ش�. 

		printf(RETURN_MAIN);

		break;
	}
	//}

	system("pause");
}

//�����ϴ� �޼ҵ�
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

	//��, ����
	if (cNum == 1) {



		strcpy(fileName, "spring_autumn_suit.bin");

		extradite(fileName);

		//if (input == 'S' || input == 's') {
		//	//���� ���� �Է� 
		//	printf("���� �Ͻ÷��� ���� ���� �Է��Ͽ� �ּ���.\n");
		//	printf("���� : ");
		//	while (getchar() != '\n') {}
		//	scanf("%[^\n]s", suitModel);

		//	while (getchar() != '\n') {}
		//	printf("���� ���� : ");
		//	scanf("%d", &quantity);// ���ڸ� �����ϵ���

		//	if (quantity > 0) {
		//		suit_puchse_file(quantity, suitModel, springAutumnSuitFile);

		//		while (1) {
		//			printf("�ݾ��� �Ա��Ͽ� �ּ���.\n");
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
		//	printf("���� �Ͻ÷��� ���� ���� �Է��Ͽ� �ּ���.\n");
		//	printf("���� : ");
		//	while (getchar() != '\n') {}
		//	scanf("%[^\n]s", suitModel);

		//	while (getchar() != '\n') {}
		//	printf("���� ���� : ");
		//	scanf("%d", &quantity);// ���ڸ� �����ϵ���

		//	if (quantity > 0) {
		//		suit_puchse_file(quantity, suitModel, springAutumnSuitFile);

		//		while (1) {
		//			printf("�ݾ��� �Ա��Ͽ� �ּ���.\n");
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
	// ����
	else if (cNum == 2) {


	}
	// �ܿ�
	else if (cNum == 3) {

	}



	//else if (input == 'N' || input == 'n') {
	//	printf("����ȭ������ ���ư��ϴ�.\n");
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
		//���� ���� �Է� 
		printf("���� �Ͻ÷��� ���� ���� �Է��Ͽ� �ּ���.\n");
		printf("���� : ");
		while (getchar() != '\n') {}
		scanf("%[^\n]s", suitModel);

		while (getchar() != '\n') {}
		printf("���� ���� : ");
		scanf("%d", &quantity);// ���ڸ� �����ϵ���

		if (quantity > 0) {

			
			suit_shirts_puchse_file(quantity, suitModel, fileName);

			while (1) {
				printf("�ݾ��� �Ա��Ͽ� �ּ���.\n");
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
		printf("���� �Ͻ÷��� ���� ���� �Է��Ͽ� �ּ���.\n");
		printf("���� : ");
		while (getchar() != '\n') {}
		scanf("%[^\n]s", suitModel);

		while (getchar() != '\n') {}
		printf("���� ���� : ");
		scanf("%d", &quantity);// ���ڸ� �����ϵ���

		if (quantity > 0) {
			suit_pants_puchse_file(quantity, suitModel, fileName);

			while (1) {
				printf("�ݾ��� �Ա��Ͽ� �ּ���.\n");
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
		printf("����ȭ������ ���ư��ϴ�.\n");
	}


	else
		printf(WRONG_MENU);












}




















// ������ ���� �޴� 
// ���Խ� ���̵�, �н������ �α��� �� �� �ֵ��� �Ѵ�
void choice_management_num(int manageNum)
{
	//while (1) {
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
		else if (input == 'N' || input == 'n') // ����ȭ������
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
	case FOURTH_NUM:
		// ���Ͽ��� �ҷ��� ������(�ܿ�� ����)�� �����ش�. 
		printf(RETURN_MAIN);
		break;
	default:
		printf("�߸��� �޴� ����!!\n");
	}
	system("pause");
	system("cls");
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