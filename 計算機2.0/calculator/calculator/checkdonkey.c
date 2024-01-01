#include<stdio.h>

int checkdonkey(char binary) //防呆
{
	if (binary>='0' && binary<='9')
	{
		return 0;
	}
	else if (binary == '\0') { return 2; }
	else if (binary<'0' || binary>'9')
	{
		printf("輸入錯誤(請輸入規定數值)\n");
		return 1;
	}
	
	
}

int change(char x)//char轉int
{
	int ris;
	if (x == '\0') { return 0; }
	if (x >= '0' && x <= '9')
	{
		for (int i = 0; i < 10; i++)
		{
			if (x == (i + 48)) { ris = i; }
		}
		//printf("ris=%d\n", ris);
		return ris;
	}
	else { return 0; }
}