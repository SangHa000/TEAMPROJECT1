#include <stdio.h>
#include "menu.h"
#include "file.h"

// ������ �������� �����Ͽ��� �� �����͸� ����ϵ���  
void choice_suit_season(int choiceSeasonNum)
{
	while (1) {

		switch (choiceSeasonNum) {
		case FIRST_NUM: {
			// ���Ͽ��� �ҷ��� ������(��, ������ ����)�� �����ش�. 
			//char springAutumnSuitFile[] = SPRING_AUTUMN_SUIT; 
			get_suit_data_spring_autumn();



			break;
		}
		case SECOND_NUM: {
			// ���Ͽ��� �ҷ��� ������(������ ����)�� �����ش�. 

			get_suit_data_summer();



			break;
		}
		case THIRD_NUM: {

			// ���Ͽ��� �ҷ��� ������(�ܿ�� ����)�� �����ش�. 
			//char winterSuitFile[] = WINTER_SUIT;
			get_suit_data_winter();


			break;
		}

		case FOURTH_NUM:
			// ���� �޴��� ���ư���.

			break;




		default:
			printf("�߸��� �޴� ����!!\n");
		}



		break;
	}
}