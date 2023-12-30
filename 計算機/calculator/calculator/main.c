#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY_LENGTH 100

void saveHistory(char *operation, double num1, double num2, double result) {
	FILE *fptr = fopen("history.txt", "a");
	if (fptr == NULL) {
		printf("無法打開或創建 history.txt 文件。\n");
		return;
	}

	fprintf(fptr, "%.2lf %s %.2lf = %.2lf\n", num1, operation, num2, result);
	fclose(fptr);
}

void clearHistory() {
	FILE *fptr = fopen("history.txt", "w");
	if (fptr == NULL) {
		printf("無法打開或創建 history.txt 文件。\n");
		return;
	}

	fclose(fptr);
	printf("歷史記錄已清除。\n");
}

void displayHistory() {
	system("cls");
	FILE *fptr = fopen("history.txt", "r");
	if (fptr == NULL) {
		printf("歷史記錄為空。\n");
		return;
	}

	printf("歷史記錄：\n");
	char c;
	while ((c = getc(fptr)) != EOF) {
		putchar(c);
	}
	fclose(fptr);
}

int main() {
	char option;
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
		case '1': {
			char operator;
			double num1, num2, result;

			printf("請輸入運算符(+, -, *, /)：");
			scanf(" %c", &operator);

			printf("請輸入兩個數字: ");
			scanf("%lf %lf", &num1, &num2);

			switch (operator) {
			case '+':
				result = num1 + num2;
				printf("結果: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
				saveHistory("+", num1, num2, result);
				break;
			case '-':
				result = num1 - num2;
				printf("結果: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
				saveHistory("-", num1, num2, result);
				break;
			case '*':
				result = num1 * num2;
				printf("結果: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
				saveHistory("*", num1, num2, result);
				break;
			case '/':
				if (num2 != 0) {
					result = num1 / num2;
					printf("結果: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
					saveHistory("/", num1, num2, result);
				}
				else {
					printf("錯誤：除數不能為0\n");
				}
				break;
			case '!':

			

			default:
				printf("錯誤：無效的運算符\n");
				break;
			}
			break;
		}
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
