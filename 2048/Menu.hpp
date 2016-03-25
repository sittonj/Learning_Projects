#ifndef _MENU
#define _MENU

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Menu
{
public:
	// OUTPUT
	static void ClearScreen();
	static void Header(const string& header);
	static void DrawHorizontalBar(int width, char symbol = '-');
	static void Logo();

	// MENUS and INPUT/OUTPUT
	static void ShowMenu(const vector<string> options, bool vertical = true);
	static int ShowMenuWithPrompt(const vector<string> options, bool vertical = true);

	static int GetValidChoice(int min, int max, const string& message = "");
	static string GetValidStringChoice(const vector<string> options, bool caseSensitive = false);

	// UTILITIES
	static string IntToString(int num);
	static int StringToInt(const string& str);
	static string ToUpper(const string& val);
};


#endif
