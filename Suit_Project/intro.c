// 처음 실행 하였을 때 인트로 화면 실행

#include <stdio.h>
#include <Windows.h>
#include "intro.h"

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	// 윈도우 콘솔에서 커서 위치 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void showIntro() 
{
	int x = 2;
	int y = 0;
	gotoxy(x, y + 1); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");//지정된 좌표로 가서 다음 문구를 실행하라.
	for (int i = 2; i < 26; i++) {
		gotoxy(x, y + i); printf("■");
	}
	gotoxy(x, y + 7); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	//제목 그림 v1.0

	font_color(BLUE);
	gotoxy(x + 2, y + 2); printf(" ●●   ●● ●●●●  ●●    ●  ●●●●  ●  ● ●●● ●●●");
	gotoxy(x + 2, y + 3); printf(" ● ● ● ● ●        ● ●   ● ●	 ●  ●   ●     ●");
	gotoxy(x + 2, y + 4); printf(" ●  ●   ● ●●●●  ●  ●  ●  ●●●●  ●  ●   ●     ●");
	gotoxy(x + 2, y + 5); printf(" ●  ●   ● ●        ●   ● ●         ● ●  ●   ●     ●");
	gotoxy(x + 2, y + 6); printf(" ●       ● ●●●●  ●    ●●  ●●●●   ●●  ●●●   ●");
	font_color(YELLOW);

	for (int i = 2; i <= 26; i++) {
		gotoxy(x + 68, y + i); printf("■");
	}
	gotoxy(x, y + 26); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

	x = 3;
	gotoxy(x, y + 10); printf("		       ※※※ 메뉴 도움말 ※※※");
	gotoxy(x, y + 12); printf("♤  사용계절 : 사용계절별 정장을 보여줍니다.");
	gotoxy(x, y + 14); printf("♤  관리자 메뉴 : 접속한 고객과 구매목록을 보여줍니다.");
	gotoxy(x, y + 20); printf("      ▶▶▶▶메인메뉴 이동은 아무키나 누르세요!◀◀◀◀");
	gotoxy(x, y + 22); printf("◈  3조 개발기간 : 2023/09/12 ~ 2023/09/22");
	gotoxy(x, y + 24); printf("◈  프로젝트 이해관계자 : 정용억, 이상하, 이종권");
}

void set_cursor_type(CURSOR_TYPE type)
{
	CONSOLE_CURSOR_INFO info = { 0 };
	switch (type) {
	case NOCURSOR:
		info.dwSize = 1;
		info.bVisible = FALSE;
		break;
	case SOLID_CURSOR:
		info.dwSize = 100;
		info.bVisible = TRUE;
		break;
	case NORMAL_CURSOR:
		info.dwSize = 20;
		info.bVisible = TRUE;
		break;
	}
	// 커서 타입을 설정 (win32 API)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void font_color(FONT_COLOR color)
{
	// 폰트에 색생 적용
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}