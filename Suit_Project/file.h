#ifndef __FILE_H__
#define __FILE_H__

//#define SPRING_AUTUMN_SUIT "spring_autumn_suit.txt"
//#define SUMMER_SUIT "summer_suit.txt"
//#define WINTER_SUIT "winter_suit.txt"

typedef struct _MANAGER {
	char id[10];      //정장 상의
	char passward[10]; // 정장 하의	
} MANAGER;

typedef struct _TAG {
	int blazerPrice;      //정장 상의 가격
	int dressPantsPrice; // 정장 하의 가격
	int blazerCount; 
	int dressPantsCount;
} TAG;

typedef struct _SUIT { 
	char blazer[50];      //정장 상의 모델명
	char dressPants[50]; // 정장 하의 모델명	
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

//const char springAutumnSuitFile[] = "D:\\work_c\\Suit_Project\\spring_autumn_suit.bin";
//const char summerSuitFile[] = "D:\\work_c\\Suit_Project\\summer_suit.bin";
//const char winterSuitFile[] = "D:\\work_c\\Suit_Project\\winter_suit.bin";
//const char managementFile[] = "D:\\work_c\\Suit_Project\\management.bin";


extern void suit_file_write(char mode, int len, SEASON season[]);
extern void get_suit_data_spring_autumn();
extern void get_suit_data_summer();
extern void get_suit_data_winter();
void register_manage();
int idPassCompare(char inputId[], char inputPass[]);
void suit_shirts_puchse_file(int quantity, char suitModel[], char fileName[]);
void suit_pants_puchse_file(int quantity, char suitModel[], char fileName[]);
int deposit_file(int money, char suitModel[], char fileName[]);

#endif