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
	printf("請輸入b2d：");
	scanf_s("%d", &x);
	y = b2d(x);
	printf("b2d結果是%d\n", y);


	printf("請輸入d2b：");
	scanf_s("%d", &a);
	b = d2b(a);
	printf("d2b結果是%d", b);



	return 0;
}