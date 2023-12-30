#include <stdio.h>
#include <math.h>


int calculator() {
	
	char operator;
	double num1, num2, result;
	printf("請輸入運算符(+, -, *, /, ^, sqrt): ");
	scanf(" %c", &operator);

	printf("請輸入兩個數字: ");
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
			printf("錯誤：除數不能為0\n");
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
			printf("錯誤：負數無法計算平方根\n");
			return 1;
		}
		break;

	default:
		printf("錯誤：無效的運算符\n");
		return 1;
	}
	printf("結果: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
}