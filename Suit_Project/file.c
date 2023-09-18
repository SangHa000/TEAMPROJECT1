#include <stdio.h>
#include <string.h> // strcpy() 문자열 비교 함수 사용
#include "file.h"
#include "suit.h"

// 계절을 선택하고 상의를 구매할 지 하의를 구매할 지 
// 선택하면 텍스파일에서 목록을 가져옴
// 사용자가 메인메뉴로 돌아가기 선택을 할 수도 있음


// 봄 가을 수트 정보 가져옴
void get_suit_data_spring_autumn(char springAutumnSuitFile[])
{
	// 데이터가 없으면 "데이터가 존재하지 않습니다" 에러 메시지를 출력!
	FILE* fp = fopen(springAutumnSuitFile, "r");  // 구조체 사용할 때는 b 옵션
	if (fp == NULL) {
		printf("파일 읽기 오류!\n");
		exit(0);
	}
	SEASON sean = { 0 }; // 파일안에 있는 구조체 한 덩어리
	int count = 1;
	int check = 0;
	while (fread(&season, sizeof(season), 1, fp) == 1) {
		printf("재고 번호:%d\n", count++);
		printf("ID:%d\n", ad.id);
		printf("이름:%s\n", ad.name);
		printf("전화:%s\n", ad.tel);
		printf("주소:%s\n", ad.addr);
		printf("이메일:%s\n", ad.email);
		printf("==========================\n");
		check = 1;
	}
	fclose(fp);
	if (check == 0) {
		printf("데이터가 존재하지 않습니다.\n");
	}


}

void get_suit_data_summer(char summerSuitFile[])
{



}

void get_suit_data_winter(char winterSuitFile[])
{



}