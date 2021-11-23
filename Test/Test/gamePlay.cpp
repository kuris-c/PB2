#include "prepro.h"
#include <random>
#include <numeric>

#pragma region CLASS VARIABLES
//FIRST VISIT
std::string playerAnswer;
bool matCorrectAnswer[15];
bool engCorrectAnswer[15];
bool worCorrectAnswer[15];
int matTotalMarks;
int engTotalMarks;
int worTotalMarks;
bool matRandomiseQuestions;
bool engRandomiseQuestions;
bool worRandomiseQuestions;
int matCompletedQuestions = 0;
int engCompletedQuestions = 0;
int worCompletedQuestions = 0;
bool firstVisit = true;

//CLASS QUESTIONS
std::string englishQuestions[15] = { "The three witches play a central role in which Shakespearean tragedy?\n", "What is the study of (-grammatical-) meaning in language?\n", "What is the correct spelling of:\nMischievious\nMischievous\nMischevous\nMischevious ", "-The War of The World- is a famous work of which author?\n", "What is the study of meaning in context?\n", "The distinct pronunciation patterns of a group of people is what?\n" , "Which play is Shakespeare’s -swan song-?\n" , "How many Maxims are contained within Grice's Theorem?\n" , "-Because I could not stop for death/He kindly stopped for me- who wrote this first line of famous poetry?\n", "Who became the best-selling author in the 2000s in Britain?\n" "What language is closest to English?\n" , "-I, Robot- is written by an American who was born in Russia. What is the name of him?\n", "What is the name of the novel by George Orwell where we find the character -Napoleon-?\n", "The negative counter-part to synonymy is called what?\n" };
std::string englishAnswers[18] = { "Macbeth", "Semantics", "Mischievous", "HG Wells", "H.G Wells", "Pragmatics", "Accents", "The Tempest", "Four", "4", "Emily Dickinson", "J.K Rowling", "JK Rowling", "Syntax", "Dutch", "Isaac Asimov", "Animal Farm", "Antonym" };

//RANDOMISE QUESTIONS
std::string shuffledQuestion[15];
#pragma endregion

void gamePlay(int enterMethod)
{
		prisonRooms[playerLocation].enterRoom(enterMethod);
}

void PlayerFight()
{
	int prisonerFighter;
	if (hour > 7 && hour < 22) prisonerFighter = rand() % prisonRooms[playerLocation].pPresentAtDay[hour - 7];
	else prisonerFighter = rand () % prisonRooms[playerLocation].pPresentAtNight;
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
			playerFight = false;
		}

		else
		{
			if (prisoners[prisonerFighter].prisonerHP >= 50)
			{
				textTyper("\nHe maintains a confident look on his face, showing little bruising or damage from the fight so far.");
			}

			if (prisoners[prisonerFighter].prisonerHP < 50)
			{
				textTyper("\nHis face shows moderate signs of trauma, with some bruising on the eyes and tears on the uniform from being stretched.");
			}

			if (prisoners[prisonerFighter].prisonerHP < 30)
			{
				textTyper("\nHis nose drips slightly with blood, the eye almost completely black and bruising all over the body.");
			}

			if (prisoners[prisonerFighter].prisonerHP < 10)
			{
				textTyper("\nHe lies on the floor, almost lifeless and close to death. There are cries from him begging you to stop, but ruthless cheering from the audience.");
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
				textTyper("You hang your hands up in retreat. Realising that he will not quit with a ferocious smirk on his face, you decide to make a break for it.");
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
			std::cout << " Damage Dealt: " << enemyDamage;

			if (player.completedMaths)
			{
				std::cout << "\nPlayer HP: " << player.playerHP << ". " << prisoners[prisonerFighter].prisonerName << " HP: " << prisoners[prisonerFighter].prisonerName;
			}
		}
	}
	
	//- COMBAT SKILLS CAN BE IMPROVED WITH TRAINING DUMMIES AND BY FIGHTING*/
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

}

void RaiseAlarm()
{

}

void WatchPrisoners()
{

}

void GoForRun()
{

}

void TrainingDummies()
{

}

void Meditation()
{

}

void EatMeal(int playerLocation)
{

}

void UseVendingMachine(int playerLocation)
{

}

void PrisonerWork(int playerLocation)
{

}

void HealthCheckup()
{

}

void ConsultDoctor()
{

}

void PrayAtChapel(std::string prayerType)
{

}

void JoinAA()
{

}

void WatchTV()
{

}

void JoinClass(std::string classType)
{
	while (firstVisit)
	{
		//MARKING
		matTotalMarks = 0;
		engTotalMarks = 0;
		worTotalMarks = 0;

		//RANDOMISE QUESTIONS
		engRandomiseQuestions = true;

		firstVisit = false;
	}

	if (classType == "maths")
	{
		//FIRST LESSON
		bool firstLesson = true;
		if (firstLesson)
		{
			int mathSkills = 0;
			firstLesson = false;
		}

		//CLASS QUESTIONS
		std::string mathQuestions[15];
		
	}

	if (classType == "english")
	{
		if (engRandomiseQuestions)
		{
			std::random_device shuffleDevice;
			std::mt19937 rng(shuffleDevice());
			std::vector<int> questions(14);
			std::iota(questions.begin(), questions.end(), 0);
			std::shuffle(questions.begin(), questions.end(), rng);

			int i = 0;
			for (int r : questions)
			{
				shuffledQuestion[i] = englishQuestions[r];
				i++;
			}

			engRandomiseQuestions = false;
		}

		//ASK AND COMPLETE QUESTIONS
		system("CLS");
		std::cout << shuffledQuestion[engCompletedQuestions];
		std::cout << "\n\nDon't forget your capitals in the correct places! This is an English Class.";
		inputTooltip();
		std::cin.ignore(), getline(std::cin, playerAnswer);
		engCompletedQuestions++;

		//CHECK ANSWER AND MARK
		fori(engCompletedQuestions)
		{
			if (playerAnswer == englishAnswers[engCompletedQuestions - 1] || playerAnswer == englishAnswers[engCompletedQuestions]) engCorrectAnswer[engCompletedQuestions - 1] = true;
			else engCorrectAnswer[engCompletedQuestions - 1] = false;
		}


		//PASS OR FAIL CLASS
		if (engCompletedQuestions == 14)
		{
			fori(15)
			{
				if (engCorrectAnswer[i] == true) engTotalMarks++;
			}

			if (engTotalMarks > 10)
			{
				player.completedEnglish = true;
			}

			else
			{
				system("pause");
				engRandomiseQuestions = true;
			}
		}

		gamePlay(0);
	}

	if (classType == "works")
	{
		//FIRST LESSON
		bool firstLesson = true;
		if (firstLesson)
		{
			int workSkills = 0;
			firstLesson = false;
		}

		//CLASS QUESTIONS
		std::string worksQuestions[15];
	}
}

void ShopAtStore()
{

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