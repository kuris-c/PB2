#include "prepro.h"

#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <ctime>

/*CREATE ROOM OBJECTS*/PrisonRooms prisonRooms[19];

//ROOM CREATION FUNCTIONS
void assignGuards(std::string securityLevel, int k);
void assignPrisoners(int k); //DAY
void assignPrisoners();		 //NIGHT

//ROOM CREATION VARIABLES
/*ROOM NAMES*/std::string roomNames[19] = { "Cell Block A", "Cell Block B", "Cell Block C", "Cell Block D", "the Reception", "the Courtyard", "the Canteen", "the Kitchen", "the Infirmary", "the Chapel", "the Common Room", "the Laundry", "the Classroom", "the Prison Store", "Visitation", "your Personal Cell", "the Showers", "your Tunnel", "the Therapists Office" };
/*ROOM DESCRIPTIONS*/std::string roomDescriptions[19];
/*ROOM SECURITY*/std::string securityLevel[19] = { "High", "High", "High", "High", "Low", "High", "High", "Med", "Low", "Low", "High", "Med", "Low", "Low", "Med", "None", "Med", "None", "None" };

/*CREATE ACTION OBJECTS*/PlayerActions playerActions[69];

//ACTION CREATION VARIABLES
/*ACTION DESCRIPTIONS*/std::string actionDescriptions[69];

/*CREATE CELL OBJECTS*/Cells prisonerCells[499];
/*CREATE PRISONER OBJECTS*/Prisoners prisoners[499];
/*CREATE SIDE CHARACTER OBJECTS*/SideCharacters sideCharacters[499];

//PRISONER CREATION VARIABLES
/*PRISONER FIRST NAMES*/std::string prisonerFirstNames[65] = { "Neil", "Santino", "Joseph", "Warren", "Kasey", "Jeffery", "Aedan", "Davon", "Ari", "Cortez", "Trey", "Elvis", "Dwayne", "Jayvon", "Nehemiah", "Isaac", "Leroy", "Isaiah", "Amari", "Steven", "Jensen", "Ahmad", "Ariel", "Jaylon", "Amare", "Alejandro", "Clinton", "Patrick", "Drake", "Eddie", "Fernando", "Joaquin", "Arjun", "Jake", "Shawn", "Terrance", "Felix", "Mauricio", "Casey", "Tristian", "Ramon", "Sullivan", "Ernesto", "Mathew", "Lukas", "Sage", "Vicente", "Konnor", "Dean", "Tommy", "Brock", "Gavyn", "Brayden", "Demetrius", "Emanuel", "Adrian", "Robert", "Christian", "Ayaan", "Yael", "Terrence", "Makai", "Semaj", "Barrett", "Declan" };
/*PRISONER SURNAMES*/std::string prisonerSurnames[65] = { "Cardenas", "Dennis", "Lowe", "Rhodes", "Love", "Coleman", "Stanley", "Cantu", "Newton", "Floyd", "Bass", "Mcbride", "Wallace", "Lee", "Ho", "Morris", "Owens", "Rowland", "Blanchard", "Wilkinson", "Avila", "Matthews", "Compton", "Flynn", "Browning", "Boyer", "Knox", "Levy", "Ramos", "Escobar", "Garcia", "Herman", "Schwartz", "Barajas", "Nguyen", "Gould", "Hicks", "Andrade", "Henson", "Franklin", "Mendoza", "Hardin", "Walters", "Armstrong", "Alexander", "Arias", "Glover", "Robertson", "Holloway", "Boyd", "Franco", "Johnson", "Snyder", "Weiss", "Mack", "Kaiser", "Potter", "Chaney", "Oneal", "Cooper", "Santos", "Adkins", "Hester", "Koch", "Freeman" };
/*PRISONER NAMES*/std::string prisonerNames[499];

