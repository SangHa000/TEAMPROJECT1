#ifndef __FILE_H__
#define __FILE_H__

#define SPRING_AUTUMN_SUIT "spring_autumn_suit.txt"
#define SUMMER_SUIT "summer_suit.txt"
#define WINTER_SUIT "winter_suit.txt"

typedef struct _MANAGER {
	char id[10];      //���� ����
	char passward[10]; // ���� ����	
} MANAGER;

typedef struct _TAG {
	int blazerPrice;      //���� ���� ����
	int dressPantsPrice; // ���� ���� ����
	int blazerCount; 
	int dressPantsCount;
} TAG;

typedef struct _SUIT { 
	char blazer[50];      //���� ���� �𵨸�
	char dressPants[50]; // ���� ���� �𵨸�	
	TAG tag;
	MANAGER manager;
} SUIT;

typedef struct _CUSTOMER {
	SUIT suit;
	char custName[10];
} CUSTOMER;

typedef struct _SEASON {   
	char springAndAutumn[10];
	char summer[10];
	char winter[10];
	CUSTOMER customer;	
} SEASON;

extern void suit_file_write(char mode, int len, SEASON season[]);
extern void get_suit_data_spring_autumn();
extern void get_suit_data_summer();
extern void get_suit_data_winter();
void register_manage();
int idPassCompare(char inputId[], char inputPass[]);

#endif