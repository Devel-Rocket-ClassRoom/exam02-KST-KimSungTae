#pragma once
#include "main.h"
#include "Utill.h"
#include "Map.h"
#include "Event.h"
using namespace std;

//void PrintSlime();
//void PrintGob();
void PrintNPC();
void PrintMonster(int Level, int CurrentHP, int MaxHP, int Bossif, std::string Name, int RandomMonster);
void PrintChest();
void PrintClear();
void Player_LevelUp(int Reward);
void PrintGameOver();
void PrintEncount(int Pick);




//플레이어 디폴트
struct Player
{
    int PlayerX = 3;
    int PlayerY = 3;
    //std::string Name = "고블린";
    int MaxHealth = 100;
    int Health = 100;
    int AttackPowerMin = 5;
    int AttackPowerMax = 15;
    int CriticalChance = 10;
    int Luck = 0;
    int MaxMana = 100;
    int Mana = 100;
    int Defense = 5;
    int Money = 0;
    int MonsterLevel = -1;
	int Skill1 = 0; //맹렬한 참격 (최소~최대 데미지가 두배로 증가/ EX. 5~15랜덤 데미지라면, 스킬사용시 몬스터에게 10~30사이의 랜덤한 데미지를 줌)
	int Skill2 = 0; //예리한 일격 (최대 데미지 기준 1.5배 데미지를 줌)
	int Skill3 = 0; //흡혈의 일격 (최소~최대 데미지는 그대로지만, 피해량의 50%를 체력으로 회복)
	
    int Level = 1;
	int Experience = 0;
	int ExperienceToNextLevel = 100;
	int StatPoints = 0;

    int Bossif = 0;
    int HaveKey = 0;

};



//몬스터 디폴트
struct MonsterDefault
{
    std::string Name = "고블린";
    int MaxHealth = 100;
    int Health = MaxHealth;
    int AttackPowerMin = 5;
    int AttackPowerMax = 15;
    int Reward = 0;

    

    MonsterDefault()
    {
        MaxHealth = GetRandomRange(50, 100);
		Health = MaxHealth;
        AttackPowerMin = GetRandomRange(3, 7);
        AttackPowerMax = GetRandomRange(8, 12);
        Reward = GetRandomRange(10, 30);
    }
    MonsterDefault(const std::string& InName, int InLevel)
        : Name(InName)
    {
        MaxHealth = GetRandomRange(50, 100);
		Health = MaxHealth;
        AttackPowerMin = GetRandomRange(3, 7);
        AttackPowerMax = GetRandomRange(8, 12);
        Reward = GetRandomRange(10, 30);

        // Level에 따른 강화
        int levelBonus = MaxHealth * InLevel / 2;

        MaxHealth += levelBonus;
        Health += levelBonus;

        AttackPowerMin += (AttackPowerMin * InLevel) / 2;
        AttackPowerMax += (AttackPowerMax * InLevel) / 3;
        if (InLevel > 0)
        {
            Reward *= InLevel;
        }
    }
};