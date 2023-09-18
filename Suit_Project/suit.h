#ifndef __SUIT_H__
#define __SUIT_H__

typedef struct _SEASON {   // 계절 선택 상위 구조체
	char springAndAutumn[10];
	char summer[10];
	char winter[10];
} SEASON;

typedef struct _SUIT {  // 하위 구조체
	char blazer[50];      //정장 상의
	char dress_pants[50]; // 정장 하의
	SEASON season;
} SUIT;

extern void choice_season_spring_autumn();
extern void choice_season_summer();
extern void choice_season_winter();

#endif