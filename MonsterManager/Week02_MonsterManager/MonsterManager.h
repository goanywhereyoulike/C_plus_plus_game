#pragma once

const int MAX_MONSTERS = 200;

class MonsterManager
{
private:
	static MonsterManager* mInstance;

	Monster* mMonsters[MAX_MONSTERS];
	int mNumMonsters;
private:
	MonsterManager();

public:
	static MonsterManager* GetInstance();
	~MonsterManager();

	Monster* CreateDarkMonster(char *pName, char *pType ,int defendPower, int attachPower, int health, int bloodAttack, int level);
	Monster* CreateDarkMonsterDefault(char *pName, char *pType, int defendPower, int attachPower, int health, int bloodAttack, int level);
	Monster* CreateLightMonster(char *pName, char *pType,int defendPower, int attachPower, int health, int lightability, int level);
	Monster* CreateLightMonsterDefault(char *pName, char *pType, int defendPower, int attachPower, int health, int lightability, int level);
	Monster* GetMonster(char *pName);
	int GetNumMonters() { return mNumMonsters; }
	Monster* PrintList();
	Monster* GetBattleMonster(int level);
	
};
