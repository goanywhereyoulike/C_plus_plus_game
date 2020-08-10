// Week02_MonsterManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "String.h"
#include "Monster.h"
#include "MonsterManager.h"
#include "CommandManager.h"
#include "Player.h"
#include "GameContent.h"
#include <windows.h>

using namespace std;

//void TestMonster()
//{
//	Monster m;
//	m.GetName();
//	m.PrintStatus();
//	
//	// Create Monster with a proper name and stats
//
//}
//
//void TestMonsterManager() 
//{
//	MonsterManager* pMonsterMan = MonsterManager::GetInstance();
//
//	char szName[MAX_NAME_SIZE];
//	char szType[MAX_NAME_SIZE];
//	strcpy_s(szName, MAX_NAME_SIZE, "Pekachoo");
//	pMonsterMan->CreateDarkMonster(szName, szType,100, 100, 10,10,1);
//
//	strcpy_s(szName, MAX_NAME_SIZE, "CharZard");
//	pMonsterMan->CreateDarkMonster(szName, szType, 1000, 1000, 100,100,1);
//
//	Monster* pMonster = pMonsterMan->GetMonster(szName);
//	pMonster->PrintStatus();
//}
//
//void TestCommandManager()
//{
//	CommandManager::GetInstance()->Update();
//}



struct PlayerGame 
{
	float health;
	bool isDead;
	bool isLive;
	bool isDead2;
	bool isLive2;
	int time;

};

void ReinterpretCast2() 
{
	PlayerGame Nova;
	Nova.health = 100;
	Nova.isDead = false;
	Nova.isLive = true;
	Nova.isDead2 = false;
	Nova.isLive2 = false;
	Nova.time = 2;
	


	float* pHealth = reinterpret_cast<float*>(&Nova);
	cout << endl<< "Health:" << *pHealth << endl;
	pHealth++;

	bool* pLive= reinterpret_cast<bool*>(pHealth);
	cout << "isDead:" << *pLive << endl;
	pLive++;

	bool* pDead = reinterpret_cast<bool*>(pLive);
	cout << "isLife:" << *pDead << endl;
	pDead++;

	bool* pDead2= reinterpret_cast<bool*>(pDead);
	cout << "really dead?:"<<*pDead2 << endl;
	pDead2++;

	bool* pLive2 = reinterpret_cast<bool*>(pDead2);
	cout << "Still alive?:" << *pLive2 << endl;
	pLive2++;

	int *pTime = reinterpret_cast<int*>(pLive2);
	cout << "Time:" << *pTime << endl;

}
int main()
{
	//GameContent::GetInstance()->GiveStartContent();
	//cout << endl;
	//system("pause");
	//system("cls");
	//GameContent::GetInstance()->GiveStartContent2();
	//system("pause");
	//system("cls");
	ReinterpretCast2();

	CommandManager::GetInstance()->GamePlay();

}


