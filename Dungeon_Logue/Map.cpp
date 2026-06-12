#include "Main.h"
#include "UI.h"
#include "Event.h"
#include "Character.h"
#include "Utill.h"
#include "Battle.h"
#include "Map.h"



char map[20][100] = {
	{"311111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111114"},
	{"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
	{"2031n1n1n1n1n1n1n1n1400000000000314000000000000031n140000031n1n1n1n1n1n1400000000000000000000000002"},
	{"2020omo?omomo?omo?o8200000000000272000000000000027o820000027o?omo?o?omo8200000003111111111111111402"},
	{"2051h1+o+1+o+1h1h1+oj00031n1n1n1+o+1n1n140000000ko+160000051h1+o+1h1h1+oj00000002000000000000000202"},
	{"2000002m202m2000002m200028omo?omo?o?o?om200000002m2000000000002$2000002?200000002000000000000000202"},
	{"200000koj0koj00000koj00051+o+1h1h1h1h1+o+1n1n1n1+o+1n1n1n1n1n1+o+14000ko+1n1n1n1j0000aaaaaaa0000202"},
	{"2000002?202?2000002m2000002m20000000002?o8Gmo?o?o?omo8omomo?o?omo820002?omomo$o8oe00a0000000a000202"},
	{"200000ko+1+o+1n1n1+o+1n1n1+o+1n1n1n14051+o+1h1h1h1h1+o+1h1h1h1h1h16000ko+1h1h1h1j00a000000000a00202"},
	{"2000002momo?omomomo$o?o?omo?o?omomo720002b20000000002720000000000000002m20000000200a0aa000aa0a00202"},
	{"200000ko+o+1h1h1h1+o+1h1h1h1+o+1h1h16000ko+1n1n1n14051603140000031n140koj0000000200a0aa000aa0a00202"},
	{"2000002mo82000000028200000002?200000000028Gmo?omom200000282000002mo8202m20000000200a000000000a00202"},
	{"200000ko+1600000005160314000ko+1n1n1n1n1+o+1h1h1+oj00000koj0000051+o+1+o+1n1n1n1j000aaaaaaaaa000202"},
	{"2000002m200000000000002820002momo?omo?o?om2000002?20000027200000002momo?omomo$o8oe000a0a0a0a0000202"},
	{"200031+o+1n1n1n1n1n1n1non1n1+o+1h1h1+o+1h1600000ko+1n1n1+o+1n1n1n1+o+1h1h1h1h1h1j0000a0a0a0a0000202"},
	{"200027o8omo?omomomo?omo?omomom20000028200000000028omomo?o?o?omo$omo?20000000000020000aaaaaaa0000202"},
	{"200051h1h1h1h1h1h1h1h1h1h1h1h160000051600000000051h1h1h1h1h1h1h1h1h16000000000002000000000000000202"},
	{"200000000000000000000000000000000000000000000000000000000000000000000000000000005111111111111111602"},
	{"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
	{"511111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111116"}
	

};

char Playermap[20][100] = {
    {"311111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111114"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"},
    {"511111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111116"}


};

int PlayerDontMove(int PlayerLocatition)
{
    if (PlayerLocatition == '1' || PlayerLocatition == '2' || PlayerLocatition == '3' || PlayerLocatition == '4' || PlayerLocatition == '5' || PlayerLocatition == '6' || PlayerLocatition == 'k' || PlayerLocatition == 'j' || PlayerLocatition == 'h' || PlayerLocatition == 'n' || PlayerLocatition == '+'|| PlayerLocatition=='G')
    {
        return 0;
    }
    return 1;
}

bool IsOnEventTile = false;


//중간보스 처치시 열리는 문 G -> o
void OpenMiddleBossDoor()
{
    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 100; x++)
        {
            if (map[y][x] == 'G')
            {
                map[y][x] = 'o';
                Playermap[y][x] = 'o';
            }
        }
    }
}

void DrawMap(int& h, int& w, int& event)
{
    PlayerEnableViewMap();

    for (h = 0; h < 20; h++)
    {
        for (w = 0; w < 100; w++)
        {
            char temp = map[h][w];
            char PlyarTemp = Playermap[h][w];
            if (temp == PlyarTemp)
            {
                if (temp == '1')
                {
                    printf("─");
                }
                else if (temp == '2')
                {
                    printf("│");
                }
                else if (temp == '3')
                {
                    printf("┌");
                }
                else if (temp == '4')
                {
                    printf("┐");
                }
                else if (temp == '5')
                {
                    printf("└");
                }
                else if (temp == '6')
                {
                    printf("┘");
                }
                else if (temp == 'k')
                {
                    printf("├");
                }
                else if (temp == 'j')
                {
                    printf("┤");
                }
                else if (temp == 'h')
                {
                    printf("┴");
                }
                else if (temp == 'n')
                {
                    printf("┬");
                }
                else if (temp == '+')
                {
                    printf("┼");
                }
                else if (temp == 'a')   //보스방 표시용
                {
                    printf("■");
                }
                else if (temp == 'e')    //보스방 입구 표시용
                {
                    SetColor(4);
                    printf("!");
                    SetColor(7);
                    if (h == GPlayer.PlayerY && w == GPlayer.PlayerX)
                    {
                        event = 8;          //최종보스 조우 조건
                        GPlayer.Bossif++;
                    }
                }
                else if (temp == 'b')   //중간보스
                {
                    SetColor(4);
                    printf("!");
                    SetColor(7);
                    if (h == GPlayer.PlayerY && w == GPlayer.PlayerX)
                    {
                        event = 7;          //중간보스 조우 조건
                        GPlayer.Bossif++;
                        
                        map[h][w] = '0';
                    }
                }
                else if (temp == '7')   //보물상자
                {
                    SetColor(6);
                    printf("θ");
                    SetColor(7);
                    if (h == GPlayer.PlayerY && w == GPlayer.PlayerX)
                    {
                        event = 5;          //보물상자 조우 조건
                        map[h][w] = 'c';
                    }
                }
                else if (temp == 'c')   //열린보물상자
                {
                    SetColor(6);
                    printf("Ф");
                    SetColor(7);
                }
                else if (temp == '8')   //회복샘
                {
                    SetColor(10);
                    printf("∀");
                    SetColor(7);

                    if (h == GPlayer.PlayerY && w == GPlayer.PlayerX && IsOnEventTile == false)
                    {
                        event = 4;          //회복샘 조우 조건
                        IsOnEventTile = true;
                    }

                }
                else if (temp == 'm')   //확정 몬스터
                {
                    printf("M");
                    if (h == GPlayer.PlayerY && w == GPlayer.PlayerX)
                    {
                        event = 1;          //몬스터 조우 조건
                        map[h][w] = '0';
                    }
                }
                else if (temp == '?')   //랜덤이벤트(플레이어 강화 OR 약화 OR 돈획득 OR 몬스터 조우)
                {
                    SetColor(5);
                    printf("?");
                    SetColor(7);
                    if (h == GPlayer.PlayerY && w == GPlayer.PlayerX)
                    {
                        event = 2;          //랜덤이벤트 조우 조건
                        map[h][w] = '0';
                    }
                }
                else if (temp == '$')   //상점
                {
                    SetColor(14);
                    printf("$");
                    SetColor(7);
                    if (h == GPlayer.PlayerY && w == GPlayer.PlayerX)
                    {
                        event = 3;          //상점이벤트 조우 조건
                        map[h][w] = '0';
                    }

                }
                else if (temp == 'G')//중간보스 처치시 열리는 문
                {
                    if (GPlayer.HaveKey == 0)
                    {
                        SetColor(12);
                        printf("│");
                        SetColor(7);
                    }
                    else
                    {
						printf(" ");
                    }
                }
                else if (temp == 'Q')
                {
                    printf("B");
                }
                else if (h == GPlayer.PlayerY && w == GPlayer.PlayerX)
                {
                    SetColor(11);
                    printf("P");
                    SetColor(7);
                }
                else if (temp == '0' || temp == 'o')
                {
                    printf(" ");
                }
            }
            else
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }
}

void PlayerEnableViewMap()
{
    const int PlayerView = 2;
    int PlayerMaxViewX = GPlayer.PlayerX + PlayerView;
    int PlayerMinViewX = GPlayer.PlayerX - PlayerView;
    int PlayerMaxViewY = GPlayer.PlayerY + PlayerView;
    int PlayerMinViewY = GPlayer.PlayerY - PlayerView;
    for (int i = PlayerMinViewY; i <= PlayerMaxViewY; i++)
    {
        for (int j = PlayerMinViewX; j <= PlayerMaxViewX; j++)
        {
            char PlayerViewTemp = map[i][j];
            if (Playermap[i][j] != map[i][j])
            {
                Playermap[i][j] = map[i][j];
            }
        }
    }
}

int MapUI() {
	system("cls");
	int h=0, w=0;		//세로,가로
    char Selectkey;
    if (GPlayer.Health<=0)
    {
        Selectkey = '3';
        return 3;
    }
    
    if (GPlayer.Health > GPlayer.MaxHealth)
    {
		GPlayer.Health = GPlayer.MaxHealth;
    }
    if (GPlayer.Mana > GPlayer.MaxMana)
    {
        GPlayer.Mana = GPlayer.MaxMana;
    }


    PrintPlayerState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana, GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense, GPlayer.Money);


    int PlayerLocatition = map[GPlayer.PlayerY][GPlayer.PlayerX];
    int event = -1;
    int RandomEventChance = -2;
    

    

    DrawMap(h, w, event);


    drawCharMenu();
    switch (event)
    {
    case 1: //몬스터 조우 이벤트
        Monster_Event_Encounter(GPlayer.MonsterLevel,0);
        GPlayer.MonsterLevel++;
        event = -1;
        return 0;
    case 2: //랜덤 조우 이벤트
        Random_Event_Encounter();
        event = -1;
        return 0;
    case 3: //상점 조우 이벤트
        Shop_Event_Encounter();
        event = -1;
        return 0;
    case 4: //회복샘 조우 이벤트
        if (Healspot_Event_Encounter() == 1)
        {
            map[GPlayer.PlayerY][GPlayer.PlayerX] = '0';
        }
        event = -1;
        return 0;
    case 5: //보물상자 조우 이벤트
        Chest_Event_Encounter();
        event = -1;
        return 0;
    case 7: //중간보스 조우 이벤트
        Middle_Boss_Encounter();
        event = -1;
        return 0;
    case 8: //최종보스 조우 이벤트
        Boss_Encounter();
        event = -1;
        Dungeon_Clear();
		return 3;
    }

    //플레이어 조작
    Selectkey = _getch();
    while (true)
    {
        if (Selectkey == 'x' || Selectkey == 'X')
        {
            // ==================== 캐릭터 메뉴 모드 ====================
            int Selected = 0;
            bool InMenu = true;

            
            while (InMenu)
            {
                system("cls");  // 메뉴 모드에서는 전체 화면을 새로 그려서 겹침 방지

                PrintPlayerState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana,
                    GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense, GPlayer.Money);

                DrawMap(h, w, event);

                printf("\n");
                drawCharMenuWithSelection(Selected);

                Selectkey = _getch();

                if (Selectkey == 72)        // ↑
                {
                    Selected = (Selected + 1) % 2;
                }
                else if (Selectkey == 80)   // ↓
                {
                    Selected = (Selected + 1) % 2;
                }
                else if (Selectkey == 'z'|| Selectkey == 'Z')//선택
                {
                    system("cls");
                    if (Selected == 0)
                    {
                        bool InStatusMenu = true;
                        int Statusselected = 0;
                        while (InStatusMenu)
                        {
                            
                            InStatusMenu = PrintPlayerStatus(Statusselected);

                        }
                        InStatusMenu = true; //스테이터스 메뉴에서 나와도 다시 캐릭터 메뉴로 돌아가기 위해 true로 초기화
                    }
                    else if (Selected == 1)
                    {
                        Selectkey = '3';
                        return 3;
                    }
					
					

                }
                else if (Selectkey == 'x' || Selectkey == 'X' || Selectkey == 27) // ESC 또는 x 다시 누르면 종료
                {
                    InMenu = false;
                }
            }

            // 메뉴 종료 후 다시 drawMap 루프를 타기 위해 break
            break;
        }
        else if (Selectkey == 72)            //위
        {

            if (GPlayer.PlayerY > 1 && GPlayer.PlayerY < 18)
            {
                GPlayer.PlayerY--;
            }
            PlayerLocatition = map[GPlayer.PlayerY][GPlayer.PlayerX];
            if (PlayerDontMove(PlayerLocatition) == 0)
            {
                GPlayer.PlayerY++;
            }
            PlayerLocatition = map[GPlayer.PlayerY][GPlayer.PlayerX];
            IsOnEventTile = false;
            break;

        }
        else if (Selectkey == 80)       //아래
        {

            if (GPlayer.PlayerY > 1 && GPlayer.PlayerY < 18)
            {
                GPlayer.PlayerY++;
            }
            PlayerLocatition = map[GPlayer.PlayerY][GPlayer.PlayerX];
            if (PlayerDontMove(PlayerLocatition) == 0)
            {
                GPlayer.PlayerY--;
            }
            PlayerLocatition = map[GPlayer.PlayerY][GPlayer.PlayerX];
            IsOnEventTile = false;
            break;
        }
        else if (Selectkey == 75)       //왼
        {
            if (GPlayer.PlayerX > 1 && GPlayer.PlayerX < 98)
            {
                GPlayer.PlayerX--;
            }
            PlayerLocatition = map[GPlayer.PlayerY][GPlayer.PlayerX];
            if (PlayerDontMove(PlayerLocatition) == 0)
            {
                GPlayer.PlayerX++;
            }
            PlayerLocatition = map[GPlayer.PlayerY][GPlayer.PlayerX];
            IsOnEventTile = false;
            break;
        }
        else if (Selectkey == 77)       //오
        {
            if (GPlayer.PlayerX > 1 && GPlayer.PlayerX < 98)
            {
                GPlayer.PlayerX++;
            }
            PlayerLocatition = map[GPlayer.PlayerY][GPlayer.PlayerX];
            if (PlayerDontMove(PlayerLocatition) == 0)
            {
                GPlayer.PlayerX--;
            }
            PlayerLocatition = map[GPlayer.PlayerY][GPlayer.PlayerX];
            IsOnEventTile = false;
            break;
        }
        else
        {
            Selectkey = _getch();
        }
    }


    if (event == -1)   //이동한 칸에 이벤트가 없을 때, 3% 확률로 랜덤 이벤트 발생
    {
        RandomEventChance = GetRandomRange(1, 100);
        if (RandomEventChance <= 3 && event == -1) //맵 이동시 3% 확률로 랜덤 이벤트 발생
        {
            Random_Encounter(PlayerLocatition);
            return 0;
        }
    }


    
}

