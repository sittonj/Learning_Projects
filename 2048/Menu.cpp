#include "Menu.hpp"

void Menu::DrawHorizontalBar(int width, char symbol)
{
	for (int i = 0; i < width; i++)
	{
		cout << symbol;
	}
	cout << endl;
}

void Menu::Logo()
{
	cout << endl;
	cout << "   22222      00000    444  444   888888   " << endl;
	cout << "  2222222   000   000  444  444  888  888  " << endl;
	cout << "  22  222   000   000  444  444  888  888  " << endl;
	cout << "      222   000   000  444  444   88  88   " << endl;
	cout << "     222    000   000  44444444   888888   " << endl;
	cout << "    222     000   000       444  888  888  " << endl;
	cout << "   222      000   000       444  888  888  " << endl;
	cout << "  2222222     00000         444   888888   " << endl;
}

void Menu::Header(const string& header)
{
	DrawHorizontalBar(80);
	string head = "| " + header + " |";
	cout << " " << head << endl << " ";
	DrawHorizontalBar(head.size());
	cout << endl;
}

void Menu::ShowMenu(const vector<string> options, bool vertical)
{
	if (vertical)
	{
		for (unsigned int i = 0; i < options.size(); i++)
		{
			cout << " " << (i + 1) << ".\t" << options[i] << endl;
		}
	}
	else
	{
		for (unsigned int i = 0; i < options.size(); i++)
		{
			cout << " " << (i + 1) << ". " << options[i] << "\t";
		}
		cout << endl;
	}
}

int Menu::ShowMenuWithPrompt(const vector<string> options, bool vertical)
{
	ShowMenu(options, vertical);
	int choice = GetValidChoice(1, options.size());
	return choice;
}

int Menu::GetValidChoice(int min, int max, const string& message)
{
	if (message != "")
	{
		cout << endl;
		DrawHorizontalBar(message.size() + 2);
		cout << " " << message << endl;
	}

	int choice;
	cout << " >> ";
	cin >> choice;

	while (choice < min || choice > max)
	{
		cout << "Invalid selection. Try again." << endl;
		cout << ">> ";
		cin >> choice;
	}

	return choice;
}

string Menu::GetValidStringChoice(const vector<string> options, bool caseSensitive)
{
	cout << " Options: ";
	for (int i = 0; i < options.size(); i++)
	{
		cout << " [" << options[i] << "]";
	}

	string choice;
	cout << endl << " >> ";
	cin >> choice;

	while (true)
	{
		for (int i = 0; i < options.size(); i++)
		{
			string option = options[i];
			if (!caseSensitive)
			{
				choice = Menu::ToUpper(choice);
				option = Menu::ToUpper(option);
			}

			if (choice == option)
			{
				return choice;
			}
		}

		cout << " Invalid input. Try again." << endl;
	}
}

void Menu::ClearScreen()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	system("cls");
#else
	system("clear");
#endif
}

string Menu::IntToString(int num)
{
	return to_string(num);
}

int Menu::StringToInt(const string& str)
{
	return stoi(str);
}

string Menu::ToUpper(const string& val)
{
	string upper = "";
	for (unsigned int i = 0; i < val.size(); i++)
	{
		upper += toupper(val[i]);
	}
	return upper;
}
