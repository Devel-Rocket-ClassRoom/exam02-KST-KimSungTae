#include "main.h"
#include "character.h"
#include "UI.h"
#include "Map.h"
#include "Event.h"
#include "Utill.h"
#include "Battle.h"
#include "Art.h"



//2		랜덤인카운트
void Random_Event_Encounter()
{
	system("cls");
	printf("랜덤 이벤트를 인카운트 했습니다!\n");
	Sleep(_getch());

	int result = rand() % 13;
	int SelectAction = 0;
	char Selectkey;
	int BenefitRisk = (rand() % 100);
	if (result == 0)//몬스터 인카운터
	{

		int randomStatusPoint = GetRandomRange(3, 5);
		while (true)
		{
			system("cls");
			PrintMonster(0, 0, 0, 0, "Monster.Name", -2);
			printf("떠돌이 몬스터 발견!!\n");
			printf("처치 하시겠습니까?(선택에 따라 스테이터스 포인트를 드립니다.)\n");
			// 메뉴 표시
			if (SelectAction == 0) printf("> 1. 인카운터!\n");
			else printf("  1. 인카운터!\n");
			if (SelectAction == 1) printf("> 2. 체력 아깝다. 도망친다. (기회가 날라갑니다!)\n");
			else printf("  2. 체력 아깝다. 도망친다. (기회가 날라갑니다!)\n");

			Selectkey = _getch();
			if (Selectkey == KEY_UP || Selectkey == KEY_DOWN) 
			{
				SelectAction = MoveCursor(SelectAction, 2, Selectkey);
			}
			else if (IsConfirm(Selectkey)) 
			{
				break;
			}
		}

		if (SelectAction == 0)
		{
			Monster_Event_Encounter(GPlayer.MonsterLevel,0);
			if (GPlayer.Health > 0)
			{
				printf("떠돌이 몬스터를 처치했습니다! 스테이터스 포인트 %d점을 획득했습니다!\n", randomStatusPoint);
				GPlayer.StatPoints += randomStatusPoint;
			}
			else
			{
				printf("떠돌이 몬스터와의 전투에서 패배했습니다. 게임 오버.\n");
				Sleep(_getch());
			}
		}
		else if (SelectAction == 1)
		{
			printf("뭐든지 때가 있는 법이죠!\n");
			printf("탐험을 계속합니다.\n");
		}
	}
	else if (result <= 3 && result > 0)//공격력 증감
	{
		int randomAttack = GetRandomRange(1, 3);
		while (true)
		{
			system("cls");
			PrintEncount(2);
			printf("무거운 무기 강화 재료를 얻었습니다.\n");
			printf("이곳에서 강화 하시겠습니까?(선택에 따라 최대,최소 공격력이 증감합니다.)\n");
			// 메뉴 표시
			if (SelectAction == 0) printf("> 1. 인생은 한방! 강화한다. (성공확률 : (70 + Luck) %)\n");
			else printf("  1. 인생은 한방! 강화한다. (성공확률 : (70 + Luck) %)\n");
			if (SelectAction == 1) printf("> 2. 불길하다. 강화하지않는다.(강화 재료를 버리고 가야합니다.)\n");
			else printf("  2. 불길하다. 강화하지않는다.(강화 재료를 버리고 가야합니다.)\n");

			Selectkey = _getch();
			if (Selectkey == KEY_UP || Selectkey == KEY_DOWN)
			{
				SelectAction = MoveCursor(SelectAction, 2, Selectkey);
			}
			else if (IsConfirm(Selectkey))
			{
				break;
			}

		}

		if (SelectAction == 0)
		{
			int DICEChance = 30 - GPlayer.Luck;
			if(DICEChance<0)
			{
				DICEChance = 0;
			}
			if (BenefitRisk >= DICEChance)
			{
				printf("강화에 성공했습니다!\n");
				printf("플레이어의 최대, 최소 공격력이 %d만큼 증가했습니다.\n", randomAttack);
				GPlayer.AttackPowerMax += randomAttack;
				GPlayer.AttackPowerMin += randomAttack;
			}
			else if (BenefitRisk < DICEChance)
			{
				printf("어이쿠 손이 미끄러졌네!\n");
				printf("플레이어의 최대, 최소 공격력이 %d만큼 감소했습니다.\n", randomAttack);

				GPlayer.AttackPowerMax -= randomAttack;
				if (GPlayer.AttackPowerMax < 2)
				{
					GPlayer.AttackPowerMax = 2;
				}

				GPlayer.AttackPowerMin -= randomAttack;
				if (GPlayer.AttackPowerMin < 1)
				{
					GPlayer.AttackPowerMin = 1;
				}

				if (GPlayer.AttackPowerMin > GPlayer.AttackPowerMax)
				{
					GPlayer.AttackPowerMin = GPlayer.AttackPowerMax;
				}
			}
		}
		else if (SelectAction == 1)
		{
			printf("불길한 마음에 무기를 강화하지않았습니다.\n");
			printf("탐험에 걸림돌이 되는 재료를 버리고 갔습니다.\n");
		}

	}
	else if (result <= 6 && result > 3)//돈 증감
	{
		int randomMoney = GetRandomRange(10, 100);
		while (true)
		{
			system("cls");
			PrintEncount(0);
			printf("땅에 떨어진 금화를 발견했습니다!\n");
			printf("허리를 숙여 가져갈까요?(선택에 따라 가진 소지금이 증감합니다.)\n");
			// 메뉴 표시
			if (SelectAction == 0) printf("> 1. 허리를 숙여 가져간다. (성공확률 : (50 + Luck) %)\n");
			else printf("  1. 허리를 숙여 가져간다. (성공확률 : (50 + Luck) %)\n");
			if (SelectAction == 1) printf("> 2. 황금 보기를 돌같이 하라....(금화를 그냥 지나칩니다.)\n");
			else printf("  2. 황금 보기를 돌같이 하라....(금화를 그냥 지나칩니다.)\n");

			Selectkey = _getch();
			if (Selectkey == KEY_UP || Selectkey == KEY_DOWN)
			{
				SelectAction = MoveCursor(SelectAction, 2, Selectkey);
			}
			else if (IsConfirm(Selectkey))
			{
				break;
			}
		}

		if (SelectAction == 0)
		{
			int DICEChance = 50 - GPlayer.Luck;
			if (DICEChance <= 0)
			{
				DICEChance = 0;
			}
			if (BenefitRisk >= DICEChance)
			{
				printf("다행히 주변에 아무도 없었나 보네요!\n");
				printf("플레이어의 소지금이 %d만큼 증가했습니다.\n", randomMoney);
				GPlayer.Money += randomMoney;
			}
			else if (BenefitRisk < DICEChance)
			{
				printf("아앗! 허리를 숙인사이, 황금 고블린이 소지금을 강탈해 갔습니다!\n");
				printf("플레이어의 소지금이 %d만큼 감소했습니다.\n", randomMoney);

				GPlayer.Money -= randomMoney;
				if (GPlayer.Money <= 0)
				{
					GPlayer.Money = 0;
				}
			}
		}
		else if (SelectAction == 1)
		{
			printf("떨어진 금화를 그냥 지나치다니... 여러의미로 대단하네요!\n");
			printf("탐험을 계속합니다.\n");
		}

	}
	else if (result <= 9 && result > 6)// 럭 증감
	{
		int randomLuck = GetRandomRange(1, 3);
		while (true)
		{
			system("cls");
			PrintEncount(1);
			printf("이세계의 슬롯머신 등장!\n");
			printf("판단은 없는데, 한판 해보시겠습니까?(선택에 따라 LUCK(행운)이 증감합니다.)\n");
			// 메뉴 표시
			if (SelectAction == 0) printf("> 1. 묻고 더블로 가! (성공확률 : (50 + Luck) %)\n");
			else printf("  1. 묻고 더블로 가! (성공확률 : (50 + Luck) %)\n");
			if (SelectAction == 1) printf("> 2. 도박은 좀;; (슬롯머신을 그냥 지나칩니다.)\n");
			else printf("  2. 도박은 좀;; (슬롯머신을 그냥 지나칩니다.)\n");

			Selectkey = _getch();
			if (Selectkey == KEY_UP || Selectkey == KEY_DOWN)
			{
				SelectAction = MoveCursor(SelectAction, 2, Selectkey);
			}
			else if (IsConfirm(Selectkey))
			{
				break;
			}
		}

		if (SelectAction == 0)
		{
			int DICEChance = 50 - GPlayer.Luck;
			if (DICEChance <= 0)
			{
				DICEChance = 0;
			}
			if (BenefitRisk >= DICEChance)
			{
				printf("777! 럭키!!\n");
				printf("플레이어의 LUCK이 %d만큼 증가했습니다.\n", randomLuck);
				GPlayer.Luck += randomLuck;
			}
			else if (BenefitRisk < DICEChance)
			{
				printf("하긴, 이런곳에 떨어져있는게 정상적일린 없겠죠..\n");
				printf("플레이어의 LUCK이 %d만큼 감소했습니다.\n", randomLuck);

				GPlayer.Luck -= randomLuck;
				if (GPlayer.Luck <= 0)
				{
					GPlayer.Luck = 0;
				}
			}
		}
		else if (SelectAction == 1)
		{
			printf("도박은 랜덤공격력으로도 충분하다! 캌 퉤!\n");
			printf("탐험을 계속합니다.\n");
		}

	}
	else if (result <= 12 && result > 9)//체력 증감

	{

		int randomhealth = GetRandomRange(10, 50);
		while (true)
		{
			system("cls");
			PrintEncount(4);
			printf("정체를 알 수 없는 영약을 발견!!\n");
			printf("마시겠습니까?(선택에 따라 최대체력이 증감합니다.)\n");
			// 메뉴 표시
			if (SelectAction == 0) printf("> 1. 마신다. (성공확률 : (70 + Luck) %)\n");
			else printf("  1. 마신다. (성공확률 : (70 + Luck) %)\n");
			if (SelectAction == 1) printf("> 2. 안마신다.(기회가 날라갑니다!)\n");
			else printf("  2. 안마신다.(기회가 날라갑니다!)\n");

			Selectkey = _getch();
			if (Selectkey == KEY_UP || Selectkey == KEY_DOWN)
			{
				SelectAction = MoveCursor(SelectAction, 2, Selectkey);
			}
			else if (IsConfirm(Selectkey))
			{
				break;
			}
		}

		if (SelectAction == 0)
		{
			int DICEChance = 30 - GPlayer.Luck;
			if (DICEChance <= 0)
			{
				DICEChance = 0;
			}
			if (BenefitRisk >= DICEChance)
			{
				printf("은은한 활력이 몸에 돕니다!\n");
				printf("플레이어의 현재 체력 및 최대 체력이 %d만큼 증가했습니다.\n", randomhealth);
				GPlayer.MaxHealth += randomhealth;
				GPlayer.Health += randomhealth;
			}
			else if (BenefitRisk < DICEChance)
			{
				printf("크아악! 누가 독약을 넣어놨어!");
				printf("플레이어의 현재 체력 및 최대 체력이 %d만큼 감소했습니다.\n", randomhealth);

				GPlayer.Health -= randomhealth;
				if (GPlayer.Health <= 1)
				{
					GPlayer.Health = 1;
				}

				GPlayer.MaxHealth -= randomhealth;
				if (GPlayer.MaxHealth <= 1)
				{
					GPlayer.MaxHealth = 1;
				}
			}
		}
		else if (SelectAction == 1)
		{
			printf("영약을 마시지 않았습니다. 기회가 날라갑니다!\n");
		}
		}


	Sleep(_getch());
}