void createPrison()
{
#pragma region ROOM DESCRIPTIONS
	roomDescriptions[0] = "You can see rows of prison cells, spread over multiple floors. The sight is almost daunting. In each corner of your eye is the subtle flicker of \nmovement as inmates pace, and run, and sit and talk, play and argue, or stand, clearly bored.\n\n";
	roomDescriptions[1] = "The sight is familiar, you can see the rows of decadent cells, spread over multiple floors. There are prisoners and guards, bustling, playing, exercising the mind, or talking in groups across the block.\n\n";
	roomDescriptions[2] = "The sight is familiar, you can see the rows of decadent cells, spread over multiple floors. There are prisoners and guards, bustling, playing, exercising the mind, or talking in groups across the block.\n\n";
	roomDescriptions[3] = "The sight is familiar, you can see the rows of decadent cells, spread over multiple floors. There are prisoners and guards, bustling, playing, exercising the mind, or talking in groups across the block.\n\n";
	roomDescriptions[4] = "You haven't been here since the day you arrived to the prison. Aside from being much quieter, not much has changed. Crowds of naked prisoners and stacks of uniforms have been replaced by clean benches and a desk with computer in the corner, behind a glass cubicle. The room is quiet, cool, and a refreshing place to be, even if you shouldn't be here.\n\n";
	roomDescriptions[5] = "There are crowds of people spread over the vast space. You spend a moment to take in the view. There are rows of barbed fences in all 4 directions, \ninterrupted only by the weathered dark grey walls of the various buildings, all accessible from the Courtyard. There is a small patch of grass below \nthe fencing in the far left corner, with room to meditate. There are crowds of people watching two groups of 11 play football on the potholed \nconcrete/makeshift football pitch. To the side are training dummies, to help improve your physique.\n\n";
	roomDescriptions[6] = "There are crowds of prisoners gathering around lunch tables, bustlingand queuing at the serving tables, food has been slightly flung up the walls, and litterered across the floor.People are shouting, plates are clangingand cutlery is clinking.\n\n";
	roomDescriptions[7] = "The kitchen. Home of the finest prison cuisine. Chefs are cutting fruit, blending vegetables and serving food with questionable chemical content, all brewed in the sweaty hotpot of a rotting prison wing, chefs are unkempt, and their prisoner assistants have even less care for standards. You almost cannot bare to watch.\n\n";
	roomDescriptions[8] = "There are low and gentle sounds of beeping, small grunts of pain as people do their best to recover from any injuries they have obtained. Doctors are quietly pacing around, checking on individual beds and collecting medication as they need to.\n\n";
	roomDescriptions[9] = "There are people praying in the pews, or on prayer rugs. There are decorated columns in the room, and low hanging chanedeliers across the middle walkway. In the far corner is some tinted stained glass, casting a unique shadow over the altar in front. To the right is some space for a choir, and to the left, an organ. It is a relaxing environment.\n\n";
	roomDescriptions[10] = "The room is loud, as prisoners chatter, play with the table football, the chess boards, and the radio channel. There are small TVs attached to the dark grey brick walls, and a small view of the outdoors from the barred windows. The room is cooled by a loud AC, there are doors all over the room that look like they could easily be lockpicked. Perhaps it would be a good place to practice.\n\n";
	roomDescriptions[11] = "The faint humming of irons rumbles throughout, and the consistent spinning of orange in the washing machines can be seen in all directions, as they stand pushed against the wall. There are rows of laundry trolleys, filled to the brim with uniforms, clean and dirty alike. Prisoners are muttering under their breath as they work.\n\n";
	roomDescriptions[12] = "Rows of hardly cleaned desks line the middle of the room. In the corner there are bookshelves, showcasing a small collection of classic literature and other assorted works, some which seem inappropriate to be shown in public. There is a teachers desk, with a computer, that could easily be accessed if you knew how. Draping down from the ceiling are small fans, that barely offer comfort amongst the sweltering heat of the concrete insulation that haunts the block.\n\n";
	roomDescriptions[13] = "The shelves of stock are impressive at first glance, and you can't help but consider how this might be a good place to obtain some contraband. You take a moment to look around at things you can see, cigarettes, porn magazines, sweets and sugary treats, DVDs, spices for food. And these are just the items on shelves, who knows what hides behind the stores storage room.\n\n";
	roomDescriptions[14] = "You can see prisoners talking to their parents, wives, husbands, children, and lawyers at the cleaned wooden tables. Or talking away on the phones, pressed against the harsh concrete walls. Guards stand at the entrances, and make their way in patrol down the walkways of the room, keeping close and suspicous eyes on everyone around.\n\n";
	roomDescriptions[15] = "You can see a small view outside of the window, looking on the pastures beyond the confinement of your block. The walls are dark grey and rotting, there is a gentle chatter of mice from below you. In the corner of your room is your bed, neatly made by yourself. There is a small desk with some paper and pens, a sink and mirror to take care of yourself, and a toilet in the corner, slowly falling apart and not cleaned as well as you would like. Luckily the lid of the toilet can open at a gentle force, and is a good place for storing contraband.\n\n";
	roomDescriptions[16] = "There are prisoners exposing themselves to the wall, muttering under their breath about the heat inconsistency and problems with water flow from shower heads that look as though they could fall from the wall at any moment and crush the user below. You look around for an open spot that will offer the most possible privacy to you, to no avail.\n\n";
	roomDescriptions[17] = "There is the gentle chattering of prisoners behind you, and the even gentler rattling of insects making their way through the holes and secret passageways left by mother nature in the dirt. You shouldn't be here for too long if you can avoid it, you don't want to make people suspicious.\n\n";
	roomDescriptions[18] = "He has his office decorated with posters of various pop idols, and there is a line of filing cabinets in the far corner, tinted green and rammed to the brim with paperwork and personal information about prisoners and staff. You ponder for a moment how you could take advantage of this information. Sat in the centre of the room is the offices desk, towered over by the centered brown desk chair, far too big for the tiny room it is part of. It is the first room in the prison you have seen with real windows, and the view of the prison entrance in the front.\n\n";
#pragma endregion

	//CREATE ROOMS
	fori(19)
	{
		prisonRooms[i].roomName = roomNames[i];
		prisonRooms[i].roomDescription = roomDescriptions[i];
		assignGuards(securityLevel[i], i);
		assignPrisoners(i);
	}
	assignPrisoners();

#pragma region ACTION DESCRIPTIONS
	//LOCATION ACTIONS
	actionDescriptions[0] = "Go To Cell Block A [0:02]\n";
	actionDescriptions[1] = "Go To Cell Block B [0:02]\n";
	actionDescriptions[2] = "Go To Cell Block C [0:02]\n";
	actionDescriptions[3] = "Go To Cell Block D [0:02]\n";
	actionDescriptions[4] = "Go To The Reception [0:02]\n";
	actionDescriptions[5] = "Go To The Courtyard [0:02]\n";
	actionDescriptions[6] = "Go To The Canteen [0:02]\n";
	actionDescriptions[7] = "Go To The Kitchen [0:02]\n";
	actionDescriptions[8] = "Go To The Infirmary [0:02]\n";
	actionDescriptions[9] = "Go To The Chapel [0:02]\n";
	actionDescriptions[10] = "Go To The Common Room [0:02]\n";
	actionDescriptions[11] = "Go To The Laundry [0:02]\n";
	actionDescriptions[12] = "Go To The Classroom [0:02]\n";
	actionDescriptions[13] = "Go To The Prison Store [0:02]\n";
	actionDescriptions[14] = "Go To Visitation [0:02]\n";
	actionDescriptions[15] = "Enter Your Personal Cell [0:02]\n";
	actionDescriptions[16] = "Go To The Showers [0:02]\n";
	actionDescriptions[17] = "Enter Your Escape Tunnel [0:02]\n";
	actionDescriptions[18] = "Go To The Therapists Office [0:02]\n";

	//GLOBAL ACTIONS
	actionDescriptions[19] = "Start A Fight\n";
	actionDescriptions[20] = "Start A Fire\n";
	actionDescriptions[21] = "Search For Contraband\n";
	actionDescriptions[22] = "Use Inventory Item\n";
	actionDescriptions[23] = "Socialise With Other Prisoners\n";

	//ROOM SPECIFIC ACTIONS
	actionDescriptions[24] = "Rummage Through Random Cell\n";																				//Cell Blocks
	actionDescriptions[25] = "Play Board Games\n";																							//Cell Blocks, Common Room
	actionDescriptions[26] = "Attempt To Break Into Side Room\n";																			//Reception
	actionDescriptions[27] = "Attempt To Break Into The Guards Cabinet\n";																	//Reception
	actionDescriptions[28] = "Raise Prison Alarm\n";																						//Reception
	actionDescriptions[29] = "Play Football\n";																								//Courtyard
	actionDescriptions[30] = "Watch Others Play Football\n";																				//Courtyard
	actionDescriptions[31] = "Go For A Run\n";																								//Courtyard
	actionDescriptions[32] = "Practice With Training Dummies\n";																			//Courtyard
	actionDescriptions[33] = "Meditate On The Grass\n";																						//Courtyard
	actionDescriptions[34] = "Eat Meal\n";																									//Canteen, Personal Cell
	actionDescriptions[35] = "Use Prison Vending Machine\n";																				//Canteen, Common Room	
	actionDescriptions[36] = "Work In The Kitchen\n";																						//Kitchen					
	actionDescriptions[37] = "Go For A Checkup\n";																							//Infirmary
	actionDescriptions[38] = "Consult The Doctor\n";																						//Infirmary
	actionDescriptions[39] = "Pray In Silence\n";																							//Chapel	
	actionDescriptions[40] = "Join Prayer Session\n";																						//Chapel
	actionDescriptions[41] = "Join Mass\n";																									//Chapel
	actionDescriptions[42] = "Join AA Meeting\n";																							//Common Room
	actionDescriptions[43] = "Play Table Football\n";																						//Common Room
	actionDescriptions[44] = "Play Chess\n";																								//Common Room
	actionDescriptions[45] = "Watch TV\n";																									//Common Room
	actionDescriptions[46] = "Work In The Laundry\n";																						//Laundry
	actionDescriptions[47] = "Join Maths Class\n";																							//Classroom
	actionDescriptions[48] = "Join English Class\n";																						//Classroom
	actionDescriptions[49] = "Join Works Class\n";																							//Classroom
	actionDescriptions[50] = "Work In The Prison Store\n";																					//Prison Store		
	actionDescriptions[51] = "Shop For Goods\n";																							//Prison Store
	actionDescriptions[52] = "Join Your Family\n";																							//Visitation
	actionDescriptions[53] = "Join Your Lawyer\n";																							//Visitation
	actionDescriptions[54] = "Join Your Prison Pen Pal\n";																					//Visitation		
	actionDescriptions[55] = "Join Your Lover\n";																							//Visitation
	actionDescriptions[56] = "Join Your Supplier\n";																						//Visitation
	actionDescriptions[57] = "Make A Phone Call\n";																							//Visitation
	actionDescriptions[58] = "Go To Sleep\n";																								//Prisoner Cell
	actionDescriptions[59] = "Go To The Window\n";																							//Prisoner Cell
	actionDescriptions[60] = "Store Contraband\n";																							//Prisoner Cell
	actionDescriptions[61] = "Start Digging Tunnel\n";																						//Prisoner Cell	
	actionDescriptions[62] = "Take A Shower\n";																								//Shower
	actionDescriptions[63] = "Continue Through The Tunnel\n";																				//Tunnel	
	actionDescriptions[64] = "Dig Further In Your Tunnel\n";																				//Tunnel	
	actionDescriptions[65] = "Return To Your Cell\n";																						//Tunnel
	actionDescriptions[66] = "Attend An Appointment\n";																						//Therapist Office
	actionDescriptions[67] = "Search Through Prisoner Files\n";																				//Therapist Office

	//SPECIAL ROOM - PRISON ENTRANCE
	actionDescriptions[68] = "Go To The Prison Entrance\n";
#pragma endregion
}

