#include <stdio.h>
#include <windows.h> 

void animation(char* dick) {
	int i = 0;
	while (dick[i] != '\0') {
		printf("%c", dick[i]);
		fflush(stdout);
		Sleep(100);
		i += 1;
	}
}
