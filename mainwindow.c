#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include "pages.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13

// Moves console cursor to specified (x, y) position
void gotoxy(int x, int y) {
	COORD cursor = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

// Set Terminal Color Using color varibale
void setcolor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Hide Corsor in terminal
void hideCursor() {
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

// Draws the main menu window with highlighted selected item
void draw_window(int selected ) {
    system("cls");

    char* items[] = { "Clean Startup", "Restore Hosts", "Delete tmp files", "Exit",};
    int count = 4;

    // TUI
    gotoxy(46, 9); setcolor(11); printf(" ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━╮");
    gotoxy(47, 10); setcolor(11); printf("┃       VoxelUnlocker       ┃");
    gotoxy(47, 11); setcolor(11); printf("┃           1.2             ┃");
    gotoxy(47, 12); setcolor(11); printf("┃———————————————————————————┃");
    gotoxy(47, 13); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 14); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 15); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 16); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 17); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 18); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 19); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 20); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 21); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 22); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 23); setcolor(11); printf("┃                           ┃");
    gotoxy(47, 24); setcolor(11); printf("╰━━━━━━━━━━━━━━━━━━━━━━━━━━━╯");
    // TUI

    // check selected??
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

// entry point
int main() {
    SetConsoleOutputCP(65001); // change the encoding of the terminal 
    SetConsoleCP(65001);  // change the encoding of the terminal 
    hideCursor(); // hide cursor
    int selected = 0; // currently highlighted menu item index
    int key; // user input 

    while (1) {
        draw_window(selected); // call draw window
        
        key = getch(); // get user input

        if (key == 0 || key == 224) {
            key = getch(); // get user input
            

            switch (key) {
            case KEY_UP:
                selected = (selected - 1 + 4) % 4;
                break;
            case KEY_DOWN:
                selected =  (selected +  1) % 4;
                break;
            }
        }
        else if (key == ENTER) {
            if (selected == 0) {
                NEXTPAGE_STARTUP();
            }
            if (selected == 1) {
                hosts_page();
            }

            if (selected == 2) {
                tmp_page();
            }

            if (selected == 3) {
                break;
            }
        }
    }
}