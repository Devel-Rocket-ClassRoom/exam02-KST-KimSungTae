#include "Main.h"


void PrintPlayerState(int Health, int MaxHealth,int Mana, int MaxMana, int AttackPowerMin, int AttackPowerMax, int Defense, int Money)
{
    printf("┌─────────────────────────────────────────────────────────────────────────────────────────────────┬──────────────┬───────────────┐\n");
    printf("│  HP : [%4d] / [%4d]      MP : [%3d] / [%3d]      Max Damage : [%3d ~ %3d]      Defense : [%2d] │ Luck : [%3d] │ Money : %5d │\n", Health, MaxHealth, Mana, MaxMana, AttackPowerMin, AttackPowerMax, Defense,GPlayer.Luck, Money);
    printf("└─────────────────────────────────────────────────────────────────────────────────────────────────┴──────────────┴───────────────┘\n");
}

void PrintPlayerBattleState(int Health, int MaxHealth, int Mana, int MaxMana, int AttackPowerMin, int AttackPowerMax, int Defense, int Critical)
{
    printf("┌─────────────────────────────────────────────────────────────────────────────────────────────────┬────────────────┐\n");
    printf("│  HP : [%4d] / [%4d]      MP : [%3d] / [%3d]      Max Damage : [%3d ~ %3d]      Defense : [%2d] │ Critical : %3d │\n", Health, MaxHealth, Mana, MaxMana, AttackPowerMin, AttackPowerMax, Defense, Critical);
    printf("└─────────────────────────────────────────────────────────────────────────────────────────────────┴────────────────┘\n");
}

//X키 누를시 선택 메뉴
void drawCharMenuWithSelection(int selected)
{
    printf("1. 스테이터스 창(미분배 스탯 %d) %s\n\n", GPlayer.StatPoints, selected == 0 ? "  <" : "");
    printf("2. 게임 종료 %s\n\n", selected == 1 ? "  <" : "");
    //printf("3. 나가기%s\n", selected == 2 ? "  <" : "");
}

// 단순 메뉴
void drawCharMenu()
{
    drawCharMenuWithSelection(-1);  // 선택 없음
}