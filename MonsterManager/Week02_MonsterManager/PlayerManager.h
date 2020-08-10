#pragma once

const int MAX_PLAYERS = 2;

class PlayerManager
{
private:
	static PlayerManager* mInstance;

	Player* mPlayers[MAX_PLAYERS];
	int mNumPlayers;
private:
	PlayerManager();

public:
	static PlayerManager* GetInstance();
	~PlayerManager();


	Player* CreatePlayerDefault(char *pName, int memory, int defendPower, int attachPower, int health, int level);
	Player* GetPlayer(char *pName);
	int GetNumMonters() { return mNumPlayers; }
	Player* PrintList();


};

