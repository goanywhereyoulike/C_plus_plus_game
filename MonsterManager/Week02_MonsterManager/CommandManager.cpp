#include "pch.h"
#include "Monster.h"
#include "Player.h"
#include "DarkMonster.h"
#include "LightMonster.h"
#include "MonsterManager.h"
#include "PlayerManager.h"
#include "CommandManager.h"
#include "GameContent.h"
#include <iostream>
#include "string.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>


using namespace std;

const int MAX_COMMAND_SIZE = 100;


CommandManager* CommandManager::mInstance = nullptr;

CommandManager::CommandManager()
{
}

CommandManager::~CommandManager()
{
}

CommandManager* CommandManager::GetInstance() {
	if (mInstance == nullptr) {
		mInstance = new CommandManager();
	}

	return mInstance;
}

void CommandManager::HandleStat()
{
	char name[MAX_NAME_SIZE];
	cout << "=====  MONSTER STAT- BEGIN =====" << endl;

	cout << "What's your monster's name?" << endl;
	cin >> name;

	Monster *pMonster = MonsterManager::GetInstance()->GetMonster(name);
	if (pMonster != nullptr) {
		DarkMonster* pMonsterCast = dynamic_cast<DarkMonster*>(pMonster);

		if (pMonsterCast)
		{
			cout << "It is a Dark Monster" << endl;
		}
		else
		{
			cout << "It is a Light Monster" << endl;
		}
	
		pMonster->PrintStatus();
	}
	else
	{
		cout << "Monster does not exist!  Please try again!" << endl;
	}
}

void CommandManager::HandlePlayerStat()
{
	char name[MAX_NAME_SIZE];
	cout << "=====  PLAYER STAT- BEGIN =====" << endl;

	cout << "What's your player's name?" << endl;
	cin >> name;

	Player *pPlayer = PlayerManager::GetInstance()->GetPlayer(name);

	if (pPlayer != nullptr) {

		pPlayer->PrintStatus();
	}
	else
	{
		cout << "Player does not exist!  Please try again!" << endl;
	}
	cout << "=====  PLAYER STAT- END =====" << endl;
}
void CommandManager::HandleList()
{
	cout << "=====  MONSTER LIST- BEGIN =====" << endl;

	 MonsterManager::GetInstance()->PrintList();
}

void CommandManager::HandlePlayerList()
{
	cout << "=====  PLAYER LIST- BEGIN =====" << endl;

	PlayerManager::GetInstance()->PrintList();

	cout << "=====  PLAYER LIST- END =====" << endl;
}

void CommandManager::HandleCreateinformation(char *pName,int &nHealth,int &nDefendPower,int &nAttackPower, int &nLevel)
{

	cout << "=====  CREATE MONSTER - BEGIN =====" << endl;

	cout << "What's the monster's name ?" << endl;
	cin >> pName;

	cout << "What's the monster's health?" << endl;
	cin >> nHealth;

	cout << "What's the monster's defend power?" << endl;
	cin >> nDefendPower;

	cout << "What's the monster's attack power?" << endl;
	cin >> nAttackPower;

	cout << "What's the monster's level?" << endl;
	cin >> nLevel;
}

void CommandManager::HandleDarkMonsterCreate(char szType[MAX_NAME_SIZE])
{
	char szName[MAX_NAME_SIZE];
	
	int nHealth;
	int nDefendPower;
	int nAttackPower;
	int nBloodAttack;
	float fInput;
	int nLevel;
	HandleCreateinformation(szName, nHealth, nDefendPower, nAttackPower, nLevel);
	cout << "What's the monster's blood ability power?" << endl;
	cin >> fInput;
	nBloodAttack = static_cast<int>(fInput);
	MonsterManager::GetInstance()->CreateDarkMonster(szName,szType, nDefendPower, nAttackPower, nHealth, nBloodAttack,nLevel);
}

