#include "Dungeon.h"
#include "Map.h"
#include "UI.h"


int DungeonScene()
{
    int IngameSelect = -1;

    while (IngameSelect != 3)
    {
        IngameSelect = MapUI();
        
        if (IngameSelect == 1)
            return 1;
        else if(IngameSelect ==2)
            return 2;
        else if (IngameSelect == 3)
            return 3;
    }
    return 3;
}