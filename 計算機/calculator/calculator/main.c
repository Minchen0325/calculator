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
		printf("\n��ܥ\��G\n");
		printf("1. �p��\��\n");
		printf("2. �G�i���ഫ\n");
		printf("3. �ʵe\n");
		printf("4. �R�����v����\n");
		printf("5. �[�ݾ��v����\n");
		printf("6. �����{��\n");
		printf("�п�ܥ\��]1/2/3/4/5/6�^�G");
		scanf(" %s", option);
		
		if (strcmp(option, "6") == 0) {
			printf("�{���w�����C\n");
			break;
		}
		while (strcmp(option, "1") != 0 && strcmp(option, "2") != 0 && strcmp(option, "3") != 0 
			&& strcmp(option, "4") != 0&& strcmp(option, "5") != 0 && strcmp(option, "6") != 0) {
			printf("��J���~�A�Э��s��J�C");
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
