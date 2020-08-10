#pragma once

class Player
{
private:
	int mHealth;
	int mDefendPower;
	int mAttackPower;
	int mMemory;
	char mName[MAX_NAME_SIZE];
	int mLevel;

public:
	Player();
	Player(const char* const pName, int memory, int defendPower, int attackPower, int health, int level);
	void PrintStatus() const;
	void SetLastMemory();
	int GetHealth();
	int GetLevel();
	int GetMemory();
	int GetAttackPower();
	void SetHealth();
	void SetLevel();
	void SetDefendPower();
	void SetAttackPower();
	void SetMemory(bool result);
	int GetAttackAmount();
	void AppliedDamage(int nAmount);
	bool isdead();
	char* GetName();
	int GetDefendPower();
	~Player();
};

