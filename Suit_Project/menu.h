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
int input_only_num();
void check_Y_or_N_menu();
void ask_management_menu();
void purchase_suit_menu();

#endif
