#ifndef __MENU_H__
#define __MENU_H__

// enum은 상수만
typedef enum {
	FIRST_NUM = 1,
	SECOND_NUM,
	THIRD_NUM,
	FOURTH_NUM,
} MENU_NUM;

extern int main_menu();
extern int search_season_suit_menu();
extern int manager_menu();
extern int input_only_num();

#endif
