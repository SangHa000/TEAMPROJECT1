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