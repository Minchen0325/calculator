#include <stdio.h>
#include <math.h>

int checkb2d(int x)
{

	int check, ret = 1;
	while (x)
	{
		check = x % 10;
		x = x / 10;

		if (check != 0 && check != 1)
		{
			printf("��J���~(�u��0~9)");
			ret = 0;
			x = 0;
			break;
		}
	}
	return ret;
}

int checkd2b(int x)
{
	int check, ret = 1;
	while (x)
	{
		check = x % 2;
		x = x / 2;
		if (check != 0 && check != 1)
		{
			printf("��J���~");
			ret = 0;
			x = 0;
			break;
		}
	}
	return ret;
}

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
	char x[20],a[20];
	int back;
	int sum = 0, count = -1, dontdo = 1;


	do {
		system("cls");
		printf("1.�G�i����Q�i��\n");
		printf("2.�Q�i����G�i��\n");
		printf("3.�h�X\n");
		printf("�п�ܷQ�n���\��:");
		scanf("%s", choose);



		int doit = 0;
		for (int i = 0; i < 10; i++)
		{
			doit = doit + checkdonkey(choose[i]);
			if (doit)break;
		}
		doit = doit - 2;

		if (doit == 0)
		{

			if (strcmp(choose, "3") == 0) {
				printf("���\�h�X\n");
				break;
			}
			while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0 && strcmp(choose, "3") != 0) {
				printf("��J���~�A�Э��s��J�C");
				scanf("%s", choose);
			}


			sum = 0, dontdo = 1, count = -1;//���ƨϥλݭ��m

			if (strcmp(choose, "1") == 0) {
				printf("�п�J�G�i��:");
				scanf("%s", &x);

				for (int i = 0; i < sizeof(x); i++)//�ӧO����
				{
					count++;
					if (checkdonkey(x[i]) == 1) { dontdo = 0; break; }
					if (checkdonkey(x[i])) break;

				}

				for (int i = 0; i < count; i++)//char��int
				{
					int rig = 1;
					for (int j = i; j < count - 1; j++)
					{
						rig = rig * 10;
					}
					sum = sum + change(x[i])*rig;
				}
				if (checkb2d(sum) && dontdo)//��X
				{
					printf("�Q�i�:%d\n", b2d(sum));
				}
			}

			else if (strcmp(choose, "2") == 0) {
				printf("�п�J�Q�i��:");
				scanf("%s", &a);

				for (int i = 0; i < sizeof(a); i++)//�ӧO����
				{
					count++;
					if (checkdonkey(a[i]) == 1) { dontdo = 0; break; }
					if (checkdonkey(a[i])) break;
				}

				for (int i = 0; i < count; i++)//char��int
				{
					int rig = 1;
					for (int j = i; j < count - 1; j++)
					{
						rig = rig * 10;
					}
					sum = sum + change(a[i])*rig;
				}


				if (checkd2b(sum) && dontdo)//��X
				{
					printf("�Q�i�:%d\n", d2b(sum));
				}
			}

		}
		system("pause");
	} while (strcmp(choose, "3") != 0);
}