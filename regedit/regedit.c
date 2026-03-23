#include "Regedit.h"
#include <stdio.h>
#include <Windows.h>

void CheckRun(char* RUN_PATH) {
    HKEY hKey;
    char valueName[256];
    DWORD valueNameSize;
    int index = 0;
    int hasEntries = 0;


    if (RegOpenKeyExA(HKEY_CURRENT_USER,
        RUN_PATH,
        0, KEY_READ | KEY_SET_VALUE, &hKey) != ERROR_SUCCESS) {
        printf("Cannot open Run key\n");
        return;
    }


    while (1) {
        valueNameSize = sizeof(valueName);
        LONG result = RegEnumValueA(hKey, index, valueName, &valueNameSize,
            NULL, NULL, NULL, NULL);

        if (result == ERROR_NO_MORE_ITEMS) break;
        if (result == ERROR_SUCCESS) {
            hasEntries = 1;
            break;
        }
        index++;
    }


    if (!hasEntries) {
        printf("Run is already clean\n");
        RegCloseKey(hKey);

        Sleep(2000);

        return;
    }


    printf("Found entries in Run. Cleaning...\n");

    while (1) {
        valueNameSize = sizeof(valueName);
        LONG result = RegEnumValueA(hKey, 0, valueName, &valueNameSize,
            NULL, NULL, NULL, NULL);

        if (result == ERROR_NO_MORE_ITEMS) break;
        if (result == ERROR_SUCCESS) {
            if (RegDeleteValueA(hKey, valueName) == ERROR_SUCCESS) {
                printf("Deleted: %s\n", valueName);
            }
        }
    }

    printf("Run cleaned successfully\n");
    RegCloseKey(hKey);
}

void CheckRunOnce(char* RUNONCE_PATH) {
    HKEY hKey;
    char valueName[256];
    DWORD valueNameSize;
    int index = 0;
    int hasEntries = 0;


    if (RegOpenKeyExA(HKEY_CURRENT_USER,
        RUNONCE_PATH,
        0, KEY_READ | KEY_SET_VALUE, &hKey) != ERROR_SUCCESS) {
        printf("Cannot open RunOnce key\n");
        return;
    }


    while (1) {
        valueNameSize = sizeof(valueName);
        LONG result = RegEnumValueA(hKey, index, valueName, &valueNameSize,
            NULL, NULL, NULL, NULL);

        if (result == ERROR_NO_MORE_ITEMS) break;
        if (result == ERROR_SUCCESS) {
            hasEntries = 1;
            break;
        }
        index++;
    }


    if (!hasEntries) {
        printf("RunOnce is already clean\n");
        RegCloseKey(hKey);

        Sleep(2000);

        return;
    }


    printf("Found entries in RunOnce. Cleaning...\n");

    while (1) {
        valueNameSize = sizeof(valueName);
        LONG result = RegEnumValueA(hKey, 0, valueName, &valueNameSize,
            NULL, NULL, NULL, NULL);

        if (result == ERROR_NO_MORE_ITEMS) break;
        if (result == ERROR_SUCCESS) {
            if (RegDeleteValueA(hKey, valueName) == ERROR_SUCCESS) {
                printf("Deleted: %s\n", valueName);
            }
        }
    }

    printf("RunOnce cleaned successfully\n");
    RegCloseKey(hKey);
}

void CheckAndResetWinlogonValues(char* DEFAULT_USERINIT, char* DEFAULT_SHELL, char* WINLOGON_PATH) {
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