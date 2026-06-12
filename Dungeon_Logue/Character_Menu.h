#pragma once 
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
//#include <random>
using namespace std;

void PrintPlayerState(int Health, int MaxHealth, int Mana, int MaxMana, int AttackPowerMin, int AttackPowerMax, int Defense, int Money);
void drawCharMenu();
void PrintPlayerBattleState(int Health, int MaxHealth, int Mana, int MaxMana, int AttackPowerMin, int AttackPowerMax, int Defense, int Critical);
void drawCharMenuWithSelection(int selected);

//if (Selectkey == '3')
//{
//    return 3;
//    break;
//}