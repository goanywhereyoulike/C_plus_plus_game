#include "pch.h"
#include "Monster.h"
#include "Player.h"
#include "PlayerManager.h"
#include <iostream>
using namespace std;

PlayerManager* PlayerManager::mInstance = nullptr;

PlayerManager::PlayerManager() :mNumPlayers(0)
{
}

PlayerManager::~PlayerManager()
{
}

PlayerManager* PlayerManager::GetInstance()
{
	if (mInstance == nullptr) {
		mInstance = new PlayerManager();
	}

	return mInstance;
}

Player* PlayerManager::CreatePlayerDefault(char *pName, int nMemory, int nDefendPower, int nAttackPower, int nHealth, int nLevel)
{

	Player *pPlayer = new Player(pName, nMemory, nDefendPower, nAttackPower, nHealth, nLevel);

	mPlayers[mNumPlayers++] = pPlayer;
	return pPlayer;
}

Player* PlayerManager::GetPlayer(char *pName)
{
	// Loop through each monster to find the one with the name
	for (int i = 0; i < mNumPlayers; i++)
	{
		// Compare name of monster and return if found
		if (strncmp(mPlayers[i]->GetName(), pName, MAX_NAME_SIZE) == 0)
		{
			return mPlayers[i];
		}
	}
	return nullptr;
}

Player* PlayerManager::PrintList()
{
	for (int i = 0; i < mNumPlayers; i++)
	{
		mPlayers[i]->PrintStatus();
		cout << endl;

	}
	return nullptr;
}
