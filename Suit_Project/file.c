#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit(), system() �޼ҵ���
#include <string.h> // strcpy() ���ڿ� �� �޼ҵ� ���
#include <Windows.h> // Sleep �޼ҵ� ���
#include "menu.h"
#include "suit.h"
#include "file.h"


// ������ �����ϰ� ���Ǹ� ������ �� ���Ǹ� ������ �� 
// �����ϸ� �ؽ����Ͽ��� ����� ������
// ����ڰ� ���θ޴��� ���ư��� ������ �� ���� ����
const char springAutumnSuitFile[] = "spring_autumn_suit.bin";
const char summerSuitFile[] = "summer_suit";
const char winterSuitFile[] = "winter_suit";


// �� ���� ��Ʈ ���� ������
void get_suit_data_spring_autumn()
{
	//// �����Ͱ� ������ "�����Ͱ� �������� �ʽ��ϴ�" ���� �޽����� ���!
	//FILE* fp = fopen(springAutumnSuitFile, "rb");  // ����ü ����� ���� b �ɼ�
	//if (fp == NULL) {
	//	printf(FILE_READ_ERR);
	//	exit(0);
	//}
	//SEASON season = { 0 }; // ���Ͼȿ� �ִ� ����ü �� ���
	////int count = 1;
	//int check = 0;
	//while (fread(&season, sizeof(season), 1, fp) == 1) {
	//	printf("���� ���� : %s\n", season.suit.blazer);
	//	printf("���� ���� : %s\n", season.suit.dress_pants);
	//	printf("==========================\n");
	//	check = 1;
	//}
	//fclose(fp);
	//if (check == 0) {
	//	printf(NO_READ_DATA);
	//}
}

void get_suit_data_summer()
{



}

void get_suit_data_winter()
{



}

// ������ �޴� �������� �� ���� ó��
// ��, ���� �� ��Ʈ ��� ä�� �ִ� ��
void restock_spring_autumn_suit(char winterSuitFile[])
{
	SUIT suit_[10] = { 0 }; // �ִ� ���� �� �ִ� ���� �����ϴ� ��
	while (1) {
		printf("�� ��, ���� �� ������ ä�� �ֽ��ϴ�.\n");
		
		
		int len = sizeof(suit_) / sizeof(SUIT); // ������ ������ ���� ������ �����ϴ��� ������
		//printf(len);

		for (int i = 0; i < len; i++) {
			printf("���� : ");
			getchar();
			gets_s(suit_[i].blazer, len);

			printf("���� : ");
			getchar();
			gets_s(suit_[i].dress_pants, len);
		}
		char mode = ' ';
		//rewind(stdin);
		printf("�� �� ������ �Է��մϴ�.\n");
		printf("�� ���� ���� �ұ��? [Y/N]\n");
		printf("�� Y - ���� ����\n");
		printf("�� N - ���� ���Ͽ� �߰�\n");

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
		suit_file_write(mode, len, suit_);
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

//�����ڷ� ���� ���Ͽ� ��� ä�� �ִ� �޼ҵ�
void suit_file_write(char mode, int len, SUIT suit_[])
{
	
	FILE* fp = NULL;

	int num = 0;
	printf("1.��, ���� ���� ä���\n");
	printf("2.���� ���� ä���\n");
	printf("3.�ܿ� ���� ä���\n");
	//scanf("%d", &inputNum);
	num = input_only_num();

	if (num == FIRST_NUM) { // ��, ���� ���� ä���

		if (mode == 'w') {
			fp = fopen(springAutumnSuitFile, "wb");  // ��� ����
		}
		else if (mode == 'a') {
			fp = fopen(springAutumnSuitFile, "ab"); // ��� �߰��ϱ�
		}
		else if (fp == NULL) {
			printf("�� ����� �����Ҽ� �����ϴ�.\n");
			return;
		}
		for (int i = 0; i < len; i++) {
			fwrite(&suit_[i], sizeof(SUIT), 1, fp);
		}
		
	}

	else if (num == SECOND_NUM) { // ���� ���� ä���
		if (mode == 'w') {
			fp = fopen(springAutumnSuitFile, "wb");  // ��� ����
		}
		else if (mode == 'a') {
			fp = fopen(springAutumnSuitFile, "ab"); // ��� �߰��ϱ�
		}
		else if (fp == NULL) {
			printf("�� ����� �����Ҽ� �����ϴ�.\n");
			return;
		}
		for (int i = 0; i < len; i++) {
			fwrite(&suit_[i], sizeof(SUIT), 1, fp);
		}
		
	}
	else if (num == THIRD_NUM) { // �ܿ� ���� ä���
		if (mode == 'w') {
			fp = fopen(springAutumnSuitFile, "wb");  // ��� ����
		}
		else if (mode == 'a') {
			fp = fopen(springAutumnSuitFile, "ab"); // ��� �߰��ϱ�
		}
		else if (fp == NULL) {
			printf("�� ����� �����Ҽ� �����ϴ�.\n");
			return;
		}
		for (int i = 0; i < len; i++) {
			fwrite(&suit_[i], sizeof(SUIT), 1, fp);   // ���� �κ� �ߺ� �Լ��� ���� �� ������ ������
		}
		
	}
	fclose(fp);

	
}