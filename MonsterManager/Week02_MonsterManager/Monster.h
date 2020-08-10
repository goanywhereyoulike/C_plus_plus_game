#pragma once

const int MAX_NAME_SIZE = 256;

class Monster
{
protected:
	mutable int mHealth;
	mutable int mLevel;
	int mDefendPower;
    int mAttackPower;
	char mName[MAX_NAME_SIZE];
	char mType[MAX_NAME_SIZE];

public:
	Monster();
	Monster(const char* const pName, const char* const pType,int defendPower, int attackPower, int health, int level);

	virtual ~Monster();
	const void SetHealth(int nFeed);
	const char* GetName() const;
	const char* GetType() const;
	int GetHealth() const;
	int GetLevel() const;
	int GetDefendPower() const;
	virtual void PrintStatus();
	void PrintHealth() const;
	int GetAttackAmount();
	void AppiledDamage(int nAmount);
	void SetUpgrade();
	bool isdead();
	virtual int GetBloodAbility();
	virtual int GetLightAbility();
	
};

