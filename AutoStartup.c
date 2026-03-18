#include "AutoStartup.h"
#include <stdio.h>
#include "Intro.h"
#include <stdlib.h>
#include <Windows.h>

#include <windows.h>
#include <stdio.h>
#include <string.h>

#define WINLOGON_PATH "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon"

const char* DEFAULT_SHELL = "explorer.exe";
const char* DEFAULT_USERINIT = "C:\\Windows\\system32\\userinit.exe,";

void CheckAndResetWinlogonValues() {
    HKEY hKey;
    DWORD type;
    char currentValue[512];
    DWORD size;
    int changed = 0;

    const char* keys[] = { "Shell", "Userinit", NULL };
    const char* defaults[] = { DEFAULT_SHELL, DEFAULT_USERINIT };

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, WINLOGON_PATH, 0, KEY_READ | KEY_WRITE, &hKey) != ERROR_SUCCESS) {
        printf("Failed to open Winlogon key (run as admin?)\n");
        return;
    }

    printf("Checking Winlogon settings...\n");

    for (int i = 0; keys[i] != NULL; i++) {
        size = sizeof(currentValue);

        if (RegQueryValueExA(hKey, keys[i], NULL, &type, (LPBYTE)currentValue, &size) == ERROR_SUCCESS) {
            if (strcmp(currentValue, defaults[i]) != 0) {
                printf("%s is not default: \"%s\"\n", keys[i], currentValue);
                printf("Resetting to: \"%s\"\n", defaults[i]);

 
                RegSetValueExA(hKey, keys[i], 0, REG_SZ, (LPBYTE)defaults[i], strlen(defaults[i]) + 1);
                changed = 1;
            }
            else {
                printf("%s is OK\n", keys[i]);
            }
        }
        else {
            printf("%s not found, creating...\n", keys[i]);
            RegSetValueExA(hKey, keys[i], 0, REG_SZ, (LPBYTE)defaults[i], strlen(defaults[i]) + 1);
            changed = 1;
        }
    }

    RegCloseKey(hKey);

    if (changed) {
        printf("\nWinlogon settings have been reset to defaults.\n");
    }
    else {
        printf("\nAll Winlogon settings are already correct.\n");
    }
}

void NEXTPAGE_STARTUP(void) {
	system("cls");
	Intro();
    CheckAndResetWinlogonValues();

    Sleep(1000);

    system("cls");
    return;
}