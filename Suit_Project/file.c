#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit(), system() 메소드사용
#include <string.h> // strcpy() 문자열 비교 메소드 사용
#include <Windows.h> // Sleep 메소드 사용
#include "menu.h"
#include "suit.h"
#include "file.h"


// 계절을 선택하고 상의를 구매할 지 하의를 구매할 지 
// 선택하면 텍스파일에서 목록을 가져옴
// 사용자가 메인메뉴로 돌아가기 선택을 할 수도 있음
const char springAutumnSuitFile[] = "spring_autumn_suit.bin";
const char summerSuitFile[] = "summer_suit";
const char winterSuitFile[] = "winter_suit";


// 봄 가을 수트 정보 가져옴
void get_suit_data_spring_autumn()
{
	//// 데이터가 없으면 "데이터가 존재하지 않습니다" 에러 메시지를 출력!
	//FILE* fp = fopen(springAutumnSuitFile, "rb");  // 구조체 사용할 때는 b 옵션
	//if (fp == NULL) {
	//	printf(FILE_READ_ERR);
	//	exit(0);
	//}
	//SEASON season = { 0 }; // 파일안에 있는 구조체 한 덩어리
	////int count = 1;
	//int check = 0;
	//while (fread(&season, sizeof(season), 1, fp) == 1) {
	//	printf("정장 상의 : %s\n", season.suit.blazer);
	//	printf("정장 하의 : %s\n", season.suit.dress_pants);
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

// 관리자 메뉴 선택했을 때 파일 처리
// 봄, 가을 용 수트 재고 채워 넣는 곳
void restock_spring_autumn_suit(char winterSuitFile[])
{
	SUIT suit_[10] = { 0 }; // 최대 넣을 수 있는 숫자 조절하는 곳
	while (1) {
		printf("▶ 봄, 가을 용 정장을 채워 넣습니다.\n");
		
		
		int len = sizeof(suit_) / sizeof(SUIT); // 컴파일 오류로 버퍼 오버런 빌생하는지 봐야함
		//printf(len);

		for (int i = 0; i < len; i++) {
			printf("상의 : ");
			getchar();
			gets_s(suit_[i].blazer, len);

			printf("하의 : ");
			getchar();
			gets_s(suit_[i].dress_pants, len);
		}
		char mode = ' ';
		//rewind(stdin);
		printf("▶ 위 정보로 입력합니다.\n");
		printf("▶ 새로 저장 할까요? [Y/N]\n");
		printf("▷ Y - 새로 저장\n");
		printf("▷ N - 기존 파일에 추가\n");

		char input1 = getchar();
		Sleep(1000);

		if (input1 == 'Y' || input1 == 'y') {
			mode = 'w';  
		}
		else if (input1 == 'N' || input1 == 'n') {
			mode = 'a';
		}
		else {
			printf("▶ 잘못 입력하셨습니다.\n");
			break;
		}
		suit_file_write(mode, len, suit_);
		break;
	}
}

//// 여름 용 수트 재고 채워 넣는 곳
//void restock_summer_suit()
//{
//
//
//
//}
//
//// 겨울 용 수트 재고 채워 넣는 곳
//void restock_winter_suit()
//{
//
//
//
//}

//관리자로 부터 파일에 재고를 채워 넣는 메소드
void suit_file_write(char mode, int len, SUIT suit_[])
{
	
	FILE* fp = NULL;

	int num = 0;
	printf("1.봄, 가을 정장 채우기\n");
	printf("2.여름 정장 채우기\n");
	printf("3.겨울 정장 채우기\n");
	//scanf("%d", &inputNum);
	num = input_only_num();

	if (num == FIRST_NUM) { // 봄, 가을 정장 채우기

		if (mode == 'w') {
			fp = fopen(springAutumnSuitFile, "wb");  // 재고 비우기
		}
		else if (mode == 'a') {
			fp = fopen(springAutumnSuitFile, "ab"); // 재고 추가하기
		}
		else if (fp == NULL) {
			printf("▶ 목록을 생성할수 없습니다.\n");
			return;
		}
		for (int i = 0; i < len; i++) {
			fwrite(&suit_[i], sizeof(SUIT), 1, fp);
		}
		
	}

	else if (num == SECOND_NUM) { // 여름 정장 채우기
		if (mode == 'w') {
			fp = fopen(springAutumnSuitFile, "wb");  // 재고 비우기
		}
		else if (mode == 'a') {
			fp = fopen(springAutumnSuitFile, "ab"); // 재고 추가하기
		}
		else if (fp == NULL) {
			printf("▶ 목록을 생성할수 없습니다.\n");
			return;
		}
		for (int i = 0; i < len; i++) {
			fwrite(&suit_[i], sizeof(SUIT), 1, fp);
		}
		
	}
	else if (num == THIRD_NUM) { // 겨울 정장 채우기
		if (mode == 'w') {
			fp = fopen(springAutumnSuitFile, "wb");  // 재고 비우기
		}
		else if (mode == 'a') {
			fp = fopen(springAutumnSuitFile, "ab"); // 재고 추가하기
		}
		else if (fp == NULL) {
			printf("▶ 목록을 생성할수 없습니다.\n");
			return;
		}
		for (int i = 0; i < len; i++) {
			fwrite(&suit_[i], sizeof(SUIT), 1, fp);   // 같은 부분 중복 함수로 빼낼 수 있으면 빼내기
		}
		
	}
	fclose(fp);

	
}