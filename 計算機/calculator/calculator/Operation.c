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
	//�ˬd�B��Ÿ�
	do {
		printf("�п�J�B���( +, -, *, /, %, ^, sqrt, log , (a)sin , (a)cos , (a)tan ) : ");
		scanf(" %s", operator);

		if (!isValidOperator(operator)) {
			printf("���~�G�L�Ī��B���\n");
		}
	} while (!isValidOperator(operator));
	//�ˬd�O�_�O��@�B��

	//�T�����
	if (strcmp(operator, "sin") == 0 || strcmp(operator, "cos") == 0 || strcmp(operator, "tan") == 0 ||
		strcmp(operator, "asin") == 0 || strcmp(operator, "acos") == 0 || strcmp(operator, "atan") == 0) {
		printf("�п�J����: ");
		scanf("%lf", &angle);
		if (strcmp(operator, "sin") == 0) *result = sin(angle / 180 * PI);
		else if (strcmp(operator, "cos") == 0) *result = cos(angle / 180 * PI);
		else if (strcmp(operator, "tan") == 0) *result = tan(angle / 180 * PI);
		else if (strcmp(operator, "asin") == 0) *result = (asin(angle) / PI * 180);
		else if (strcmp(operator, "acos") == 0) *result = (acos(angle) / PI * 180);
		else if (strcmp(operator, "atan") == 0) *result = (atan(angle) / PI * 180);
		printf("���G: %s %.2lf = %.2lf\n", operator, angle, *result);
		saveHistory(operator, 0.0, angle, *result);
	}

	//�Ӧ����}�ڸ�
	if ((strcmp(operator, "sqrt") ==0)) {
		printf("�п�J�@�ӼƦr: ");
		scanf("%lf", num2);
		if (*num2 >= 0) *result = sqrt(*num2);
		else printf("���~�G�t�ƵL�k�p�⥭���\n");
		printf("���G: %s %.2lf = %.2lf\n", operator, *num2, *result);
		saveHistory(operator, 0.0 ,*num2, *result);
	}

	//�T����Ƹ�sqrt���~�p��
	if (strcmp(operator, "sin") != 0 && strcmp(operator, "cos") != 0 && strcmp(operator, "tan") != 0 &&
		strcmp(operator, "asin") != 0 && strcmp(operator, "acos") != 0 && strcmp(operator, "atan") != 0&& (strcmp(operator, "sqrt") != 0)) {
		printf("�п�J��ӼƦr: ");
		scanf("%lf %lf", num1, num2);
		if (strcmp(operator, "+") == 0) *result = *num1 + *num2;
		else if (strcmp(operator, "-") == 0) *result = *num1 - *num2;
		else if (strcmp(operator, "*") == 0) *result = *num1 * *num2;

		//���ƭp��
		else if (strcmp(operator, "/") == 0) {
			if (num1 != 0) *result = *num1 / *num2;
			else printf("���~�G���Ƥ��ର0\n");
		}

		else if (strcmp(operator, "%") == 0) *result = (int)*num1 % (int)*num2;
		else if (strcmp(operator, "^") == 0) *result = pow(*num1, *num2);
		else if (strcmp(operator, "log") == 0) *result = log(*num2) / log(*num1);
		//���G���L( +  -  *  /  %  log)
		printf("���G: %.2lf %s %.2lf = %.2lf\n", *num1, operator, *num2, *result);
		saveHistory(operator, *num1, *num2, *result);
	}


	//���L�ʵe
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
		snprintf(fuck, 100, "%s %f %c %f\n", operator, *num2, '=', *result);
	}

	return fuck;
}