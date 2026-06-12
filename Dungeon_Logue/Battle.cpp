#define _CRT_SECURE_NO_WARNINGS
#include "Battle.h"
#include "main.h"
#include "character.h"
#include "UI.h"
#include "Utill.h"

void NowStatus(int PlayerHP, int EnemyHP)
{
    printf("=========================\n");
    printf("플레이어 HP: %d, 적 HP: %d\n", PlayerHP, EnemyHP);
    printf("=========================\n\n");
    printf("진행하려면 아무키나 입력하세요.\n\n");
    Sleep(_getch());
}

//1		몬스터
void Monster_Event_Encounter(int InLevel, int Bossif)
{
	srand(time(0));
	int randomMonster = GetRandomRange(0, 5);
	char Selectkey;
	int Level = InLevel / 3;
	if (Level < 0)
	{
		Level = 0;
	}

	system("cls");

	MonsterDefault Monster; // Monster 변수를 함수 시작부에 선언

	if (Bossif == 0)
	{
		if (Level == 0)
		{
			Monster = MonsterDefault("오염수 슬라임", 0);
			PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, -1);
		}
		else if (Level == 1)
		{
			Monster = MonsterDefault("고블린 약탈자", Level);
			PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, -1);
		}
		else if (Level == 2)
		{
			Monster = MonsterDefault("하이오크", Level);
			PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, -1);
		}
		else if (Level == 3)
		{
			Monster = MonsterDefault("스켈레톤 나이트", Level);
			PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, -1);
		}
		else if (Level == 4)
		{
			Monster = MonsterDefault("트윈 헤드 오우거", Level);
			PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, -1);
		}
		else if (Level == 5)
		{
			Monster = MonsterDefault("트롤", Level);
			PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, -1);
		}
		else if (Level >= 6)
		{
			if (randomMonster == 0)
			{
				Monster = MonsterDefault("오염수 슬라임", Level);
				PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, randomMonster);
			}
			else if (randomMonster == 1)
			{
				Monster = MonsterDefault("고블린 약탈자", Level);
				PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, randomMonster);
			}
			else if (randomMonster == 2)
			{
				Monster = MonsterDefault("하이오크", Level);
				PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, randomMonster);
			}
			else if (randomMonster == 3)
			{
				Monster = MonsterDefault("스켈레톤 나이트", Level);
				PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, randomMonster);
			}
			else if (randomMonster == 4)
			{
				Monster = MonsterDefault("트윈 헤드 오우거", Level);
				PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, randomMonster);
			}
			else if (randomMonster == 5)
			{
				Monster = MonsterDefault("트롤", Level);
				PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, randomMonster);
			}
		}
	}
	else if (Bossif == 1)
	{
		Monster = MonsterDefault("중간 보스 : 던전 미노타우로스", Level);
		PrintMonster(Level, Monster.Health, Monster.MaxHealth, 1, Monster.Name, -1);
	}
	else if (Bossif == 2)
	{
		Monster = MonsterDefault("최종 보스 : 던전드래곤", Level);
		PrintMonster(Level, Monster.Health, Monster.MaxHealth, 2, Monster.Name, -1);
	}


	int CriticalChance = GPlayer.CriticalChance + GPlayer.Luck;
	int EnemyCriticalChance = Level * 3;
	int BattleTurn = 1;
	bool IsDefending = false;
	bool IsEnemyCritical = rand() % 100 < EnemyCriticalChance;



	printf("%s과(와) 조우했습니다! 전투 시작!\n", Monster.Name.c_str());
	Sleep(_getch());

	while (GPlayer.Health > 0 && Monster.Health > 0)
	{
		int PlayerDamage = GetRandomRange(GPlayer.AttackPowerMin, GPlayer.AttackPowerMax);
		int EnemyDamage = GetRandomRange(Monster.AttackPowerMin, Monster.AttackPowerMax);


		system("cls");
		PrintPlayerBattleState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana,
			GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense,
			GPlayer.CriticalChance + GPlayer.Luck);
		if (Bossif == 0)
		{
			PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, randomMonster);
		}
		else if (Bossif == 1)
		{
			PrintMonster(Level, Monster.Health, Monster.MaxHealth, 1, Monster.Name, -1);
		}
		else if (Bossif == 2)
		{
			PrintMonster(Level, Monster.Health, Monster.MaxHealth, 2, Monster.Name, -1);
		}

		printf("===================== 턴 %d =====================\n", BattleTurn);
		printf("플레이어 HP: %4d / %4d\t<적의 다음 행동>\n", GPlayer.Health, GPlayer.MaxHealth);
		if (Bossif == 0)
		{
			printf("적       HP: %4d / %4d\t%s\n", Monster.Health, Monster.MaxHealth, IsEnemyCritical ? " 치명적인 일격" : "   일반 공격");
		}
		else
		{
			printf("적       HP: %4d / %4d\t\t?\n", Monster.Health, Monster.MaxHealth);
		}
		printf("================================================\n");


		if (BattleTurn % 2 == 1)
		{
			// 플레이어 행동 선택 UI
			int SelectAction = 0;
			while (true)
			{
				// 메뉴 표시
				if (SelectAction == 0) printf("> 1. 공격\n");
				else printf("  1. 공격\n");
				if (SelectAction == 1) printf("> 2. 방어\n");
				else printf("  2. 방어\n");
				if (SelectAction == 2) printf("> 3. 스킬 사용\n");
				else printf("  3. 스킬 사용\n");

				Selectkey = _getch();
				if (Selectkey == 72) {  // 위
					SelectAction = (SelectAction + 2) % 3;
				}
				else if (Selectkey == 80) {  // 아래
					SelectAction = (SelectAction + 1) % 3;
				}
				else if (Selectkey == 'z' || Selectkey == 'Z') {
					break;
				}
				system("cls");
				PrintPlayerBattleState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana, GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense, GPlayer.CriticalChance + GPlayer.Luck);

				if (Bossif == 0)
				{
					PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, randomMonster);
				}
				else if (Bossif == 1)
				{
					PrintMonster(Level, Monster.Health, Monster.MaxHealth, 1, Monster.Name, -1);
				}
				else if (Bossif == 2)
				{
					PrintMonster(Level, Monster.Health, Monster.MaxHealth, 2, Monster.Name, -1);
				}

				printf("===================== 턴 %d =====================\n", BattleTurn);
				printf("플레이어 HP: %4d / %4d\t<적의 다음 행동>\n", GPlayer.Health, GPlayer.MaxHealth);
				if (Bossif == 0)
				{
					printf("적       HP: %4d / %4d\t%s\n", Monster.Health, Monster.MaxHealth, IsEnemyCritical ? " 치명적인 일격" : "   일반 공격");
				}
				else
				{
					printf("적       HP: %4d / %4d\t\t?\n", Monster.Health, Monster.MaxHealth);
				}
				printf("================================================\n");
			}
			if (SelectAction == 0)  // 공격
			{
				if (rand() % 100 < CriticalChance)
				{
					printf("플레이어의 크리티컬 히트! %d의 두배인 %d데미지를 주었음.\n", PlayerDamage, PlayerDamage * 2);
					PlayerDamage *= 2;
				}
				else
				{
					printf("플레이어의 공격 히트! %d의 데미지를 주었음.\n", PlayerDamage);
				}
				Monster.Health -= PlayerDamage;
				BattleTurn++;
				NowStatus(GPlayer.Health, Monster.Health);
			}
			else if (SelectAction == 1)  // 방어
			{
				printf("방어 태세를 취했습니다! 다음 적 공격 데미지가 감소합니다.\n");
				IsDefending = true;
				BattleTurn++;
				NowStatus(GPlayer.Health, Monster.Health);
			}
			else if (SelectAction == 2)  // 스킬 사용
			{

				int SkillMenu = 0;
				bool SkillUsed = false;
				char SkillKey;

				while (true)
				{
					system("cls");
					PrintPlayerBattleState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana,
						GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense,
						GPlayer.CriticalChance + GPlayer.Luck);
					if (Bossif == 0)
					{
						PrintMonster(Level, Monster.Health, Monster.MaxHealth, 0, Monster.Name, randomMonster);
					}
					else if (Bossif == 1)
					{
						PrintMonster(Level, Monster.Health, Monster.MaxHealth, 1, Monster.Name, -1);
					}
					else if (Bossif == 2)
					{
						PrintMonster(Level, Monster.Health, Monster.MaxHealth, 2, Monster.Name, -1);
					}

					printf("===================== 턴 %d (스킬 선택) =====================\n", BattleTurn);
					printf("플레이어 HP: %d / %d\n", GPlayer.Health, GPlayer.MaxHealth);
					printf("적       HP: %d / %d\n", Monster.Health, Monster.MaxHealth);
					printf("================================================\n\n");

					// 메뉴 구성: 1. 돌아가기 + 보유한 스킬만 표시
					int menuIndex = 0;

					// 1. 돌아가기 (항상 표시)
					if (SkillMenu == menuIndex) printf("> 1. 돌아가기\n");
					else                        printf("  1. 돌아가기\n");
					menuIndex++;

					// 2. 맹렬한 참격 (Skill1)
					if (GPlayer.Skill1 == 1)
					{
						if (SkillMenu == menuIndex) printf("> 2. 맹렬한 참격 (데미지 2배 / MP30)\n");
						else                        printf("  2. 맹렬한 참격 (데미지 2배 / MP30)\n");
						menuIndex++;
					}

					// 3. 예리한 일격 (Skill2)
					if (GPlayer.Skill2 == 1)
					{
						if (SkillMenu == menuIndex) printf("> 3. 예리한 일격 (최대 데미지 1.5배 / MP20)\n");
						else                        printf("  3. 예리한 일격 (최대 데미지 1.5배 / MP20)\n");
						menuIndex++;
					}

					// 4. 흡혈의 일격 (Skill3)
					if (GPlayer.Skill3 == 1)
					{
						if (SkillMenu == menuIndex) printf("> 4. 흡혈의 일격 (피해 50%% 회복 / MP25)\n");
						else                        printf("  4. 흡혈의 일격 (피해 50%% 회복 / MP25)\n");
						menuIndex++;
					}

					// 방향키 및 선택 처리
					SkillKey = _getch();
					if (SkillKey == 72) // 위
					{
						SkillMenu = (SkillMenu + menuIndex - 1) % menuIndex;
					}
					else if (SkillKey == 80) // 아래
					{
						SkillMenu = (SkillMenu + 1) % menuIndex;
					}
					else if (SkillKey == 'z' || SkillKey == 'Z')
					{
						// 메뉴 인덱스에 따라 행동 결정
						int currentMenu = 0;

						// 1. 돌아가기
						if (SkillMenu == currentMenu)
						{
							// 턴 유지하고 메인 메뉴로 복귀
							break;
						}
						currentMenu++;

						// 2. 맹렬한 참격
						if (GPlayer.Skill1 == 1)
						{
							if (SkillMenu == currentMenu)
							{
								if (GPlayer.Mana < 30)
								{
									printf("\n마나가 부족합니다! (필요 MP: 30)\n");
									Sleep(_getch());
								}
								else
								{
									GPlayer.Mana -= 30;

									int minDmg = GPlayer.AttackPowerMin * 2;
									int maxDmg = GPlayer.AttackPowerMax * 2;
									int skillDamage = GetRandomRange(minDmg, maxDmg);

									printf("\n[맹렬한 참격!] MP 30 소모! %d ~ %d 데미지로 %d의 피해를 입혔습니다!\n",
										minDmg, maxDmg, skillDamage);
									Monster.Health -= skillDamage;
									SkillUsed = true;
								}
							}
							currentMenu++;
						}

						// 3. 예리한 일격
						if (GPlayer.Skill2 == 1)
						{
							if (SkillMenu == currentMenu)
							{
								if (GPlayer.Mana < 20)
								{
									printf("\n마나가 부족합니다! (필요 MP: 20)\n");
									Sleep(_getch());
								}
								else
								{
									GPlayer.Mana -= 20;

									int baseMax = GPlayer.AttackPowerMax;
									int skillDamage = (int)(baseMax * 1.5f);

									printf("\n[예리한 일격!] MP 20 소모! 최대 데미지 기준 1.5배로 %d의 피해를 입혔습니다!\n", skillDamage);
									Monster.Health -= skillDamage;
									SkillUsed = true;
								}
							}
							currentMenu++;
						}

						// 4. 흡혈의 일격
						if (GPlayer.Skill3 == 1)
						{
							if (SkillMenu == currentMenu)
							{
								if (GPlayer.Mana < 25)
								{
									printf("\n마나가 부족합니다! (필요 MP: 25)\n");
									Sleep(_getch());
								}
								else
								{
									GPlayer.Mana -= 25;

									int skillDamage = GetRandomRange(GPlayer.AttackPowerMin, GPlayer.AttackPowerMax);
									int healAmount = skillDamage / 2;

									printf("\n[흡혈의 일격!] MP 25 소모! %d의 피해를 입히고 %d만큼 체력을 회복했습니다!\n",
										skillDamage, healAmount);
									Monster.Health -= skillDamage;
									GPlayer.Health += healAmount;
									if (GPlayer.Health > GPlayer.MaxHealth) GPlayer.Health = GPlayer.MaxHealth;
									SkillUsed = true;
								}
							}
							currentMenu++;
						}

						if (SkillUsed)
						{
							break; // 스킬 사용 후 턴 종료
						}
					}
				}

				if (SkillUsed)
				{
					BattleTurn++;
					NowStatus(GPlayer.Health, Monster.Health);
				}
				// SkillUsed가 false이면 (돌아가기) → 턴 유지, 메인 루프로 복귀
			}

		}
		else
		{
			int BaseDamage = EnemyDamage;

			if (IsEnemyCritical)
			{
				printf("적의 크리티컬 히트! %d의 두배인 %d데미지를 받았음.\n", BaseDamage, BaseDamage * 2);
				IsEnemyCritical = rand() % 100 < EnemyCriticalChance;
				BaseDamage *= 2;
			}
			else
			{
				printf("적의 공격 히트! %d의 데미지를 받았음.\n", BaseDamage);
				IsEnemyCritical = rand() % 100 < EnemyCriticalChance;
			}

			// 방어력 적용 + 방어 상태(방어 선택 시) 보너스
			int FinalDamage = BaseDamage - GPlayer.Defense;
			if (IsDefending)
			{
				FinalDamage = FinalDamage / 2;
			}
			if (FinalDamage < 0) FinalDamage = 0;

			// 사용자 친화적 데미지 출력
			if (GPlayer.Defense > 0 || IsDefending)
			{
				printf("  → 방어력 %d 적용", GPlayer.Defense);
				if (IsDefending) printf(" + 방어 태세(감소된 데미지의 50%% 감소)");
				printf(" → 실제 받은 데미지: %d\n", FinalDamage);
			}

			GPlayer.Health -= FinalDamage;
			IsDefending = false;  // 방어 효과 1회 소모

			GPlayer.Mana += FinalDamage / 10; // 받은 데미지의 10%만큼 마나 회복
			if (GPlayer.Mana > GPlayer.MaxMana)
			{
				GPlayer.Mana = GPlayer.MaxMana;
			}

			BattleTurn++;
			NowStatus(GPlayer.Health, Monster.Health);
		}
		if (Monster.Health <= 0 || GPlayer.Health <= 0)
		{
			break;
		}
	}

	if (GPlayer.Health > 0)
	{
		GPlayer.Money += Monster.Reward;
		printf("%s을 물리쳤습니다!\n", Monster.Name.c_str());
		printf("%d골드를 획득 했습니다.\n", Monster.Reward);
		printf("%d의 경험치를 획득했습니다.", (int)(Monster.Reward * 1.5));
		GPlayer.Experience += (int)(Monster.Reward * 1.5);
		if (GPlayer.Experience >= GPlayer.ExperienceToNextLevel)
		{
			while (GPlayer.Experience >= GPlayer.ExperienceToNextLevel)
			{
				Player_LevelUp(Monster.Reward);
			}
		}
		Selectkey = _getch();
	}
	else
	{
		PrintGameOver();
		Sleep(_getch());
	}
}