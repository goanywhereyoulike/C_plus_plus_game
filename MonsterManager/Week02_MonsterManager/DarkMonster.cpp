#include "pch.h"
#include "Monster.h"
#include "DarkMonster.h"
#include <iostream>

using namespace std;

DarkMonster::DarkMonster():mBloodAttack(0)
{
}

DarkMonster::DarkMonster(const char* const pName, const char* const pType, int defendPower, int attackPower, int health, int bloodattack, int level):
	Monster(pName,pType, defendPower,attackPower, health,level),
	mBloodAttack(bloodattack)
{
}

int DarkMonster::GetBloodAbility() 
{
	mAttackPower += mBloodAttack;
	return mAttackPower;
}

void DarkMonster::PrintStatus()
{

	Monster::PrintStatus();
	cout << " Blood Ability: " << mBloodAttack << endl;
}
DarkMonster::~DarkMonster()
{
}

int DarkMonster::GetDarkMonsterLevel() const
{
	return mLevel;
}
