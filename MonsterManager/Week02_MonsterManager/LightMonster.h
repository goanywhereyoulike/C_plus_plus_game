#pragma once
#include "Monster.h"
class LightMonster :
	public Monster
{
private:
	int mLightAbility;
public:
	LightMonster();
	LightMonster(const char* const pName, const char* const pType, int defendPower, int attackPower, int health, int lightability,int level);
	virtual ~LightMonster();
	virtual void PrintStatus();
	int GetLightAbility();
	int GetLightMonsterLevel() const;
};

