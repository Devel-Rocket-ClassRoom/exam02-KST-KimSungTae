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

void NowStatus(int PlayerHP, int EnemyHP)
{
    printf("=========================\n");
    printf("플레이어 HP: %d, 적 HP: %d\n", PlayerHP, EnemyHP);
    printf("=========================\n\n");
    printf("진행하려면 아무키나 입력하세요.\n\n");
    Sleep(_getch());
}