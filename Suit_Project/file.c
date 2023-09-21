#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit(), system() 메소드사용
#include <string.h> // strcpy() 문자열 비교 메소드 사용
#include <Windows.h> // Sleep 메소드 사용
#include "menu.h"
#include "suit.h"
#include "file.h"
#include "msg.h"

const char springAutumnSuitFile[] = "D:\\work_c\\Suit_Project\\spring_autumn_suit.bin";
const char summerSuitFile[] = "D:\\work_c\\Suit_Project\\summer_suit.bin";
const char winterSuitFile[] = "D:\\work_c\\Suit_Project\\winter_suit.bin";
const char managementFile[] = "D:\\work_c\\Suit_Project\\management.bin";

// 봄 가을 수트 정보 가져옴
void get_suit_data_spring_autumn()
{
	// 데이터가 없으면 "데이터가 존재하지 않습니다" 에러 메시지를 출력!
	FILE* fp = fopen(springAutumnSuitFile, "rb");  // 구조체 사용할 때는 b 옵션
	if (fp == NULL) {
		printf(FILE_READ_ERR);
		return;
	}

	SEASON season = { 0 }; // 파일안에 있는 구조체 한 덩어리	
	int count = 1;
	int check = 0;
	while (fread(&season, sizeof(season), 1, fp) == 1) {
		printf("재고 번호 %d\n", count++);
		printf("정장 상의 : %s\n", season.customer.suit.blazer);
		printf("정장 하의 : %s\n", season.customer.suit.dressPants);
		printf("구매 가능한 상의 수량 : %d개\n", season.customer.suit.tag.blazerCount);
		printf("상의 가격 %d ￦\n", season.customer.suit.tag.blazerPrice);
		printf("구매 가능한 하의 수량 : %d개\n", season.customer.suit.tag.dressPantsCount);
		printf("하의 가격 %d ￦\n", season.customer.suit.tag.dressPantsPrice);
		printf("==========================\n");
		check = 1;
	}
	fclose(fp);
	if (check == 0) {
		printf(NO_READ_DATA);
	}
}

// 여름 수트 정보 가져옴
void get_suit_data_summer()
{
	// 데이터가 없으면 "데이터가 존재하지 않습니다" 에러 메시지를 출력!
	FILE* fp = fopen(summerSuitFile, "rb");  // 구조체 사용할 때는 b 옵션
	if (fp == NULL) {
		printf(FILE_READ_ERR);
		return;
	}

	SEASON season = { 0 }; // 파일안에 있는 구조체 한 덩어리
	int count = 1;
	int check = 0;
	while (fread(&season, sizeof(season), 1, fp) == 1) {
		printf("재고 번호 %d\n", count++);
		printf("정장 상의 : %s\n", season.customer.suit.blazer);
		printf("정장 하의 : %s\n", season.customer.suit.dressPants);
		printf("구매 가능한 상의 수량 : %d개\n", season.customer.suit.tag.blazerCount);
		printf("상의 가격 %d ￦\n", season.customer.suit.tag.blazerPrice);
		printf("구매 가능한 하의 수량 : %d개\n", season.customer.suit.tag.dressPantsCount);
		printf("하의 가격 %d ￦\n", season.customer.suit.tag.dressPantsPrice);
		printf("==========================\n");
		check = 1;
	}
	fclose(fp);
	if (check == 0) {
		printf(NO_READ_DATA);
	}
}

// 겨울 수트 정보 가져옴
void get_suit_data_winter()
{
	// 데이터가 없으면 "데이터가 존재하지 않습니다" 에러 메시지를 출력!
	FILE* fp = fopen(winterSuitFile, "rb");  // 구조체 사용할 때는 b 옵션
	if (fp == NULL) {
		printf(FILE_READ_ERR);
		return;
	}
	SEASON season = { 0 }; // 파일안에 있는 구조체 한 덩어리

	int count = 1;
	int check = 0;
	while (fread(&season, sizeof(season), 1, fp) == 1) {
		printf("재고 번호 %d\n", count++);
		printf("정장 상의 : %s\n", season.customer.suit.blazer);
		printf("정장 하의 : %s\n", season.customer.suit.dressPants);
		printf("구매 가능한 상의 수량 : %d개\n", season.customer.suit.tag.blazerCount);
		printf("상의 가격 %d ￦\n", season.customer.suit.tag.blazerPrice);
		printf("구매 가능한 하의 수량 : %d개\n", season.customer.suit.tag.dressPantsCount);
		printf("하의 가격 %d ￦\n", season.customer.suit.tag.dressPantsPrice);
		printf("==========================\n");
		check = 1;
	}
	fclose(fp);
	if (check == 0) {
		printf(NO_READ_DATA);
	}
}

