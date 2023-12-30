double calculate(double num1,double num2) {
	int result;
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
	default:
		printf("錯誤：無效的運算符\n");
		break;
	}#pragma once


}