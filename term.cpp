#include "term.hpp"

void term::setTextHighlight(void)
{
    SetConsoleTextAttribute(console, highlightColor);
}

void term::setTextNormal(void)
{
    SetConsoleTextAttribute(console, normalColor);
}

void term::hideCursor(void)
{
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(console, &cursorInfo);
}

void term::showCursor(void)
{
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = true;
    cursorInfo.dwSize = 100;
    SetConsoleCursorInfo(console, &cursorInfo);
}

void term::moveCursor(short X, short Y)
{
    cursor.X = X;
    cursor.Y = Y;
    SetConsoleCursorPosition(console, cursor);
}