//상의만
// 구매 수량을 결정하면 진행되는 메소드 
// 수정 예정 (파일이름 넘겨받아서 파일 이름만 넘겨받아서)
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
			printf("현재 재고 수량이 부족합니다.");
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
		printf("모델명을 잘못 입력하였습니다.\n");
		return; // void 함수 종료
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

//하의만
// 구매 수량을 결정하면 진행되는 메소드 
// 수정 예정 (파일이름 넘겨받아서 파일 이름만 넘겨받아서)
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
			printf("현재 재고 수량이 부족합니다.");
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
		printf("모델명을 잘못 입력하였습니다.\n");
		return; // void 함수 종료
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
				printf("잔액이 부족합니다.\n");
			}
			else {
				printf("금액이 정상적으로 입금되었습니다.\n");
				printf("%d원이 반환되었습니다.\n", resiveMoney);
				printf("구매해주셔서 감사합니다.\n");
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







//관리자로 부터 파일에 재고를 채워 넣는 메소드
void suit_file_write(char mode, int len, SEASON season[])
{
	FILE* fp = NULL;

	int num = 0;
	printf("♠ 채울 시즌을 입력해주세요. ♠\n");
	printf("1.봄, 가을 정장 채우기\n");
	printf("2.여름 정장 채우기\n");
	printf("3.겨울 정장 채우기\n");

	num = input_only_num();
	printf("재고를 수정하는 중 입니다......\n");
	Sleep(2000);
	if (num == FIRST_NUM) { // 봄, 가을 정장 채우기

		if (mode == 'w') {
			fp = fopen(springAutumnSuitFile, "wb");  // 재고 새로 채우기
		}
		else if (mode == 'a') {
			fp = fopen(springAutumnSuitFile, "ab"); // 재고 추가하기
		}
		else if (fp == NULL) {
			printf("▶ 목록을 생성할수 없습니다.\n");
			return;
		}
		for (int i = 0; i < len; i++) {
			fwrite(&season[i], sizeof(SEASON), 1, fp);
		}
	}
	else if (num == SECOND_NUM) { // 여름 정장 채우기
		if (mode == 'w') {
			fp = fopen(summerSuitFile, "wb");  // 재고 새로 채우기
		}
		else if (mode == 'a') {
			fp = fopen(summerSuitFile, "ab"); // 재고 추가하기
		}
		else if (fp == NULL) {
			printf("▶ 목록을 생성할수 없습니다.\n");
			return;
		}
		for (int i = 0; i < len; i++) {
			fwrite(&season[i], sizeof(SEASON), 1, fp);
		}
	}
	else if (num == THIRD_NUM) { // 겨울 정장 채우기
		if (mode == 'w') {
			fp = fopen(winterSuitFile, "wb");  // 재고 비우기
		}
		else if (mode == 'a') {
			fp = fopen(winterSuitFile, "ab"); // 재고 추가하기
		}
		else if (fp == NULL) {
			printf("▶ 목록을 생성할수 없습니다.\n");
			return;
		}
		for (int i = 0; i < len; i++) {
			fwrite(&season[i], sizeof(SEASON), 1, fp);   // 같은 부분 중복 함수로 빼낼 수 있으면 빼내기
		}
	}
	fclose(fp);
}

// 프로그램 처음실행할 때 관리자 등록 
void register_manage()
{
	MANAGER manager = { 0 };
	printf("새로운 관리자를 등록합니다.\n");
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

// 아이디, 패스워드 맞는지 비교
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
		printf("로그인에 실패 하였습니다.\n");
		return 0; // 함수 종료
	}	
}