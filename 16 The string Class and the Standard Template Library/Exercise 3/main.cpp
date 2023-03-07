// hangman.cpp -- some string methods
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include<fstream>

using std::string;
const int NUM = 26;
string wordlist[NUM]; /*= { "apiary", "beetle", "cereal",
"danger", "ensign", "florid", "garage", "health", "insult",
"jackal", "keeper", "loaner", "manage", "nonce", "onset",
"plaid", "quilt", "remote", "stolid", "train", "useful",
"valid", "whence", "xenon", "yearn", "zippy" };*/

int main()
{
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;

	std::string FilePath = "C:\\Users\\User\\source\\repos\\Prata\\Prata\\wordlist.txt"; // default database file path
	std::cout << "Beyond the default, the program uses a database located in the following path:\n\"" << FilePath <<
		"\"\nWould you like to change the path to the database file? <Y/N>: ";
	char ch = ' ';
	std::cin >> ch;
	system("cls");
	switch (ch) {
	case 'Y': case 'y':
		std::cout << "\nEnter new database file path: ";
		std::cin >> FilePath;
		break;
	default:
		break;
	}

	std::ifstream inFile;

	inFile.open(FilePath);

	if (!inFile.is_open()) { // failed to open file
		std::cout << "Could not open the file " << FilePath << std::endl;
		std::cout << "Program terminating.\n";
		system("pause");
		std::cin.get();    // keep window open
		exit(EXIT_FAILURE);
	}

	for (int i = 0; inFile >> wordlist[i] and i <= NUM; ++i)
		; // cycle without body
	inFile.close();

	std::srand(std::time(0));
	
	char play;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[std::rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length
			<< " letters, and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter; // add to string
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				// check if letter appears again
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";

		cout << "Will you play another? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "Bye\n";

	return 0;
}
