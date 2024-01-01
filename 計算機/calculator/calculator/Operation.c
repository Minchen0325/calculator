#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int isValidOperator(char operator[]) {
	char validOperators[] = "+-*/%^sqrtlogsincostanasincostan";
	return (strstr(validOperators, operator) != NULL);
}

char* calculator(double *num1, double *num2, double *result) {

	char* fuck = malloc(100);
	char operator[10];
	double angle;

	do {
		printf("請輸入運算符( +, -, *, /, %, ^, sqrt, log , (a)sin , (a)cos , (a)tan ) : ");
		scanf(" %s", operator);

		if (!isValidOperator(operator)) {
			printf("錯誤：無效的運算符\n");
		}
	} while (!isValidOperator(operator));

	if (strcmp(operator, "sin") == 0 || strcmp(operator, "cos") == 0 || strcmp(operator, "tan") == 0 ||
		strcmp(operator, "asin") == 0 || strcmp(operator, "acos") == 0 || strcmp(operator, "atan") == 0) {
		printf("請輸入角度: ");
		scanf("%lf", &angle);
		if (strcmp(operator, "sin") == 0) *result = sin(angle / 180 * PI);
		else if (strcmp(operator, "cos") == 0) *result = cos(angle / 180 * PI);
		else if (strcmp(operator, "tan") == 0) *result = tan(angle / 180 * PI);
		else if (strcmp(operator, "asin") == 0) *result = (asin(angle) / PI * 180);
		else if (strcmp(operator, "acos") == 0) *result = (acos(angle) / PI * 180);
		else if (strcmp(operator, "atan") == 0) *result = (atan(angle) / PI * 180);
		printf("結果: %s %.2lf = %.2lf\n", operator, angle, *result);
		saveHistory(operator, 0.0, angle, *result);
	}
	if ((strcmp(operator, "sqrt") ==0)) {
		printf("請輸入一個數字: ");
		scanf("%lf", num1);
		if (*num1 >= 0) *result = sqrt(*num1);
		else printf("錯誤：負數無法計算平方根\n");
		printf("結果: %s %.2lf = %.2lf\n", operator, *num1, *result);
	}
	if (strcmp(operator, "sin") != 0 && strcmp(operator, "cos") != 0 && strcmp(operator, "tan") != 0 &&
		strcmp(operator, "asin") != 0 && strcmp(operator, "acos") != 0 && strcmp(operator, "atan") != 0&& (strcmp(operator, "sqrt") != 0)) {
		printf("請輸入兩個數字: ");
		scanf("%lf %lf", num1, num2);
		if (strcmp(operator, "+") == 0) *result = *num1 + *num2;
		else if (strcmp(operator, "-") == 0) *result = *num1 - *num2;
		else if (strcmp(operator, "*") == 0) *result = *num1 * *num2;
		else if (strcmp(operator, "/") == 0) {
			if (num1 != 0) *result = *num1 / *num2;
			else printf("錯誤：除數不能為0\n");
		}
		else if (strcmp(operator, "%") == 0) *result = (int)*num1 % (int)*num2;
		else if (strcmp(operator, "^") == 0) *result = pow(*num1, *num2);
		/*else if (strcmp(operator, "sqrt") == 0) {
			if (*num1 >= 0) *result = sqrt(*num1);
			else printf("錯誤：負數無法計算平方根\n");
		}*/
		else if (strcmp(operator, "log") == 0) *result = log(*num2) / log(*num1);
		printf("結果: %.2lf %s %.2lf = %.2lf\n", *num1, operator, *num2, *result);
		saveHistory(operator, *num1, *num2, *result);
	}

	if (strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0 || strcmp(operator, "*") == 0 ||
		strcmp(operator, "/") == 0 || strcmp(operator, "%") == 0 || strcmp(operator, "^") == 0 ||
		strcmp(operator, "log") == 0) {
		snprintf(fuck, 100, "%f %s %f %c %f\n", *num1, operator, *num2, '=', *result);
	}
	else if (strcmp(operator, "sin") == 0 || strcmp(operator, "cos") == 0 ||
		strcmp(operator, "tan") == 0 || strcmp(operator, "asin") == 0 || strcmp(operator, "acos") == 0 ||
		strcmp(operator, "atan") == 0) {
		snprintf(fuck, 100, "%s %f %c %f\n", operator, angle, '=', *result);
	}
	else if (strcmp(operator, "sqrt") == 0) {
		snprintf(fuck, 100, "%s %f %c %f\n", operator, *num1, '=', *result);
	}

	return fuck;
}