void CommandManager::HandleDarkMonsterCreateDefault(char szName[MAX_NAME_SIZE],char szType[MAX_NAME_SIZE], int nDefendPower,int nAttackPower,int nHealth,int nBloodAttack,int nLevel)
{
	MonsterManager::GetInstance()->CreateDarkMonsterDefault(szName, szType, nDefendPower, nAttackPower, nHealth, nBloodAttack,nLevel);
}

void CommandManager::HandleLightMonsterCreateDefault(char szName[MAX_NAME_SIZE], char szType[MAX_NAME_SIZE], int nDefendPower, int nAttackPower, int nHealth, int nLightAbility, int nLevel)
{
	MonsterManager::GetInstance()->CreateLightMonsterDefault(szName, szType, nDefendPower, nAttackPower, nHealth, nLightAbility, nLevel);
}

void CommandManager::HandlePlayerCreateDefault(char szName[MAX_NAME_SIZE], int nMemory, int nDefendPower, int nAttackPower, int nHealth, int nLevel)
{
	PlayerManager::GetInstance()->CreatePlayerDefault(szName, nMemory, nDefendPower, nAttackPower, nHealth, nLevel);
}

void CommandManager::HandleLightMonsterCreate(char szType[MAX_NAME_SIZE])
{
	char szName[MAX_NAME_SIZE];
	
	int nHealth;
	int nDefendPower;
	int nAttackPower;
	int nLightability;
	float fInput;
	int nLevel;
	HandleCreateinformation(szName, nHealth, nDefendPower, nAttackPower, nLevel);
	cout << "What's the monster's light ability power?" << endl;
	cin >> fInput;
	nLightability = static_cast<int>(fInput);
	MonsterManager::GetInstance()->CreateLightMonster(szName,szType, nDefendPower, nAttackPower, nHealth, nLightability, nLevel);
}
void CommandSizeLimit()
{
	int *p = const_cast<int*>(&MAX_COMMAND_SIZE);
	cout << "The length of your command should be less than " << *p - 1 << endl;

}
void CommandManager::HandleCreate()
{
	char type[MAX_NAME_SIZE];
	cout << "What Type to create?" << endl;
	cin >> type;

	if (strncmp(type, "dark", MAX_NAME_SIZE) == 0)
	{
		HandleDarkMonsterCreate(type);
	}
	else if (strncmp(type, "light", MAX_NAME_SIZE) == 0)
	{
		HandleLightMonsterCreate(type);
	}

}

void CommandManager::HandleStart()
{
	GameContent::GetInstance()->GiveStartContent();
	
}

