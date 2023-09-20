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