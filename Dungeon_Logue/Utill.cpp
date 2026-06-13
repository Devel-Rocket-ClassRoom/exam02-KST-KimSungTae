#include "Utill.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <fstream>


int GetRandomRange(int Min, int Max)
{
    return Min + rand() % (Max - Min + 1);  // Min ~ Max(양끝 포함)
}

void SetColor(int Color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

bool IsConfirm(int key)
{
    return key == 'Z' || key == 'z';
}

bool IsCancel(int key)
{
    return key == 'X' || key == 'x' || key == KEY_ESC;
}

// 메뉴 선택 커서 이동 (각각, 커서/메뉴갯수/입력받을 변수)
int MoveCursor(int cur, int count, int key)
{
    if(key == KEY_UP)
    {
		return (cur + count - 1) % count;  // 위 방향키: 커서 위치 감소
    }
    else if(key == KEY_DOWN)
    {
        return (cur + 1) % count;  // 아래 방향키: 커서 위치 증가
    }
    return cur;
}