//3		상점
int Shop_Event_Encounter()
{
	//system("cls");
	//printf("상점 이벤트를 인카운트 했습니다!\n");
	//Sleep(_getch());

	system("cls");
	PrintNPC();
	int Select_NPC_Menu = 0;

	printf("상점에 방문하였습니다.\n");
	Sleep(_getch());

	while (Select_NPC_Menu != -1)
	{
		if (Select_NPC_Menu == 0)
		{
			system("cls");
			PrintPlayerState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana, GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense, GPlayer.Money);
			PrintNPC();
			printf(" > 1. 체력 30 추가(50골드)      \t2. 공격력 3 증가(70골드)       \t 3. 방어력 2 증가(90골드)      \t 4. 마나 30 추가(50골드)\n");
			// 5-> 데미지를 2배로 주는 스킬		6->데미지 1.5배 + 항상 최대 데미지 보장	7->데미지 1배 + 가한 피해의 50% 회복
			printf("   5. 맹렬한 참격 구매%s       6. 예리한 일격 구매%s   7. 흡혈의 일격%s       8. 나가기  "
				, GPlayer.Skill1 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill2 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill3 == 0 ? "(200골드)  " : "(구매 완료)");
		}
		else if (Select_NPC_Menu == 1)
		{
			system("cls");
			PrintPlayerState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana, GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense, GPlayer.Money);
			PrintNPC();
			printf("   1. 체력 30 추가(50골드)    \t      > 2. 공격력 3 증가(70골드)       \t 3. 방어력 2 증가(90골드)      \t 4. 마나 30 추가(50골드)\n");
			// 5-> 데미지를 2배로 주는 스킬		6->데미지 1.5배 + 항상 최대 데미지 보장	7->데미지 1배 + 가한 피해의 50% 회복
			printf("   5. 맹렬한 참격 구매%s       6. 예리한 일격 구매%s   7. 흡혈의 일격%s       8. 나가기  "
				, GPlayer.Skill1 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill2 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill3 == 0 ? "(200골드)  " : "(구매 완료)");
		}
		else if (Select_NPC_Menu == 2)
		{
			system("cls");
			PrintPlayerState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana, GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense, GPlayer.Money);
			PrintNPC();
			printf("   1. 체력 30 추가(50골드)      \t2. 공격력 3 증가(70골드)       > 3. 방어력 2 증가(90골드)      \t 4. 마나 30 추가(50골드)\n");
			// 5-> 데미지를 2배로 주는 스킬		6->데미지 1.5배 + 항상 최대 데미지 보장	7->데미지 1배 + 가한 피해의 50% 회복
			printf("   5. 맹렬한 참격 구매%s       6. 예리한 일격 구매%s   7. 흡혈의 일격%s       8. 나가기  "
				, GPlayer.Skill1 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill2 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill3 == 0 ? "(200골드)  " : "(구매 완료)");
		}
		else if (Select_NPC_Menu == 3)
		{
			system("cls");
			PrintPlayerState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana, GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense, GPlayer.Money);
			PrintNPC();
			printf("   1. 체력 30 추가(50골드)      \t2. 공격력 3 증가(70골드)       \t 3. 방어력 2 증가(90골드)      > 4. 마나 30 추가(50골드)\n");
			// 5-> 데미지를 2배로 주는 스킬		6->데미지 1.5배 + 항상 최대 데미지 보장	7->데미지 1배 + 가한 피해의 50% 회복
			printf("   5. 맹렬한 참격 구매%s       6. 예리한 일격 구매%s   7. 흡혈의 일격%s       8. 나가기  "
				, GPlayer.Skill1 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill2 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill3 == 0 ? "(200골드)  " : "(구매 완료)");
		}
		else if (Select_NPC_Menu == 4)
		{
			system("cls");
			PrintPlayerState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana, GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense, GPlayer.Money);
			PrintNPC();
			printf("   1. 체력 30 추가(50골드)      \t2. 공격력 3 증가(70골드)       \t 3. 방어력 2 증가(90골드)      \t 4. 마나 30 추가(50골드)\n");
			// 5-> 데미지를 2배로 주는 스킬		6->데미지 1.5배 + 항상 최대 데미지 보장	7->데미지 1배 + 가한 피해의 50% 회복
			printf(" > 5. 맹렬한 참격 구매%s       6. 예리한 일격 구매%s   7. 흡혈의 일격%s       8. 나가기  "
				,GPlayer.Skill1==0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill2 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill3 == 0 ? "(200골드)  " : "(구매 완료)");
		}
		else if (Select_NPC_Menu == 5)
		{
			system("cls");
			PrintPlayerState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana, GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense, GPlayer.Money);
			PrintNPC();
			printf("   1. 체력 30 추가(50골드)      \t2. 공격력 3 증가(70골드)       \t 3. 방어력 2 증가(90골드)      \t 4. 마나 30 추가(50골드)\n");
			// 5-> 데미지를 2배로 주는 스킬		6->데미지 1.5배 + 항상 최대 데미지 보장	7->데미지 1배 + 가한 피해의 50% 회복
			printf("   5. 맹렬한 참격 구매%s     > 6. 예리한 일격 구매%s   7. 흡혈의 일격%s       8. 나가기  "
				, GPlayer.Skill1 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill2 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill3 == 0 ? "(200골드)  " : "(구매 완료)");
		}
		else if (Select_NPC_Menu == 6)
		{
			system("cls");
			PrintPlayerState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana, GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense, GPlayer.Money);
			PrintNPC();
			printf("   1. 체력 30 추가(50골드)      \t2. 공격력 3 증가(70골드)       \t 3. 방어력 2 증가(90골드)      \t 4. 마나 30 추가(50골드)\n");
			// 5-> 데미지를 2배로 주는 스킬		6->데미지 1.5배 + 항상 최대 데미지 보장	7->데미지 1배 + 가한 피해의 50% 회복
			printf("   5. 맹렬한 참격 구매%s       6. 예리한 일격 구매%s > 7. 흡혈의 일격%s       8. 나가기  "
				, GPlayer.Skill1 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill2 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill3 == 0 ? "(200골드)  " : "(구매 완료)");
		}
		else if (Select_NPC_Menu == 7)
		{
			system("cls");
			PrintPlayerState(GPlayer.Health, GPlayer.MaxHealth, GPlayer.Mana, GPlayer.MaxMana, GPlayer.AttackPowerMin, GPlayer.AttackPowerMax, GPlayer.Defense, GPlayer.Money);
			PrintNPC();
			printf("   1. 체력 30 추가(50골드)      \t2. 공격력 3 증가(70골드)       \t 3. 방어력 2 증가(90골드)      \t 4. 마나 30 추가(50골드)\n");
			// 5-> 데미지를 2배로 주는 스킬		6->데미지 1.5배 + 항상 최대 데미지 보장	7->데미지 1배 + 가한 피해의 50% 회복
			printf("   5. 맹렬한 참격 구매%s       6. 예리한 일격 구매%s   7. 흡혈의 일격%s     > 8. 나가기  "
				, GPlayer.Skill1 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill2 == 0 ? "(200골드)  " : "(구매 완료)", GPlayer.Skill3 == 0 ? "(200골드)  " : "(구매 완료)");
		}


		char Selectkey = _getch();
		while (true)
		{
			if (IsConfirm(Selectkey))
			{
				if (Select_NPC_Menu == 0)
				{
					if (GPlayer.Money < 50)
					{
						printf("\n돈이 부족합니다! (필요 돈: 50)\n");
						Sleep(_getch());
						break;
					}
					else
					{
						GPlayer.Money -= 50;
						GPlayer.MaxHealth += 30;
						GPlayer.Health += 30;
						printf("\n체력이 증가했습니다! (체력 +30)\n");
						Sleep(_getch());
						break;
					}
				}
				else if (Select_NPC_Menu == 1)
				{
					if (GPlayer.Money < 70)
					{
						printf("\n돈이 부족합니다! (필요 돈: 70)\n");
						Sleep(_getch());
						break;
					}
					else
					{
						GPlayer.Money -= 70;
						GPlayer.AttackPowerMin += 3;
						GPlayer.AttackPowerMax += 3;
						printf("\n공격력이 증가했습니다! (공격력 +3)\n");
						Sleep(_getch());
						break;
					}
				}
				else if (Select_NPC_Menu == 2)
				{
					if (GPlayer.Money < 90)
					{
						printf("\n돈이 부족합니다! (필요 돈: 90)\n");
						Sleep(_getch());
						break;
					}
					else
					{
						GPlayer.Money -= 90;
						GPlayer.Defense += 2;
						printf("\n방어력이 증가했습니다! (방어력 +2)\n");
						Sleep(_getch());
						break;
					}
				}
				else if (Select_NPC_Menu == 3)
				{
					if (GPlayer.Money < 50)
					{
						printf("\n돈이 부족합니다! (필요 돈: 50)\n");
						Sleep(_getch());
						break;
					}
					else
					{
						GPlayer.Money -= 50;
						GPlayer.MaxMana += 30;
						GPlayer.Mana += 30;
						printf("\n마나가 증가했습니다! (마나 +30)\n");
						Sleep(_getch());
						break;
					}
				}
				else if (Select_NPC_Menu == 4)
				{
					if (GPlayer.Skill1 == 1)
					{
						printf("\n이미 구매한 스킬입니다!\n");
						Sleep(_getch());
						break;
					}
					else
					{
						if (GPlayer.Money < 200)
						{
							printf("\n돈이 부족합니다! (필요 돈: 200)\n");
							Sleep(_getch());
							break;
						}
						else
						{
							GPlayer.Money -= 200;
							GPlayer.Skill1 = 1; //맹렬한 참격 구매
							printf("\n맹렬한 참격을 구매했습니다! (맹렬한 참격: 데미지를 2배로 주는 스킬)\n");
							Sleep(_getch());
							break;
						}
					}
				}
				else if (Select_NPC_Menu == 5)
				{
					if (GPlayer.Skill2 == 1)
					{
						printf("\n이미 구매한 스킬입니다!\n");
						Sleep(_getch());
						break;
					}
					else
					{
						if (GPlayer.Money < 200)
						{
							printf("\n돈이 부족합니다! (필요 돈: 200)\n");
							Sleep(_getch());
							break;
						}
						else
						{
							GPlayer.Money -= 200;
							GPlayer.Skill2 = 1; //예리한 일격 구매
							printf("\n예리한 일격을 구매했습니다! (예리한 일격: 데미지를 1.5배로 주는 스킬 + 항상 최대 데미지 보장)\n");
							Sleep(_getch());
							break;
						}
					}
				}
				else if (Select_NPC_Menu == 6)
				{
					if (GPlayer.Skill3 == 1)
					{
						printf("\n이미 구매한 스킬입니다!\n");
						Sleep(_getch());
						break;
					}
					else
					{
						if (GPlayer.Money < 200)
						{
							printf("\n돈이 부족합니다! (필요 돈: 200)\n");
							Sleep(_getch());
							break;
						}
						else
						{
							GPlayer.Money -= 200;
							GPlayer.Skill3 = 1; //흡혈의 일격 구매
							printf("\n흡혈의 일격을 구매했습니다! (흡혈의 일격: 데미지 1배 + 가한 피해의 50% 회복)\n");
							Sleep(_getch());
							break;
						}
					}

				}
				else if (Select_NPC_Menu == 7)
				{
					Select_NPC_Menu = -1;
					break;
				}


			}


			if (Selectkey == KEY_UP || Selectkey == KEY_LEFT)            //위,왼
			{
				Select_NPC_Menu--;
				Select_NPC_Menu = (Select_NPC_Menu + 8) % 8;
				system("cls");
				break;

			}
			else if (Selectkey == KEY_DOWN || Selectkey == KEY_RIGHT)       //오,아래
			{
				Select_NPC_Menu++;
				Select_NPC_Menu = (Select_NPC_Menu + 8) % 8;
				system("cls");
				break;
			}
			else
			{
				Selectkey = _getch();
			}

		}
	}

	if (Select_NPC_Menu == -1)
	{
		return 0;
	}
	return 0;
}




