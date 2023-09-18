#include <stdio.h>
#include "menu.h"
#include "file.h"

// 정장을 계절별로 선택하였을 때 데이터를 출력하도록  
void choice_suit_season(int choiceSeasonNum)
{
	while (1) {

		switch (choiceSeasonNum) {
		case FIRST_NUM: {
			// 파일에서 불러온 데이터(봄, 가을용 정장)를 보여준다. 
			//char springAutumnSuitFile[] = SPRING_AUTUMN_SUIT; 
			get_suit_data_spring_autumn();



			break;
		}
		case SECOND_NUM: {
			// 파일에서 불러온 데이터(여름용 정장)를 보여준다. 

			get_suit_data_summer();



			break;
		}
		case THIRD_NUM: {

			// 파일에서 불러온 데이터(겨울용 정장)를 보여준다. 
			//char winterSuitFile[] = WINTER_SUIT;
			get_suit_data_winter();


			break;
		}

		case FOURTH_NUM:
			// 메인 메뉴로 돌아간다.

			break;




		default:
			printf("잘못된 메뉴 선택!!\n");
		}



		break;
	}
}