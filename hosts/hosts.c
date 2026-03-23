#include "../pages/pages.h"
#include <stdio.h>
#include <Windows.h>
#include "../Intro/Intro.h"

void hosts_page() {
    Intro();
    const char* defaultHosts =
        "# Copyright (c) 1993-2009 Microsoft Corp.\r\n"
        "#\r\n"
        "# This is a sample HOSTS file...\r\n"
        "\r\n"
        "127.0.0.1       localhost\r\n"
        "::1             localhost\r\n";

    FILE* f = fopen("C:\\Windows\\System32\\drivers\\etc\\hosts", "w");
    if (f) {
        fprintf(f, "%s", defaultHosts);
        fclose(f);
        printf("Hosts restored :D \n");

        Sleep(1000);
        
        return;
    }
    else {
        printf("No write permissions (run as administrator?)\n");
    }
}