void CommandManager::HandlePlayer(int nStep)
{
	srand(time(NULL));
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Player* pAttacker = PlayerManager::GetInstance()->GetPlayer("Jone");
	char DoorColour[MAX_COMMAND_SIZE];
	int DoorChoice = rand() % 2;
	int nLevel3 = rand() % 3 + 14;
	int nLevel4 = rand() % 3 + 18;
	int nLevel5 = rand() % 3 + 24;
	if (nStep == 3)
	{
		cout << "There are two doors in front of you, it is time to make a choice" << endl;
		while (true) 
		{
			cout << "Please enter your choice, red door or blue door?[red/blue]" << endl;
			cin >> DoorColour;
			if (strncmp(DoorColour, "red", MAX_COMMAND_SIZE) == 0)
			{
				if (DoorChoice == 1)
				{
					HandleAttack();
					cout << endl;
					break;
				}
				else
				{

					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << "You are lucky, you get an apple to increase your health" << endl;
					pAttacker->SetHealth();
					cout << "Your health is " << pAttacker->GetHealth() << " now" << endl;
					cout << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
			}
			else if (strncmp(DoorColour, "blue", MAX_COMMAND_SIZE) == 0)
			{
				if (DoorChoice == 0)
				{
					HandleAttack();
					cout << endl;
					break;
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << "You are lucky, you get an apple to increase your health" << endl;
					pAttacker->SetHealth();
					cout << "Your health is " << pAttacker->GetHealth() << " now" << endl;
					cout << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}

			}
			
		}
	}
	else if(nStep == 5)
	{
		cout << "There are two doors in front of you, it is time to make a choice" << endl;
		while (true)
		{
			cout << "Please enter your choice, red door or blue door?[red/blue]" << endl;
			cin >> DoorColour;
			if (strncmp(DoorColour, "red", MAX_COMMAND_SIZE) == 0)
			{
				if (DoorChoice == 1)
				{
					HandleAttack();
					cout << endl;
					break;
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << "You are lucky, you get a shield to increase your defend power" << endl;
					pAttacker->SetDefendPower();
					cout << "Your defend power is " << pAttacker->GetDefendPower() << " now" << endl;
					cout << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
			}
			else if (strncmp(DoorColour, "blue", MAX_COMMAND_SIZE) == 0)
			{
				if (DoorChoice == 0)
				{
					HandleAttack();
					cout << endl;
					break;
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << "You are lucky, you get an apple to increase your health" << endl;
					pAttacker->SetHealth();
					cout << "Your health is " << pAttacker->GetHealth() << " now" << endl;
					cout << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}

			}

		}
	}
	else if (nStep == 8)
	{
		cout << "There are two doors in front of you, it is time to make a choice" << endl;
		while (true)
		{
			cout << "Please enter your choice, red door or blue door?[red/blue]" << endl;
			cin >> DoorColour;
			if (strncmp(DoorColour, "red", MAX_COMMAND_SIZE) == 0)
			{
				if (DoorChoice == 1)
				{
					HandleAttack();
					cout << endl;
					break;
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << "You are lucky, you get a sword to increase your attack power" << endl;
					pAttacker->SetAttackPower();
					cout << "Your attack power is " << pAttacker->GetAttackPower() << " now" << endl;
					cout << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
			}
			else if (strncmp(DoorColour, "blue", MAX_COMMAND_SIZE) == 0)
			{
				if (DoorChoice == 0)
				{
					HandleAttack();
					cout << endl;
					break;
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << "You are lucky, you get an apple to increase your health" << endl;
					pAttacker->SetHealth();
					cout << "Your health is " << pAttacker->GetHealth() << " now" << endl;
					cout << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}

			}

		}
	}
	else if (nStep == 10)
	{
	cout << "There are two doors in front of you, it is time to make a choice" << endl;
	while (true)
	{
		cout << "Please enter your choice, red door or blue door?[red/blue]" << endl;
		cin >> DoorColour;
		if (strncmp(DoorColour, "red", MAX_COMMAND_SIZE) == 0)
		{
			if (DoorChoice == 1)
			{
				HandleAttack();
				cout << endl;
				break;
			}
			else
			{
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
				cout << "You are lucky, you get a sword to increase your attack power" << endl;
				pAttacker->SetAttackPower();
				cout << "Your attack power is " << pAttacker->GetAttackPower() << " now" << endl;
				cout << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			}
		}
		else if (strncmp(DoorColour, "blue", MAX_COMMAND_SIZE) == 0)
		{
			if (DoorChoice == 0)
			{
				HandleAttack();
				cout << endl;
				break;
			}
			else
			{
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
				cout << "You are lucky, you get an apple to increase your health" << endl;
				pAttacker->SetHealth();
				cout << "Your health is " << pAttacker->GetHealth() << " now" << endl;
				cout << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			}

		}

	}
	}
		else if (nStep == nLevel3)
	{
		cout << "There are two doors in front of you, it is time to make a choice" << endl;
		while (true)
		{
			cout << "Please enter your choice, red door or blue door?[red/blue]" << endl;
			cin >> DoorColour;
			if (strncmp(DoorColour, "red", MAX_COMMAND_SIZE) == 0)
			{
				if (DoorChoice == 1)
				{
					HandleAttack();
					cout << endl;
					break;
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << "You are lucky, you get a sword to increase your attack power" << endl;
					pAttacker->SetAttackPower();
					cout << "Your attack power is " << pAttacker->GetAttackPower() << " now" << endl;
					cout << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
			}
			else if (strncmp(DoorColour, "blue", MAX_COMMAND_SIZE) == 0)
			{
				if (DoorChoice == 0)
				{
					HandleAttack();
					cout << endl;
					break;
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << "You are lucky, you get an apple to increase your health" << endl;
					pAttacker->SetHealth();
					cout << "Your health is " << pAttacker->GetHealth() << " now" << endl;
					cout << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}

			}

		}
	}

	else if (nStep == nLevel4)
	{
		cout << "There are two doors in front of you, it is time to make a choice" << endl;
		while (true)
		{
			cout << "Please enter your choice, red door or blue door?[red/blue]" << endl;
			cin >> DoorColour;
			if (strncmp(DoorColour, "red", MAX_COMMAND_SIZE) == 0)
			{
				if (DoorChoice == 1)
				{
					HandleAttack();
					cout << endl;
					break;
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << "You are lucky, you get an apple to increase your health" << endl;
					pAttacker->SetHealth();
					cout << "Your health is " << pAttacker->GetHealth() << " now" << endl;
					cout << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
			}
			else if (strncmp(DoorColour, "blue", MAX_COMMAND_SIZE) == 0)
			{
				if (DoorChoice == 0)
				{
					HandleAttack();
					cout << endl;
					break;
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << "You are lucky, you get an apple to increase your health" << endl;
					pAttacker->SetHealth();
					cout << "Your health is " << pAttacker->GetHealth() << " now" << endl;
					cout << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}

			}

		}
	}
	else if (nStep == nLevel5)
	{
		cout << "There are two doors in front of you, it is time to make a choice" << endl;
		while (true)
		{
			cout << "Please enter your choice, red door or blue door?[red/blue]" << endl;
			cin >> DoorColour;
			if (strncmp(DoorColour, "red", MAX_COMMAND_SIZE) == 0)
			{
				if (DoorChoice == 1)
				{
					HandleAttack();
					cout << endl;
					break;
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << "You are lucky, you get an apple to increase your health" << endl;
					pAttacker->SetHealth();
					cout << "Your health is " << pAttacker->GetHealth() << " now" << endl;
					cout << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
			}
			else if (strncmp(DoorColour, "blue", MAX_COMMAND_SIZE) == 0)
			{
				if (DoorChoice == 0)
				{
					HandleAttack();
					cout << endl;
					break;
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << "You are lucky, you get an apple to increase your health" << endl;
					pAttacker->SetHealth();
					cout << "Your health is " << pAttacker->GetHealth() << " now" << endl;
					cout << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}

			}

		}
	}
	else if (nStep == 30)
	{
	cout << "It is the end of this game" << endl;
	cout << "Now it is time to fight against the Boss" << endl;
	HandleLastAttack();

	cout << "GAME END" << endl;

	}
	else
	{
		cout << "There is nothing, please move again" << endl;
	}

}


void CommandManager::FeedMonster()
{
	srand(time(NULL));
	char name[MAX_NAME_SIZE];
	int nFeed;
	int nPosibility;
	cout << "=====  Feed Monster - BEGIN =====" << endl;
	cout << "What's your monster's name?" << endl;
	cin >> name;
	nPosibility = rand() % 10 + 1;
	Monster *pMonster = MonsterManager::GetInstance()->GetMonster(name);
	if (pMonster != nullptr) {
		cout << "How much do you want to feed the monster?" << endl;
		cin >> nFeed;
		if (nPosibility > 3)
		{
			cout << "Feed successful!" << endl;
			pMonster->SetHealth(nFeed);
			pMonster->PrintHealth();
		}
		else
		{
			cout << "Feed failed!" << endl;
			
		}
	}
	else
	{
		cout << "Monster does not exist!  Please try again!" << endl;
	}
	
}

void CommandManager::HandleUpgrade()
{
	srand(time(NULL));
	char name[MAX_NAME_SIZE];
	int nPosibility=rand()%10+1;
	cout << "=====  Upgrade Monster - BEGIN =====" << endl;
	cout << "What's your monster's name?" << endl;
	cin >> name;
	Monster *pMonster = MonsterManager::GetInstance()->GetMonster(name);
	if (pMonster != nullptr) {
		if (nPosibility > 5)
		{
			cout << "Upgrade successful!" << endl;
			pMonster->SetUpgrade();
			pMonster->PrintStatus();
		}
		else
		{
			cout << "Upgrade failed!" << endl;

		}
	}
	else
	{
		cout << "Monster does not exist!  Please try again!" << endl;
	}

}

void CommandManager::HandleAttack()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	Player* pAttacker = NULL;
	Monster* pDefender = NULL;
	while (true) 
	{
		pAttacker = PlayerManager::GetInstance()->GetPlayer("Jone");
		pDefender = MonsterManager::GetInstance()->GetBattleMonster(pAttacker->GetLevel());
		//pAttacker->isdead();
		
		/*if (pAttacker->isdead() == false)
		{
			cout << "You are deed, please exit the game" << endl;
			break;
		}
		if (pDefender->isdead() == false)
		{
			cout << "The defender is deed, please try again" << endl;
			break;
		}*/
		
		if (pAttacker == NULL || pDefender == NULL)
		{
			cout << "Monster does not exist!  Please try again!" << endl;
			break;

		}
		else
		{
			cout << "The name of the monster is " << pDefender->GetName();
			cout << endl << "=====  ATTACK - BEGIN =====" << endl;
			while (true)
			{
				cout << "It is your time to attack" << endl;
				int attackmount = pAttacker->GetAttackAmount();
				pDefender->AppiledDamage(attackmount);
				cout << "The health left of the monster is " << pDefender->GetHealth()<<endl;
				Sleep(1000);

				if (pDefender->isdead() == false)
				{
					cout << "You can equip the armor of the monster" << endl;
					pAttacker->SetDefendPower();
					pAttacker->SetMemory(true);
					pAttacker->SetLevel();
					break;
				}
				else
				{
					cout << "It is the time for monster to attack" << endl;
					cout << "Ability Active" << endl;
					int attackmount = pDefender->GetAttackAmount();
					int health;
					if (strncmp(pDefender->GetType(), "dark", MAX_COMMAND_SIZE) == 0)
					{
						attackmount = pDefender->GetBloodAbility();
						cout << "The attack power of the monster is " << attackmount << " now" << endl;
						pAttacker->AppliedDamage(attackmount);
						
					}
					else if (strncmp(pDefender->GetType(), "light", MAX_COMMAND_SIZE) == 0)
					{
						health = pDefender->GetLightAbility();
						cout << "The health of the monster is " << health << " now" << endl;
						pAttacker->AppliedDamage(attackmount);
				
					}
					if (pAttacker->isdead() == false)
					{
					cout << "You are defeated, please try again" << endl;
					pAttacker->SetMemory(false);
					break;
					}
				}
			}
			cout << endl << "=====  ATTACK - END =====" << endl;
			break;
		}

	}

	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void CommandManager::HandleLastAttack()
{

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,BACKGROUND_RED |BACKGROUND_GREEN |BACKGROUND_BLUE |BACKGROUND_INTENSITY);

	Player* pAttacker = NULL;
	Monster* pDefender = NULL;
	while (true)
	{
		pAttacker = PlayerManager::GetInstance()->GetPlayer("Jone");
		pDefender = MonsterManager::GetInstance()->GetMonster("BOSS");

		if (pAttacker->isdead() == false)
		{
			cout << "You are dead, please try again" << endl;
			break;
		}
		/*if (pDefender->isdead() == false)
		{
			cout << "The defender is deed, please try again" << endl;
			break;
		}*/

		if (pAttacker == NULL || pDefender == NULL)
		{
			cout << "Monster does not exist!  Please try again!" << endl;
			break;

		}
		else
		{
			cout << "The name of the monster is " << pDefender->GetName();
			cout << endl << "=====  ATTACK - BEGIN =====" << endl;
			while (true)
			{
				cout << "It is your time to attack" << endl;
				int attackmount = pAttacker->GetAttackAmount();
				pDefender->AppiledDamage(attackmount);
				cout << "The health left of the monster is " << pDefender->GetHealth() << endl;
				Sleep(500);

				if (pDefender->isdead() == false)
				{
					cout << "The BOSS is dead" << endl;
					pAttacker->SetLastMemory();
					pAttacker->SetLevel();
					cout << "Congratulations!!! You beat the boss" << endl;
					
					break;
				}
				else
				{
					cout << "It is the time for monster to attack" << endl;
					cout << "Ability Active" << endl;
					int attackmount = pDefender->GetAttackAmount();
					int health;
					if (strncmp(pDefender->GetType(), "dark", MAX_COMMAND_SIZE) == 0)
					{
						attackmount = pDefender->GetBloodAbility();
						cout << "The attack power of the monster is " << attackmount << " now" << endl;
						pAttacker->AppliedDamage(attackmount);

					}
					else if (strncmp(pDefender->GetType(), "light", MAX_COMMAND_SIZE) == 0)
					{
						health = pDefender->GetLightAbility();
						cout << "The health of the monster is " << health << " now" << endl;
						pAttacker->AppliedDamage(attackmount);

					}
					if (pAttacker->isdead() == false)
					{
						cout << "You are defeated, please try again" << endl;
						pAttacker->SetMemory(false);
						break;
					}
				}
			}
			cout << endl << "=====  ATTACK - END =====" << endl;
			break;
		}

	}

	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void CommandManager::Update()
{
	char command[MAX_COMMAND_SIZE];

	while (true) {
		cout << endl;

		cout << "What do you want to do?" << endl;
		cout << "Enter 'help' for guidance " << endl;
		CommandSizeLimit();
		cin >> command;

		if (strncmp(command, "exit", MAX_COMMAND_SIZE) == 0)
		{
			break;
		}
		else if (strncmp(command, "create", MAX_COMMAND_SIZE) == 0) {
			HandleCreate();
		}
		else if (strncmp(command, "stat", MAX_COMMAND_SIZE) == 0) {
			HandleStat();
		}
		else if (strncmp(command, "feed", MAX_COMMAND_SIZE) == 0) {
			FeedMonster();
		}
		else if (strncmp(command, "list", MAX_COMMAND_SIZE) == 0) {
			HandleList();
		}
		else if (strncmp(command, "upgrade", MAX_COMMAND_SIZE) == 0) {
			HandleUpgrade();
		}
		else if (strncmp(command, "help", MAX_COMMAND_SIZE) == 0) {
			cout << "[create]: Create new monster" << endl;
			cout << "[stat]: Print out the status" << endl;
			cout << "[feed]: Feed monster" << endl;
			cout << "[list]: Print out all monsters'status" << endl;
			cout << "[upgrade]: Upgrade monster" << endl;
			cout << "[exit]: Exit the game" << endl;
		

		}

	}

	
}
void CommandManager::GamePlay()
{
	char command[MAX_COMMAND_SIZE];
	char playercommand;
	int nStep = 0;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	HandlePlayerCreateDefault("Jone", 0, 50, 50, 50,1);
	HandleDarkMonsterCreateDefault("Boy1", "dark", 10, 11, 20, 1,1);
	HandleDarkMonsterCreateDefault("Boy2", "dark", 20, 13, 30, 3,2);
	HandleDarkMonsterCreateDefault("Boy3", "dark", 30, 30, 40, 3,3);
	HandleDarkMonsterCreateDefault("Boy4", "dark", 40, 40, 40, 4,4);
	HandleLightMonsterCreateDefault("Girla", "light", 10, 10, 20, 3, 1);
	HandleLightMonsterCreateDefault("Girlb", "light", 20, 20, 30, 3, 2);
	HandleLightMonsterCreateDefault("Girlc", "light", 30, 30, 40, 3, 3);
	HandleLightMonsterCreateDefault("Girld", "light", 30, 30, 40, 3, 4);
	HandleLightMonsterCreateDefault("Girl1", "light", 10, 10, 20, 6, 5);
	HandleLightMonsterCreateDefault("Girl2", "light", 20, 20, 30, 6, 6);
	HandleLightMonsterCreateDefault("Girl3", "light", 30, 30, 40, 3, 7);
	HandleLightMonsterCreateDefault("Girl4", "light", 40, 40, 40, 4, 8);
	HandleDarkMonsterCreateDefault("BOSS", "dark", 40, 55, 40, 3,8);

	while (true) 
	{

		cout << "=== Weolcome to Game Manager ===" << endl;
		cout << endl;
		cout << "What do you want to do?" << endl;
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		cout << "Enter 'help' for guidance " << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cin >> command;

		if (strncmp(command, "exit", MAX_COMMAND_SIZE) == 0)
		{
			
			break;
		}
		else if (strncmp(command, "start", MAX_COMMAND_SIZE) == 0) {
			cout << endl;
			system("pause");
			system("cls");

			while (true)
			{
				if (nStep == 30)
				{
					break;
				}
				cout << "Do you want to move?[y/n]" << endl;
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
				cout << "Press n to back to game manager" << endl;
				cout << "The distance between you and the boss is " << 30-nStep << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cin >> playercommand;
				if (playercommand == 'y')
				{
					nStep++;
					//cout << nStep << endl;
					HandlePlayer(nStep);
					cout << endl;
					system("pause");
					system("cls");
					if (nStep == 30)
					{
						cout << "GAME END" << endl;
						break;
					}
				}
				else if (playercommand == 'n')
				{
					break;
				}

			}

		}
		else if (strncmp(command, "attack", MAX_COMMAND_SIZE) == 0) {
			HandleAttack();
		}
		else if (strncmp(command, "monstermanager", MAX_COMMAND_SIZE) == 0) {
			cout << endl << "=====  MONSTER MANAGER - START =====" << endl;
			Update();
			cout << endl << "=====  MONSTER MANAGER - END =====" << endl;
			system("pause");
			system("cls");
		}
		else if (strncmp(command, "stat", MAX_COMMAND_SIZE) == 0) {
			HandlePlayerStat();
			cout << endl;
			system("pause");
			system("cls");
		}
		else if (strncmp(command, "list", MAX_COMMAND_SIZE) == 0) {
			HandlePlayerList();
			cout << endl;
			system("pause");
			system("cls");
		}
		else if (strncmp(command, "memory", MAX_COMMAND_SIZE) == 0) {
			Player* pAttacker = PlayerManager::GetInstance()->GetPlayer("Jone");
			if (pAttacker->GetMemory() == 1)
			{
				GameContent::GetInstance()->GiveMemoryContent1();
			}
			else if (pAttacker->GetMemory() == 2)
			{
				GameContent::GetInstance()->GiveMemoryContent2();
			}
			else if (pAttacker->GetMemory() == 3)
			{
				GameContent::GetInstance()->GiveMemoryContent3();
			}
			else if (pAttacker->GetMemory() == 4)
			{
				GameContent::GetInstance()->GiveMemoryContent4();
			}
			else if (pAttacker->GetMemory() == 5)
			{
				GameContent::GetInstance()->GiveMemoryContent5();
			}
			else if (pAttacker->GetMemory() == 6)
			{
				GameContent::GetInstance()->GiveMemoryContent6();
			}
			else if (pAttacker->GetMemory() == 7)
			{
				GameContent::GetInstance()->GiveMemoryContent7();
			}
			else if (pAttacker->GetMemory() == 8)
			{
				GameContent::GetInstance()->GiveMemoryContentAll();
			}
			else 
			{
				cout << "You have no memory" << endl;
			}
			cout << endl;
			system("pause");
			system("cls");
		}
		else if (strncmp(command, "help", MAX_COMMAND_SIZE) == 0) {
			cout << "[exit]: Exit the game" << endl;
			cout << "[start]: Start the game" << endl;
			cout << "[list]: list all players" << endl;
			cout << "[stat]: stat the player" << endl;
			cout << "[memory]: read your memory" << endl;
			//cout << "[monstermanager]: Manage the default monster" << endl;
			cout << endl;
			system("pause");
			system("cls");

		}

	}
	cout << "Thanks for playing.  Good bye!" << endl;
}