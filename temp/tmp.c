#include "../pages/pages.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>



void tmp_page() {
	Intro();

	printf("Clean temp folders? (y/n): ");
	if (getchar() != 'y') return;

	int temp = system("del /q /s %temp%\\*");
	int windowstemp = system("del /q /s C:\\Windows\\Temp\\*");

	if (temp != 0) printf("Failed to clean temp.. maybe run as admin?");
	if (windowstemp != 0) printf("Failed to clean C:\\Windows\\Temp.. maybe run as admin?");

	Sleep(2000);

	return;
}
