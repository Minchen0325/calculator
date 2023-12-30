#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY_LENGTH 100

void saveHistory(char *operation, double num1, double num2, double result) {
	FILE *fptr = fopen("history.txt", "a");
	if (fptr == NULL) {
		printf("�L�k���}�γЫ� history.txt ���C\n");
		return;
	}

	fprintf(fptr, "%.2lf %s %.2lf = %.2lf\n", num1, operation, num2, result);
	fclose(fptr);
}

void clearHistory() {
	FILE *fptr = fopen("history.txt", "w");
	if (fptr == NULL) {
		printf("�L�k���}�γЫ� history.txt ���C\n");
		return;
	}

	fclose(fptr);
	printf("���v�O���w�M���C\n");
}

void displayHistory() {
	system("cls");
	FILE *fptr = fopen("history.txt", "r");
	if (fptr == NULL) {
		printf("���v�O�����šC\n");
		return;
	}

	printf("���v�O���G\n");
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
		printf("\n��ܥ\��G\n");
		printf("1. �p��\��\n");
		printf("2. �R�����v����\n");
		printf("3. �[�ݾ��v����\n");
		printf("4. �����{��\n");
		printf("�п�ܥ\��]1/2/3/4�^�G");
		scanf(" %c", &option);

		switch (option) {
		case '1': {
			char operator;
			double num1, num2, result;

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
			case '!':

			

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
