#include "prepro.h"
#include <Windows.h>
#include <iomanip>

void gameLogo()
{
	std::cout << R"(
					__________        .__                     
					\______   \_______|__| __________   ____  
					 |     ___/\_  __ \  |/  ___/  _ \ /    \ 
					 |    |     |  | \/  |\___ (  <_> )   |  \
					 |____|     |__|  |__/____  >____/|___|  /
							__________                        __      
							\______   \_______   ____ _____  |  | __  
							 |    |  _/\_  __ \_/ __ \\__  \ |  |/ /  
							 |    |   \ |  | \/\  ___/ / __ \|    <   
							 |______  / |__|    \___  >____  /__|_ \  
								\/              \/     \/     \/ )" << std::endl;
}

void gameWin(std::string winMessage, int widthLength)
{
	std::cout << R"(
						 ___ ___ _______ _______   ________ _______ _______ 
						|   |   |       |   |   | |  |  |  |_     _|    |  |
						 \     /|   -   |   |   | |  |  |  |_|   |_|       |
						  |___| |_______|_______| |________|_______|__|____|
                                                    )" << std::endl;

	std::cout << "\n\n\n\n\n" << std::endl;
	std::cout << std::setw(widthLength) << winMessage << std::endl;
}

void gameLose(std::string loseMessage, int widthLength)
{
	std::cout << R"(
						 ___ ___ _______ _______   _____   _______ _______ _______ 
						|   |   |       |   |   | |     |_|       |     __|    ___|
						 \     /|   -   |   |   | |       |   -   |__     |    ___|
						  |___| |_______|_______| |_______|_______|_______|_______|
                                                    )" << std::endl;

	std::cout << "\n\n\n\n\n" << std::endl;
	std::cout << std::setw(widthLength) << loseMessage << std::endl;

}

//INSERT OPTIONS MENU

void textTyper(std::string inputText)
{
	int i = 0;
	if (typeWriterEnabled)
	{
		while (inputText[i] != '\0')
		{
			std::cout << inputText[i];
			Sleep(18);
			i++;
		};
	}
	else
	{
		while (inputText[i] != '\0')
		{
			std::cout << inputText[i];
			Sleep(0);
			i++;
		};
	}
}

void displayGameWindow(int width, int height)
{
	HWND console = GetConsoleWindow();
	HWND desktop = GetDesktopWindow();
	RECT r, d;
	GetWindowRect(console, &r); //Stores Consoles Current Dimensions
	GetWindowRect(desktop, &d);
	int x = d.right;
	int y = d.bottom;
	//Creates and Centres the Console
	MoveWindow(console, (x - width) / 2, (y - height) / 2, width, height, TRUE);
}

void inputTooltip()
{
	std::cout << "\n_________________________________________" << std::endl;
	std::cout << " -> ";
}

void gameTopline()
{
	displayTime();
}