#include <stdio.h>
#include <windows.h> 

void animation(double num1, double num2, double result) {
	
    char display[100];

    snprintf(display, sizeof(display), "num1: %.2lf, num2: %.2lf, result: %.2lf", num1, num2, result);

    int i = 0;
    while (display[i] != '\0') {
        printf("%c", display[i]);
        fflush(stdout); 
        Sleep(100); 
        i += 1;
    }
}
