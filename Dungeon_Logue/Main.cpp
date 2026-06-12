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
        system("cls");
        MenuSelect = MenuDraw(MenuSelect);
        if (MenuSelect == 0)
        {
            
            printf("게임을 종료합니다.\n");
            Sleep(_getch());
            break;
        }
        else if(MenuSelect==2)
        {
            system("cls");

            //도움말 페이지
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("플레이어의 이동 및 선택지 선택이동 : 방향키(→, ←, ↑, ↓)\n");
            printf("\n");
			printf("캐릭터 메뉴 : X키\n");
            printf("\n");
            printf("메뉴 및 선택지 선택 : Z키\n");
            printf("\n");
            printf("\n");
            printf("\n");
            SetColor(11);
            printf("'P' : 플레이어\n");
            printf("\n");
            SetColor(7);
            printf("'M' : 몬스터\n");
            printf("\n");
            SetColor(5);
			printf("'?' : 랜덤 이벤트\n");
            printf("\n");
            SetColor(14);
			printf("'$' : 상점\n");
            printf("\n");
			SetColor(10);
			printf("'H' : 회복샘\n");
            printf("\n");
			SetColor(6);
			printf("'θ' : 보물상자\n");
            printf("'Ф' : 열린 보물상자\n");
            printf("\n");
            SetColor(4);
			printf("'!' : 중간보스 & 최종보스\n");
            printf("\n");
            SetColor(12);
            printf("'│' : 중간보스 처치시 열리는 문\n");
            printf("\n");
            SetColor(7);
            printf("\n");
            printf("\n");

            printf("\n");
			printf("목표 : 몬스터를 처치하고, 이벤트와 상점을 통해 플레이어를 강화하여 최종보스를 처치하는 것입니다.\n");
            printf("행운을 빕니다.\n");
            printf("\n");
            printf("\n");
            printf("\n계속 하려면 아무키나 누르세요.\n");
            Sleep(_getch());
        }
    }
    if (MenuSelect == 1)
    {
        MenuSelect = DungeonScene();
        if (MenuSelect == 3)
        {
			if (GPlayer.Health <= 0)
            {
                system("cls");
                PrintGameOver();
                Sleep(_getch());
            }
            else
            {
                system("cls");
                printf("게임을 종료합니다.\n");
                Sleep(_getch());
                return 0;
            }
        }

    }
    
}