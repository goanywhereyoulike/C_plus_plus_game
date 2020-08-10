#include "pch.h"
#include "Monster.h"
#include "LightMonster.h"
#include <iostream>
using namespace std;

LightMonster::LightMonster():mLightAbility(0)
{
}

LightMonster::LightMonster(const char* const pName, const char* const pType, int defendPower, int attackPower, int health, int lightability, int level):
	Monster(pName,pType, defendPower, attackPower, health, level),
	mLightAbility(lightability)
{
}
void LightMonster::PrintStatus()
{
	
	Monster::PrintStatus();
	cout << " Light ability: " << mLightAbility << endl;
}

int LightMonster::GetLightAbility()
{
	mHealth += mLightAbility;
	return mHealth;

}
int LightMonster::GetLightMonsterLevel() const
{
	return mLevel;
}
LightMonster::~LightMonster()
{
}
