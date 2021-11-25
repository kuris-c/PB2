#include "prepro.h"
#include <random>
#include <numeric>
#include <Windows.h>

#pragma region LOCKPICKING VARIABLES
int lockDistance;
bool lockPicking;

struct LockPickingScenarios
{
	std::string scenarioText;
	std::string scenarioResponse[3];

	void PrintScenario()
	{
		std::string playerInput;

		system("CLS");
		std::cout << scenarioText;
		std::cout << scenarioResponse[0];
		std::cout << scenarioResponse[1];
		std::cout << scenarioResponse[2];
		std::cout << "\n";
		std::getline(std::cin, playerInput);
		ScenarioResult(playerInput);
	}

	void ScenarioResult(std::string playerInput)
	{
		int playerInputs = 0;
		std::string contains1("significant resistence");
		std::string contains2("some resistence");
		std::string contains3("no resistance");

		std::string contains4("Turn");
		std::string contains5("Push");
		std::string contains6("Stop");

		std::string contains7("1");
		std::string contains8("2");
		std::string contains9("3");

		if (playerInput.find(contains7) != std::string::npos)
		{
			playerInputs = 0;
		}

		if (playerInput.find(contains8) != std::string::npos)
		{
			playerInputs = 1;
		}

		if (playerInput.find(contains9) != std::string::npos)
		{
			playerInputs = 2;
		}

		if (scenarioText.find(contains1) != std::string::npos)
		{
			if (scenarioResponse[playerInputs].find(contains4) != std::string::npos)
			{
				std::cout << "The lock turned and eventually kicked. You can now progress." << std::endl;
				lockDistance++;
				system("pause");
			}

			if (scenarioResponse[playerInputs].find(contains5) != std::string::npos)
			{
				std::cout << "You were met with fierce resistance. The lock refused to pick. No progress." << std::endl;
				system("pause");
			}

			if (scenarioResponse[playerInputs].find(contains6) != std::string::npos)
			{
				std::cout << "You stop in your tracks and pull the rake out before you are seen." << std::endl;
				lockPicking = false;
				system("pause");
			}
		}

		if (scenarioText.find(contains2) != std::string::npos)
		{
			if (scenarioResponse[playerInputs].find(contains4) != std::string::npos)
			{
				std::cout << "The lock turned and eventually kicked. You can now progress." << std::endl;
				lockDistance++;
				system("pause");
			}

			if (scenarioResponse[playerInputs].find(contains5) != std::string::npos)
			{
				std::cout << "You were met with too much resistance. The lock refused to pick. No progress." << std::endl;
				system("pause");
			}

			if (scenarioResponse[playerInputs].find(contains6) != std::string::npos)
			{
				std::cout << "You stop in your tracks and pull the rake out before you are seen." << std::endl;
				lockPicking = false;
				system("pause");
			}
		}

		if (scenarioText.find(contains3) != std::string::npos)
		{
			if (scenarioResponse[playerInputs].find(contains4) != std::string::npos)
			{
				std::cout << "You turn and realise that you should not have done that. No progress." << std::endl;
				system("pause");
			}

			if (scenarioResponse[playerInputs].find(contains5) != std::string::npos)
			{
				std::cout << "The lock clicked. You can now progress." << std::endl;
				lockDistance++;
				system("pause");
			}

			if (scenarioResponse[playerInputs].find(contains6) != std::string::npos)
			{
				std::cout << "You stop in your tracks and pull the rake out before you are seen." << std::endl;
				lockPicking = false;
				system("pause");
			}
		}
	}
};
LockPickingScenarios lockPickingScenarios[3];
#pragma endregion

#pragma region GO FOR A RUN VARIABLES
int runDistance = 0;
bool onARun = true;
void GoForRun();

struct RunningScenarios
{
	std::string scenarioText;
	std::string scenarioResponse[3];

	void PrintScenario()
	{
		int playerInput;

		std::cout << scenarioText;
		std::cout << scenarioResponse[0];
		std::cout << scenarioResponse[1];
		std::cout << scenarioResponse[2];
		std::cout << "\n";
		inputTooltip();
		std::cin >> playerInput, std::cin.ignore();
		ScenarioResult(playerInput - 1);
	}

	void ScenarioResult(int playerInput)
	{
		std::string contains1("Hop The Fence");
		std::string contains2("Change Direction");
		std::string contains3("Stop For A Break");
		std::string contains4("Check Your Inventory For A Snack");
		std::string contains5("Search For Contraband");
		std::string contains6("Keep Running");
		std::string contains7("Stop Running");

		if (scenarioResponse[playerInput].find(contains1) != std::string::npos)
		{
			std::cout << "You hope the fence and continue on your path.\n";
			player.playerStamina -= 10;
			runDistance++;
			system("pause");
		}

		if (scenarioResponse[playerInput].find(contains2) != std::string::npos)
		{
			std::cout << "You change direction, slightly pushing you behind where you would like to be.\n";
			player.playerStamina -= 5;
			system("pause");
		}

		if (scenarioResponse[playerInput].find(contains3) != std::string::npos)
		{
			std::cout << "You take a small break to regather some Stamina.\n";
			player.playerStamina -= 2;
			runDistance++;
			system("pause");
		}

		if (scenarioResponse[playerInput].find(contains4) != std::string::npos)
		{
			std::cout << "WORKED";
			player.playerStamina -= 5;
			//PLAYER INVENTORY
			runDistance++;
			system("pause");
		}

		if (scenarioResponse[playerInput].find(contains5) != std::string::npos)
		{
			std::cout << "WORKED";
			player.playerStamina -= 5;
			//PLAYER CONTRABAND
			runDistance++;
			system("pause");
		}

		if (scenarioResponse[playerInput].find(contains6) != std::string::npos)
		{
			std::cout << "You keep pushing ahead!\n";
			player.playerStamina -= 10;
			runDistance++;
			system("pause");
		}

		if (scenarioResponse[playerInput].find(contains7) != std::string::npos)
		{
			std::cout << "You stop running before your target. The gains are not as good as you would like, but still impressive.\n";
			player.playerStamina -= 10;
			addMin(runDistance * 10);
			player.playerRunningSpeed += runDistance;
			onARun = false;
			system("pause");
		}
	}
};
RunningScenarios runningScenarios[5];
#pragma endregion

#pragma region TRAINING DUMMY VARIABLES
bool skillObtained[3]{ false, false, false };
void TrainingDummies();
#pragma endregion

#pragma region MEDITATION VARIABLES;
std::string philQuotes[30];
#pragma endregion

#pragma region CLASSROOM VARIABLES
//SUBJECT QUESTIONS
struct matClassQuestions
{
	//CREATE QUESTIONS
	std::string question;
	std::string answers[2];

	//CORRECT
	bool questionAnswered = false;
	bool questionCorrect = false;

	void CheckAnswer(std::string playerAnswer)
	{
		questionAnswered = true;

		if (playerAnswer == answers[0] || playerAnswer == answers[1])
		{
			questionCorrect = true;
		}
	}
};
matClassQuestions matQuestions[45];

struct engClassQuestions
{
	//CREATE QUESTIONS
	std::string question;
	std::string answers[2];

	//CORRECT
	bool questionAnswered = false;
	bool questionCorrect = false;

	void CheckAnswer(std::string playerAnswer)
	{
		questionAnswered = true;

		if (playerAnswer == answers[0] || playerAnswer == answers[1])
		{
			questionCorrect = true;
		}
	}
};
engClassQuestions engQuestions[45];

struct worClassQuestions
{
	//CREATE QUESTIONS
	std::string question;
	std::string answers[2];

	//CORRECT
	bool questionAnswered = false;
	bool questionCorrect = false;

	void CheckAnswer(std::string playerAnswer)
	{
		questionAnswered = true;

		if (playerAnswer == answers[0] || playerAnswer == answers[1])
		{
			questionCorrect = true;
		}
	}
};
worClassQuestions worQuestions[45];

//CLASS VARIABLES
std::string playerAnswer;
int questionOrder[15];

//QUESTIONS ANSWERED
int matQuestionsAnswered = 0;
int engQuestionsAnswered = 0;
int worQuestionsAnswered = 0;

//QUESTIONS ASKED
int matQuestionsAsked = 0;
int engQuestionsAsked = 0;
int worQuestionsAsked = 0;
#pragma endregion

#pragma region LOOK OUT WINDOW VARIABLES
bool firstLook = true;
bool discoveredTunnel = false;
#pragma endregion

void gamePlay(int enterMethod)
{
		prisonRooms[playerLocation].enterRoom(enterMethod);
}

