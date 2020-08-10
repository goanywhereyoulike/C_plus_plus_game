#include "pch.h"
#include "Monster.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include<time.h>


using namespace std;

Monster::Monster()
{
}

Monster::Monster(const char* const pName, const char* const pType, int defendPower, int attackPower, int health, int level) :
	mDefendPower(defendPower), mAttackPower(attackPower), mHealth(health), mLevel(level)
{
	strcpy_s(mName, MAX_NAME_SIZE, pName);
	strcpy_s(mType, MAX_NAME_SIZE, pType);

}

void Monster::PrintStatus()
{
	cout << " Monster Name: " << mName << endl;
	cout << " Monster Type: " << mType << endl;
	cout << " Health:       " << mHealth << endl;
	cout << " Defend Power: " << mDefendPower << endl;
	cout << " Attack Power: " << mAttackPower << endl;
	cout << " Level:       " << mLevel << endl;
}

int Monster::GetBloodAbility()
{
	return 0;
}

int Monster::GetLightAbility()
{
	return 0;
}
void Monster::PrintHealth() const
{
	cout << "Monster " << mName << "'s health is " << mHealth << " now." << endl;
}
const void Monster::SetHealth(int nFeed)
{
	mHealth+=nFeed;
}
void Monster::SetUpgrade()
{
	mHealth *=2;
	mDefendPower *= 2;
	mAttackPower *= 2;
}
const char* Monster::GetName() const
{
	return mName;
}
const char* Monster::GetType() const
{
	return mType;
}
int Monster::GetAttackAmount()
{
	srand(time(NULL));
	int attackamount = mAttackPower;
	int posibility = rand() % 10 + 1;
	return attackamount + posibility; 

}
void Monster::AppiledDamage(int nAmount)
{
	srand(time(NULL));
	int realdamage = 0;
	int posibility = rand() % 10 + 1;
	if (posibility > 3)
	{
		cout << "Attack succesful!" << endl;
		realdamage =nAmount-mDefendPower;
		if (realdamage > 0)
		{
			mHealth -= realdamage;
		}
		else
		{
			realdamage = 0;
			cout << "There is no damage to the monster" << endl;
		}
		if (mHealth <= 0)
		{
			mHealth = 0;
			cout << "The monster is dead" << endl;
		}
		else
		{
			cout << "The left health of the monster is " << mHealth << " now." << endl;
		}
	}
	else
	{
		cout << "Attack failed!" << endl;
	}
}

int Monster::GetHealth() const
{
	return mHealth;
}

int Monster::GetLevel() const
{
	return mLevel;
}


int Monster::GetDefendPower() const
{
	return mDefendPower;
}

bool Monster::isdead()
{
	if (mHealth <= 0)
	{
		mHealth = 0;
		return false;
	}
	return true;
}

Monster::~Monster()
{
}

