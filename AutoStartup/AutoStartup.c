#include "../pages/pages.h"
#include <stdio.h>
#include "../Intro/Intro.h"
#include "../regedit/Regedit.h"
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include "define.h"

void NEXTPAGE_STARTUP(void) {
	Intro();

    printf("Checking Winlogon..\n");
    CheckAndResetWinlogonValues(DEFAULT_USERINIT, DEFAULT_SHELL, WINLOGON_PATH);
    printf("===================\n");
    Sleep(2000);

    printf("checking run...\n");
    CheckRun(RUN_PATH);
    printf("================\n");

    Sleep(2000);

    printf("checking runonce...\n");
    CheckRunOnce(RUNONCE_PATH);
    printf("======================");

    system("cls");
    return;
}