void PlayerFight(int prisonerFighter)
{
	int playerChoice;
	bool playerFight = true;

	if (player.playerHP > 20)
	{
		system("CLS");
		textTyper("You approach " + prisoners[prisonerFighter].prisonerName + ", shouting at them, beckoning them to a challenge. They look unimpressed, but raise their fists anyway.\n");
	}

	else
	{
		textTyper("You tighten your hands into fists, approaching " + prisoners[prisonerFighter].prisonerName + " as you do. They look at you, calmly saying they do not want to fight someone so injured and weak.");
		std::cout << "\n\nThis is because your HP is less than 20. Would you like to:\n\n[1] Start A Fight Anyway[2] Walk Away\n\n" << std::endl;
		inputTooltip();
		std::cin >> playerChoice;

		switch (playerChoice)
		{
		case 1:
			textTyper("You continue to taunt your opponent, calling them cowardly, mocking their appearance and even daring to spit in his face. Finally, he raises his fists to match your own, and braces for combat. Almost laughing to himself at how easy this will be.");
			break;
		case 2:
			textTyper("You take a step back, refusing to apologise nonetheless, but retreating from the battlefield to protect yourself. There is some jeering from the building audience.");
			playerFight = false;
			break;
		default:
			std::cout << "Input Not Recognised. Try Again" << std::endl;
			inputTooltip();
			std::cin >> playerChoice;
		}
	}

	while (playerFight)
	{
		if (player.playerHP <= 0)
		{
			if (playerChoice == 69) gameLose("Brutal Blow To The Dick", 90);
			else gameLose("Was That Really Worth It?", 90);
			playerFight = false;
		}

		if (player.playerHP < 5 && player.playerHP > 0)
		{
			player.playerHappines -= 25;
			playerFight = false;
		}

		else
		{
			if (prisoners[prisonerFighter].prisonerHP >= 50)
			{
				textTyper("\nHe maintains a confident look on his face, showing little bruising or damage from the fight so far.");
			}

			if (prisoners[prisonerFighter].prisonerHP < 50 && prisoners[prisonerFighter].prisonerHP > 29)
			{
				textTyper("\nHis face shows moderate signs of trauma, with some bruising on the eyes and tears on the uniform from being stretched.");
			}

			if (prisoners[prisonerFighter].prisonerHP < 30 && prisoners[prisonerFighter].prisonerHP > 9)
			{
				textTyper("\nHis nose drips slightly with blood, the eye almost completely black and bruising all over the body.");
			}

			if (prisoners[prisonerFighter].prisonerHP < 10 && prisoners[prisonerFighter].prisonerHP > 0)
			{
				textTyper("\nHe lies on the floor, almost lifeless and close to death. There are cries from him begging you to stop, but ruthless cheering from the audience.");
				player.playerCombat += static_cast <int> (0.5);
			}

			if (prisoners[prisonerFighter].prisonerHP <= 0)
			{
				textTyper("The body of " + prisoners[prisonerFighter].prisonerName + " lies in front of you.");
				std::cout << "\n " << prisoners[prisonerFighter].prisonerName << "died at " << prisoners[prisonerFighter].prisonerAge << std::endl;
				replacePrisoner(prisonerFighter);
				system("pause");
				//Prisoner Solitary Confinement
				playerFight = false;
			}

			//SUCCESS VARIABLES
			player.CheckStrength();
			player.CheckDamage();
			int playerSuccess;
			int enemyDamage, enemyDamageBoost = 0;

			//ATTACK
			std::cout << "\n\n[1] Throw A Punch\n[2] Kick Your Opponent In The Shins\n[3] Attempt To Kick Your Opponent In The Face\n[4] Prepare To Block An Attack\n[5] Withdraw From The Fight\n";
			inputTooltip();
			std::cin >> playerChoice;
			addMin(static_cast <int> (0.5));

			switch (playerChoice)
			{
			case 1:
				//PLAYER PUNCH
				playerSuccess = rand() % 5;
				switch (playerSuccess)
				{
				case 0:
					system("CLS");
					std::cout << "Your punch lands a fierce blow to the jaw. Damage Dealt: " << player.playerDamage + 1;
					player.playerStamina -= 1;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage + 1);
					break;
				case 1:
					system("CLS");
					std::cout << "Your punch lands a fierce blow to the jaw. Damage Dealt: " << player.playerDamage + 1;
					player.playerStamina -= 1;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage + 1);
					break;
				case 2:
					system("CLS");
					std::cout << "Your punch lands a powerful blow to the stomach. He heaves momentarily in annoyance. Damage Dealt: " << player.playerDamage;
					player.playerStamina -= 1;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage);
					break;
					system("CLS");
					std::cout << "Your punch lands a powerful blow to the stomach. He heaves momentarily in annoyance. Damage Dealt: " << player.playerDamage;
					player.playerStamina -= 1;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage);
					break;
				case 3:
					system("CLS");
					std::cout << "Your punch lands a painful sting to the arm. Some damage is blocked. Damage Dealt: " << (player.playerDamage - 1);
					player.playerStamina -= 1;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage - 1);
					break;
					system("CLS");
					std::cout << "Your punch lands a painful sting to the arm. Some damage is blocked. Damage Dealt: " << (player.playerDamage - 1);
					player.playerStamina -= 1;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage - 1);
					break;
				case 4:
					system("CLS");
					std::cout << prisoners[prisonerFighter].prisonerName <<+ " predicted this attack, and was able to catch your hand, throw you off and prepare for a more damning shot. No Damage Dealt.";
					player.playerStamina -= 1;
					enemyDamageBoost = 1;
					break;
				}
				break;
			case 2:
				//PLAYER KICK SHINS
				playerSuccess = rand() % 5;
				switch (playerSuccess)
				{
				case 0:
					system("CLS");
					std::cout << "Your kick with raw power, he yelps in pain. Damage Dealt: " << (player.playerDamage + 3);
					player.playerStamina -= 2;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage + 3);
					break;
				case 1:
					system("CLS");
					std::cout << "Your kick with raw power, he yelps in pain. Damage Dealt: " << (player.playerDamage + 3);
					player.playerStamina -= 2;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage + 3);
					break;
				case 2:
					system("CLS");
					std::cout << "Your kick with your foot, landing a successful blow, he yelps in pain. Damage Dealt: " << (player.playerDamage);
					player.playerStamina -= 2;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage);
					break;
				case 3:
					system("CLS");
					std::cout << "Your kick with your foot, landing a successful blow, he yelps in pain. Damage Dealt: " << (player.playerDamage);
					player.playerStamina -= 2;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage);
					break;
				case 4:
					system("CLS");
					std::cout << prisoners[prisonerFighter].prisonerName << " predicted this attack, and was able to catch your foot, throw you off and prepare for a more damning shot. No Damage Dealt.";
					player.playerStamina -= 2;
					enemyDamageBoost = 1;
					break;
				}
				break;
			case 3:
				//PLAYER KICK FACE
				playerSuccess = rand() % 7;
				switch (playerSuccess)
				{
				case 0:
					system("CLS");
					std::cout << "Your kick with raw power, his face is knocked to the side. Damage Dealt: " << (player.playerDamage + 5);
					player.playerStamina -= 10;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage + 3);
					break;
				case 1:
					system("CLS");
					std::cout << "Your kick with raw power, his face is knocked to the side. Damage Dealt: " << (player.playerDamage + 5);
					player.playerStamina -= 10;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage + 3);
					break;
				case 2:
					system("CLS");
					std::cout << "Your kick with raw power, his face is knocked to the side. Damage Dealt: " << (player.playerDamage + 5);
					player.playerStamina -= 10;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage + 3);
					break;
				case 3:
					system("CLS");
					std::cout << "Your kick with your foot, landing a successful blow, he yelps in pain. Damage Dealt: " << (player.playerDamage);
					player.playerStamina -= 10;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage);
					break;
				case 4:
					system("CLS");
					std::cout << "Your kick with your foot, landing a successful blow, he yelps in pain. Damage Dealt: " << (player.playerDamage);
					player.playerStamina -= 10;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage);
					break;
				case 5:
					system("CLS");
					std::cout << "Your kick with your foot, landing a successful blow, he yelps in pain. Damage Dealt: " << (player.playerDamage);
					player.playerStamina -= 10;
					prisoners[prisonerFighter].prisonerHP -= (player.playerDamage);
					break;
				case 6:
					system("CLS");
					std::cout << prisoners[prisonerFighter].prisonerName << " predicted this attack, and was able to catch your foot, throw you off and prepare for a more damning shot. No Damage Dealt.";
					player.playerStamina -= 5;
					enemyDamageBoost = 3;
					break;
				}
				break;
			case 4:
				//PLAYER BLOCK
				playerSuccess = rand() % 3;
				switch (playerSuccess)
				{
				case 0:
					system("CLS");
					std::cout << "You correctly predict your enemies next attack, preparing yourself as he lunges. Damage Blocked: " << (player.playerDamage);
					player.playerStamina -= 1;
					enemyDamageBoost = -player.playerDamage;
					break;
				case 1:
					system("CLS");
					std::cout << "You correctly predict your enemies next attack, preparing yourself as he kicks. Damage Blocked: " << (player.playerDamage);
					player.playerStamina -= 1;
					enemyDamageBoost = -player.playerDamage;
					break;
				case 2:
					system("CLS");
					std::cout << "You incorrectly guess the attack of the prisoner, and fail to move in time to block the attack.";
					enemyDamageBoost = 0;
					break;
				}
				break;
			case 5:
				//PLAYER WITHDRAW
				textTyper("You hang your hands up in retreat. You quickly leave the scene, to the sound of some jeering from the audience");
				//PLAYER RUNS AWAY
				playerFight = false;
				break;
			case 69:
				playerSuccess = rand() % 2;
				switch (playerSuccess)
				{
				case 0:
					textTyper("You deal a shocking blow to " + prisoners[prisonerFighter].prisonerName + "'s genitals. It is a ruthless and daring attack, that has paid off.");
					break;
				case 1:
					textTyper("He repels your perverted charge, and retaliates in kind.");
					break;
				}
			default:
				std::cout << "Input Not Recognised. Try Again" << std::endl;
				inputTooltip();
				std::cin >> playerChoice;
			}

			textTyper("\n\nHe makes his attack.");
			std::random_device damage;
			std::mt19937 rng(damage());
			std::uniform_int_distribution<std::mt19937::result_type> enemyDam(1, 7);
			enemyDamage = enemyDam(rng) + enemyDamageBoost;
			player.playerHP -= enemyDamage;
			player.playerHappines -= enemyDamage / 2;
			std::cout << " Damage Dealt: " << enemyDamage;

			if (player.completedMaths)
			{
				std::cout << "\nPlayer HP: " << player.playerHP << ". " << prisoners[prisonerFighter].prisonerName << " HP: " << prisoners[prisonerFighter].prisonerName;
			}
		}
	}
}

void PlayerFire()
{
	/*REQUIRES LIGHTER, LOCATION, PEOPLE PRESENT
	- IF 0 PRESENT, FIRE ALARM MUST BE RAISED BY PLAYER OR NOT AT ALL
	- IF GUARDS PRESENT, FIRE ALARM IS RAISED
	- IF PRISONERS PRESENT, THEY BEGIN TO ASSIST IN RIOTING
	- IF PRISONERS AND GUARDS, ALARM IS RAISED, THERE IS FIGHTING
	- IF IN RECEPTION, ALARM RAISING GRANTS ACCESS TO OUTER PRISON ENTRANCE*/
}

void ContrabandSearch()
{
	/*PLAYER INVENTORY, 5 SLOTS, HAS RANDOM CHANCE OF GENERATING INVENTORY ITEM THAT CAN BE STORED OR DISCARDED
	- IF SEEN BY PRISONER, PRISONER HAS RANDOM SMALL CHANCE TO SNITCH
	- IF SEEN BY GUARD, CHASE COMMENCES*/
}

