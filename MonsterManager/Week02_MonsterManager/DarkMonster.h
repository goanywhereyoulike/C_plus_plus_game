#pragma once
#include "Monster.h"
class DarkMonster :
	public Monster
{
private:
	int mBloodAttack;
public:
	DarkMonster();
	DarkMonster(const char* const pName, const char* const pType, int defendPower, const int attackPower, int health, int bloodAttack, int level);
	virtual ~DarkMonster();
	virtual void PrintStatus();
	int GetBloodAbility();
	int GetDarkMonsterLevel() const;
};

