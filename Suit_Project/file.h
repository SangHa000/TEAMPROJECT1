#ifndef __FILE_H__
#define __FILE_H__

#define SPRING_AUTUMN_SUIT "spring_autumn_suit.txt"
#define SUMMER_SUIT "summer_suit.txt"
#define WINTER_SUIT "winter_suit.txt"

typedef struct _SUIT {  // 하위 구조체
	char blazer[30];      //정장 상의
	char dress_pants[30]; // 정장 하의	
} SUIT;

typedef struct _SEASON {   // 계절 선택 상위 구조체
	char springAndAutumn[10];
	char summer[10];
	char winter[10];
	SUIT suit;
} SEASON;

extern void suit_file_write(char mode, int len, SUIT suit_[]);
extern void get_suit_data_spring_autumn();
extern void get_suit_data_summer();
extern void get_suit_data_winter();


#endif