#pragma once

class CommandManager
{
private:
	static CommandManager* mInstance;
	CommandManager();

public:
	static CommandManager* GetInstance();
	~CommandManager();

	void Update();
	void GamePlay();

private:
	void HandleCreateinformation(char* pName, int &nHealth, int &nDefendPower, int &nAttackPower, int &nLevel);
	void HandleDarkMonsterCreate(char szType[MAX_NAME_SIZE]);
	void HandleStat();
	void HandlePlayerStat();
	void FeedMonster();
	void HandleAttack();
	void HandleList();
	void HandleUpgrade();
	void HandleCreate();
	void HandleStart();
	void HandleLastAttack();
	void HandlePlayerList();
	void HandlePlayer(int nStep);
	void HandleLightMonsterCreate(char szType[MAX_NAME_SIZE]);
	void HandleDarkMonsterCreateDefault(char szName[MAX_NAME_SIZE], char szType[MAX_NAME_SIZE], int nDefendPower, int nAttackPower, int nHealth, int nBloodAttack, int level);
	void HandleLightMonsterCreateDefault(char szName[MAX_NAME_SIZE], char szType[MAX_NAME_SIZE], int nDefendPower, int nAttackPower, int nHealth, int nLightAbility,int level);
	void HandlePlayerCreateDefault(char szName[MAX_NAME_SIZE], int nMemory, int nDefendPower, int nAttackPower, int nHealth, int nLevel);

};