void checkActions()
{
	//CREATE ACTION OBJECTS
	fori(69)
	{
		playerActions[i].actionID = i;
		playerActions[i].actionDescription = actionDescriptions[i];
		playerActions[i].playerPermission = false;
		//ACTION TYPES

		playerActions[i].actionType = "roomaction";

		if (-1 < i && i < 19 || i == 68)
		{
			playerActions[i].actionType = "location";
		}

		if (18 < i && i < 24)
		{
			playerActions[i].actionType = "globalaction";
		}
	}
	//GLOBAL ACTIONS
	playerActions[19].playerPermission = true;
	if (player.hasLighter == true) playerActions[20].playerPermission = true;
	playerActions[21].playerPermission = true;
	playerActions[22].playerPermission = true;
	playerActions[23].playerPermission = true;

	//ROOM SPECIFIC ACTIONS
	switch (playerLocation)
	{
	case 0: /*Cell Block A*/
		//LOCATIONS
		playerActions[15].playerPermission = true;
		playerActions[16].playerPermission = true;
		playerActions[9].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[24].playerPermission = true;
		playerActions[25].playerPermission = true;
		break;
	case 1: /*Cell Block B*/
		//LOCATIONS
		playerActions[13].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[24].playerPermission = true;
		playerActions[25].playerPermission = true;
		break;
	case 2: /*Cell Block C*/
		//LOCATIONS
		playerActions[11].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[24].playerPermission = true;
		playerActions[25].playerPermission = true;
		break;
	case 3: /*Cell Block D*/
		//LOCATIONS
		playerActions[12].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[24].playerPermission = true;
		playerActions[25].playerPermission = true;
		break;
	case 4: /*Reception*/
		//LOCATIONS
		playerActions[5].playerPermission = true;
		playerActions[68].playerPermission = true;

		//ACTIONS
		playerActions[26].playerPermission = true;
		playerActions[27].playerPermission = true;
		playerActions[28].playerPermission = true;

		//CANCELLING GLOBALS
		playerActions[23].playerPermission = false;
		break;
	case 5: /*Courtyard*/
		//LOCATIONS
		playerActions[0].playerPermission = true;
		playerActions[1].playerPermission = true;
		playerActions[2].playerPermission = true;
		playerActions[3].playerPermission = true;
		playerActions[4].playerPermission = true;
		playerActions[6].playerPermission = true;
		playerActions[7].playerPermission = true;
		playerActions[8].playerPermission = true;
		playerActions[9].playerPermission = true;
		playerActions[10].playerPermission = true;
		playerActions[11].playerPermission = true;
		playerActions[12].playerPermission = true;
		playerActions[13].playerPermission = true;
		playerActions[14].playerPermission = true;

		//ACTIONS
		playerActions[29].playerPermission = true;
		playerActions[30].playerPermission = true;
		playerActions[31].playerPermission = true;
		playerActions[32].playerPermission = true;
		playerActions[33].playerPermission = true;
		playerActions[34].playerPermission = true;
		break;
	case 6: /*Canteen*/
		//LOCATIONS
		playerActions[7].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[34].playerPermission = true;
		playerActions[35].playerPermission = true;
		break;
	case 7: /*Kitchen*/
		//LOCATIONS
		playerActions[6].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[36].playerPermission = true;
		break;
	case 8: /*Infirmary*/
		//LOCATIONS
		playerActions[9].playerPermission = true;
		playerActions[18].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[37].playerPermission = true;
		playerActions[38].playerPermission = true;
		break;
	case 9: /*Chapel*/
		//LOCATIONS
		playerActions[0].playerPermission = true;
		playerActions[8].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[39].playerPermission = true;
		playerActions[40].playerPermission = true;
		playerActions[41].playerPermission = true;
		break;
	case 10: /*Common Room*/
		//LOCATIONS
		playerActions[12].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[25].playerPermission = true;
		playerActions[34].playerPermission = true;
		playerActions[42].playerPermission = true;
		playerActions[43].playerPermission = true;
		playerActions[44].playerPermission = true;
		playerActions[45].playerPermission = true;
		break;
	case 11: /*Laundry*/
		//LOCATIONS
		playerActions[2].playerPermission = true;
		playerActions[14].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[46].playerPermission = true;
		break;
	case 12: /*Classroom*/
		//LOCATIONS
		playerActions[3].playerPermission = true;
		playerActions[10].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[47].playerPermission = true;
		playerActions[48].playerPermission = true;
		playerActions[49].playerPermission = true;
		break;
	case 13: /*Prison Store*/
		//LOCATIONS
		playerActions[2].playerPermission = true;
		playerActions[7].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[50].playerPermission = true;
		playerActions[51].playerPermission = true;
		break;
	case 14: /*Visitation*/
		//LOCATIONS
		playerActions[11].playerPermission = true;
		playerActions[5].playerPermission = true;

		//ACTIONS
		playerActions[52].playerPermission = true;
		playerActions[53].playerPermission = true;
		playerActions[54].playerPermission = true;
		playerActions[55].playerPermission = true;
		playerActions[56].playerPermission = true;
		playerActions[57].playerPermission = true;
		break;
	case 15: /*Personal Cell*/
		//LOCATIONS
		playerActions[0].playerPermission = true;
		playerActions[17].playerPermission = true;

		//ACTIONS
		playerActions[58].playerPermission = true;
		playerActions[59].playerPermission = true;
		playerActions[60].playerPermission = true;
		playerActions[61].playerPermission = true;
		break;
	case 16: /*Shower*/
		//LOCATIONS
		playerActions[0].playerPermission = true;

		//ACTIONS
		playerActions[62].playerPermission = true;
		break;
	case 17: /*Tunnel*/
		//LOCATIONS
		playerActions[15].playerPermission = true;

		//ACTIONS
		playerActions[63].playerPermission = true;
		playerActions[64].playerPermission = true;
		playerActions[65].playerPermission = true;
		break;
	case 18: /*Therapist Office*/
		//LOCATIONS
		playerActions[8].playerPermission = true;

		//ACTIONS
		playerActions[66].playerPermission = true;
		playerActions[67].playerPermission = true;
		break;
	}

}