//4		회복샘
int  Healspot_Event_Encounter()
{
	char Selectkey;
	int SelectMenu = 0;

	while (true)
	{
		system("cls");
		PrintEncount(5);
		printf("회복샘 이벤트를 인카운트 했습니다!\n");

		//Sleep(_getch());

		if (SelectMenu == 0)
		{
			printf("> 1. 최대 체력의 30%%, 마나의 50%%를 회복한다.(재방문 불가능)\n\n");
		}
		else
		{
			printf("  1. 최대 체력의 30%%, 마나의 50%%를 회복한다.(재방문 불가능)\n\n");
		}
		if (SelectMenu == 1)
		{
			printf("> 2. 회복하지 않는다.(재방문 가능)\n\n");
		}
		else
		{
			printf("  2. 회복하지 않는다.(재방문 가능)\n\n");
		}


		while (true)
		{
			Selectkey = _getch();
			if (Selectkey == KEY_UP|| Selectkey == KEY_DOWN)
			{
				SelectMenu = MoveCursor(SelectMenu, 2, Selectkey);
				system("cls");
				break;
			}
			if (IsConfirm(Selectkey))
			{
				if (SelectMenu == 0)
				{
					GPlayer.Health += GPlayer.MaxHealth * 0.3;
					if (GPlayer.Health > GPlayer.MaxHealth)
					{
						GPlayer.Health = GPlayer.MaxHealth;
					}

					GPlayer.Mana += GPlayer.MaxMana * 0.5;
					if (GPlayer.Mana > GPlayer.MaxMana)
					{
						GPlayer.Mana = GPlayer.MaxMana;
					}

					return 1;
				}
				else if (SelectMenu == 1)
				{
					return 0;
				}


			}

		}
	}

}



