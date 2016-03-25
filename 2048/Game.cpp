#include "Game.hpp"
#include "Menu.hpp"
#include <iostream>
using namespace std;

Game::Game()
{
	m_defineSize = 1;
	m_size = 4;

	m_width= 4;
	m_height = 4;
}


bool Game::openSlots()
{
	string openID = "  o  ";
	
	for (int y = 0; y < m_size; y++)
	{
		for (int x = 0; x < m_size; x++)
		{
			if (gameBoard[y][x] == openID )
			{
				return true;
			}
		}
		return false;
	}
}

void Game::gamePlay()
{
	bool running = true;
	

	while(running)
	{
		m_numX = rand() % m_width;
		m_numY = rand() % m_height;
		cout << m_numX << " " << m_numY << endl;

		cout << endl;
		for (int y = 0; y < m_size; y++)
		{
			for (int x = 0; x < m_size; x++)
			{
				if (m_numY == y && m_numX == x)
				{
					cout << x << " " << y << endl;
					tempGameBoard.push_back("  2  ");
				}
				tempGameBoard.push_back("  o  ");
			}
			gameBoard.push_back(tempGameBoard);
			tempGameBoard.clear();
		}
		DisplayGame();
		running = openSlots();
	}
}

void Game::DisplayGame()
{
	for (int y = 0; y < m_size; y++)
	{
		cout << "     _______________________" << endl;
		cout << "    |";
		for (int x = 0; x < m_size; x++)
		{
			cout << gameBoard[y][x] << "|";
		}
		cout << endl;
	}
	cout << "     _______________________" << endl;
	system("Pause");
}




void Game::Setup()
{
	
	GameSetupOptions.push_back("4x4");
	GameSetupOptions.push_back("5x5");

	m_defineSize = Menu::ShowMenuWithPrompt(GameSetupOptions);

	if (m_defineSize == 1)
	{
		m_size = 4;
	}
	else
	{
		m_size = 5;
	}

	gamePlay();
	
}