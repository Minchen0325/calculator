double calculate(double num1,double num2) {
	int result;
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
	}#pragma once


}