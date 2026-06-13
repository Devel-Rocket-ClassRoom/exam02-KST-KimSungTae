#define _CRT_SECURE_NO_WARNINGS
#include "Main.h"
#include "Main_Menu.h"
#include "Dungeon.h"
#include "Map.h"
#include "Art.h"

using namespace std;


Player GPlayer;



int main()
{
    srand((unsigned)time(0));
    // wt.exe로 실행된 게 아니면 → wt 최대화로 재실행 후 기존 창 숨기기/종료
    if (GetEnvironmentVariableA("WT_SESSION", NULL, 0) == 0) {
        char exePath[MAX_PATH];
        GetModuleFileNameA(NULL, exePath, MAX_PATH);

        char workDir[MAX_PATH];
        GetCurrentDirectoryA(MAX_PATH, workDir);

        // launcher 창을 최대한 빠르게 숨김
        HWND hwnd = GetConsoleWindow();
        if (hwnd) ShowWindow(hwnd, SW_HIDE);

        std::string cmd = "wt.exe --maximized -d \"" + std::string(workDir) +
            "\" cmd /c \"" + std::string(exePath) + "\"";
        system(cmd.c_str());

        return 0;  // launcher 창 종료
    }

    PlayBGM("Main_BGM", 140);

    int MenuSelect=-1;
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
            PrintHelp();
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