void assignGuards(std::string securityLevel, int k)
{
	if (securityLevel == "High")
	{
		//Day Guards
		fori(14)
		{
			prisonRooms[k].gPresentAtDay[i] = rand() % 4 + 7;
		}

		//Night Guards
		prisonRooms[k].gPresentAtNight = 3;
	}

	if (securityLevel == "Med")
	{
		//Day Guards
		fori(14)
		{
			prisonRooms[k].gPresentAtDay[i] = rand() % 3 + 4;
		}

		//Night Guards
		prisonRooms[k].gPresentAtNight = 2;
	}

	if (securityLevel == "Low")
	{
		//Day Guards
		fori(14)
		{
			prisonRooms[k].gPresentAtDay[i] = rand() % 3 + 2;
		}

		//Night Guards
		prisonRooms[k].gPresentAtNight = 1;
	}

	if (securityLevel == "None")
	{
		//Day Guards
		fori(14)
		{
			prisonRooms[k].gPresentAtDay[i] = 0;
		}

		//Night Guards
		prisonRooms[k].gPresentAtNight = 0;
	}
}

void assignPrisoners(int k)
{
#pragma region CREATE PRISONERS
	std::random_device shuffleDevice;																										//Generate Uniformly Distributed Random Numbers
	std::mt19937 rng(shuffleDevice());																										//Seed RNG using Shuffle Device
	std::vector<int> cellNumbers(499);																										//Assign Cell Numbers To Sequence
	std::iota(cellNumbers.begin(), cellNumbers.end(), 0);																					//Fill With Sequence of 499 Values
	std::shuffle(cellNumbers.begin(), cellNumbers.end(), rng);																				//Shuffle The Sequence

	int i = 0;
	for (int r : cellNumbers)
	{
		//CREATE NAMES
		int firstname = rand() % 65;
		int surname = rand() % 65;
		prisonerNames[i] = prisonerFirstNames[firstname] + " " + prisonerSurnames[surname];
		prisoners[i].prisonerName = prisonerNames[i];

		//CREATE AGE
		int age = rand() % 50 + 18;
		prisoners[i].prisonerAge = age;

		//ASSIGN CELL
		prisonerCells[i].assignedPrisoner = prisoners[r];
		prisoners[i].assignedCell = r;

		i++;
	}
#pragma endregion

	fori(14)
	{
		//Personal Cell
		if (i != 10)
		{
			prisonRooms[k].pPresentAtDay[i] = rand() % 11 + 32;
		}
	}

	//Night Time
	fori(10)
	{
		prisonRooms[i + 4].pPresentAtNight = 0;
	}

	//Dinner Time
	prisonRooms[6].pPresentAtDay[2] = rand() % 100 + 200;
	prisonRooms[6].pPresentAtDay[11] = rand() % 100 + 200;
}

void assignPrisoners()
{
	//Personal Cell, Tunnel, TherapistsOffice
	fori(14)
	{
		prisonRooms[10].pPresentAtDay[i] = 0;
		prisonRooms[16].pPresentAtDay[i] = 0;
		prisonRooms[17].pPresentAtDay[i] = 0;
	}

	//Night Time
	fori(10)
	{
		prisonRooms[i + 4].pPresentAtNight = 0;
	}

	//Dinner Time
	prisonRooms[6].pPresentAtDay[2] = rand() % 100 + 200;
	prisonRooms[6].pPresentAtDay[11] = rand() % 100 + 200;
}

void replacePrisoner(int prisonerNumber)
{
	//CREATE NAMES
	int firstname = rand() % 65;
	int surname = rand() % 65;
	prisonerNames[prisonerNumber] = prisonerFirstNames[firstname] + " " + prisonerSurnames[surname];
	prisoners[prisonerNumber].prisonerName = prisonerNames[prisonerNumber];

	//CREATE AGE
	int age = rand() % 50 + 18;
	prisoners[prisonerNumber].prisonerAge = age;

	//RESET STATS
	prisoners[prisonerNumber].likesPlayer = 0;
}