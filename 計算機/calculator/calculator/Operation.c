#include <stdio.h>
#include <math.h>


int calculator() {
	
	char operator;
	double num1, num2, result;
	printf("�п�J�B���(+, -, *, /, ^, sqrt): ");
	scanf(" %c", &operator);

	printf("�п�J��ӼƦr: ");
	scanf("%lf %lf", &num1, &num2);

	switch (operator) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		if (num2 != 0) {
			result = num1 / num2;
		}
		else {
			printf("���~�G���Ƥ��ର0\n");
			return 1;
		}
		break;
	case '^':
		result = pow(num1, num2);
		break;

	case 's':
		if (num1 >= 0) {
			result = sqrt(num1);
		}
		else {
			printf("���~�G�t�ƵL�k�p�⥭���\n");
			return 1;
		}
		break;

	default:
		printf("���~�G�L�Ī��B���\n");
		return 1;
	}
	printf("���G: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
}