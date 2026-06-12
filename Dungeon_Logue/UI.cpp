#include "Main.h"
#include "UI.h"
#include "Utill.h"



void PrintPlayerState(int Health, int MaxHealth,int Mana, int MaxMana, int AttackPowerMin, int AttackPowerMax, int Defense, int Money)
{
    printf("┌─────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│  HP : [%4d] / [%4d]      MP : [%3d] / [%3d]      Max Damage : [%3d ~ %3d]      Defense : [%2d] │\n", Health, MaxHealth, Mana, MaxMana, AttackPowerMin, AttackPowerMax, Defense);
    printf("├───────────────┬─────────────────────────────────────────────────────────────────┬───────────────┤\n");
    printf("│  Luck : [%3d] │     ", GPlayer.Luck);
    PrintPlayerEXPbar(GPlayer.Experience,GPlayer.ExperienceToNextLevel,GPlayer.Level);
    printf("  │ Money : %5d │\n", Money);
    printf("└───────────────┘                                                                 └───────────────┘\n");
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

bool PrintPlayerStatus(int& Statusselected)
{
    system("cls");
    PrintPlayerState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana,
        GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense, GPlayer.Money);
    printf("\n");
    printf("스탯 포인트가 %d개 남았습니다.\n", GPlayer.StatPoints);
    printf("1. 현재, 최대 체력 +10 (필요 스탯 포인트: 1) %s\n\n", Statusselected == 0 ? "  <" : "");
    printf("2. 최소, 최대 공격력 +1 (필요 스탯 포인트: 1) %s\n\n", Statusselected == 1 ? "  <" : "");
    printf("3. 방어력 +1 (필요 스탯 포인트: 1) %s\n\n", Statusselected == 2 ? "  <" : "");
    printf("4. 마나 +10 (필요 스탯 포인트: 1) %s\n\n", Statusselected == 3 ? "  <" : "");
    printf("4. 럭 +1 (필요 스탯 포인트: 1) %s\n\n", Statusselected == 4 ? "  <" : "");
    printf("6. 돌아가기(또는 X키) %s\n\n", Statusselected == 5 ? "  <" : "");

    char StatusSelectkey = _getch();
    if (StatusSelectkey == 72)        // ↑
    {
        Statusselected = (Statusselected + 5) % 6;
    }
    else if (StatusSelectkey == 80)   // ↓
    {
        Statusselected = (Statusselected + 7) % 6;
    }
    else if (StatusSelectkey == 'z' || StatusSelectkey == 'Z')//선택
    {
        if (Statusselected == 5)
        {
            return false; // 돌아가기 선택 시 false 반환
        }

        if (GPlayer.StatPoints > 0)
        {
            if (Statusselected == 0)
            {
                GPlayer.StatPoints -= 1; // 스탯 포인트 차감
                GPlayer.Health += 10;
                GPlayer.MaxHealth += 10;
				printf("현재, 최대 체력이 10 증가했습니다!\n");
                Sleep(_getch());
            }
            else if (Statusselected == 1)
            {
                GPlayer.StatPoints -= 1; // 스탯 포인트 차감
                GPlayer.AttackPowerMin += 1;
                GPlayer.AttackPowerMax += 1;
				printf("최소, 최대 공격력이 1 증가했습니다!\n");
                Sleep(_getch());
            }
            else if (Statusselected == 2)
            {
                GPlayer.StatPoints -= 1; // 스탯 포인트 차감
                GPlayer.Defense += 1;
				printf("방어력이 1 증가했습니다!\n");
                Sleep(_getch());
            }
            else if (Statusselected == 3)
            {
                GPlayer.StatPoints -= 1; // 스탯 포인트 차감
                GPlayer.Mana += 10;
                GPlayer.MaxMana += 10;
				printf("현재, 최대 마나가 10 증가했습니다!\n");
                Sleep(_getch());

            }
            else if (Statusselected == 4)
            {
                GPlayer.StatPoints -= 1; // 스탯 포인트 차감
				GPlayer.Luck += 1;
				printf("럭이 1 증가했습니다!\n");
                Sleep(_getch());
            }

        }
        else
        {
            printf("스탯 포인트가 부족합니다!\n");
            Sleep(_getch());
            return true; // 스탯 포인트 부족 시 메뉴 유지
        }
		

    }
    else if (StatusSelectkey == 'x' || StatusSelectkey == 'X' || StatusSelectkey == 27) // ESC
    {
        return false;
    }
    return true;
}


void PrintMonsterHealthBar(int current, int maxHP, std::string Name)
{
    if (maxHP <= 0) maxHP = 1;
    int barWidth = 30;  // 바 길이 (조정 가능)
    float percent = (float)current / maxHP;
    int filled = (int)(percent * barWidth);

    if (GPlayer.Bossif >= 1)
    {
        SetColor(4);
    }
    else
    {
        SetColor(6);
    }
    printf("%s HP: ", Name.c_str());
    printf("[");
    for (int i = 0; i < barWidth; i++)
    {
        if (i < filled)
            printf("█");      // 채워진 부분
        else
            printf("░");      // 빈 부분
    }
    printf("] %d / %d  (%.0f%%)", current, maxHP, percent * 100);
    SetColor(7);

    if (percent <= 0.3f) SetColor(12);      // 빨강
    else if (percent <= 0.6f) SetColor(14); // 노랑
    printf("\n");
    SetColor(7);
}

void PrintPlayerEXPbar(int currentEXP, int maxEXP, int Level)
{
    if (maxEXP <= 0) maxEXP = 1;
    int barWidth = 30;  // 바 길이 (조정 가능)
    float percent = (float)currentEXP / maxEXP;
    int filled = (int)(percent * barWidth);

    printf("LV.%2d: ", Level);
    SetColor(10);
    printf("[");
    for (int i = 0; i < barWidth; i++)
    {
        if (i < filled)
            printf("█");      // 채워진 부분
        else
            printf("░");      // 빈 부분
    }
    printf("] %4d / %4d  (%2.f%%)", currentEXP, maxEXP, percent * 100);

    SetColor(7);
}
