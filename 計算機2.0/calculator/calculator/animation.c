#include <stdio.h>
#include <windows.h> 

void animation(char* dick) {
	if (strcmp(dick, "") == 0) {
		printf("\n�����W���p������A�ЧQ�έp��\��C\n\n");
	}
	int i = 0;
	while (dick[i] != '\0') {
		printf("%c", dick[i]);
		fflush(stdout);
		Sleep(100);
		i += 1;
	}
}