void UseInventoryItem()
{
	/*PLAYER INVENTORY, 5 SLOTS, CAN BE USED AT ANY TIME TO COMPLETE ITS ACTION AND IS THEN DISCARDED UNDER MOST CIRCUMSTANCES
	- IF SEEN BY PRISONER, PRISONER HAS SMALL CHANCE TO ASK FOR FOOD, ASK FOR A LIGHT, OR ATTEMPT TO STEAL FROM YOU
	- IF SEEN BY GUARD, DEPENDING ON ITEM, CHASE COMMENCES

	INVENTORY ITEMS
	- LIGHTER: ALLOWS FOR STARTIN A FIRE _ DONE
	- SPOON: ALLOWS FOR DIGGING OF TUNNEL _ DONE
	- GUARD KEYS: ALLOWS FOR OPENING OF ANY DOOR _ DONE
	- KNIFE: DEAL CONSIDERABLE DAMAGE
	- CANDY: QUICKLY REGENERATES HP
	- PORK PIE: QUICKLY REGENERATES HP
	- ENERGY DRINK: QUICKLY REGENERATES STAMINA
	ALL DONE*/
}

void TalkToPrisoners()
{
	/*PRISONER LIKES PLAYER, IF +50 THERE IS POSITIVE INTERACTIONS, IF LESS THAN ZERO THERE IS NEGATIVE
	- CHANCE OF FIGHT STARTING IF BELOW 0 AND INTERACTING
	- PLAYER SOCIAL SKILLS IMPROVES
	- PLAYER RAPPORT COULD INCREASE OR DECREASE*/
}

void SearchRandomCell()
{

}

void PlayMiniGames(std::string gameType)
{

}

void BreakIn(std::string breakRoom)
{
	lockPicking = true;
	lockDistance = 0;
	std::random_device dev;
	std::mt19937 rng(dev());

	lockPickingScenarios[0].scenarioText = "There is significant resistance. Do you: \n\n";
	lockPickingScenarios[0].scenarioResponse[0] = "[1] Turn The Rake Further\n";
	lockPickingScenarios[0].scenarioResponse[1] = "[2] Push The Rake Further Into The Cylinder\n";
	lockPickingScenarios[0].scenarioResponse[2] = "[3] Stop Lockpicking\n";

	lockPickingScenarios[1].scenarioText = "There is some resistance. Do you: \n\n";
	lockPickingScenarios[1].scenarioResponse[0] = "[1] Turn The Rake Further\n";
	lockPickingScenarios[1].scenarioResponse[1] = "[2] Push The Rake Further Into The Cylinder\n";
	lockPickingScenarios[1].scenarioResponse[2] = "[3] Stop Lockpicking\n";

	lockPickingScenarios[2].scenarioText = "There is no resistance. Do you: \n\n";
	lockPickingScenarios[2].scenarioResponse[0] = "[1] Turn The Rake Further\n";
	lockPickingScenarios[2].scenarioResponse[1] = "[2] Push The Rake Further Into The Cylinder\n";
	lockPickingScenarios[2].scenarioResponse[2] = "[3] Stop Lockpicking\n";

	while (lockPicking)
	{
		if (breakRoom == "sideRoom")
		{
			system("CLS");
			std::cout << "You place a rake into the lock cylinder, and begin turning it.";

			std::uniform_int_distribution<std::mt19937::result_type> scenario(0, 6);

			if (scenario(rng) == 0) lockPickingScenarios[0].PrintScenario();
			if (scenario(rng) == 1) lockPickingScenarios[1].PrintScenario();
			if (scenario(rng) == 2) lockPickingScenarios[2].PrintScenario();
			if (scenario(rng) > 2)
			{
				system("CLS");
				std::cout << "You have pushed ahead with the lock without any trouble." << std::endl;
				lockDistance++;
				system("pause");
			}

			if (lockDistance >= 4)
			{
				std::cout << "You realise there is little behind this door. But it has improved your lockpicking skills nonetheless, this could be extremely useful for you. If only \nyou could find an external door." << std::endl;
				system("pause");
				player.playerLockpicking += 10;
				lockPicking = false;
			}
		}

		if (breakRoom == "guardCabinet")
		{
			system("CLS");
			std::cout << "You place a rake into the lock cylinder, and begin turning it.";

			std::uniform_int_distribution<std::mt19937::result_type> scenario(0, 6);

			if (scenario(rng) == 0) lockPickingScenarios[0].PrintScenario();
			if (scenario(rng) == 1) lockPickingScenarios[1].PrintScenario();
			if (scenario(rng) == 2) lockPickingScenarios[2].PrintScenario();
			if (scenario(rng) > 2)
			{
				system("CLS");
				std::cout << "You have pushed ahead with the lock without any trouble.";
				system("pause");
				lockDistance++;
			}

			if (lockDistance >= 4)
			{
				std::cout << "You open the guard cabinet to find some useful tools.";
				lockPicking = false;

				std::uniform_int_distribution<std::mt19937::result_type> weapon(0, 9);
				if (weapon(rng) >= 0 && weapon(rng) <= 2)
				{
					std::cout << "\n\nYou have found some guard keys.\n";
					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
					{
						std::cout << "Your inventory is full. Item Not Added\n";
						system("pause");
					}

					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
					{
						player.inventoryItemName[4] = "guardKeys";
						player.hasKeys = true;
						player.inventoryFull = true;
						system("pause");
					}

					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
					{
						player.inventoryItemName[3] = "guardKeys";
						player.hasKeys = true;
						system("pause");
					}

					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
					{
						player.inventoryItemName[2] = "guardKeys";
						player.hasKeys = true;
						system("pause");
					}

					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
					{
						player.inventoryItemName[1] = "guardKeys";
						player.hasKeys = true;
						system("pause");
					}

					if (player.inventoryItemName[0] == "None")
					{
						player.inventoryItemName[0] = "guardKeys";
						player.hasKeys = true;
						system("pause");
					}
				}
				if (weapon(rng) >= 3 && weapon(rng) <= 8)
				{
					std::cout << "\n\nYou have found a Tazer.\n";
					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
					{
						std::cout << "Your inventory is full. Item Not Added\n";
						system("pause");
					}

					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
					{
						player.inventoryItemName[4] = "tazer";
						player.hasTazer = true;
						player.inventoryFull = true;
						system("pause");
					}

					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
					{
						player.inventoryItemName[3] = "tazer";
						player.hasTazer = true;
						system("pause");
					}

					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
					{
						player.inventoryItemName[2] = "tazer";
						player.hasTazer = true;
						system("pause");
					}

					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
					{
						player.inventoryItemName[1] = "tazer";
						player.hasTazer = true;
						system("pause");
					}

					if (player.inventoryItemName[0] == "None")
					{
						player.inventoryItemName[0] = "tazer";
						player.hasTazer = true;
						system("pause");
					}
				}
				if (weapon(rng) == 9)
				{
					std::cout << "\n\nYou have found a gun. I am sure you shouldn't have this.\n";
					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
					{
						std::cout << "Your inventory is full. Item Not Added\n";
						system("pause");
					}

					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
					{
						player.inventoryItemName[4] = "handgun";
						player.hasHandgun = true;
						player.inventoryFull = true;
						system("pause");
					}

					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
					{
						player.inventoryItemName[3] = "handgun";
						player.hasHandgun = true;
						system("pause");
					}

					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
					{
						player.inventoryItemName[2] = "handgun";
						player.hasHandgun = true;
						system("pause");
					}

					if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
					{
						player.inventoryItemName[1] = "handgun";
						player.hasHandgun = true;
						system("pause");
					}

					if (player.inventoryItemName[0] == "None")
					{
						player.inventoryItemName[0] = "handgun";
						player.hasHandgun = true;
						system("pause");
					}
				}
			}
		}

		if (breakRoom == "prisonEscape")
		{
			std::cout << "You place a rake into the lock cylinder, and begin turning it.";

			std::uniform_int_distribution<std::mt19937::result_type> scenario(0, 6);

			if (scenario(rng) == 0) lockPickingScenarios[0].PrintScenario();
			if (scenario(rng) == 1) lockPickingScenarios[1].PrintScenario();
			if (scenario(rng) == 2) lockPickingScenarios[2].PrintScenario();
			if (scenario(rng) > 2)
			{
				system("CLS");
				std::cout << "You have pushed ahead with the lock without any trouble.";
				lockDistance++;
			}

			if (lockDistance >= 4)
			{
				std::cout << "You realise there is little behind this door. But it has improved your lockpicking skills nonetheless, this could be extremely useful for you. If only you could find an external door.";
			}
		}
	}
}

void RaiseAlarm()
{

}

void WatchPrisoners()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> scenario(0, 30);
	if (scenario(rng) > 23)
	{
		system("CLS");
		textTyper("You were accidentally hit with a rogue football, when you looked away for just a second.");
		player.playerHP -= 1;
		player.playerFootball += 1;
		system("pause");
	}

	else
	{
		system("CLS");
		textTyper("You have observed the game. Who knows if you just wasted time or actually got better at football.");
		player.playerFootball += 1;
		system("pause");
	}
}

