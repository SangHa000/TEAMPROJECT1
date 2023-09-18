#include <stdio.h>
#include "menu.h"
#include "file.h"

// 정장을 계절별로 선택하였을 때 데이터를 출력하도록  
void choice_suit_season() 
{
	while (1) {
		int num = search_season_suit_menu();
		switch (num) {
		case FIRST_NUM: {
			// 파일에서 불러온 데이터(봄, 가을용 정장)를 보여준다. 
			char springAutumnSuitFile[] = "spring_autumn_suit.txt"; 
			get_suit_data_spring_autumn(springAutumnSuitFile);



			break;
		}
		case SECOND_NUM: {
			// 파일에서 불러온 데이터(여름용 정장)를 보여준다. 
			char summerSuitFile[] = "summer_suit.txt";
			get_suit_data_summer(summerSuitFile);



			break;
		}
		case THIRD_NUM: {

			// 파일에서 불러온 데이터(겨울용 정장)를 보여준다. 
			char winterSuitFile[] = "winter_suit.txt";
			get_suit_data_winter(winterSuitFile);


			break;
		}

		case FOURTH_NUM:
			// 메인 메뉴로 돌아간다.

			break; 




		default:
			printf("잘못된 메뉴 선택!!\n");
		}




	}
}