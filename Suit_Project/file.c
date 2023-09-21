#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit(), system() �޼ҵ���
#include <string.h> // strcpy() ���ڿ� �� �޼ҵ� ���
#include <Windows.h> // Sleep �޼ҵ� ���
#include "menu.h"
#include "suit.h"
#include "file.h"
#include "msg.h"

const char springAutumnSuitFile[] = "D:\\work_c\\Suit_Project\\spring_autumn_suit.bin";
const char summerSuitFile[] = "D:\\work_c\\Suit_Project\\summer_suit.bin";
const char winterSuitFile[] = "D:\\work_c\\Suit_Project\\winter_suit.bin";
const char managementFile[] = "D:\\work_c\\Suit_Project\\management.bin";

// �� ���� ��Ʈ ���� ������
void get_suit_data_spring_autumn()
{
	// �����Ͱ� ������ "�����Ͱ� �������� �ʽ��ϴ�" ���� �޽����� ���!
	FILE* fp = fopen(springAutumnSuitFile, "rb");  // ����ü ����� ���� b �ɼ�
	if (fp == NULL) {
		printf(FILE_READ_ERR);
		return;
	}

	SEASON season = { 0 }; // ���Ͼȿ� �ִ� ����ü �� ���	
	int count = 1;
	int check = 0;
	while (fread(&season, sizeof(season), 1, fp) == 1) {
		printf("��� ��ȣ %d\n", count++);
		printf("���� ���� : %s\n", season.customer.suit.blazer);
		printf("���� ���� : %s\n", season.customer.suit.dressPants);
		printf("���� ������ ���� ���� : %d��\n", season.customer.suit.tag.blazerCount);
		printf("���� ���� %d ��\n", season.customer.suit.tag.blazerPrice);
		printf("���� ������ ���� ���� : %d��\n", season.customer.suit.tag.dressPantsCount);
		printf("���� ���� %d ��\n", season.customer.suit.tag.dressPantsPrice);
		printf("==========================\n");
		check = 1;
	}
	fclose(fp);
	if (check == 0) {
		printf(NO_READ_DATA);
	}
}

// ���� ��Ʈ ���� ������
void get_suit_data_summer()
{
	// �����Ͱ� ������ "�����Ͱ� �������� �ʽ��ϴ�" ���� �޽����� ���!
	FILE* fp = fopen(summerSuitFile, "rb");  // ����ü ����� ���� b �ɼ�
	if (fp == NULL) {
		printf(FILE_READ_ERR);
		return;
	}

	SEASON season = { 0 }; // ���Ͼȿ� �ִ� ����ü �� ���
	int count = 1;
	int check = 0;
	while (fread(&season, sizeof(season), 1, fp) == 1) {
		printf("��� ��ȣ %d\n", count++);
		printf("���� ���� : %s\n", season.customer.suit.blazer);
		printf("���� ���� : %s\n", season.customer.suit.dressPants);
		printf("���� ������ ���� ���� : %d��\n", season.customer.suit.tag.blazerCount);
		printf("���� ���� %d ��\n", season.customer.suit.tag.blazerPrice);
		printf("���� ������ ���� ���� : %d��\n", season.customer.suit.tag.dressPantsCount);
		printf("���� ���� %d ��\n", season.customer.suit.tag.dressPantsPrice);
		printf("==========================\n");
		check = 1;
	}
	fclose(fp);
	if (check == 0) {
		printf(NO_READ_DATA);
	}
}

// �ܿ� ��Ʈ ���� ������
void get_suit_data_winter()
{
	// �����Ͱ� ������ "�����Ͱ� �������� �ʽ��ϴ�" ���� �޽����� ���!
	FILE* fp = fopen(winterSuitFile, "rb");  // ����ü ����� ���� b �ɼ�
	if (fp == NULL) {
		printf(FILE_READ_ERR);
		return;
	}
	SEASON season = { 0 }; // ���Ͼȿ� �ִ� ����ü �� ���

	int count = 1;
	int check = 0;
	while (fread(&season, sizeof(season), 1, fp) == 1) {
		printf("��� ��ȣ %d\n", count++);
		printf("���� ���� : %s\n", season.customer.suit.blazer);
		printf("���� ���� : %s\n", season.customer.suit.dressPants);
		printf("���� ������ ���� ���� : %d��\n", season.customer.suit.tag.blazerCount);
		printf("���� ���� %d ��\n", season.customer.suit.tag.blazerPrice);
		printf("���� ������ ���� ���� : %d��\n", season.customer.suit.tag.dressPantsCount);
		printf("���� ���� %d ��\n", season.customer.suit.tag.dressPantsPrice);
		printf("==========================\n");
		check = 1;
	}
	fclose(fp);
	if (check == 0) {
		printf(NO_READ_DATA);
	}
}

