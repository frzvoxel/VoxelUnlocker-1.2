#include "pages.h"
#include <stdio.h>
#include "Intro.h"
#include "Regedit.h"
#include <stdlib.h>
#include <Windows.h>

#include <windows.h>
#include <stdio.h>
#include <string.h>

#define WINLOGON_PATH "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon"
#define RUN_PATH "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"

const char* DEFAULT_SHELL = "explorer.exe";
const char* DEFAULT_USERINIT = "C:\\Windows\\system32\\userinit.exe,";

void NEXTPAGE_STARTUP(void) {
	Intro();
    CheckAndResetWinlogonValues(DEFAULT_USERINIT, DEFAULT_SHELL, WINLOGON_PATH);
    CheckRun(RUN_PATH);

    Sleep(1000);

    system("cls");
    return;
}