#include "pch.h"
#include "Monster.h"
#include "Player.h"
#include "GameContent.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

GameContent* GameContent::mInstance = nullptr;



GameContent* GameContent::GetInstance()
{
	if (mInstance == nullptr) {
		mInstance = new GameContent();
	}

	return mInstance;
}


GameContent::GameContent()
{
}

void GameContent::GiveStartContent() const
{
	char szName[MAX_NAME_SIZE];
	int nHealth;
	int nDefendPower;
	int nAttackPower;
	cout << "***************************************************************************************************************************************************************************" << endl;
	Sleep(1000);
	cout << "***************************************************************************************************************************************************************************" << endl;
	Sleep(1000);
	cout << "****** 66         66          66 **** 666666666666 ***** 66 **************** 666666666 ************ 666666 *************** 6          66 *************** 666666666666 *****" << endl;
	Sleep(1000);
	cout << "******* 66       6666        66 ***** 66           ***** 66 ************** 666 ***************** 66        66 *********** 666        6666 ************** 66           *****" << endl;
	Sleep(1000);
	cout << "******** 66     66  66      66 ****** 66           ***** 66 ************* 666 ****************** 66        66 ********** 66 66      66  66 ************* 66           *****" << endl;
	Sleep(1000);
	cout << "********* 66   66    66    66 ******* 666666666666 ***** 66 ************ 666 ******************  66        66 ********* 66   66    66    66 ************ 666666666666 *****" << endl;
	Sleep(1000);
	cout << "********** 66 66      66  66 ******** 66           ***** 66 ************* 666 ****************** 66        66 ******** 66     66  66      66 *********** 66           *****" << endl;
	Sleep(1000);
	cout << "*********** 666        6666 ********* 66           ***** 66 ************** 666 ***************** 66        66 ******* 66       6666        66 ********** 66           *****" << endl;
	Sleep(1000);
	cout << "************ 6          66 ********** 666666666666 ***** 6666666666666 **** 6666666666 ************ 6666666 ******** 66         66          66 ********* 666666666666 *****" << endl;
	Sleep(1000);
	cout << "***************************************************************************************************************************************************************************" << endl;
	Sleep(1000);
	cout << "***************************************************************************************************************************************************************************" << endl;
	Sleep(1000);
	cout << "***************************************************************************************************************************************************************************" << endl;
	Sleep(1000);

	cout << "You should create your character first" << endl;
	cout << "Please enter your name: " << endl;
	cin >> szName;
	while (true)
	{
		cout << "Please enter your health(1-100): " << endl;
		cin >> static_cast<int>(nHealth);
		if (nHealth <= 100 && nHealth >= 1)
		{
			break;
		}
	}
	while (true)
	{
		cout << "Please enter your defend power(1-100): " << endl;
		cin >> nDefendPower;
		if (nDefendPower <= 100 && nDefendPower >= 1)
		{
			break;
		}

	}

	while (true)
	{
		cout << "Please enter your attack power(1-100): " << endl;
		cin >> nAttackPower;
		if (nAttackPower <= 100 && nAttackPower >= 1)
		{
			break;
		}

	}
	cout << "Please wait for creating" ;
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << endl << "System failed, the default charactor is used." << endl;
	Sleep(2000);
	cout<<"Enjoy the game";

}

void GameContent::GiveStartContent2() const
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Wake up, wake up, hey man wake up" << endl;
	cout << "Oh you already wake up" << endl;
	cout << "Come on, stand up, look around, this is not a nice place" << endl;
	cout << "As you can see, it is a dark room with only one door" << endl;
	cout << "You may meet two doors later and that is the time to make a choice" << endl;
	cout << "Be careful of your choice, you may get some prizes or you may meet something bad" << endl;
	cout << "Who am I?" << endl;
	cout << "you can regard me as a narrator of this game" << endl;
	cout << "Yes, you are in a game, linear story game" << endl;
	cout << "There is no way to come back" << endl;
	cout << "but you can check your status whenever you want" << endl;
	cout << "I know you lost all your memory" << endl;
	cout << "The only thing I can tell you is that your name is Jone" << endl;
	cout << "I understand what you worry about" << endl;
	cout << "But waiting will not change anything" << endl;
	cout << "Open the door and move forward, don't worry, I will always be with you" << endl;
	cout << "By the way, always remember to go back to see your memory, old memory may be covered by new memory" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void GameContent::GiveMemoryContent1() const
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	cout << "Now you get a piece of memory back" << endl;
	cout << "Let's check what it is" << endl;
	cout << "Oh, you are a loser" << endl;
	cout << "your wife and your children have left you" << endl;
	cout << "You came to this creepy place because you heard a news." << endl;
	cout << "Anyone who can survive one night can have a chance to make one dream come true" << endl;
	cout << "Well well well, look at you, you must want to make your families come back" << endl;
	cout << "Let's see whether you can make it" << endl;

	SetConsoleTextAttribute(hOut,FOREGROUND_RED |FOREGROUND_GREEN |FOREGROUND_BLUE);

}

