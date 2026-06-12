#include "Dungeon.h"
#include "Map.h"
#include "Character_Menu.h"


int IngameSelect = -1;
char DungeonScene()
{

    while (IngameSelect != 3)
    {
        IngameSelect = MapUI();
        
        if (IngameSelect == 1)
        {
            return 1;
        }
        else if(IngameSelect ==2)
        {
            return 2;
        }
        else if (IngameSelect == 3)
        {
            return 3;
        }


    }
}