#include "Choice.h"
#include "Processing.h"
#include <stdio.h>
#include <Windows.h>

void USER_CHOICE(void) {
	char username[256];
	DWORD size = sizeof(username);
	int USER_CE;

	printf("\033[36m What do you want to do? \033[0m \n\n");
	printf("\033[32m 1. Clean up startup \033[0m \n");

	if (GetUserNameA(username, &size)) {
		printf("~ %s ", username);
		scanf_s("%d", &USER_CE);
		PROCESSING_C(USER_CE, NULL);
	}
	else {
		printf("~ User ");
		scanf_s("%d", &USER_CE);
		PROCESSING_C(USER_CE, NULL);
	}

	(void)getchar();
}