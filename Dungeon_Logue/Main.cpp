#define _CRT_SECURE_NO_WARNINGS
#include "Main.h"
#include "Main_Menu.h"
#include "Dungeon.h"
#include "Map.h"

using namespace std;


Player GPlayer;



int main()
{
    // wt.exe로 실행된 게 아니면 → wt 최대화로 재실행 후 기존 창 숨기기/종료
    if (GetEnvironmentVariableA("WT_SESSION", NULL, 0) == 0) {
        char exePath[MAX_PATH];
        GetModuleFileNameA(NULL, exePath, MAX_PATH);

        // launcher 창을 최대한 빠르게 숨김
        HWND hwnd = GetConsoleWindow();
        if (hwnd) ShowWindow(hwnd, SW_HIDE);

        std::string cmd = "wt.exe --maximized cmd /c \"" + std::string(exePath) + "\"";
        system(cmd.c_str());

        return 0;  // launcher 창 종료
    }


	GPlayer.PlayerX = 3;
	GPlayer.PlayerY = 3;
    GPlayer.MaxHealth = 3000;
    GPlayer.Health = GPlayer.MaxHealth;
    GPlayer.MaxMana = 50;
	GPlayer.Mana = GPlayer.MaxMana;
    GPlayer.AttackPowerMin = 15;
    GPlayer.AttackPowerMax = 115;
    GPlayer.Defense = 5;
    GPlayer.Money = 1000;
	GPlayer.CriticalChance = 10;
	GPlayer.Luck = 0;
	GPlayer.Skill1 = 0;
	GPlayer.Skill2 = 0;
	GPlayer.Skill3 = 0;
	GPlayer.MonsterLevel = -1;
    GPlayer.Level = 1;
    GPlayer.Experience = 0;
    GPlayer.ExperienceToNextLevel = 1;
    GPlayer.StatPoints = 0;
	GPlayer.Bossif = 0;
    GPlayer.HaveKey = 0;

    int MenuSelect=-1;
    //initScreen();
    while (MenuSelect!=1)
    {
        MenuSelect = MenuDraw(MenuSelect);
        if (MenuSelect == 0)
        {
            break;
        }
    }
    if (MenuSelect == 1)
    {
        MenuSelect = DungeonScene();
        if (MenuSelect == 3)
        {
			if (GPlayer.Health <= 0)//추후 UI를 좀더 꾸밀것********
            {
                system("cls");
                printf("플레이어가 패배했습니다. 게임 오버.\n");
                Sleep(_getch());
            }
            else
            {
                system("cls");
                printf("게임을 종료합니다.\n");
                return 0;
            }
        }

    }
    
}