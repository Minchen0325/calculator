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
		printf("1.�G�i����Q�i��\n");
		printf("2.�Q�i����G�i��\n");
		printf("3.�h�X\n");
		printf("�п�ܷQ�n���\��:");
		scanf("%s", choose);
		if (strcmp(choose, "3") == 0) {
			printf("���\�h�X\n");
			break;
		}
		while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0 && strcmp(choose, "3") != 0) {
			printf("��J���~�A�Э��s��J�C");
			scanf("%s", choose);
		}
		if (strcmp(choose, "1") == 0) {
			printf("�п�J�G�i��:");
			scanf("%d", &x);
			printf("�Q�i�:%d\n", b2d(x));
		}
		else if (strcmp(choose, "2") == 0) {
			printf("�п�J�Q�i��:");
			scanf("%d", &x);
			printf("�Q�i�:%d\n", d2b(x));
		}
		system("pause");
	} while (strcmp(choose, "3") != 0);
}