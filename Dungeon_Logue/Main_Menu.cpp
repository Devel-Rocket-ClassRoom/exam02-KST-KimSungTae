#include "Main_Menu.h"
#include "Dungeon.h"


void initScreen() {
    system("cls");
}

int MenuDraw(int MenuSelect)
{

    int SelectMenu = 0;
    char Selectkey;

    while (true)
    {
        // 메인 화면 UI 그리기
        printf("=============================\n");
        printf("        Dungeon Logue        \n");
        printf("=============================\n");
        printf("\n");
        printf("\n");
        printf("\n");

        if (SelectMenu == 0)
        {
            printf("        > 게임 시작\n");
        }
        else
        {
            printf("          게임 시작\n");
        }
        if (SelectMenu == 1)
        {
            printf("        > 게임 방법\n");
        }
        else
        {
            printf("          게임 방법\n");
        }

        if (SelectMenu == 2)
        {
            printf("        > 게임 종료\n");
        }
        else
        {
            printf("          게임 종료\n");
        }

        while (true)
        {
            Selectkey = _getch();
            if (Selectkey == 72)    //위 방향키
            {

                SelectMenu = SelectMenu + 3 - 1;
                SelectMenu = SelectMenu % 3;
                initScreen();
                break;
            }
            else if (Selectkey == 80)   //아래 방향키
            {
                SelectMenu = SelectMenu + 3 + 1;
                SelectMenu = SelectMenu % 3;
                initScreen();
                break;
            }
            if (Selectkey == 'z' || Selectkey == 'Z')
            {
                if (SelectMenu == 0)
                {
                    return 1;
                }
                else if (SelectMenu == 1)
                {
                    return 2;
                }
                else if (SelectMenu == 2)
                {
                    return 0;
                }
                
            }
            
        }
        

    }
}