void GoForRun()
{
	onARun = true;
	runDistance = 0;

	runningScenarios[0].scenarioText = "You are running and come across a fence. Do you: \n\n";
	runningScenarios[0].scenarioResponse[0] = "[1] Hop The Fence\n";
	runningScenarios[0].scenarioResponse[1] = "[2] Change Direction\n";
	runningScenarios[0].scenarioResponse[2] = "[3] Stop Running\n";

	runningScenarios[1].scenarioText = "You feel a shortness of breath. Should you:\n\n";
	runningScenarios[1].scenarioResponse[0] = "[1] Stop For A Break\n";
	runningScenarios[1].scenarioResponse[1] = "[2] Check Your Inventory For A Snack\n";
	runningScenarios[1].scenarioResponse[2] = "[3] Stop Running\n";

	runningScenarios[2].scenarioText = "You encounter nothing special on your run at this time.\n\n";
	runningScenarios[2].scenarioResponse[0] = "[1] Keep Running\n";
	runningScenarios[2].scenarioResponse[1] = "[2] Stop Running\n";

	runningScenarios[3].scenarioText = "You think you can see some contraband on the floor. Should you: \n\n";
	runningScenarios[3].scenarioResponse[0] = "[1] Search For Contraband\n";
	runningScenarios[3].scenarioResponse[1] = "[2] Keep Running\n";
	runningScenarios[3].scenarioResponse[2] = "[3] Stop Running\n";

	while (onARun)
	{
		system("CLS");

		if (runDistance == 0)
		{
			std::cout << R"(
					            _( }
					  -=   _  <<  \
					      `.\__/`/\\
					-=      '--'\\  `
					     -=     //
					            \)
)";
		}

		if (runDistance == 1)
		{
			std::cout << R"(
							            _( }
							  -=   _  <<  \
							      `.\__/`/\\
							-=      '--'\\  `
							     -=     //
							            \)
)";
		}

		if (runDistance == 2)
		{
			std::cout << R"(
									            _( }
									  -=   _  <<  \
									      `.\__/`/\\
									-=      '--'\\  `
									     -=     //
									            \)
)";
		}

		if (runDistance == 3)
		{
			std::cout << R"(
											            _( }
											  -=   _  <<  \
											      `.\__/`/\\
											-=      '--'\\  `
											     -=     //
											            \)
)";
		}

		if (runDistance == 4)
		{
			std::cout << R"(
													            _( }
													  -=   _  <<  \
													      `.\__/`/\\
													-=      '--'\\  `
													     -=     //
													            \)
)";
		}

		std::cout << R"(
					---------------  ---------------  ---------------  ---------------  ---------------
                                                    )" << std::endl;
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> scenario(0, 3);
		if (runDistance < 5) runningScenarios[scenario(rng)].PrintScenario();

		else
		{
			system("CLS");
			std::cout << "Your Run Was Completed";
			player.playerRunningSpeed += 5;
			addMin(runDistance * 10);
			system("pause");
			onARun = false;
		}
	}
}

void TrainingDummies()
{
	//VARIABLES
	std::string playerInput[5];
	int combatSkillBooster = 0;

	system("CLS");
	textTyper("You approach the training dummies on the grass. You recall watching sparring fight scenes in the past in movies, and begin to think of new ways to \nattack. You try these out on the training dummy.\n\n");
	std::cout << "[1] Punch The Opponent\n[2] Kick The Opponent In The Shins\n[3] Kick The Opponent In The Face\n\n";
	for (int i = 0; i < 5; i++)
	{
		inputTooltip();
		std::cin >> playerInput[i];

		//ACHIEVEMENTS TO COMBAT BOOST
		if (i > 1)
		{
			if (playerInput[i] == "3" && playerInput[i - 1] == "2" && playerInput[i - 2] == "1" && skillObtained[0] == false)
			{
				std::cout << "You have learnt that sometimes attacking in patterns can improve the damage you do! Combat Skills Boosted.\n" << std::endl;
				skillObtained[0] = true;
				combatSkillBooster += 2;
			}

			if (playerInput[i] == playerInput[i - 1] && playerInput[i] == playerInput[i - 2] && playerInput[i] == playerInput[i - 3] && playerInput[i] == playerInput[i - 4] && skillObtained[1] == false)
			{
				std::cout << "You have learnt that taking advantage of a weakness will help you win! Combat Skills Boosted.\n";
				skillObtained[1] = true;
				combatSkillBooster += 2;
			}

			if (playerInput[i] == "1" && playerInput[i - 1] == "1" && playerInput[i - 2] == "1" && playerInput[i - 3] == "1" && skillObtained[2] == false)
			{
				std::cout << "You have become a master of quick fire punching, this will surely help you! Combat Skills Boosted.\n";
				skillObtained[2] = true;
				combatSkillBooster += 2;
			}
		}
	}

	player.playerCombat += (static_cast <int> (0.5) + combatSkillBooster);
	player.playerStamina -= 10;
}

void Meditation()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> quote(0, 30);
	philQuotes[0] = "Happiness is the feeling that power increases - that resistance is being overcome";
	philQuotes[1] = "Happiness is the meaning and the purpose of life, the whole aim and end of human existence";
	philQuotes[2] = "Rules for happiness: something to do, someone to love, something to hope for";
	philQuotes[3] = "For every minute you are angry you lose sixty seconds of happiness";
	philQuotes[4] = "A day without laughter is a day wasted";
	philQuotes[5] = "The greatest blessings of mankind are within us and within our reach. A wise man is content with his lot, whatever it may be, without wishing for what he has not";
	philQuotes[6] = "May you live every day of your life";
	philQuotes[7] = "Life is not a problem to be solved but a reality to be experienced";
	philQuotes[8] = "If you hate a person, then youre defeated by them";
	philQuotes[9] = "There are only two ways to live your life. One is as though nothing is a miracle. The other is as though everything is a miracle";
	philQuotes[10] = "To live is the rarest thing in the world. Most people exist, that is all";
	philQuotes[11] = "When it is obvious that goals can’t be reached, don’t adjust the goals, but adjust the action steps";
	philQuotes[12] = "If they spit at you behind your back it means youre ahead of them”";
	philQuotes[13] = "There is only one way to avoid criticism: do nothing, say nothing, and be nothing";
	philQuotes[14] = "Conquer yourself rather than the world";
	philQuotes[15] = "Talk to yourself like you would to someone you love";
	philQuotes[16] = "Do not let the behavior of others destroy your inner peace";
	philQuotes[17] = "Nothing is so difficult as not deceiving oneself";
	philQuotes[18] = "The more you know, the more you know you dont know";
	philQuotes[19] = "Its strange how simple things become, once you see them clearly";
	philQuotes[20] = "Cogito, ergo sum";
	philQuotes[21] = "We live in the best of all possible worlds";
	philQuotes[22] = "Liberty consists in doing what one desires";
	philQuotes[23] = "There is only one good, knowledge, and one evil, ignorance";
	philQuotes[24] = "Happiness is the highest good";
	philQuotes[25] = "Whatever is reasonable is true, and whatever is true is reasonable";
	philQuotes[26] = "Morality is not the doctrine of how we may make ourselves happy, but of how we may make ourselves worthy of happiness";
	philQuotes[27] = "Hardship often prepares an ordinary person for an extraordinary destiny";
	philQuotes[28] = "There is no easy way from the earth to the stars";
	philQuotes[29] = "Well, I must endure the presence of a few caterpillars if I wish to become acquainted with the butterflies";

	textTyper(philQuotes[quote(rng)]);
	Sleep(500);
	std::cout << ".";
	Sleep(500);
	std::cout << "  .";
	Sleep(500);
	std::cout << "  .";
	Sleep(500);
	std::cout << "  .";
	system("CLS");
	textTyper("You Enjoy A Relaxing Time On The Softened Grass");
	player.playerStamina += 10;
	player.playerHappines += 5;
	addMin(45);
}

void EatMeal(int playerLocation)
{
	if (playerLocation == 15)
	{
		system("CLS");
		textTyper("You eat in the comfort of your home cell. Consuming your meal quicker without any distractions.\n\n Your health has been moderately improved. Your stamina has been moderately improved.");
		player.playerHP += 5;
		player.playerStamina += 5;
	}

	if (playerLocation == 6)
	{
		textTyper("You eat amongst the masses of the canteen, there is shouting, chanting, arguing, jeering, and a clanking of crockery. You forego some of the joys of eating your meal to improve your rapport with other prisoners nearby.\n\n Your health has been slightly improved. Your stamina has been slightly improved.");
		player.playerHP += 3;
		player.playerStamina += 3;
		player.playerRapport += 1;
	}
}

void UseVendingMachine(int playerLocation)
{
	int playerInput;

	system("CLS");
	player.CheckInventory();
	std::cout << "You have: \x9C" << player.playerCurrency << " in your prisoner balance\n\n";
	player.playerCurrency += 2;

	if (player.playerCurrency == 0)
	{
		std::cout << "You do not have enough to purchase items.\n";
		system("pause");
	}

	else
	{
		std::cout << "[1] " << candy.itemName << ": \x9C" << candy.itemCost << "0  [" << "\033[0;32m" << "+" << candy.healthBoost << " Health" << "\033[0;m" << "]\n";
		std::cout << "[2] " << crisps.itemName << ": \x9C" << crisps.itemCost << "  [" << "\033[0;32m" << "+" << crisps.healthBoost << " Health" << "\033[0;m" << "]\n";
		std::cout << "[3] " << sodaDrink.itemName << ": \x9C" << sodaDrink.itemCost << "  [" << "\033[0;33m" << "+" << sodaDrink.staminaBoost << " Stamina" << "\033[0;m" << "]\n";
		std::cout << "[4] " << energyDrink.itemName << ": \x9C" << energyDrink.itemCost << "0  [" << "\033[0;33m" << "+" << energyDrink.staminaBoost << " Stamina" << "\033[0;m" << "]\n";
		inputTooltip();
		std::cin >> playerInput;

		switch (playerInput)
		{
		case 1:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Candy";
				player.playerCurrency -= candy.itemCost;
				player.hasCandy = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Candy, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Candy";
				player.playerCurrency -= candy.itemCost;
				player.hasCandy = true;
				std::cout << "\nYou have bought some Candy, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Candy";
				player.playerCurrency -= candy.itemCost;
				player.hasCandy = true;
				std::cout << "\nYou have bought some Candy, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Candy";
				player.playerCurrency -= candy.itemCost;
				player.hasCandy = true;
				std::cout << "\nYou have bought some Candy, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Candy";
				player.playerCurrency -= candy.itemCost;
				player.hasCandy = true;
				std::cout << "\nYou have bought some Candy, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 2:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Crisps";
				player.playerCurrency -= crisps.itemCost;
				player.hasCrisps = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Crisps, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Crisps";
				player.playerCurrency -= crisps.itemCost;
				player.hasCrisps = true;
				std::cout << "\nYou have bought some Crisps, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Crisps";
				player.playerCurrency -= crisps.itemCost; 
				player.hasCrisps = true;
				std::cout << "\nYou have bought some Crisps, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Crisps";
				player.playerCurrency -= crisps.itemCost;
				player.hasCrisps = true;
				std::cout << "\nYou have bought some Crisps, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Crisps";
				player.playerCurrency -= crisps.itemCost;
				player.hasCrisps = true;
				std::cout << "\nYou have bought some Crisps, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 3:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Soda Drink";
				player.playerCurrency -= sodaDrink.itemCost;
				player.hasSodaDrink = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought a Soda Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Soda Drink";
				player.playerCurrency -= sodaDrink.itemCost;
				player.hasSodaDrink = true;
				std::cout << "\nYou have bought a Soda Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Soda Drink";
				player.playerCurrency -= sodaDrink.itemCost;
				player.hasSodaDrink = true;
				std::cout << "\nYou have bought a Soda Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Soda Drink";
				player.playerCurrency -= sodaDrink.itemCost;
				player.hasSodaDrink = true;
				std::cout << "\nYou have bought a Soda Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Soda Drink";
				player.playerCurrency -= sodaDrink.itemCost;
				player.hasSodaDrink = true;
				std::cout << "\nYou have bought a Soda Drink, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 4:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Energy Drink";
				player.playerCurrency -= energyDrink.itemCost;
				player.hasEnergyDrink = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought an Energy Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Energy Drink";
				player.playerCurrency -= energyDrink.itemCost;
				player.hasEnergyDrink = true;
				std::cout << "\nYou have bought an Energy Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Energy Drink";
				player.playerCurrency -= energyDrink.itemCost;
				player.hasEnergyDrink = true;
				std::cout << "\nYou have bought an Energy Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Energy Drink";
				player.playerCurrency -= energyDrink.itemCost;
				player.hasEnergyDrink = true;
				std::cout << "\nYou have bought an Energy Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Energy Drink";
				player.playerCurrency -= energyDrink.itemCost;
				player.hasEnergyDrink = true;
				std::cout << "\nYou have bought an Energy Drink, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		}
	}
}

void PrisonerWork(int playerLocation)
{

}

void HealthCheckup()
{
	system("CLS");

	if (player.playerHP <= 15)
	{
		textTyper("You spend time with the Doctor analysing your various injuries. She recommends a course for treatment and you will remain in the hospital for 8 hours.");
		addHour(8);
		player.playerHP = 100;
	}

	if (player.playerHP <= 35 && player.playerHP > 15)
	{
		textTyper("You spend time with the Doctor analysing your various injuries. There is some damage to your body and bones, but not enough to keep you overnight. You can expect to be here for around 4 hours.");
		addHour(4);
		player.playerHP = 100;
	}

	if (player.playerHP <= 65 && player.playerHP > 35)
	{
		textTyper("You spend time with the Doctor analysing your various injuries. There are only minor injuries on your body, and will not need to spend more than 2 hours in hospital treatment.");
		addHour(2);
		player.playerHP = 100;
	}

	else
	{
		textTyper("You are not injured enough to warrant a treatment at the Doctor. They will be careful with allocation of resources so as to ensure there is always enough.");
	}
}

void ConsultDoctor()
{
	system("CLS");

	std::cout << "You pay a quick visit to ask the doctor to assess your medical situation. She tells you that you have: " << "\033[0;32m" << player.playerHP << "\033[0;m" << " HP right now.\n";

	if (player.playerHappines < 10)
	{
		textTyper("\n\nThe doctor assesses your mental state, and determines that you may be in need of help. The Therapists Office is now open for appointments to improve your happiness quickly.");
		player.AccessToTherapy = true;
		std::cout << "\nKeeping your happiness high is important. You may not feel confident enough to work, or be cooperative with your lawyer in states of unhappiness, hindering your prisone experience and escape plans.";
	}
	system("pause");
}

void PrayAtChapel(std::string prayerType)
{

}

void JoinAA()
{

}

void WatchTV()
{
	system("CLS");
	textTyper("You switch on your favourite show, and enjoy the entertainment sat on a bench in the far corner. You occassionally talk to other prisoners over time and\nslowly build up your report.\n");
	std::cout << "\n[" << "\033[0;32m" << "You notice you are more adept at using commputers." << "\033[0;m" << "]\n";
	player.playerRapport += 1;
	player.playerStamina += 5;
	system("pause");
}

void JoinMathsClass()
{
	bool buildClass;
	for (int i = 0; i < 15; i++)
	{
		if (matQuestions[i].questionAnswered == false)
		{
			i++;
			buildClass = true;
		}

		else
		{
			buildClass = false;
			break;
		}
	}

	if (buildClass == true)
	{
		std::random_device shuffleDevice;
		std::mt19937 rng(shuffleDevice());
		std::vector<int> questionNo(15);
		std::iota(questionNo.begin(), questionNo.end(), 0);
		std::shuffle(questionNo.begin(), questionNo.end(), rng);

		int r = 0;
		for (int i : questionNo)
		{
			questionOrder[r] = i;
			r++;
		}

		matQuestions[0].question = "What is the only even prime number?\n";
		matQuestions[0].answers[0] = "Two";
		matQuestions[0].answers[1] = "2";
		matQuestions[0].questionAnswered = false;

		matQuestions[1].question = "What is the square root of 144?\n";
		matQuestions[1].answers[0] = "12";
		matQuestions[1].answers[1] = "Twelve";
		matQuestions[1].questionAnswered = false;

		matQuestions[2].question = "What is 64 divided by 8?\n";
		matQuestions[2].answers[0] = "8";
		matQuestions[2].answers[1] = "Eight";
		matQuestions[2].questionAnswered = false;

		matQuestions[3].question = "Which number is greater, a googol, or a quadrillion?\n";
		matQuestions[3].answers[0] = "Googol";
		matQuestions[3].answers[1] = "A googal";
		matQuestions[3].questionAnswered = false;

		matQuestions[4].question = "What is an angle called if it’s greater than 90 degrees?\n";
		matQuestions[4].answers[0] = "Obtuse";
		matQuestions[4].answers[1] = "Obtuse";
		matQuestions[4].questionAnswered = false;

		matQuestions[5].question = "What is five to the power of zero?\n";
		matQuestions[5].answers[0] = "One";
		matQuestions[5].answers[1] = "1";
		matQuestions[5].questionAnswered = false;

		matQuestions[6].question = "What does the Roman numeral -X- equal?\n";
		matQuestions[6].answers[0] = "Ten";
		matQuestions[6].answers[1] = "10";
		matQuestions[6].questionAnswered = false;

		matQuestions[7].question = "What is a shape with eight sides called?\n";
		matQuestions[7].answers[0] = "An octagon";
		matQuestions[7].answers[1] = "Octagon";
		matQuestions[6].questionAnswered = false;

		matQuestions[8].question = "How many seconds are in one day? \n";
		matQuestions[8].answers[0] = "86,400";
		matQuestions[8].answers[1] = "86400";
		matQuestions[8].questionAnswered = false;

		matQuestions[9].question = "What is 91 divided by 7? \n";
		matQuestions[9].answers[0] = "13";
		matQuestions[9].answers[1] = "Thirteen";
		matQuestions[9].questionAnswered = false;

		matQuestions[10].question = "What is the least common multiple of 6, 8, and 12? \n";
		matQuestions[10].answers[0] = "24";
		matQuestions[10].answers[1] = "Twenty four";
		matQuestions[10].questionAnswered = false;

		matQuestions[11].question = "What is the largest composite number less than 40?\n";
		matQuestions[11].answers[0] = "39";
		matQuestions[11].answers[1] = "Thirty nine";
		matQuestions[11].questionAnswered = false;

		matQuestions[12].question = "Who developed the cartesian axes?\n";
		matQuestions[12].answers[0] = "Rene Descartes";
		matQuestions[12].answers[1] = "Descartes";
		matQuestions[12].questionAnswered = false;

		matQuestions[13].question = "What is the next prime number after 7?\n";
		matQuestions[13].answers[0] = "11";
		matQuestions[13].answers[1] = "Eleven";
		matQuestions[13].questionAnswered = false;

		matQuestions[14].question = "Are opposite angles of a parallelogram equal?\n";
		matQuestions[14].answers[0] = "Yes";
		matQuestions[14].answers[1] = "Yes";
		matQuestions[14].questionAnswered = false;

	}

	if (matQuestionsAnswered < 16)
	{
		bool questionAsked = false;

		while (!questionAsked)
		{
			if (matQuestions[questionOrder[matQuestionsAsked]].questionAnswered == false)
			{
				system("CLS");
				std::cout << matQuestions[questionOrder[matQuestionsAsked]].question;
				inputTooltip();
				std::cin.ignore(), std::getline(std::cin, playerAnswer);
				matQuestions[questionOrder[matQuestionsAsked]].CheckAnswer(playerAnswer);
				matQuestions[questionOrder[matQuestionsAsked]].questionAnswered = true;
				matQuestionsAnswered++;
				matQuestionsAsked++;
				questionAsked = true;
			}

			if (matQuestionsAsked == 15)
			{
				questionAsked = true;
			}
		}
	}

	if (matQuestionsAnswered > 14)
	{
		int correctAnswers = 0;
		for (int i = 0; i < 15; i++)
		{
			if (matQuestions[i].questionCorrect == true)
			{
				correctAnswers++;
			}
		}

		if (correctAnswers > 10)
		{
			player.completedMaths = true;
		}

		else if (correctAnswers <= 10)
		{
			for (int i = 0; i < 15; i++)
			{
				matQuestions[i].questionAnswered = false;
				matQuestions[i].questionCorrect = false;
				matQuestionsAsked = 0;
				matQuestionsAnswered = 0;
			}
		}
	}
}

void JoinEnglishClass()
{
	bool buildClass;
	for (int i = 0; i < 15; i++)
	{
		if (engQuestions[i].questionAnswered == false)
		{
			i++;
			buildClass = true;
		}

		else
		{
			buildClass = false;
			break;
		}
	}

	if (buildClass == true)
	{
		std::random_device shuffleDevice;
		std::mt19937 rng(shuffleDevice());
		std::vector<int> questionNo(15);
		std::iota(questionNo.begin(), questionNo.end(), 0);
		std::shuffle(questionNo.begin(), questionNo.end(), rng);

		int r = 0;
		for (int i : questionNo)
		{
			questionOrder[r] = i;
			r++;
		}

		engQuestions[0].question = "The three witches play a central role in which Shakespearean tragedy?\n";
		engQuestions[0].answers[0] = "Macbeth";
		engQuestions[0].answers[1] = "MacBeth";
		engQuestions[0].questionAnswered = false;

		engQuestions[1].question = "What is the study of (-grammatical-) meaning in language?\n";
		engQuestions[1].answers[0] = "Semantics";
		engQuestions[1].answers[1] = "Semantic";
		engQuestions[1].questionAnswered = false;

		engQuestions[2].question = "What is the correct spelling of:\nMischievious\nMischievous\nMischevous\nMischevious\n";
		engQuestions[2].answers[0] = "Mischievous";
		engQuestions[2].answers[1] = "Mischievous";
		engQuestions[2].questionAnswered = false;

		engQuestions[3].question = "-The War of The World- is a famous work of which author?\n";
		engQuestions[3].answers[0] = "HG Wells";
		engQuestions[3].answers[1] = "H.G Wells";
		engQuestions[3].questionAnswered = false;

		engQuestions[4].question = "What is the study of meaning in context?\n";
		engQuestions[4].answers[0] = "Pragmatics";
		engQuestions[4].answers[1] = "Pragmatic";
		engQuestions[4].questionAnswered = false;

		engQuestions[5].question = "The distinct pronunciation patterns of a group of people is what?\n";
		engQuestions[5].answers[0] = "Accents";
		engQuestions[5].answers[1] = "Accent";
		engQuestions[5].questionAnswered = false;

		engQuestions[6].question = "Which play is Shakespeare’s -swan song-?\n";
		engQuestions[6].answers[0] = "The Tempest";
		engQuestions[6].answers[1] = "The Tempest";
		engQuestions[6].questionAnswered = false;

		engQuestions[7].question = "How many Maxims are contained within Grice's Theorem?\n";
		engQuestions[7].answers[0] = "Four";
		engQuestions[7].answers[1] = "4";
		engQuestions[6].questionAnswered = false;

		engQuestions[8].question = "-Because I could not stop for death/He kindly stopped for me- who wrote this first line of famous poetry?\n";
		engQuestions[8].answers[0] = "Emily Dickinson";
		engQuestions[8].answers[1] = "Emily Dickinson";
		engQuestions[8].questionAnswered = false;

		engQuestions[9].question = "Who became the best-selling author in the 2000s in Britain?\n";
		engQuestions[9].answers[0] = "JK Rowling";
		engQuestions[9].answers[1] = "J.K Rowling";
		engQuestions[9].questionAnswered = false;

		engQuestions[10].question = "What language is closest to English?\n";
		engQuestions[10].answers[0] = "Dutch";
		engQuestions[10].answers[1] = "Dutch";
		engQuestions[10].questionAnswered = false;

		engQuestions[11].question = "-I, Robot- is written by an American who was born in Russia. What is the name of him?\n";
		engQuestions[11].answers[0] = "Isaac Asimov";
		engQuestions[11].answers[1] = "Isaac Asimov";
		engQuestions[11].questionAnswered = false;

		engQuestions[12].question = "What is the name of the novel by George Orwell where we find the character -Napoleon-?\n";
		engQuestions[12].answers[0] = "Animal Farm";
		engQuestions[12].answers[1] = "Animal Farm";
		engQuestions[12].questionAnswered = false;

		engQuestions[13].question = "The negative counter-part to synonymy is called what?\n";
		engQuestions[13].answers[0] = "Antonym";
		engQuestions[13].answers[1] = "Antonym";
		engQuestions[13].questionAnswered = false;

		engQuestions[14].question = "Who wrote The Cask of Amontillado?\n";
		engQuestions[14].answers[0] = "Edgar Allan Poe";
		engQuestions[14].answers[1] = "Edgar Allan-Poe";
		engQuestions[14].questionAnswered = false;

	}

	if (engQuestionsAnswered < 16)
	{
		bool questionAsked = false;

		while (!questionAsked)
		{
			if (engQuestions[questionOrder[engQuestionsAsked]].questionAnswered == false)
			{
				system("CLS");
				std::cout << engQuestions[questionOrder[engQuestionsAsked]].question;
				inputTooltip();
				std::cin.ignore(), std::getline(std::cin, playerAnswer);
				engQuestions[questionOrder[engQuestionsAsked]].CheckAnswer(playerAnswer);
				engQuestions[questionOrder[engQuestionsAsked]].questionAnswered = true;
				engQuestionsAnswered++;
				engQuestionsAsked++;
				questionAsked = true;
			}

			if (engQuestionsAsked == 15)
			{
				questionAsked = true;
			}
		}
	}

	if (engQuestionsAnswered > 14)
	{
		int correctAnswers = 0;
		for (int i = 0; i < 15; i++)
		{
			if (engQuestions[i].questionCorrect == true)
			{
				correctAnswers++;
			}
		}

		if (correctAnswers > 10)
		{
			player.completedEnglish = true;
		}

		else if (correctAnswers <= 10)
		{
			for (int i = 0; i < 15; i++)
			{
				engQuestions[i].questionAnswered = false;
				engQuestions[i].questionCorrect = false;
				engQuestionsAsked = 0;
				engQuestionsAnswered = 0;
			}
		}
	}
}

void JoinWorksClass()
{
	bool buildClass;
	for (int i = 0; i < 15; i++)
	{
		if (worQuestions[i].questionAnswered == false)
		{
			i++;
			buildClass = true;
		}

		else
		{
			buildClass = false;
			break;
		}
	}

	if (buildClass == true)
	{
		std::random_device shuffleDevice;
		std::mt19937 rng(shuffleDevice());
		std::vector<int> questionNo(15);
		std::iota(questionNo.begin(), questionNo.end(), 0);
		std::shuffle(questionNo.begin(), questionNo.end(), rng);

		int r = 0;
		for (int i : questionNo)
		{
			questionOrder[r] = i;
			r++;
		}

		worQuestions[0].question = "How many main types of Fire Extinguisher are there?\n";
		worQuestions[0].answers[0] = "Six";
		worQuestions[0].answers[1] = "6";
		worQuestions[0].questionAnswered = false;

		worQuestions[1].question = "When was the Health and Safety at Work Act introduced?\n";
		worQuestions[1].answers[0] = "1974";
		worQuestions[1].answers[1] = "Ninety seventy four";
		worQuestions[1].questionAnswered = false;

		worQuestions[2].question = "What is the UK Minimum Wage";
		worQuestions[2].answers[0] = "£8.91";
		worQuestions[2].answers[1] = "8.91";
		worQuestions[2].questionAnswered = false;

		worQuestions[3].question = "Where was paper invented?\n";
		worQuestions[3].answers[0] = "China";
		worQuestions[3].answers[1] = "China";
		worQuestions[3].questionAnswered = false;

		worQuestions[4].question = "True Or False: Office workers swear more at work than at home?\n";
		worQuestions[4].answers[0] = "True";
		worQuestions[4].answers[1] = "true";
		worQuestions[4].questionAnswered = false;

		worQuestions[5].question = "79% of employees say they should have what at work?\n";
		worQuestions[5].answers[0] = "Fun";
		worQuestions[5].answers[1] = "Have fun";
		worQuestions[5].questionAnswered = false;

		worQuestions[6].question = "Who built the first Apple computer?\n";
		worQuestions[6].answers[0] = "Steve Wozniak";
		worQuestions[6].answers[1] = "Steve Wozniak";
		worQuestions[6].questionAnswered = false;

		worQuestions[7].question = "-Backrub- was the original name of which company?\n";
		worQuestions[7].answers[0] = "Google";
		worQuestions[7].answers[1] = "Google";
		worQuestions[6].questionAnswered = false;

		worQuestions[8].question = "Which company has the slogan -just slightly ahead of our time-?\n";
		worQuestions[8].answers[0] = "Panasonic";
		worQuestions[8].answers[1] = "Panasonic";
		worQuestions[8].questionAnswered = false;

		worQuestions[9].question = "Who invented www?\n";
		worQuestions[9].answers[0] = "Tim Berners-Lee";
		worQuestions[9].answers[1] = "Tim Berners Lee";
		worQuestions[9].questionAnswered = false;

		worQuestions[10].question = "Global studies reveal that what percent of people who quit their jobs cite ‘lack of appreciation’ as their reason for leaving?\n";
		worQuestions[10].answers[0] = "79";
		worQuestions[10].answers[1] = "79%";
		worQuestions[10].questionAnswered = false;

		worQuestions[11].question = "-Drivers Wanted- is the slogan for which car manufacturer?\n";
		worQuestions[11].answers[0] = "Volkswagen";
		worQuestions[11].answers[1] = "Volkswagen";
		worQuestions[11].questionAnswered = false;

		worQuestions[12].question = "David Rosen founded which company in the 1950s?\n";
		worQuestions[12].answers[0] = "SEGA";
		worQuestions[12].answers[1] = "SEGA";
		worQuestions[12].questionAnswered = false;

		worQuestions[13].question = "Jeff Bezos is the founder of which global company?\n";
		worQuestions[13].answers[0] = "Amazon";
		worQuestions[13].answers[1] = "Amazon";
		worQuestions[13].questionAnswered = false;

		worQuestions[14].question = "Dave Thomas founded which fast-food chain?\n";
		worQuestions[14].answers[0] = "Wendys";
		worQuestions[14].answers[1] = "Wendy's";
		worQuestions[14].questionAnswered = false;
	}

	if (worQuestionsAnswered < 16)
	{
		bool questionAsked = false;

		while (!questionAsked)
		{
			if (worQuestions[questionOrder[worQuestionsAsked]].questionAnswered == false)
			{
				system("CLS");
				std::cout << worQuestions[questionOrder[worQuestionsAsked]].question;
				inputTooltip();
				std::cin.ignore(), std::getline(std::cin, playerAnswer);
				worQuestions[questionOrder[worQuestionsAsked]].CheckAnswer(playerAnswer);
				worQuestions[questionOrder[worQuestionsAsked]].questionAnswered = true;
				worQuestionsAnswered++;
				worQuestionsAsked++;
				questionAsked = true;
			}

			if (matQuestionsAsked == 15)
			{
				questionAsked = true;
			}
		}
	}

	if (matQuestionsAnswered > 14)
	{
		int correctAnswers = 0;
		for (int i = 0; i < 15; i++)
		{
			if (worQuestions[i].questionCorrect == true)
			{
				correctAnswers++;
			}
		}

		if (correctAnswers > 10)
		{
			player.completedWorks = true;
		}

		else if (correctAnswers <= 10)
		{
			for (int i = 0; i < 15; i++)
			{
				worQuestions[i].questionAnswered = false;
				worQuestions[i].questionCorrect = false;
				worQuestionsAsked = 0;
				worQuestionsAnswered = 0;
			}
		}
	}
}

void ShopAtStore()
{
	int playerInput;

	system("CLS");
	player.CheckInventory();
	std::cout << "You have: \x9C" << player.playerCurrency << " in your prisoner balance\n\n";
	player.playerCurrency += 2;

	if (player.playerCurrency == 0)
	{
		std::cout << "You do not have enough to purchase items.\n";
		system("pause");
	}

	else
	{
		std::cout << "[1] " << candy.itemName << ": \x9C" << candy.itemCost << "0  [" << "\033[0;32m" << "+" << candy.healthBoost << " Health" << "\033[0;m" << "]\n";
		std::cout << "[2] " << crisps.itemName << ": \x9C" << crisps.itemCost << "  [" << "\033[0;32m" << "+" << crisps.healthBoost << " Health" << "\033[0;m" << "]\n";
		std::cout << "[3] " << sodaDrink.itemName << ": \x9C" << sodaDrink.itemCost << "  [" << "\033[0;33m" << "+" << sodaDrink.staminaBoost << " Stamina" << "\033[0;m" << "]\n";
		std::cout << "[4] " << energyDrink.itemName << ": \x9C" << energyDrink.itemCost << "0  [" << "\033[0;33m" << "+" << energyDrink.staminaBoost << " Stamina" << "\033[0;m" << "]\n";
		std::cout << "\nStore Exclusive Items\n";
		std::cout << "[5] " << porkPie.itemName << ": \x9C" << porkPie.itemCost << "  [" << "\033[0;32m" << "+" << porkPie.healthBoost << " Health" << "\033[0;m" << "]\n";
		std::cout << "[6] " << ramen.itemName << ": \x9C" << ramen.itemCost << "  [" << "\033[0;32m" << "+" << ramen.healthBoost << " Health" << "\033[0;m" << "]\n";
		std::cout << "[7] " << sausageBeans.itemName << ": \x9C" << sausageBeans.itemCost << "  [" << "\033[0;32m" << "+" << sausageBeans.healthBoost << " Health" << "\033[0;m" << "]\n";
		std::cout << "[8] " << carrotCake.itemName << ": \x9C" << carrotCake.itemCost << "  [" << "\033[0;32m" << "+" << carrotCake.healthBoost << " Health" << "\033[0;m" << "][" << "\033[0;33m" << "+" << carrotCake.staminaBoost << " Stamina" << "\033[0;m" << "]\n";
		std::cout << "[9] " << honeyBun.itemName << ": \x9C" << honeyBun.itemCost << "  [" << "\033[0;32m" << "+" << honeyBun.healthBoost << " Health" << "\033[0;m" << "][" << "\033[0;33m" << "+" << honeyBun.staminaBoost << " Stamina" << "\033[0;m" << "]\n";
		std::cout << "[10] " << gingerBread.itemName << ": \x9C" << gingerBread.itemCost << " [" << "\033[0;32m" << "+" << gingerBread.healthBoost << " Health" << "\033[0;m" << "][" << "\033[0;33m" << "+" << gingerBread.staminaBoost << " Stamina" << "\033[0;m" << "]\n";
		std::cout << "[11] " << kiplingCakes.itemName << ": \x9C" << kiplingCakes.itemCost << "  [" << "\033[0;32m" << "+" << kiplingCakes.healthBoost << " Health" << "\033[0;m" << "][" << "\033[0;33m" << "+" << kiplingCakes.staminaBoost << " Stamina" << "\033[0;m" << "]\n";
		std::cout << "\nStore Special Items\n";
		std::cout << "[12] " << phoneCallToken.itemName << ": \x9C" << phoneCallToken.itemCost << "  [Entitles You To Make A Phone Call In The Visitation Room]\n";
		std::cout << "[13] " << boardGame.itemName << ": \x9C" << boardGame.itemCost << "  [You Can Play Board Games In The Common Room And Cell Block " << "\033[0;33m" << "+3 Happiness With Each Game" << "\033[0;m" <<"]\n";
		std::cout << "[14] " << shampoo.itemName << ": \x9C" << shampoo.itemCost << "  [When Showering You Will Add " << "\033[0;33m" << "+3 Happiness With Each Wash" << "\033[0;m" << "]\n";
		std::cout << "[15] " << magazine.itemName << ": \x9C" << magazine.itemCost << "  [You Can Read A Magazine In The Comfort Of Your Cell " << "\033[0;33m" << "+6 Happiness With Each Read" << "\033[0;m" << "]\n";
		std::cout << "[16] " << personalRadio.itemName << ": \x9C" << personalRadio.itemCost << "  [You Can Listen To The Radio In The Comfort Of Your Cell: " << "\033[0;33m" << "+6 Happiness Every 30 Minutes" << "\033[0;m" << "]\n";
		inputTooltip();
		std::cin >> playerInput;

		switch (playerInput)
		{
		case 1:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Candy";
				player.playerCurrency -= candy.itemCost;
				player.hasCandy = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Candy, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Candy";
				player.playerCurrency -= candy.itemCost;
				player.hasCandy = true;
				std::cout << "\nYou have bought some Candy, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Candy";
				player.playerCurrency -= candy.itemCost;
				player.hasCandy = true;
				std::cout << "\nYou have bought some Candy, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Candy";
				player.playerCurrency -= candy.itemCost;
				player.hasCandy = true;
				std::cout << "\nYou have bought some Candy, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Candy";
				player.playerCurrency -= candy.itemCost;
				player.hasCandy = true;
				std::cout << "\nYou have bought some Candy, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 2:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Crisps";
				player.playerCurrency -= crisps.itemCost;
				player.hasCrisps = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Crisps, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Crisps";
				player.playerCurrency -= crisps.itemCost;
				player.hasCrisps = true;
				std::cout << "\nYou have bought some Crisps, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Crisps";
				player.playerCurrency -= crisps.itemCost;
				player.hasCrisps = true;
				std::cout << "\nYou have bought some Crisps, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Crisps";
				player.playerCurrency -= crisps.itemCost;
				player.hasCrisps = true;
				std::cout << "\nYou have bought some Crisps, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Crisps";
				player.playerCurrency -= crisps.itemCost;
				player.hasCrisps = true;
				std::cout << "\nYou have bought some Crisps, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 3:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Soda Drink";
				player.playerCurrency -= sodaDrink.itemCost;
				player.hasSodaDrink = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought a Soda Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Soda Drink";
				player.playerCurrency -= sodaDrink.itemCost;
				player.hasSodaDrink = true;
				std::cout << "\nYou have bought a Soda Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Soda Drink";
				player.playerCurrency -= sodaDrink.itemCost;
				player.hasSodaDrink = true;
				std::cout << "\nYou have bought a Soda Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Soda Drink";
				player.playerCurrency -= sodaDrink.itemCost;
				player.hasSodaDrink = true;
				std::cout << "\nYou have bought a Soda Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Soda Drink";
				player.playerCurrency -= sodaDrink.itemCost;
				player.hasSodaDrink = true;
				std::cout << "\nYou have bought a Soda Drink, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 4:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Energy Drink";
				player.playerCurrency -= energyDrink.itemCost;
				player.hasEnergyDrink = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought an Energy Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Energy Drink";
				player.playerCurrency -= energyDrink.itemCost;
				player.hasEnergyDrink = true;
				std::cout << "\nYou have bought an Energy Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Energy Drink";
				player.playerCurrency -= energyDrink.itemCost;
				player.hasEnergyDrink = true;
				std::cout << "\nYou have bought an Energy Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Energy Drink";
				player.playerCurrency -= energyDrink.itemCost;
				player.hasEnergyDrink = true;
				std::cout << "\nYou have bought an Energy Drink, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Energy Drink";
				player.playerCurrency -= energyDrink.itemCost;
				player.hasEnergyDrink = true;
				std::cout << "\nYou have bought an Energy Drink, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 5:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Pork Pie";
				player.playerCurrency -= porkPie.itemCost;
				player.hasPorkPie = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought a Pork Pie, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Pork Pie";
				player.playerCurrency -= porkPie.itemCost;
				player.hasPorkPie = true;
				std::cout << "\nYou have bought a Pork Pie, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Pork Pie";
				player.playerCurrency -= porkPie.itemCost;
				player.hasPorkPie = true;
				std::cout << "\nYou have bought a Pork Pie, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Pork Pie";
				player.playerCurrency -= porkPie.itemCost;
				player.hasPorkPie = true;
				std::cout << "\nYou have bought a Pork Pie, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Pork Pie";
				player.playerCurrency -= porkPie.itemCost;
				player.hasPorkPie = true;
				std::cout << "\nYou have bought a Pork Pie, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 6:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Ramen";
				player.playerCurrency -= ramen.itemCost;
				player.hasRamen = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Ramen, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Ramen";
				player.playerCurrency -= ramen.itemCost;
				player.hasRamen = true;
				std::cout << "\nYou have bought some Ramen, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Ramen";
				player.playerCurrency -= ramen.itemCost;
				player.hasRamen = true;
				std::cout << "\nYou have bought some Ramen, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Ramen";
				player.playerCurrency -= ramen.itemCost;
				player.hasRamen = true;
				std::cout << "\nYou have bought some Ramen, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Ramen";
				player.playerCurrency -= ramen.itemCost;
				player.hasRamen = true;
				std::cout << "\nYou have bought some Ramen, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 7:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Sausage and Beans";
				player.playerCurrency -= sausageBeans.itemCost;
				player.hasSausageBeans = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Sausage and Beans, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Sausage and Beans";
				player.playerCurrency -= sausageBeans.itemCost;
				player.hasSausageBeans = true;
				std::cout << "\nYou have bought some Sausage and Beans, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Sausage and Beans";
				player.playerCurrency -= sausageBeans.itemCost;
				player.hasSausageBeans = true;
				std::cout << "\nYou have bought some Sausage and Beans, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Sausage and Beans";
				player.playerCurrency -= sausageBeans.itemCost;
				player.hasSausageBeans = true;
				std::cout << "\nYou have bought some Sausage and Beans, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Sausage and Beans";
				player.playerCurrency -= sausageBeans.itemCost;
				player.hasSausageBeans = true;
				std::cout << "\nYou have bought some Sausage and Beans, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 8:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Carrot Cake";
				player.playerCurrency -= carrotCake.itemCost;
				player.hasCarrotCake = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Carrot Cake, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Carrot Cake";
				player.playerCurrency -= carrotCake.itemCost;
				player.hasCarrotCake = true;
				std::cout << "\nYou have bought some Carrot Cake, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Carrot Cake";
				player.playerCurrency -= carrotCake.itemCost;
				player.hasCarrotCake = true;
				std::cout << "\nYou have bought some Carrot Cake, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Carrot Cake";
				player.playerCurrency -= carrotCake.itemCost;
				player.hasCarrotCake = true;
				std::cout << "\nYou have bought some Carrot Cake, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Carrot Cake";
				player.playerCurrency -= carrotCake.itemCost;
				player.hasCarrotCake = true;
				std::cout << "\nYou have bought some Carrot Cake, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 9:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Honeybuns";
				player.playerCurrency -= honeyBun.itemCost;
				player.hasHoneyBun = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Honeybuns, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Honeybuns";
				player.playerCurrency -= honeyBun.itemCost;
				player.hasHoneyBun = true;
				std::cout << "\nYou have bought some Honeybuns, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Honeybuns";
				player.playerCurrency -= honeyBun.itemCost;
				player.hasHoneyBun = true;
				std::cout << "\nYou have bought some Honeybuns, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Honeybuns";
				player.playerCurrency -= honeyBun.itemCost;
				player.hasHoneyBun = true;
				std::cout << "\nYou have bought some Honeybuns, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Honeybuns";
				player.playerCurrency -= honeyBun.itemCost;
				player.hasHoneyBun = true;
				std::cout << "\nYou have bought some Honeybuns, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 10:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Gingerbread";
				player.playerCurrency -= gingerBread.itemCost; 
				player.hasGingerBread = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Gingerbread, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Gingerbread";
				player.playerCurrency -= gingerBread.itemCost;
				player.hasGingerBread = true;
				std::cout << "\nYou have bought some Gingerbread, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Gingerbread";
				player.playerCurrency -= gingerBread.itemCost;
				player.hasGingerBread = true;
				std::cout << "\nYou have bought some CGingerbreadandy, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Gingerbread";
				player.playerCurrency -= gingerBread.itemCost;
				player.hasGingerBread = true;
				std::cout << "\nYou have bought some Gingerbread, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Gingerbread";
				player.playerCurrency -= gingerBread.itemCost;
				player.hasGingerBread = true;
				std::cout << "\nYou have bought some Gingerbread, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 11:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Kipling Cakes";
				player.playerCurrency -= kiplingCakes.itemCost;
				player.hasKiplingCakes = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Kipling Cakes, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Kipling Cakes";
				player.playerCurrency -= kiplingCakes.itemCost;
				player.hasKiplingCakes = true;
				std::cout << "\nYou have bought some Kipling Cakes, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Kipling Cakes";
				player.playerCurrency -= kiplingCakes.itemCost;
				player.hasKiplingCakes = true;
				std::cout << "\nYou have bought some Kipling Cakes, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Kipling Cakes";
				player.playerCurrency -= kiplingCakes.itemCost;
				player.hasKiplingCakes = true;
				std::cout << "\nYou have bought some Kipling Cakes, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Kipling Cakes";
				player.playerCurrency -= kiplingCakes.itemCost;
				player.hasKiplingCakes = true;
				std::cout << "\nYou have bought some Kipling Cakes, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 12:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Phonecall Token";
				player.playerCurrency -= phoneCallToken.itemCost;
				player.hasPhoneToken = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought a Phonecall Token, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Phonecall Token";
				player.playerCurrency -= phoneCallToken.itemCost;
				player.hasPhoneToken = true;
				std::cout << "\nYou have bought a Phonecall Token, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Phonecall Token";
				player.playerCurrency -= phoneCallToken.itemCost;
				player.hasPhoneToken = true;
				std::cout << "\nYou have bought a Phonecall Token, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Phonecall Token";
				player.playerCurrency -= phoneCallToken.itemCost;
				player.hasPhoneToken = true;
				std::cout << "\nYou have bought a Phonecall Token, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Phonecall Token";
				player.playerCurrency -= phoneCallToken.itemCost;
				player.hasPhoneToken = true;
				std::cout << "\nYou have bought a Phonecall Token, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 13:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Board Games";
				player.playerCurrency -= boardGame.itemCost;
				player.hasBoardGame = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Board Games, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Board Games";
				player.playerCurrency -= boardGame.itemCost;
				player.hasBoardGame = true;
				std::cout << "\nYou have bought some Board Games, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Board Games";
				player.playerCurrency -= boardGame.itemCost;
				player.hasBoardGame = true;
				std::cout << "\nYou have bought some Board Games, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Board Games";
				player.playerCurrency -= boardGame.itemCost;
				player.hasBoardGame = true;
				std::cout << "\nYou have bought some Board Games, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Board Games";
				player.playerCurrency -= boardGame.itemCost;
				player.hasBoardGame = true;
				std::cout << "\nYou have bought some Board Games, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 14:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Shampoo";
				player.playerCurrency -= shampoo.itemCost;
				player.hasShampoo = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Shampoo, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Shampoo";
				player.playerCurrency -= shampoo.itemCost;
				player.hasShampoo = true;
				std::cout << "\nYou have bought some Shampoo, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Shampoo";
				player.playerCurrency -= shampoo.itemCost;
				player.hasShampoo = true;
				std::cout << "\nYou have bought some Shampoo, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Shampoo";
				player.playerCurrency -= shampoo.itemCost;
				player.hasShampoo = true;
				std::cout << "\nYou have bought some Shampoo, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Shampoo";
				player.playerCurrency -= shampoo.itemCost;
				player.hasShampoo = true;
				std::cout << "\nYou have bought some Shampoo, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 15:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Magazines";
				player.playerCurrency -= magazine.itemCost;
				player.hasMagazine = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought some Magazines, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Magazines";
				player.playerCurrency -= magazine.itemCost;
				player.hasMagazine = true;
				std::cout << "\nYou have bought some Magazines, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Magazines";
				player.playerCurrency -= magazine.itemCost;
				player.hasMagazine = true;
				std::cout << "\nYou have bought some Magazines, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Magazines";
				player.playerCurrency -= magazine.itemCost;
				player.hasMagazine = true;
				std::cout << "\nYou have bought some Magazines, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Magazines";
				player.playerCurrency -= magazine.itemCost;
				player.hasMagazine = true;
				std::cout << "\nYou have bought some Magazines, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		case 16:
			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] != "None")
			{
				std::cout << "Your inventory is full. Item Not Added\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] != "None" && player.inventoryItemName[4] == "None")
			{
				player.inventoryItemName[4] = "Personal Radio";
				player.playerCurrency -= personalRadio.itemCost;
				player.hasPersonalRadio = true;
				player.inventoryFull = true;
				std::cout << "\nYou have bought a Personal Radio, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] != "None" && player.inventoryItemName[3] == "None")
			{
				player.inventoryItemName[3] = "Personal Radio";
				player.playerCurrency -= personalRadio.itemCost;
				player.hasPersonalRadio = true;
				std::cout << "\nYou have bought a Personal Radio, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] != "None" && player.inventoryItemName[2] == "None")
			{
				player.inventoryItemName[2] = "Personal Radio";
				player.playerCurrency -= personalRadio.itemCost;
				player.hasPersonalRadio = true;
				std::cout << "\nYou have bought a Personal Radio, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] != "None" && player.inventoryItemName[1] == "None")
			{
				player.inventoryItemName[1] = "Personal Radio";
				player.playerCurrency -= personalRadio.itemCost;
				player.hasPersonalRadio = true;
				std::cout << "\nYou have bought a Personal Radio, it has been added to your inventory.\n";
				system("pause");
			}

			if (player.inventoryItemName[0] == "None")
			{
				player.inventoryItemName[0] = "Personal Radio";
				player.playerCurrency -= personalRadio.itemCost;
				player.hasPersonalRadio = true;
				std::cout << "\nYou have bought a Personal Radio, it has been added to your inventory.\n";
				system("pause");
			}
			break;
		}
	}
}

void JoinVisitation(std::string playerGuest)
{

}

void MakePhoneCall()
{

}

void PrisonerSleep()
{

}

void PrisonerLookOutWindow()
{
	system("CLS");
	textTyper("You walk to the window, you look over the fence to your future freedom. You hope to be out there soon, and take a moment to enjoy the views. You observe the grass and the meadows, and the distance between your cell block and the fence that separates you from the Outer World. You cast your gaze over the surroundings, the road, the hgihway, the guard outputs closer to the fence, the lake district in the far corner. The World is beautiful, the experience fills you with a wish to be there sooner.");

	if (firstLook)
	{
		firstLook = false;
		discoveredTunnel = true;
		std::cout << "\n\n" << "\033[0;32m" << "You realise that you could dig a tunnel to the fence. If only you had something to dig with." << "\033[0;m";
	}
}

void StoreContraband()
{

}

void StartDiggingTunnel()
{

}

void TakeShower()
{

}

void InsideTunnel()
{

}

void AttendTherapy()
{

}

void SearchThroughFiles()
{

}