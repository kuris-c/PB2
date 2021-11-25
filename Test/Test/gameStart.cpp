#include "prepro.h"
#include <windows.h>
#include <iomanip>

//Player Init Variables
int playerLocation;
int playerClass;
std::string playerName;
int playerAge;

//Create the Player
Player player;

bool playGame = true, typeWriterEnabled = true;
void onGameRun(), mainMenu(), onGameStart();

int main()
{
	srand((unsigned int)time(0));
	displayGameWindow(1250, 750);
	onGameRun();
	onGameStart();
}

//Plays on Run, after Window is created
void onGameRun()
{
	//Display Logo and Advance to Menu
	gameLogo();
	Sleep(500);
	mainMenu();
}

//The Start Menu
void mainMenu()
{
	//GameMenu Variables
	int menuChoice;

	//Settings Options are console outted individually for setw function
	std::cout << "\n\n" << std::endl;
	std::cout << std::setw(80) << "[1] Play Game" << std::endl;
	std::cout << std::setw(78) << "[2] Options" << std::endl;
	std::cout << std::setw(78) << "[3] Credits" << std::endl;
	std::cout << std::setw(80) << "[4] Exit Game" << std::endl;
	inputTooltip();
	std::cin >> menuChoice;

	//Player Makes Option
	switch (menuChoice)
	{
	case 1:
		break;
	case 2:
		system("CLS");
		std::cout << "Player Options.\n[1] Toggle TypeWriter Mode\n[2] Load Game\n[3] Return To Main Menu\n[4] Exit Application" << std::endl;
		inputTooltip();
		std::cin >> menuChoice;
		if (menuChoice == 1)
		{
			if (typeWriterEnabled)
			{
				typeWriterEnabled = false;
				std::cout << "Type Writer Disabled\n";
				system("pause");
				system("CLS");
				gameLogo();
				mainMenu();
			}
			else
			{
				typeWriterEnabled = true;
				std::cout << "Type Writer Enabled\n";
				system("pause");
				system("CLS");
				gameLogo();
				mainMenu();
			}
		}
		if (menuChoice == 2)
		{
			break;
		}
		if (menuChoice == 3)
		{
			system("CLS");
			gameLogo();
			mainMenu();
		}
		else
		{
			exit(0);
		}
		break;
	case 3:
		std::cout << "Game Created By: Christian Freeman\nWith the invaluable help of StackExchange\n\nEnter 1 to play the game, 2 to return to the main menu, or 3 to exit the application." << std::endl;
		if (menuChoice == 1)
		{
			break;
		}
		if (menuChoice == 2)
		{
			system("CLS");
			gameLogo();
			mainMenu();
		}
		else
		{
			exit(0);
		}
	case 4:
		exit(0);
	}

	system("CLS");
	gameLogo();
	textTyper("\n\nPrisoner 401. Welcome to your first day in the clink, I can assure you I will do whatever I can do to make this the most painful experience for you \npossible.. Try not to get into any fights, or you will be punished.\nJust fit in with the other prisoners.\n");
	std::cout << "You take a second to remember why you are here.\n\n[1] You were arrested for Hacking: " << "\033[0;32m" << "+ Computer Skills\n" << "\033[0;m" << "[2] You were arrested for Fighting: " << "\033[0;32m" << " + Player Strength\n" << "\033[0;m" << "[3] You were arrested for Gang Activity : " << "\033[0;32m" << " + Player Rapport\n" << "\033[0;m" << "[4] You were arrested for Theft: " << "\033[0;32m" << " + Contraband Chances\n" << "\033[0;m";
	std::cin >> playerClass;
	system("pause");
	onGameStart();
}

//After Player Has Chosen To Play THe Game
void onGameStart()
{
	system("CLS");
	textTyper("You cast your eyes over the prison reception, the space is vast, well lit and with cameras monitoring every nook of the room. It is clear to you there \nis no blindspot in this particular room. Around you, you can see other prisoners being stripped and searched, you keep your face down to avoid making \neye contact with the other hardened criminals as much as you can.\n\nSuddenly you feel a gentle tap on your shoulder, and raise your face to meet the eyeline of another prisoner. He has a slightly muscular frame, blue \neyes with blonde hair, and is clearly one of the youngest and most agile in the room. He looks at you to talk.\nWhat is your name?\n");
	inputTooltip();
	std::cin.ignore(), getline(std::cin, playerName);
	textTyper("\nHe looks you up and down. That name suits you, " + playerName + ". He looks neither impressed nor the alternative. How old are you? He asks, squinting his eyes \nslightly, as though this will play a role in his judgement of you.\n");
	inputTooltip();
	std::cin >> playerAge;
	while (playerAge < 18)
	{
		std::cout << "You are far too young to be in prison. Are you sure this is your real age?.\nEnter your real age (18+)." << std::endl;
		inputTooltip();
		std::cin >> playerAge;
	}
	
	//Player Info Assignment
	player.playerName = playerName;
	player.playerAge = playerAge;

	//ASSIGN CLASS SKILL BOOST
	player.CheckClass(playerClass);

	//Escorted to Cell Block
	textTyper("\n\nHe says little more, and you are taken away by a burly guard, dressed in his uniform, but his shirt untucked. He commences the invasive search of your \nperson, and thrusts a slightly folded, less slightly ironed, orange uniform into your hands, gesturing you to put it on. You are walked to your cell by \nthe guard who strip searched, and uniformed, you. Over the journey you learn that his name is Franz. You continue to not pay much attention, as you \nperuse the surroundings to learn about ways that you could escape this hellhole. You walk out of Reception, and into the courtyard. Prisoners are \nplaying on the concrete football pitch, or sat to observe the players build a sweat, fighting with the training dummys, or lying on the way-too-small \ngrassy patch in the far corner, under the fence.\n");
	playerLocation = 0;
	createPrison();

	//Set Time
	day = 3;
	hour = 8;
	min = 0;

	//Enter Game
	system("pause");
	gamePlay(0);
}