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