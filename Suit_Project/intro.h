// 표준 사용법 헤더 파일 중복 사용방지
#ifndef __INTRO_H__
#define __INTRO_H__

typedef enum {
	NOCURSOR,		// 커서 없앰		0
	SOLID_CURSOR,	// solid 형태	1
	NORMAL_CURSOR	// 일반 형태		2
} CURSOR_TYPE;

typedef enum {
	BLACK,	// 0
	BLUE,	// 1
	GREEN,	// 2
	CYAN,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	LIGHT_GRAY	// 15
} FONT_COLOR;

extern void gotoxy(int x, int y);
extern void set_cursor_type(CURSOR_TYPE type);
extern void font_color(FONT_COLOR color);
extern void showIntro();

#endif