#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int calculator() {
	
	char operator[10];
	double num1, num2, result;
	printf("請輸入運算符(+, -, *, /, ^, %%, sqrt,log, sin, cos, tan): ");
	scanf(" %s", operator);

	printf("請輸入兩個數字: ");
	scanf("%lf %lf", &num1, &num2);

	if (strcmp(operator, "+") == 0) result = num1 + num2;
	else if(strcmp(operator, "-") == 0) result = num1 - num2;
	else if (strcmp(operator, "*") == 0) result = num1 * num2;
	else if (strcmp(operator, "/") == 0) {
		if (num1 != 0) result = num1 / num2;
		else printf("錯誤：除數不能為0\n");
	}
	else if (strcmp(operator, "%") == 0) result = (int)num1 % (int)num2;
	else if (strcmp(operator, "^") == 0) result = pow(num1, num2);
	else if (strcmp(operator, "sqrt") == 0) {
		if (num1 >= 0) result = sqrt(num1);
		else printf("錯誤：負數無法計算平方根\n");
	}
	else if (strcmp(operator, "log") == 0) result = log(num2) / log(num1);

	else if (strcmp(operator, "sin") == 0) result = sin(num1 / 180 * PI);
	else if (strcmp(operator, "cos") == 0) result = cos(num1 / 180 * PI);
	else if (strcmp(operator, "tan") == 0) result = tan(num1 / 180 * PI);
	else if (strcmp(operator, "asin") == 0) result = (asin(num1) / PI * 180);
	else if (strcmp(operator, "acos") == 0) result = (acos(num1) / PI * 180);
	else if (strcmp(operator, "atan") == 0) result = (atan(num1) / PI * 180);
	else printf("錯誤：無效的運算符\n");
	
	printf("結果: %.2lf %s %.2lf = %.2lf\n", num1, operator, num2, result);
	saveHistory(operator, num1, num2, result);
}