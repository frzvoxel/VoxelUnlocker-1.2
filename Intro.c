#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

void Intro() {
    system("cls");

    const char* logo[] = {
        "__   __           _ _   _      _         _",
        "\\ \\ / /____ _____| | | | |_ _ | |___  __| |_____ _ _",
        " \\ V / _ \\ \\ / -_) | |_| | ' \\| / _ \\/ _| / / -_) '_|",
        "  \\_/\\___/_\\_\\___|_|\\___/|_||_|_\\___/\\__|_\\_\\___|_|",
        ""
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; logo[i][j] != '\0'; j++) {
            printf("\033[36m%c\033[0m", logo[i][j]);
            fflush(stdout);
            Sleep(5);  
        }
        printf("\n");
        Sleep(50);  
    }
}