#include "Menu.hpp"
#include "Game.hpp"

int mainMenu();

int SetupGame();




int main()
{
	int usersChoice;
	string gameSize;
	usersChoice = mainMenu();
	Game twentyforty;

	if (usersChoice == 1)
	{
		Menu::ClearScreen();
		cout << "\t\t2048" << endl;
		cout << "\t---------" << endl;
		twentyforty.Setup();
		
	}



	return 0;
}








int mainMenu()
{
	int usersChoice;

	vector<string>options;
	options.push_back("New Game");

	Menu::Header("WELCOME TO ");
	Menu::Logo();
	cout << endl;
	usersChoice = Menu::ShowMenuWithPrompt(options);
	return usersChoice;
}

int SetupGame()
{
	int defineSize;

	vector<string>GameSetupOptions;
	GameSetupOptions.push_back("4x4");
	GameSetupOptions.push_back("5x5");

	defineSize = Menu::ShowMenuWithPrompt(GameSetupOptions);
	return defineSize;
}