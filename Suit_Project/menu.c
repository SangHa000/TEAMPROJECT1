#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit(), system() 五社球紫遂
#include "menu.h"

// 五昔 五敢
int main_menu()
{
	int menu = 0;
	printf("＝＝ΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΟΤΟΤΟΤΟΤ\n");
	printf("＝＝                                     Ν\n");
	printf("Ν   ⊆ 失昔 害失遂 舛舌 姥古 覗稽益轡 ⊆ Ν\n");
	printf("Ν                                        Ν\n");
	printf("ΡΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΠΦΠΦΠΦΠΠ\n");
	printf(" 1. 域箭紺 舛舌 鯉系\n");
	printf(" 2. 淫軒切 五敢\n");
	printf(" 3. 曽戟\n");
	menu = input_only_num();
	return menu;
}

// 淫軒切 五敢
int manager_menu()
{
	printf("1. 羨紗廃 壱梓税 姥古 鯉系 溌昔");
	printf("2. 恥 毒古 衝呪 溌昔");
	int num;
	num = input_only_num();
	return num;
}

// 域箭紺 舛舌 伊事馬澗 五敢
int search_season_suit_menu()
{
	printf("＝＝ΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤΤ\n");
	printf("＝＝                        Ν\n");
	printf("Ν  ⊆ Season紺 舛舌 識澱 ⊆ Ν\n");
	printf("Ν                           Ν\n");
	printf("ΡΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΦΠΦΠ\n");
	printf("1. 砂 / 亜聖 遂 舛舌\n"); // 雌税 馬税稽 歳嫌
	printf("2. 食硯 遂 舛舌\n");
	printf("3. 移随 遂 舛舌\n");
	printf("4. 五昔 五敢 宜焼亜奄\n");
	int menu;
	menu = input_only_num();
	return menu;
}

// 収切幻 脊径馬惟 
int input_only_num()
{
	int num = 0;
	while (1) {
		//
		printf("『 収切(丞税 舛呪)幻 識澱馬食 爽室推!!! 『\n");
		printf("収切(丞税 舛呪)研 脊径背爽室推 : ");
		scanf("%d", &num);
 
		if (num > 0) {
			break;
		} else {
			while (getchar() != '\n'); // 収切須税 葵聖 脊径馬檎 巷廃 鋼差
		}
		//printf("けけけけけけ\n");
		//system("cls");				
	}
	return num;
}