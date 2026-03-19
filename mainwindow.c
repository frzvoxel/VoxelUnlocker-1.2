#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include "pages.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13

void gotoxy(int x, int y) {
	COORD cursor = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void setcolor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void draw_window(int selected ) {
    system("cls");

    char* items[] = { "Clean Startup", "Exit" };
    int count = 2;
    gotoxy(46, 9); setcolor(11); printf(" ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
    gotoxy(47, 10); setcolor(11); printf("┃       VoxelUnlocker       ┃");
    gotoxy(47, 11); setcolor(11); printf("┃           1.1             ┃");
    gotoxy(47, 12); setcolor(11); printf("┃———————————————————————————┃");
    gotoxy(47, 13); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 14); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 15); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 16); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 17); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 18); setcolor(11); printf("╰━━━━━━━━━━━━━━━━━━━━━━━━━━━╯");

    for (int i = 0; i < count; i++) {
        gotoxy(53, 14 + i * 2);
        if (i == selected) {
            setcolor(7);       
            printf("> %s ", items[i]);
        }
        else {
            setcolor(7);
            printf("  %s  ", items[i]);
        }
    }
}

int main() {
    SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);
    hideCursor();
    int selected = 0;
    int key;

    while (1) {
        draw_window(selected);
        
        key = getch();

        if (key == 0 || key == 224) {
            key = getch();
            

            switch (key) {
            case KEY_UP:
                selected = (selected - 1 + 4) % 2;
                break;
            case KEY_DOWN:
                selected =  (selected +  1) % 2;
                break;
            }
        }
        else if (key == ENTER) {
            if (selected == 0) {
                NEXTPAGE_STARTUP();
            }
            if (selected == 1) {
                break;
            }
        }
    }
}