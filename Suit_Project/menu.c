#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit(), system() �޼ҵ���
#include "menu.h"

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
	printf("�ذ����� ���� �޴� �Դϴ�.��\n");
	printf("�ؽ��� ��ü�� ���� �ִ� ��� ������ ���ϴ�.��\n");
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
	printf("4. ���� �޴� ���ư���\n");
	int menu;
	menu = input_only_num();
	return menu;
}

// ���ڸ� �Է��ϰ� 
int input_only_num()
{
	int num = 0;
	while (1) {
		printf("�� ����(���� ����)�� �����Ͽ� �ּ���!!! ��\n");
		printf("����(���� ����)�� �Է����ּ��� : ");
		scanf("%d", &num);
 
		if (num > 0) {
			break;
		} else {
			while (getchar() != '\n'); // ���ڿ��� ���� �Է��ϸ� ���� �ݺ�
		}
		//system("cls");				
	}
	return num;
}