#include <stdio.h>
#include <math.h>



int b2d(int x)
{
	int ans = 0, count = -1, ris = 1, time;
	while (x)
	{
		ris = x % 10;
		x = x / 10;
		count++;
		time = count;
		while (time)
		{
			ris = ris * 2;
			time--;
		}
		ans = ans + ris;
	}
	return ans;
}

int d2b(int x)
{
	int ans = 0, count = -1, ris = 1, time;
	while (x)
	{
		ris = x % 2;
		x = x / 2;
		count++;
		time = count;
		while (time)
		{
			ris = ris * 10;
			time--;
		}
		ans = ans + ris;
	}
	return ans;
}

int binary() {
	char choose[10];
	int x;
	int back;
	do {
		system("cls");
		printf("1.二進制轉十進制\n");
		printf("2.十進制轉二進制\n");
		printf("3.退出\n");
		printf("請選擇想要的功能:");
		scanf("%s", choose);
		if (strcmp(choose, "3") == 0) {
			printf("成功退出\n");
			break;
		}
		while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0 && strcmp(choose, "3") != 0) {
			printf("輸入錯誤，請重新輸入。");
			scanf("%s", choose);
		}
		if (strcmp(choose, "1") == 0) {
			printf("請輸入二進制:");
			scanf("%d", &x);
			printf("十進制為:%d\n", b2d(x));
		}
		else if (strcmp(choose, "2") == 0) {
			printf("請輸入十進制:");
			scanf("%d", &x);
			printf("十進制為:%d\n", d2b(x));
		}
		system("pause");
	} while (strcmp(choose, "3") != 0);
}