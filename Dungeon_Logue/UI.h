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
bool PrintPlayerStatus(int& Statusselected);
void PrintMonsterHealthBar(int current, int maxHP, std::string Name);
void PrintPlayerEXPbar(int currentEXP, int maxEXP, int Level);