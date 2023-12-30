#include <stdio.h>
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