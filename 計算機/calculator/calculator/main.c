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
		printf("\n��ܥ\��G\n");
		printf("1. �p��\��\n");
		printf("2. �R�����v����\n");
		printf("3. �[�ݾ��v����\n");
		printf("4. �����{��\n");
		printf("�п�ܥ\��]1/2/3/4�^�G");
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
			printf("�{���w�����C\n");
			break;
		default:
			printf("�п�ܦ��Ī��ﶵ�]1/2/3/4�^�C\n");
			break;
		}
		system("pause");
	} while (option != '4');

	return 0;
}
