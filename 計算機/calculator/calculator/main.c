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
		case '1': {
			printf("�п�J�B���(+, -, *, /)�G");
			scanf(" %c", &operator);

			printf("�п�J��ӼƦr: ");
			scanf("%lf %lf", &num1, &num2);

			switch (operator) {
			case '+':
				result = num1 + num2;
				printf("���G: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
				saveHistory("+", num1, num2, result);
				break;
			case '-':
				result = num1 - num2;
				printf("���G: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
				saveHistory("-", num1, num2, result);
				break;
			case '*':
				result = num1 * num2;
				printf("���G: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
				saveHistory("*", num1, num2, result);
				break;
			case '/':
				if (num2 != 0) {
					result = num1 / num2;
					printf("���G: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
					saveHistory("/", num1, num2, result);
				}
				else {
					printf("���~�G���Ƥ��ର0\n");
				}
				break;
			default:
				printf("���~�G�L�Ī��B���\n");
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
