#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#define fori(x) for (int i = 0; i < (x); i++)
#define pRelationship(x, functionName) if (sideCharacters[x].characterInAction) sideCharacters[x].functionName(); else prisoners[x].functionName();

/*STORE PLAYER LOCATION*/extern int playerLocation;
/*SETTINGS*/
extern bool typeWriterEnabled;

#pragma region GAME FUNCTIONS
//PRISON CREATION FUNCTIONS
void gamePlay(int enterMethod);
void createPrison();

//PRISONER REPLACEMENT FUNCTION
void replacePrisoner(int prisonerNumber);

//GAME SETTING FUNCTIONS
void gameLogo();
void gameWin(std::string winMessage, int widthLength);
void gameLose(std::string loseMessage, int widthLength);
void gameTopline();
void displayGameWindow(int width, int height);
void textTyper(std::string inputText);

//TIME MANAGER VARIABLES
extern int day, hour, min;
extern std::string sday, shour, smin;
extern int cday, chour, cmin;
extern bool tfhourclock;

//TIME MANAGER FUNCTIONS
void addDay(int days);
void addHour(int hours);
void addMin(int mins);
void displayTime();
void checkTime();

//ESCAPE BOOLS AND FUNCTIONS
extern bool discoveredTunnel;

//GAME PLAY FUNCTIONS
void inputTooltip();
void checkActions();

void PlayerFight(int prisonerFighter);
void PlayerFire();
void ContrabandSearch();
void UseInventoryItem();
void TalkToPrisoners();

void SearchRandomCell();
void PlayMiniGames(std::string gameType); //Board Games, Table Football, Football, Chess
void BreakIn(std::string breakRoom); //Side Room In Reception, Guards Cabinet
void RaiseAlarm();
void WatchPrisoners(); //Play Football
void GoForRun();
void TrainingDummies();
void Meditation();
void EatMeal(int playerLocation); //Canteen, Personal Cell
void UseVendingMachine(int playerLocation); //Canteen, Personal Cell
void PrisonerWork(int playerLocation); //Work In Kitchen, Laundry, Prison Store
void HealthCheckup();
void ConsultDoctor();
void PrayAtChapel(std::string prayerType); //Silence, Prayer Session, Mass
void JoinAA();
void WatchTV();
void JoinEnglishClass();
void JoinMathsClass();
void JoinWorksClass();
void ShopAtStore();
void JoinVisitation(std::string playerGuest); //Family, Lawyer, Prisoner Penpal, Lover, Supplier
void MakePhoneCall();
void PrisonerSleep();
void PrisonerLookOutWindow();
void StoreContraband();
void StartDiggingTunnel();
void TakeShower();
void InsideTunnel();
void AttendTherapy();
void SearchThroughFiles();
#pragma endregion

struct InventoryItems
{
	std::string itemName;
	double itemCost;

	bool inPlayerPosession;

	//Damage Weapons
	int weaponDamage;

	//Health Items
	int healthBoost;

	//Stamina Items
	int staminaBoost;

	//Happiness Items
	int happinesBoost;
};
extern InventoryItems lighter;
extern InventoryItems spoon;
extern InventoryItems guardKeys;
extern InventoryItems knife;
extern InventoryItems tazer;
extern InventoryItems handgun;
extern InventoryItems candy;
extern InventoryItems crisps;
extern InventoryItems sodaDrink;
extern InventoryItems energyDrink;
extern InventoryItems porkPie;
extern InventoryItems ramen;
extern InventoryItems sausageBeans;
extern InventoryItems carrotCake;
extern InventoryItems honeyBun;
extern InventoryItems gingerBread;
extern InventoryItems kiplingCakes;
extern InventoryItems phoneCallToken;
extern InventoryItems boardGame;
extern InventoryItems shampoo;
extern InventoryItems magazine;
extern InventoryItems personalRadio;

class Prisoners
{
public:
	//BASIC INFORMATION
	std::string prisonerName = "Steve";
	int prisonerAge = 18;

	//PLAYER INTERACTION VARIABLES
	int prisonerHP = 100;
	int likesPlayer = 0;

	//ASSIGNED CELL
	int assignedCell = 0;

	void JoinGang()
	{
		std::cout << "\nNo";
	}
};
extern Prisoners prisoners[499];

class Player : public Prisoners
{
public:
	//BASIC INFORMATION
	std::string playerName = "Steve Irwin";
	int playerAge = 0;
	int playerClass = 0;
	double playerCurrency = 0;

