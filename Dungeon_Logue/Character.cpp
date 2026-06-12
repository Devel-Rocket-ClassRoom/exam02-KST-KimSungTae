#include "main.h"
#include "character.h"
#include "Utill.h"
#include "UI.h"



void Player_LevelUp(int Reward)
{
    printf("\n");
    printf("===============================\n");
    printf("Level Up!\n");
    printf("LV.%d -> LV.%d가 되었습니다!\n",GPlayer.Level,GPlayer.Level+1);
    printf("StatusPoint가 3 포인트 지급되었습니다!\n");
    printf("HP와 MP가 10% 회복되었습니다.");
	GPlayer.Health += GPlayer.MaxHealth / 10;
	GPlayer.Mana += GPlayer.MaxMana / 10;
    GPlayer.Experience -= GPlayer.ExperienceToNextLevel;
    GPlayer.ExperienceToNextLevel += 50;
    GPlayer.Level++;
    GPlayer.StatPoints += 3;

}