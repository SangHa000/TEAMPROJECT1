#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit(), system() �޼ҵ���
#include "menu.h"
#include "intro.h"

// ���� �޴�
int main_menu()
{
	int menu = 0;
	printf("��ᦳ��������������������������������������������������������������������������\n");
	printf("���                                     ��\n");
	printf("��   �� ���� ������ ���� ���� ���α׷� �� ��\n");
	printf("��                                        ��\n");
	printf("������������������������������������������������������������������������������������\n");
	printf(" 1. ������ ���� ���\n");
	printf(" 2. ������ �޴�\n");
	printf(" 3. ����\n");
	menu = input_only_num();
	return menu;
}

// ������ �޴�
int manager_menu()
{
	font_color(RED);
	printf("�ذ����� ���� �޴� �Դϴ�.��\n");
	printf("�ؽ��� ��ü�� ���� �ִ� ��� ������ ���ϴ�.��\n");
	font_color(LIGHT_GRAY);
	printf("1. �� / ���� �� ���� ��� ä���\n");
	printf("2. ���� �� ���� ��� ä���\n");
	printf("3. �ܿ� �� ���� ��� ä���\n");

	// ���߿� �޴� �߰�
	//printf("1. ������ ���� ���� ��� Ȯ��\n");
	//printf("2. �� �Ǹ� �׼� Ȯ��\n");
	//printf("3. ��� ä��� �Ǵ� ���� ��ü\n");
	int num;
	num = input_only_num();
	return num;
}

// ������ ���� �˻��ϴ� �޴�
int search_season_suit_menu()
{
	printf("��ᦳ������������������������������������������������\n");
	printf("���                        ��\n");
	printf("��  �� Season�� ���� ���� �� ��\n");
	printf("��                           ��\n");
	printf("����������������������������������������������������������\n");
	printf("1. �� / ���� �� ����\n"); // ���� ���Ƿ� �з�
	printf("2. ���� �� ����\n");
	printf("3. �ܿ� �� ����\n");
	int menu;
	menu = input_only_num();
	return menu;
}

// ���ڸ� �Է��ϰ� 
int input_only_num()
{
	// scanf scanf�Լ��� ���� ������ �Ǿտ��� ���� ������ �Ѿ
	int num = 0;
	while (1) {	
		font_color(LIGHT_RED);
		printf("�� ����(���� ����)�� �����Ͽ� �ּ���!!! ��\n");
		font_color(LIGHT_GRAY);
		printf("����(���� ����)�� �Է����ּ��� : ");
		//char input = getchar();
		//scanf("%d", &num);
		//printf(input);
		scanf("%d", &num);

		if (num > 0 && num < 6) {
			break;
		}
		else {
			while (getchar() != '\n'); // ���ڿ��� ���� �Է��ϸ� ���� �ݺ�
		}
		//system("cls");				
	}
	return num;
	//	if (input == 49 ||	input == 50 || input == 51 || input == 52 || input == 53 || input == 54) {
	//		returnNum = input - 48;
	//		break;
	//	} 
	//	else {
	//		while (getchar() != '\n'); // ���ڿ��� ���� �Է��ϸ� ���� �ݺ�
	//	}
	//	//system("cls");				
	//}
	//while (getchar() != '\n') {}
	//return returnNum;
}

void check_Y_or_N_menu()
{
	font_color(LIGHT_YELLOW);
	printf("�� �� ������ �Է��մϴ�.\n");
	printf("�� ���� ���� �ұ��? [Y/N]\n");
	printf("�� Y - ���� ��ü\n");
	printf("�� N - ��� ä�� �ֱ�\n");
	font_color(LIGHT_GRAY);
}

void ask_management_menu()
{
	font_color(LIGHT_YELLOW);
	printf("�� Y - ��� ä�� �����ðڽ��ϱ�?\n");
	printf("�� N - ����ȭ������ ���� �����ϴ�.\n");
	font_color(LIGHT_GRAY);
}