	//PLAYER STATS
	int playerHP = 100;
	int playerStamina = 100;
	int playerStrength = 0;
	int playerRapport = 0;
	int playerDamage = 0;
	int playerHappines = 50;
	bool AccessToTherapy = false;

	//PLAYER SKILLS
	int playerCombat = 5;
	int playerComputing = 0;
	int playerLockpicking = 0;
	int playerRunningSpeed = 2;
	int playerFootball = 0;

	//PLAYER INVENTORY
	std::string inventoryItemName[5]{ "None","None","None","None","None" };
	bool inventoryFull = false;

	//CONTRABAND CHANCES
	int findContrabandChance = 0;
	int guardSearchChance = 0;

	//INVENTORY BOOLS
	bool hasLighter = false;
	bool hasSpoon = false;
	bool hasKeys = false;

	bool hasKnife = false;
	bool hasTazer = false;
	bool hasHandgun = false;

	bool hasDrugs = false;

	bool hasCandy = false;
	bool hasCrisps = false;
	bool hasSodaDrink = false;
	bool hasEnergyDrink = false;

	bool hasPorkPie = false;
	bool hasRamen = false;
	bool hasSausageBeans = false;
	bool hasCarrotCake = false;
	bool hasHoneyBun = false;
	bool hasGingerBread = false;
	bool hasKiplingCakes = false;

	bool hasPhoneToken = false;
	bool hasBoardGame = false;
	bool hasShampoo = false;
	bool hasMagazine = false;
	bool hasPersonalRadio = false;

	//CLASSROOM BOOLS
	bool completedEnglish = false;
	bool completedMaths = false;
	bool completedWorks = false;

	//ESCAPE BOOLS
	bool canDigTunnel = false;

	//PLAYER FUNCTIONS
	void CheckClass(int playerClass)
	{
		switch (playerClass)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}
	}

	void CheckStrength()
	{
		playerStrength = (playerStamina * playerCombat) / 100;
	}

	void CheckDamage()
	{
		if (hasKnife == true) playerDamage = playerStrength + knife.weaponDamage;
		if (hasTazer == true) playerDamage = playerStrength + tazer.weaponDamage;
		if (hasHandgun == true) playerDamage = playerStrength + handgun.weaponDamage;
		else playerDamage = playerStrength;
	}

	void CheckStamina()
	{
		if (playerStamina < 10)
		{
			system("CLS");
			textTyper("Your stamina is extremely low, you should consider resting soon.");
			system("pause");
		}
	}

	void CheckInventory()
	{
		std::cout << "PLAYER INVENTORY\nSlot 1: " << inventoryItemName[0] << " Slot 2: " << inventoryItemName[1] << " Slot 3: " << inventoryItemName[2] << " Slot 4: " << inventoryItemName[3] << " Slot 5: " << inventoryItemName[4] << std::endl;
	}
};
extern Player player;

class SideCharacters : public Prisoners
{
public:
	//BASIC INFORMATION
	bool characterInAction = false;
	std::string characterName ="Steve";
	int characterAge = 0;

	//PLAYER INTERACTION VARIABLES
	int characterHP = 100;
	int likesPlayer = 0;

	//ASSIGNED CELL
	int assignedCell = 0;

	void CheckSideCharacter(int prisonerNumber)
	{
		if (prisoners[prisonerNumber].likesPlayer < 50)
		{
			characterInAction = true;
			characterName = (prisoners + prisonerNumber)->prisonerName;
			std::cout << characterName;
		}
	}

	void JoinGang()
	{
		std::cout << "\nYes";
	}
};
extern SideCharacters sideCharacters[499];

struct PlayerActions
{
	int actionID;
	bool playerPermission;
	std::string actionType;
	std::string actionDescription;
};
extern PlayerActions playerActions[69];

class PrisonRooms
{
public:
	bool playerAccess = true;
	std::string roomName;
	std::string roomDescription;
	int gPresentAtDay[14];
	int gPresentAtNight;
	int pPresentAtDay[14];
	int pPresentAtNight;

private:
	bool firstVisit = true;
	std::string enterMethods[2] = { "You walk into ", "You awake in " };
	int roomAction;
	int printedAction[70];

public:
	//PLAYER HAS ENTERED ROOM
	void enterRoom(int enterMethod)
	{
		//CLEAR CONSOLE
		system("CLS");

		//DISPLAY ROOM DETAILS
		PlayerAccess();
		gameTopline();
		ShowRoomDescription(enterMethod);
		ShowRoomGuardCount();
		ShowRoomPrisonerCount();
		DisplayPlayerActions();

		//PLAYER INPUT
		PlayerActionChoice();
	}

private:
	//DETERMINE PLAYER ACCESS TO ROOM
	void PlayerAccess()
	{

	}