//���Ǹ�
// ���� ������ �����ϸ� ����Ǵ� �޼ҵ� 
// ���� ���� (�����̸� �Ѱܹ޾Ƽ� ���� �̸��� �Ѱܹ޾Ƽ�)
void suit_shirts_puchse_file(int quantity, char suitModel[], char fileName[])
{
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL) {
		printf(FILE_READ_ERR);
		return;
	}
	SEASON season = { 0 };
	SEASON custData[100] = { 0 };
	int check = 0;
	int i = 0;

	while (fread(&season, sizeof(season), 1, fp) == 1) {
		if (quantity > season.customer.suit.tag.blazerCount || season.customer.suit.tag.blazerCount == 0) {
			printf("���� ��� ������ �����մϴ�.");
			check = 1;
		}
		else if (strcmp(season.customer.suit.blazer, suitModel) == 0) {
			custData[i].customer.suit.tag.blazerCount = season.customer.suit.tag.blazerCount -= quantity;
			if (custData[i].customer.suit.tag.blazerCount > 0) {
				check = 1;
			}		
		}
		else {
			custData[i].customer.suit.tag.blazerCount = season.customer.suit.tag.blazerCount;
		}
		strcpy(custData[i].customer.suit.blazer, season.customer.suit.blazer);
		strcpy(custData[i].customer.suit.dressPants, season.customer.suit.dressPants);
		custData[i].customer.suit.tag.blazerCount = season.customer.suit.tag.blazerCount;
		custData[i].customer.suit.tag.blazerPrice = season.customer.suit.tag.blazerPrice;
		custData[i].customer.suit.tag.dressPantsCount = season.customer.suit.tag.dressPantsCount;
		custData[i].customer.suit.tag.dressPantsPrice = season.customer.suit.tag.dressPantsPrice;
		i++;	
	}
	fclose(fp);

	int size = i;
	if (check == 0) {
		printf("�𵨸��� �߸� �Է��Ͽ����ϴ�.\n");
		return; // void �Լ� ����
	}

	FILE* fp2 = fopen(fileName, "wb");
	if (fp2 == NULL) {
		printf(FILE_READ_ERR);
		return;
	}
	for (int i = 0; i < size; i++) {
		//printf("del_arr[%d]:%d\n", i, del_arr[i].id);
		fwrite(&custData[i], sizeof(SEASON), 1, fp2);
	}
	fclose(fp2);
}

//���Ǹ�
// ���� ������ �����ϸ� ����Ǵ� �޼ҵ� 
// ���� ���� (�����̸� �Ѱܹ޾Ƽ� ���� �̸��� �Ѱܹ޾Ƽ�)
void suit_pants_puchse_file(int quantity, char suitModel[], char fileName[])
{
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL) {
		printf(FILE_READ_ERR);
		return;
	}
	SEASON season = { 0 };
	SEASON custData[100] = { 0 };
	int check = 0;
	int i = 0;

	while (fread(&season, sizeof(season), 1, fp) == 1) {
		if (quantity > season.customer.suit.tag.dressPantsCount || season.customer.suit.tag.dressPantsCount == 0) {
			printf("���� ��� ������ �����մϴ�.");
			check = 1;
		}
		else if (strcmp(season.customer.suit.dressPants, suitModel) == 0) {
			custData[i].customer.suit.tag.dressPantsCount = season.customer.suit.tag.dressPantsCount -= quantity;
			if (custData[i].customer.suit.tag.dressPantsCount > 0) {
				check = 1;
			}
		}
		else {
			custData[i].customer.suit.tag.dressPantsCount = season.customer.suit.tag.dressPantsCount;
		}
		strcpy(custData[i].customer.suit.blazer, season.customer.suit.blazer);
		strcpy(custData[i].customer.suit.dressPants, season.customer.suit.dressPants);
		custData[i].customer.suit.tag.blazerCount = season.customer.suit.tag.blazerCount;
		custData[i].customer.suit.tag.blazerPrice = season.customer.suit.tag.blazerPrice;
		custData[i].customer.suit.tag.dressPantsCount = season.customer.suit.tag.dressPantsCount;
		custData[i].customer.suit.tag.dressPantsPrice = season.customer.suit.tag.dressPantsPrice;
		i++;
	}
	fclose(fp);

	int size = i;
	if (check == 0) {
		printf("�𵨸��� �߸� �Է��Ͽ����ϴ�.\n");
		return; // void �Լ� ����
	}

	FILE* fp2 = fopen(fileName, "wb");
	if (fp2 == NULL) {
		printf(FILE_READ_ERR);
		return;
	}
	for (int i = 0; i < size; i++) {
		//printf("del_arr[%d]:%d\n", i, del_arr[i].id);
		fwrite(&custData[i], sizeof(SEASON), 1, fp2);
	}
	fclose(fp2);
}


