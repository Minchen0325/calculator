#include<stdio.h>

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


int main()
{
	int x, y, a, b;
	printf("�п�Jb2d�G");
	scanf_s("%d", &x);
	y = b2d(x);
	printf("b2d���G�O%d\n", y);


	printf("�п�Jd2b�G");
	scanf_s("%d", &a);
	b = d2b(a);
	printf("d2b���G�O%d", b);



	return 0;
}