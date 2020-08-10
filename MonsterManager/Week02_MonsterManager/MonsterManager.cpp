#include "pch.h"
#include "Monster.h"
#include "DarkMonster.h"
#include "LightMonster.h"
#include "MonsterManager.h"
#include <iostream>
#include <time.h>
using namespace std;

MonsterManager* MonsterManager::mInstance = nullptr;

MonsterManager::MonsterManager():mNumMonsters(0)
{
}

MonsterManager::~MonsterManager()
{
}


MonsterManager* MonsterManager::GetInstance()
{
	if (mInstance == nullptr) {
		mInstance = new MonsterManager();
	}

	return mInstance;
} 

Monster* MonsterManager::CreateDarkMonster(char *pName, char *pType, int nDefendPower, int nAttackPower, int nHealth, int nBloodAttack, int nLevel)
{
	cout << "Create Monster =>"
		<< " N:" << pName
		<< " T:"  << pType
		<< " DP:" << nDefendPower
		<< " AP:" << nAttackPower
		<< " H:" << nHealth
		<<" BAP:"<<nBloodAttack
		<<"  L:"<<nLevel
		<< endl;

	Monster *pMonster = new DarkMonster(pName, pType,nDefendPower, nAttackPower, nHealth,nBloodAttack, nLevel);

	mMonsters[mNumMonsters++] = pMonster;
	return pMonster;
}
Monster* MonsterManager::CreateDarkMonsterDefault(char *pName, char *pType, int nDefendPower, int nAttackPower, int nHealth, int nBloodAttack, int nLevel)
{

	Monster *pMonster = new DarkMonster(pName, pType, nDefendPower, nAttackPower, nHealth, nBloodAttack, nLevel);

	mMonsters[mNumMonsters++] = pMonster;
	return pMonster;
}

Monster* MonsterManager::CreateLightMonster(char *pName, char *pType, int nDefendPower, int nAttackPower, int nHealth, int nLightAbility, int nLevel)
{
	cout << "Create Monster =>"
		<< " N:" << pName
		<< " T:" << pType
		<< " DP:" << nDefendPower
		<< " AP:" << nAttackPower
		<< " H:" << nHealth
		<< " LAP:" << nLightAbility
		<< "  L:" << nLevel
		<< endl;

	Monster *pMonster = new LightMonster(pName, pType, nDefendPower, nAttackPower, nHealth, nLightAbility, nLevel);

	mMonsters[mNumMonsters++] = pMonster;
	return pMonster;
}

Monster * MonsterManager::CreateLightMonsterDefault(char * pName, char * pType, int nDefendPower, int nAttackPower, int nHealth, int nLightAbility, int nLevel)
{
	Monster *pMonster = new LightMonster(pName, pType, nDefendPower, nAttackPower, nHealth, nLightAbility, nLevel);

	mMonsters[mNumMonsters++] = pMonster;
	return pMonster;
	
}

Monster* MonsterManager::GetMonster(char *pName)
{
	// Loop through each monster to find the one with the name
	for (int i = 0; i < mNumMonsters; i++)
	{
		// Compare name of monster and return if found
		if (strncmp(mMonsters[i]->GetName(), pName, MAX_NAME_SIZE) == 0)
		{
			return mMonsters[i];
		}
	}
	return nullptr;
}

Monster* MonsterManager::PrintList()
{
	for (int i = 0; i < mNumMonsters; i++)
	{
		mMonsters[i]->PrintStatus();
		cout << endl;
		
	}
	return nullptr;
}




Monster* MonsterManager::GetBattleMonster(int level)
{
	srand(time(NULL));
	int Posibility = rand() % 2;
	// Loop through each monster to find the one with the name
	for (int i = 0; i < mNumMonsters; i++)
	{
		if (mMonsters[i]->isdead() == true) 
		{
			if (Posibility == 1)
			{
					if (mMonsters[i]->GetLevel() == level + 1)
					{
						return mMonsters[i];
					}
				
			}
			else if (mMonsters[i]->GetLevel() == level)
			{
				return mMonsters[i];
			}
		}
	}
	return nullptr;
}

