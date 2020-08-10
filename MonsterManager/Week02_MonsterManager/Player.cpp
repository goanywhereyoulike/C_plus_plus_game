#include "pch.h"
#include "Monster.h"
#include "Player.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Player::Player()
{
}

Player::Player(const char* const pName, int memory, int defendPower, int attackPower, int health,int level) :
	mMemory(memory), mDefendPower(defendPower), mAttackPower(attackPower), mHealth(health),mLevel(level)
{
	strcpy_s(mName, MAX_NAME_SIZE, pName);
}
void Player::PrintStatus() const
{
	cout << " Player Name: " << mName << endl;
	cout << " PLayer memory number: " << mMemory << endl;
	cout << " Health:       " << mHealth << endl;
	cout << " Defend Power: " << mDefendPower << endl;
	cout << " Attack Power: " << mAttackPower << endl;
	cout << " Level:       " << mLevel << endl;
}
int Player::GetHealth()
{
	return mHealth;
}

int Player::GetLevel()
{
	return mLevel;
}

int Player::GetMemory()
{
	return mMemory;
}

int Player::GetAttackPower()
{
	return mAttackPower;
}

void Player::SetHealth()
{
	mHealth += 10;
}
void Player::SetLevel()
{
	mLevel += 1;
}
void Player::SetLastMemory()
{
	mMemory = 8;
}
void Player::SetDefendPower()
{
	mDefendPower+= 10;
}

void Player::SetAttackPower()
{
	mAttackPower += 10;
}

void Player::SetMemory(bool result)
{
	if (result == true)
	{
		mMemory++;
	}
	else
	{
		mMemory--;
		if (mMemory < 0)
		{
			mMemory = 0;
		}
	}
}

int Player::GetAttackAmount()
{
		srand(time(NULL));
		int attackamount = mAttackPower;
		int posibility = rand() % 5 + 1;
		return attackamount + posibility;
}

void Player::AppliedDamage(int nAmount)
{
	srand(time(NULL));
	int realdamage = 0;
	int posibility = rand() % 10 + 1;
	if (posibility > 3)
	{
		cout << "Attack succesful!" << endl;
		realdamage = nAmount - mDefendPower;
		if (realdamage > 0)
		{
			mHealth -= realdamage;
		}
		else
		{
			realdamage = 0;
			cout << "There is no damage to the you" << endl;
		}
		if (mHealth <= 0)
		{
			mHealth = 0;
			cout << "You are dead" << endl;
		}
		else
		{
			cout << "The left health of you is " << mHealth << " now." << endl;
		}
	}
	else
	{
		cout << "Attack failed!" << endl;
	}
}

bool Player::isdead()
{
	if (mHealth <= 0)
	{
		mHealth = 0;
		return false;
	}
	return true;
}

int Player::GetDefendPower()
{
	return mDefendPower;
}

char* Player::GetName()
{
	return mName;
}

Player::~Player()
{
}


