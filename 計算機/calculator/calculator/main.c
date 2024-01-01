#include <stdio.h>
#include <stdlib.h>
#include "../calculator//history.h"
#include "../calculator//Operation.h"
#include "../calculator//animation.h"

#define MAX_HISTORY_LENGTH 100 

char option;
double num1, num2, result;
char dick[100] = "";

int main() {
	
	do {
		system("cls");
		printf("\n選擇功能：\n");
		printf("1. 計算功能\n");
		printf("2. 二進制轉換\n");
		printf("3. 動畫\n");
		printf("4. 刪除歷史紀錄\n");
		printf("5. 觀看歷史紀錄\n");
		printf("6. 關閉程式\n");
		printf("請選擇功能（1/2/3/4/5/6）：");
		scanf(" %c", &option);

		switch (option) {

		case '1':
			snprintf(dick, 100, "%s", calculator(&num1, &num2, &result));
			break;
		case '2':
			//binary();
			break;
		case '3':
			animation(dick);
			break;
		case '4':
			clearHistory();
			break;
		case '5':
			displayHistory();
			break;
		case '6':
			printf("程式已關閉。\n");
			break;
		default:
			printf("請選擇有效的選項（1/2/3/4/5/6）。\n");
			break;
		}
		system("pause");
	} while (option != '6');

	return 0;
}
