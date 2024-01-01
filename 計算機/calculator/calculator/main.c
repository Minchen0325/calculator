#include <stdio.h>
#include <stdlib.h>
#include "../calculator//history.h"
#include "../calculator//Operation.h"
#include "../calculator//animation.h"

#define MAX_HISTORY_LENGTH 100 

char option[10];
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
		scanf(" %s", option);
		
		if (strcmp(option, "6") == 0) {
			printf("程式已關閉。\n");
			break;
		}
		while (strcmp(option, "1") != 0 && strcmp(option, "2") != 0 && strcmp(option, "3") != 0 
			&& strcmp(option, "4") != 0&& strcmp(option, "5") != 0 && strcmp(option, "6") != 0) {
			printf("輸入錯誤，請重新輸入。");
			scanf("%s", option);
		}
		if (strcmp(option, "1") == 0) {
			snprintf(dick, 100, "%s", calculator(&num1, &num2, &result));
		}
		else if (strcmp(option, "2") == 0) {
			binary();
		}
		else if (strcmp(option, "3") == 0) {
			animation(dick);
		}
		else if (strcmp(option, "4") == 0) {
			clearHistory();
		}
		else if (strcmp(option, "5") == 0) {
			displayHistory();
		}
		system("pause");
	} while (strcmp(option, "6") != 0);
		

	return 0;
}
