#include <stdio.h>
#include <stdlib.h>
#include "../calculator//history.h"

#define MAX_HISTORY_LENGTH 100

int main() {
	char option;
	char operator;
	double num1, num2, result;
	do {
		system("cls");
		printf("\n選擇功能：\n");
		printf("1. 計算功能\n");
		printf("2. 刪除歷史紀錄\n");
		printf("3. 觀看歷史紀錄\n");
		printf("4. 關閉程式\n");
		printf("請選擇功能（1/2/3/4）：");
		scanf(" %c", &option);

		switch (option) {

		case '1':
			calculator();
			break;
		case '2':
			clearHistory();
			break;
		case '3':
			displayHistory();
			break;
		case '4':
			printf("程式已關閉。\n");
			break;
		default:
			printf("請選擇有效的選項（1/2/3/4）。\n");
			break;
		}
		system("pause");
	} while (option != '4');

	return 0;
}