int deposit_file(int money, char suitModel[], char fileName[])
{
	int resiveMoney = 0;
	//int* pResiveMoney = NULL;
	int check = 0;

	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL) {
		printf(FILE_READ_ERR);
		return;
	}
	SEASON season = { 0 };
	while (fread(&season, sizeof(season), 1, fp) == 1) {

		if (strcmp(season.customer.suit.blazer, suitModel) == 0) {
			resiveMoney = money - season.customer.suit.tag.blazerPrice;

			if (resiveMoney < 0) {
				printf("�ܾ��� �����մϴ�.\n");
			}
			else {
				printf("�ݾ��� ���������� �ԱݵǾ����ϴ�.\n");
				printf("%d���� ��ȯ�Ǿ����ϴ�.\n", resiveMoney);
				printf("�������ּż� �����մϴ�.\n");
				check = FIRST_NUM;
			}
		}

	}
	//if (check != FIRST_NUM) {
	//	
	//}


	return check;
	fclose(fp);
}







//�����ڷ� ���� ���Ͽ� ��� ä�� �ִ� �޼ҵ�
void suit_file_write(char mode, int len, SEASON season[])
{
	FILE* fp = NULL;

	int num = 0;
	printf("�� ä�� ������ �Է����ּ���. ��\n");
	printf("1.��, ���� ���� ä���\n");
	printf("2.���� ���� ä���\n");
	printf("3.�ܿ� ���� ä���\n");

	num = input_only_num();
	printf("��� �����ϴ� �� �Դϴ�......\n");
	Sleep(2000);
	if (num == FIRST_NUM) { // ��, ���� ���� ä���

		if (mode == 'w') {
			fp = fopen(springAutumnSuitFile, "wb");  // ��� ���� ä���
		}
		else if (mode == 'a') {
			fp = fopen(springAutumnSuitFile, "ab"); // ��� �߰��ϱ�
		}
		else if (fp == NULL) {
			printf("�� ����� �����Ҽ� �����ϴ�.\n");
			return;
		}
		for (int i = 0; i < len; i++) {
			fwrite(&season[i], sizeof(SEASON), 1, fp);
		}
	}
	else if (num == SECOND_NUM) { // ���� ���� ä���
		if (mode == 'w') {
			fp = fopen(summerSuitFile, "wb");  // ��� ���� ä���
		}
		else if (mode == 'a') {
			fp = fopen(summerSuitFile, "ab"); // ��� �߰��ϱ�
		}
		else if (fp == NULL) {
			printf("�� ����� �����Ҽ� �����ϴ�.\n");
			return;
		}
		for (int i = 0; i < len; i++) {
			fwrite(&season[i], sizeof(SEASON), 1, fp);
		}
	}
	else if (num == THIRD_NUM) { // �ܿ� ���� ä���
		if (mode == 'w') {
			fp = fopen(winterSuitFile, "wb");  // ��� ����
		}
		else if (mode == 'a') {
			fp = fopen(winterSuitFile, "ab"); // ��� �߰��ϱ�
		}
		else if (fp == NULL) {
			printf("�� ����� �����Ҽ� �����ϴ�.\n");
			return;
		}
		for (int i = 0; i < len; i++) {
			fwrite(&season[i], sizeof(SEASON), 1, fp);   // ���� �κ� �ߺ� �Լ��� ���� �� ������ ������
		}
	}
	fclose(fp);
}

// ���α׷� ó�������� �� ������ ��� 
void register_manage()
{
	MANAGER manager = { 0 };
	printf("���ο� �����ڸ� ����մϴ�.\n");
	printf("ID : ");
	scanf("%s", manager.id);
	printf("PW : ");
	scanf("%s", manager.passward);

	FILE* fp = fopen(managementFile, "wb");
	if (fp == NULL) {
		printf(FILE_READ_ERR);
		return;
	}
	fwrite(&manager, sizeof(MANAGER), 1, fp);
	fclose(fp);
}

// ���̵�, �н����� �´��� ��
int idPassCompare(char inputId[], char inputPass[])
{
	FILE* fp = fopen(managementFile, "rb");
	if (fp == NULL) {
		printf(FILE_READ_ERR);
		return;
	}

	MANAGER manager = { 0 };
	int check = 0;
	while (fread(&manager, sizeof(manager), 1, fp) == 1) {
		if ( strcmp(manager.id, inputId) == 0 && strcmp(manager.passward, inputPass) == 0 ){ 
			check = 1;
			return 1;
		}
	}
	fclose(fp);
	
	if (check == 0 || strcmp(manager.id, inputId) != 0 || strcmp(manager.passward, inputPass) != 0 ) {
		printf("�α��ο� ���� �Ͽ����ϴ�.\n");
		return 0; // �Լ� ����
	}	
}