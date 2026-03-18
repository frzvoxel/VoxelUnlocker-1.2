#include <stdio.h>
#include "Intro.h"
#include "Choice.h"
#include <Windows.h>

void EnableANSIConsole() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}


int main() {
    EnableANSIConsole();
    while (1) {
        Intro();
        USER_CHOICE();
    }
}