#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit(), system() �޼ҵ���
#include <Windows.h> // Sleep �޼ҵ� ���
#include "menu.h"
#include "file.h"
#include "data.h"

#define LEN 2 // SEASON season[LEN] ����ü �迭�� �� ���� 10�� ������ save

// ������ �������� �����Ͽ��� �� �����͸� ����ϵ���  
void choice_suit_season(int choiceSeasonNum)
{
	while (1) {

		switch (choiceSeasonNum) {
		case FIRST_NUM: {
			// ���Ͽ��� �ҷ��� ������(��, ������ ����)�� �����ش�. 
			//char springAutumnSuitFile[] = SPRING_AUTUMN_SUIT; 
			get_suit_data_spring_autumn();



			break;
		}
		break;


		case SECOND_NUM: {
			// ���Ͽ��� �ҷ��� ������(������ ����)�� �����ش�. 

			get_suit_data_summer();



			break;
		}
		case THIRD_NUM: {

			// ���Ͽ��� �ҷ��� ������(�ܿ�� ����)�� �����ش�. 
			//char winterSuitFile[] = WINTER_SUIT;
			get_suit_data_winter();


			break;
		}

		case FOURTH_NUM:
			// ���� �޴��� ���ư���.

			break;




		default:
			printf("�߸��� �޴� ����!!\n");
		}



		//break;
	}
}

// ������ ���� �޴� 
// ���Խ� ���̵�, �н������ �α��� �� �� �ֵ��� �Ѵ�
void choice_management_num(int manageNum)
{
	while (1) {

		switch (manageNum) { //��, ���� ���� ��� ä���
		case FIRST_NUM: {
			restock_spring_autumn_suit();
			get_suit_data_spring_autumn(); // �׽�Ʈ������ ȣ��
			system("pause");
			break;
		}

		

		case SECOND_NUM: { // ���� ���� ��� ä���
			



			break;
		}
		case THIRD_NUM: { // �ܿ� ���� ��� ä���

			


			break;
		}

		case FOURTH_NUM:
			

			break;




		default:
			printf("�߸��� �޴� ����!!\n");
		}
		break;
	}



}

// ������ �޴� �������� �� ���� ó��
// ��, ���� �� ��Ʈ ��� ä�� �ִ� ��
void restock_spring_autumn_suit()
{
	SEASON season[LEN] = { 0 }; // �ִ� ���� �� �ִ� ���� �����ϴ� ��
	while (1) {
		printf("�� ��, ���� �� ������ ä�� �ֽ��ϴ�.\n");

		int len = sizeof(season) / sizeof(SEASON); // ������ ������ ���� ������ �����ϴ��� ������
		//printf(len);

		for (int i = 0; i < len; i++) {
			printf("���� : ");
			// ���� ����ִ� ���
			while (getchar() != '\n') {}
			//rewind(stdin);
			scanf("%[^\n]s", season[i].customer.suit.blazer);

			printf("���� : ");
			while (getchar() != '\n') {}
			//rewind(stdin);
			scanf("%[^\n]s", season[i].customer.suit.dressPants);
		}
		char mode = ' ';
		// ���� ����ִ� ���
		while (getchar() != '\n') {}
		//rewind(stdin);
		printf("�� �� ������ �Է��մϴ�.\n");
		printf("�� ���� ���� �ұ��? [Y/N]\n");
		printf("�� Y - ���� �� ���� ���� ä���\n");
		printf("�� N - ��� ä�� �ֱ�\n");

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

//// ���� �� ��Ʈ ��� ä�� �ִ� ��
//void restock_summer_suit()
//{
//
//
//
//}
//
//// �ܿ� �� ��Ʈ ��� ä�� �ִ� ��
//void restock_winter_suit()
//{
//
//
//
//}





// ������ id üũ�ϴ� ��
void check_management()
{
	//system("cls");
	int flag = 0;

	while (1) {
		char inputId[20] = { 0 };
		char inputPass[20] = { 0 };

		printf("�� ������ �޴��� �����մϴ�.\n");
		printf("�� ID : ");
		scanf("%s", inputId);
		printf("�� PW : ");
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