	//SHOW ROOM DESCRIPTION
	void ShowRoomDescription(int enterMethod)
	{
		if (firstVisit)
		{
			textTyper(enterMethods[enterMethod] + roomName + ". " + roomDescription);
			firstVisit = false;
		}

		else textTyper(enterMethods[enterMethod] + roomName + ". " + roomDescription);
	}

	//SHOW NUMBER OG GUARDS IN ROOM
	void ShowRoomGuardCount()
	{
		switch (hour)
		{
		case 7:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[0] << "\033[0;m" << " guards present.";
			break;
		case 8:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[1] << "\033[0;m" << " guards present.";
			break;
		case 9:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[2] << "\033[0;m" << " guards present.";
			break;
		case 10:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[3] << "\033[0;m" << " guards present.";
			break;
		case 11:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[4] << "\033[0;m" << " guards present.";
			break;
		case 12:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[5] << "\033[0;m" << " guards present.";
			break;
		case 13:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[6] << "\033[0;m" << " guards present.";
			break;
		case 14:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[7] << "\033[0;m" << " guards present.";
			break;
		case 15:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[8] << "\033[0;m" << " guards present.";
			break;
		case 16:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[9] << "\033[0;m" << " guards present.";
			break;
		case 17:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[10] << "\033[0;m" << " guards present.";
			break;
		case 18:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[11] << "\033[0;m" << " guards present.";
			break;
		case 19:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[12] << "\033[0;m" << " guards present.";
			break;
		case 20:
			std::cout << "There are " << "\033[0;34m" << gPresentAtDay[13] << "\033[0;m" << " guards present.";
			break;
		default:
			std::cout << "There are " << "\033[0;34m" << gPresentAtNight << "\033[0;m" << " guards present.";
		}
	}

	//SHOW NUMBER OF PRISONERS IN ROOM
	void ShowRoomPrisonerCount()
	{
		switch (hour)
		{
		case 7:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[0] << "\033[0;m" << " prisoners present.";
			break;
		case 8:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[1] << "\033[0;m" << " prisoners present.";
			break;
		case 9:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[2] << "\033[0;m" << " prisoners present.";
			break;
		case 10:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[3] << "\033[0;m" << " prisoners present.";
			break;
		case 11:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[4] << "\033[0;m" << " prisoners present.";
			break;
		case 12:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[5] << "\033[0;m" << " prisoners present.";
			break;
		case 13:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[6] << "\033[0;m" << " prisoners present.";
			break;
		case 14:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[7] << "\033[0;m" << " prisoners present.";
			break;
		case 15:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[8] << "\033[0;m" << " prisoners present.";
			break;
		case 16:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[9] << "\033[0;m" << " prisoners present.";
			break;
		case 17:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[10] << "\033[0;m" << " prisoners present.";
			break;
		case 18:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[11] << "\033[0;m" << " prisoners present.";
			break;
		case 19:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[12] << "\033[0;m" << " prisoners present.";
			break;
		case 20:
			std::cout << " There are " << "\033[0;33m" << pPresentAtDay[13] << "\033[0;m" << " prisoners present.";
			break;
		default:
			std::cout << " There are " << "\033[0;33m" << pPresentAtNight << "\033[0;m" << " prisoners present.";
		}
	}

	//SHOW LIST OF POSSIBLE ACTIONS
	void DisplayPlayerActions()
	{
		//CHECK ACTION PERMISSIONS
		checkActions();

		//RESET LOOP
		roomAction = 1;
		std::cout << "\n\n";

		fori(70)
		{
			if (playerActions[i].playerPermission == true && playerActions[i].actionType == "roomaction")
			{
				std::cout << "[" << roomAction << "] " << playerActions[i].actionDescription;
				printedAction[roomAction] = i;
				roomAction++;
			}
		}

		std::cout << "\n";
		fori(70)
		{
			if (playerActions[i].playerPermission == true && playerActions[i].actionType == "globalaction")
			{
				std::cout << "[" << roomAction << "] " << playerActions[i].actionDescription;
				printedAction[roomAction] = i;
				roomAction++;
			}
		}

		std::cout << "\n";
		fori(70)
		{
			if (playerActions[i].playerPermission == true && playerActions[i].actionType == "location")
			{
				std::cout << "[" << roomAction << "] " << playerActions[i].actionDescription;
				printedAction[roomAction] = i;
				roomAction++;
			}
		}
	}