//4_2 회복샘(랜덤인카운트용)
int  Healspot_RandomEvent_Encounter()
{
	char Selectkey;
	int SelectMenu = 0;

	while (true)
	{
		system("cls");
		PrintEncount(5);
		printf("회복샘 이벤트를 인카운트 했습니다!\n");

		//Sleep(_getch());

		if (SelectMenu == 0)
		{
			printf("> 1. 최대 체력의 30%%, 마나의 50%%를 회복한다.(재방문 불가능)\n\n");
		}
		else
		{
			printf("  1. 최대 체력의 30%%, 마나의 50%%를 회복한다.(재방문 불가능)\n\n");
		}
		if (SelectMenu == 1)
		{
			printf("> 2. 회복하지 않는다.(재방문 불가능)\n\n");
		}
		else
		{
			printf("  2. 회복하지 않는다.(재방문 불가능)\n\n");
		}


		while (true)
		{
			Selectkey = _getch();
			if (Selectkey == KEY_UP || Selectkey == KEY_DOWN)    //위 방향키
			{
				SelectMenu = MoveCursor(SelectMenu, 2, Selectkey);
				system("cls");
				break;
			}

			if (IsConfirm(Selectkey))
			{
				if (SelectMenu == 0)
				{
					GPlayer.Health += GPlayer.MaxHealth * 0.3;
					if (GPlayer.Health > GPlayer.MaxHealth)
					{
						GPlayer.Health = GPlayer.MaxHealth;
					}

					GPlayer.Mana += GPlayer.MaxMana * 0.5;
					if (GPlayer.Mana > GPlayer.MaxMana)
					{
						GPlayer.Mana = GPlayer.MaxMana;
					}

					return 1;
				}
				else if (SelectMenu == 1)
				{
					return 0;
				}


			}

		}
	}

}


