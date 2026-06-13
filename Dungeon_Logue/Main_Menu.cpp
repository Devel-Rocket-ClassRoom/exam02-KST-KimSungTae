#include "Main_Menu.h"
#include "Dungeon.h"
#include "Utill.h"



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
            if (Selectkey == KEY_UP||Selectkey == KEY_DOWN)
            {

				SelectMenu = MoveCursor(SelectMenu, 3, Selectkey);
                system("cls");
                break;
            }
            if (IsConfirm(Selectkey))
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

void PrintHelp()
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