	//ENTER ACTION INTO SWITCH
	void PlayerActionChoice()
	{
		inputTooltip();
		std::cin >> roomAction;
		switch (roomAction)
		{
		case 1:
			CompleteAction(printedAction[roomAction]);
			break;
		case 2:
			CompleteAction(printedAction[roomAction]);
			break;
		case 3:
			CompleteAction(printedAction[roomAction]);
			break;
		case 4:
			CompleteAction(printedAction[roomAction]);
			break;
		case 5:
			CompleteAction(printedAction[roomAction]);
			break;
		case 6:
			CompleteAction(printedAction[roomAction]);
			break;
		case 7:
			CompleteAction(printedAction[roomAction]);
			break;
		case 8:
			CompleteAction(printedAction[roomAction]);
			break;
		case 9:
			CompleteAction(printedAction[roomAction]);
			break;
		case 10:
			CompleteAction(printedAction[roomAction]);
			break;
		case 11:
			CompleteAction(printedAction[roomAction]);
			break;
		case 12:
			CompleteAction(printedAction[roomAction]);
			break;
		case 13:
			CompleteAction(printedAction[roomAction]);
			break;
		case 14:
			CompleteAction(printedAction[roomAction]);
			break;
		case 15:
			CompleteAction(printedAction[roomAction]);
			break;
		case 16:
			CompleteAction(printedAction[roomAction]);
			break;
		case 17:
			CompleteAction(printedAction[roomAction]);
			break;
		case 18:
			CompleteAction(printedAction[roomAction]);
			break;
		case 19:
			CompleteAction(printedAction[roomAction]);
			break;
		case 20:
			CompleteAction(printedAction[roomAction]);
			break;
		case 21:
			CompleteAction(printedAction[roomAction]);
			break;
		case 22:
			CompleteAction(printedAction[roomAction]);
			break;
		case 23:
			CompleteAction(printedAction[roomAction]);
			break;
		case 24:
			CompleteAction(printedAction[roomAction]);
			break;
		case 25:
			CompleteAction(printedAction[roomAction]);
			break;
		}
	}