//5		보물상자
void Chest_Event_Encounter()
{
	system("cls");
	PrintChest();
	printf("보물 이벤트를 인카운트 했습니다!\n");
	Sleep(_getch());

	int result = rand() % 10;

	if (result == 0)
	{
		system("cls");
		PrintEncount(4);

		int randomhealth = GetRandomRange(10, 50);

		printf("영약을 마셔 은은한 활력이 몸에 돕니다!\n");
		printf("플레이어의 현재 체력 및 최대 체력이 %d만큼 증가했습니다.\n", randomhealth);
		GPlayer.MaxHealth += randomhealth;
		GPlayer.Health += randomhealth;
	}
	else if (result <= 3 && result > 0)
	{
		system("cls");
		PrintEncount(2);
		int randomAttack = GetRandomRange(1, 3);

		printf("새로운 무기를 얻었습니다!\n");
		printf("플레이어의 최대, 최소 공격력이 %d만큼 증가했습니다.\n", randomAttack);
		GPlayer.AttackPowerMax += randomAttack;
		GPlayer.AttackPowerMin += randomAttack;
	}
	else if (result <= 6 && result > 3)
	{
		system("cls");
		PrintEncount(3);
		int randomDefense = GetRandomRange(1, 2);

		printf("새로운 방어구를 얻었습니다!\n");
		printf("플레이어의 방어력이 %d만큼 증가했습니다.\n", randomDefense);
		GPlayer.Defense += randomDefense;
	}
	else if (result <= 9 && result > 6)
	{
		int randomLuck = GetRandomRange(1, 3);

		printf("상자엔 아무것도 없었지만, 뭔가 운이 좋아진 것 같습니다!\n");
		printf("플레이어의 LUCK이 %d만큼 증가했습니다.\n", randomLuck);
		GPlayer.Luck += randomLuck;
	}

	Sleep(_getch());
}


