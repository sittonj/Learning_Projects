#ifndef _GAME
#define _GAME

#include <vector>
using namespace std;

class Game
{
private:
	int m_defineSize;
	int m_size;

	int m_numX;
	int m_numY;

	int m_width;
	int m_height;

	vector<vector<string>>gameBoard;
	vector<string>tempGameBoard;

	vector<string>GameSetupOptions;
	

	void gamePlay();
	bool openSlots();
	

public:
	Game();
	void Setup();
	void DisplayGame();
	


};


#endif