	//EXECUTE ACTION FUNCTION
	void CompleteAction(int actionNumber)
	{
		switch (actionNumber)
		{
		case 0:
			playerLocation = 0;
			addMin(2);
			gamePlay(0);
			break;
		case 1:
			playerLocation = 1;
			addMin(2);
			gamePlay(0);
			break;
		case 2:
			playerLocation = 2;
			addMin(2);
			gamePlay(0);
			break;
		case 3:
			playerLocation = 3;
			addMin(2);
			gamePlay(0);
			break;
		case 4:
			playerLocation = 4;
			addMin(2);
			gamePlay(0);
			break;
		case 5:
			playerLocation = 5;
			addMin(2);
			gamePlay(0);
			break;
		case 6:
			playerLocation = 6;
			addMin(2);
			gamePlay(0);
			break;
		case 7:
			playerLocation = 7;
			addMin(2);
			gamePlay(0);
			break;
		case 8:
			playerLocation = 8;
			addMin(2);
			gamePlay(0);
			break;
		case 9:
			playerLocation = 9;
			addMin(2);
			gamePlay(0);
			break;
		case 10:
			playerLocation = 10;
			addMin(2);
			gamePlay(0);
			break;
		case 11:
			playerLocation = 11;
			addMin(2);
			gamePlay(0);
			break;
		case 12:
			playerLocation = 12;
			addMin(2);
			gamePlay(0);
			break;
		case 13:
			playerLocation = 13;
			addMin(2);
			gamePlay(0);
			break;
		case 14:
			playerLocation = 14;
			addMin(2);
			gamePlay(0);
			break;
		case 15:
			playerLocation = 15;
			addMin(2);
			gamePlay(0);
			break;
		case 16:
			playerLocation = 16;
			addMin(2);
			gamePlay(0);
			break;
		case 17:
			playerLocation = 17;
			addMin(2);
			gamePlay(0);
			break;
		case 18:
			playerLocation = 18;
			addMin(2);
			gamePlay(0);
			break;
		case 19:
			int prisonerFighter;
			if (hour > 7 && hour < 22) prisonerFighter = rand() % pPresentAtDay[hour - 7];
			else prisonerFighter = rand() % pPresentAtNight;
			PlayerFight(prisonerFighter);
			addMin(2);
			if (player.playerHP < 5 && player.playerHP > 0)
			{
				playerLocation = 8;
				player.playerStamina = 100;
				gamePlay(1);
			}
			player.CheckStamina();
			break;
		case 20:
			PlayerFire();
			addMin(2);
			break;
		case 21:
			ContrabandSearch();
			addMin(2);
			break;
		case 22:
			UseInventoryItem();
			addMin(2);
			break;
		case 23:
			TalkToPrisoners();
			addMin(2);
			break;
		case 24:
			SearchRandomCell();
			addMin(2);
			break;
		case 25:
			PlayMiniGames("boardGame");
			addMin(2);
			break;
		case 26:
			BreakIn("sideRoom");
			addMin(5);
			gamePlay(0);
			break;
		case 27:
			BreakIn("guardCabinet");
			addMin(2);
			gamePlay(0);
			break;
		case 28:
			RaiseAlarm();
			addMin(2);
			break;
		case 29:
			PlayMiniGames("football");
			addMin(2);
			break;
		case 30:
			WatchPrisoners();
			addMin(15);
			gamePlay(0);
			break;
		case 31:
			GoForRun();
			player.CheckStamina();
			gamePlay(0);
			break;
		case 32:
			TrainingDummies();
			addMin(60);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 33:
			Meditation();
			player.CheckStamina();
			gamePlay(0);
			break;
		case 34:
			EatMeal(playerLocation);
			addMin(2);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 35:
			UseVendingMachine(playerLocation);
			addMin(1);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 36:
			PrisonerWork(playerLocation);
			addMin(2);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 37:
			HealthCheckup();
			addMin(2);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 38:
			ConsultDoctor();
			addMin(2);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 39:
			PrayAtChapel("silence");
			addMin(2);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 40:
			PrayAtChapel("prayerSession");
			addMin(2);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 41:
			PrayAtChapel("mass");
			addMin(2);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 42:
			JoinAA();
			addMin(2);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 43:
			PlayMiniGames("tableFootball");
			addMin(2);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 44:
			PlayMiniGames("chess");
			addMin(2);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 45:
			WatchTV();
			addMin(60);
			player.CheckStamina();
			gamePlay(0);
			break;
		case 46:
			PrisonerWork(playerLocation);
			addMin(2);
			break;
		case 47:
			addMin(60);
			JoinMathsClass();
			player.CheckStamina();
			gamePlay(0);
			break;
		case 48:
			addMin(60);
			JoinEnglishClass();
			player.CheckStamina();
			gamePlay(0);
			break;
		case 49:
			addMin(60);
			JoinWorksClass();
			player.CheckStamina();
			gamePlay(0);
			break;
		case 50:
			PrisonerWork(playerLocation);
			addMin(2);
			break;
		case 51:
			addMin(15);
			ShopAtStore();
			player.CheckStamina();
			gamePlay(0);
			break;
		case 52:
			JoinVisitation("family");
			addMin(2);
			break;
		case 53:
			JoinVisitation("laywer");
			addMin(2);
			break;
		case 54:
			JoinVisitation("penPal");
			addMin(2);
			break;
		case 55:
			JoinVisitation("lover");
			addMin(2);
			break;
		case 56:
			JoinVisitation("supplier");
			addMin(2);
			break;
		case 57:
			MakePhoneCall();
			addMin(2);
			break;
		case 58:
			PrisonerSleep();
			addMin(2);
			break;
		case 59:
			PrisonerLookOutWindow();
			addMin(2);
			break;
		case 60:
			StoreContraband();
			addMin(2);
			break;
		case 61:
			StartDiggingTunnel();
			addMin(2);
			break;
		case 62:
			TakeShower();
			addMin(2);
			break;
		case 63:
			InsideTunnel();
			addMin(2);
			break;
		case 64:
			InsideTunnel();
			addMin(2);
			break;
		case 65:
			InsideTunnel();
			addMin(2);
			break;
		case 66:
			AttendTherapy();
			addMin(2);
			break;
		case 67:
			SearchThroughFiles();
			addMin(2);
			break;
		case 68:
			StoreContraband();
			addMin(2);
			break;
		}
	}
};
extern PrisonRooms prisonRooms[19];

class Cells
{
public:
	Prisoners assignedPrisoner;
};
extern Cells prisonerCells[499];