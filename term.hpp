#pragma once
#include "windows.h"

namespace term
{
    const int margin = 8;
    const int menuWidth = 54;
    const int windowWidth = 70;
    const int windowHeight = 21;

    const int foregroundBlack = 0;
    const int backgroundBlack = 0;
    const int foregroundWhite = (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    const int backgroundWhite = (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

    const int normalColor = (foregroundWhite | backgroundBlack);
    const int highlightColor = (foregroundBlack | backgroundWhite);

    const int keyUp = 72;
    const int keyDown = 80;
    const int keyEnter = 13;

    extern HANDLE console;
    extern COORD cursor;
    extern SMALL_RECT windowRect;


    void hideCursor(void);
    void showCursor(void);
    void moveCursor(short X, short Y);
    void setTextHighlight(void);
    void setTextNormal(void);
}