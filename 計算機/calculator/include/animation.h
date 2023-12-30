#include <windows.h> 

void animation(double num1, double num2, double result) {

    char display[100];

    snprintf(display, sizeof(display), "num1: %lf, num2: %lf, result: %lf", num1, num2, result);

    int i = 0;
    while (display[i] != '\0') {
        printf("%c", display[i]);
        fflush(stdout); 
        Sleep(100); 
        i += 1;
    }
}