void GameContent::GiveMemoryContent2() const
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Now you get another piece of memory" << endl;
	cout << "Now you know you are a loser and lost your family. You come here for a wish." << endl;
	cout << "Let's see what the new memory is." << endl;
	cout << "Before you came to this place, you have done some research" << endl;
	cout << "You knew there exist some monsters and items that you can equip" << endl;
	cout << "And you knew you could not bring any weapon to this place" << endl;
	cout << "So you've been exercising for a long time and have a good body" << endl;
	cout << "and you have learned some survival techniques." << endl;
	cout << "And you seemed to put a secret weapon in your mind." << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void GameContent::GiveMemoryContent3() const
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Oh,cool, you did a good job" << endl;
	cout << "Now you get another memory" << endl;
	cout << "You know your family left you, you came here for a wish, you have prepared much for it." << endl;
	cout << "And you may have a secret weapon" << endl;
	cout << "This new memory seems about your secret weapon" << endl;
	cout << "It seems not a physical weapon." << endl;
	cout << "It seems have a ability to affect the monster of this creepy place" << endl;
	cout << "It seems a word" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void GameContent::GiveMemoryContent4() const
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "This memory seems to have some interteresting thing" << endl;
	cout << "You are a loser, you have a secret weapon whcih may about monsters in this place" << endl;
	cout << "What else about your previous memory?" << endl;
	cout << "You can't remember, that is how memory works" << endl;
	cout << "When you have a new memory, you may forget some details of your previous memory" << endl;
	cout << "So it is improtant to remember the key points" << endl;
	cout << "Understand? Then tell me do you remember how you came here?" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void GameContent::GiveMemoryContent5() const
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "This memory semms boring" << endl;
	cout << "You know you are a loser and you come here for a wish" << endl;
	cout << "But do you know why you are a loser?" << endl;
	cout << "Becase your best friend betraied you" << endl;
	cout << "He stole your job and even your family" << endl;
	cout << "you came here not only for the wish but also you knew he is here " << endl;
	cout << "what you really want is to use the wish to kill him" << endl;
	cout << "But you need to remember his name, you lost that memory " << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void GameContent::GiveMemoryContent6() const
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Another boring but dark memory" << endl;
	cout << "You now know it is your best friend who made you lose everything" << endl;
	cout << "But you don't remember his name" << endl;
	cout << "This new memory is some information about your best friend" << endl;
	cout << "He is a scientist and his major is occult and mana" << endl;
	cout << "He discovered this place and build this game" << endl;
	cout << "He raised monsters here and build these red and blue doors" << endl;
	cout << "He believed that the more people sacrificed, the bigger wish could be accomplished" << endl;
	cout << "And he told you this place" << endl;

	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void GameContent::GiveMemoryContent7() const
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "This memory is interesting" << endl;
	cout << "Now you know some truths" << endl;
	cout << "This place was discovered by your best friend" << endl;
	cout << "The reason why you are here mainly because of him" << endl;
	cout << "However, your best friend was dead three years ago because of a accident" << endl;
	cout << "He didn't know your family when he was alive" << endl;
	cout << "So who actually communicated with you? " << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void GameContent::GiveMemoryContentAll() const
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Now you have all your memory" << endl;
	cout << "You used to believe that it is your best friend who made this game" << endl;
	cout << "But he was dead three years ageo" << endl;
	cout << "So the truth is that I brought you here" << endl;
	cout << "I know you are lucky and strong enough to win this game" << endl;
	cout << "Here is your prize" << endl;
	cout << "The secret weapon is a artifact which is called ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED  | FOREGROUND_INTENSITY);
	cout << "monstermanager" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "you will know how to use it. " << endl;
	cout << "Who am I? My name is Jone" << endl;
	cout << "I look forward to seeing you next time. Goodbye hero" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}


GameContent::~GameContent()
{
}