//6 이동시 랜덤 인카운트
int Random_Encounter(int PlayerLocatition)
{
	int EncounterNumber = rand() % 3;
	if (PlayerLocatition == '0')
	{
		if (EncounterNumber == 0)
		{
			Monster_Event_Encounter(GPlayer.MonsterLevel,0);
			PlayBGM("Main_BGM", 140);
			return 0;
		}
		else if (EncounterNumber == 1)
		{
			Shop_Event_Encounter();
			return 0;
		}
		else if (EncounterNumber == 2)
		{
			Healspot_RandomEvent_Encounter();
			return 0;
		}

	}
	return 0;
}


//7 중간보스 인카운트
void Middle_Boss_Encounter()
{
	Monster_Event_Encounter(GPlayer.MonsterLevel + 9, GPlayer.Bossif);
	GPlayer.HaveKey = 1;
	OpenMiddleBossDoor();
}

//8 최종보스 인카운트
void Boss_Encounter()
{
	Monster_Event_Encounter(GPlayer.MonsterLevel + 45, GPlayer.Bossif);
}

//9 던전 클리어 및 엔딩
void Dungeon_Clear()
{
	system("cls");
	PrintClear();
	printf("던전을 클리어 했습니다! 축하드립니다!\n");
	Sleep(_getch());
}




















