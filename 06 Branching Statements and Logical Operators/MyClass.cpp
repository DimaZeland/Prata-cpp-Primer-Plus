#include "MyClass.h"

// constructor & destructor
MyClass::MyClass() : itsSentence{}, itsDonations{}, flag{ 1 },
Arr{ {"Wimp Macho", "Junior Developer", "Wimp", 1},{ "Raki Rhodes", "Middle Developer", "Raki", 2 },{ "Celia Laiter", "Senior Developer", "Celia", 3 },
{ "Hoppy Hitman", "Techical Lead", "Hoppy", 1 },{ "Pat Hand", "Project Manager", "Pat", 2 }, }
{}

MyClass::~MyClass() {}

void
MyClass::operator +=(const char& ch) { // operator overload + = for string concatenation and symbol
	this->itsSentence.push_back(ch);
}

void
MyClass::AccountingDonations(void) { // Accounting donations

	cout << "\nEnter amount of donation <$>: ";
	double donate{ 0 }, sumDonations{ 0 };
	int i{ 0 };
	const int Max = itsDonations.size();
	while (cin >> donate and i < Max) { // writing values to a template array
		this->itsDonations[i] = donate;
		sumDonations += donate;
		++i;
	}
	double averageDonate = sumDonations / i;
	int largeDonations{ 0 };
	for (double x : itsDonations) // accounting for more than average donations
		if (x > averageDonate)
			++largeDonations;
	cout << "\nAverage donation: " << averageDonate << ", the number of donations is higher than the average: " << largeDonations << '\n';
}

void
MyClass::ConclusionPatrons(void) { // the conclusion of patrons of the society of protection of influential persons
	cout << "Enter number of patrons:";
	int patrons{ 0 };
	PatronInfo input;
	cin >> patrons;
	for (int i = 0; i < patrons; ++i) { // enter the information about patrons
		cout << "\nEnter the name of " << i + 1 << " patron: ";
		cin >> input.name;
		cout << "\nEnter the value of donations of this patron: ";
		cin >> input.donations;
		itsPatronsArr.push_back(input);
	}

	flag = true;
	cout << "\"Grand Patrons\"";
	for (PatronInfo x : itsPatronsArr) // information on major sponsors
		if (x.donations >= 10000) {
			cout << endl << x.name << '\t' << x.donations;
			flag = false;
		}

	if (flag == true)
		cout << "none\n";

	flag = true;
	cout << "\n\"Patrons\"";
	for (PatronInfo x : itsPatronsArr) // information on other sponsors
		if (x.donations < 10000) {
			cout << endl << x.name << '\t' << x.donations;
			flag = false;
		}

	if (flag == true)
		cout << "none\n";
}

void
MyClass::ConclusionPatronsFile(void) { // the conclusion of patrons of the society of protection of influential persons
	cout << "Enter name of data file: ";
	std::string filename{};
	cin >> filename; // C:\Users\User\source\repos\SolutionName\ProjectName\FileName.txt (for MS Visual Studio 2017 on Windows 7)
	std::ifstream inFile;
	inFile.open(filename);

	if (!inFile.is_open())  // failed to open file
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		system("pause");
		cin.get();    // keep window open
		exit(EXIT_FAILURE);
	}
	int patrons{ 0 };
	inFile >> patrons; // get number of patrons
	PatronInfo input;
	for (int i = 0; i < patrons; ++i) { // enter the information about patrons
		inFile.get(); // reading a space in the buffer
		std::getline(inFile,input.name); // get the name of the patron (which consists of two separate words)
		inFile >> input.donations; // get the value of the donation
		itsPatronsArr.push_back(input);
	}
	
	inFile.close();

	flag = true;
	cout << "\"Grand Patrons\"";
	for (PatronInfo x : itsPatronsArr) // information on major sponsors
		if (x.donations >= 10000) {
			cout << endl << x.name << '\t' << x.donations;
			flag = false;
		}

	if (flag == true)
		cout << " none\n";

	flag = true;
	cout << "\n\"Patrons\"";
	for (PatronInfo x : itsPatronsArr) // information on other sponsors
		if (x.donations < 10000) {
			cout << endl << x.name << '\t' << x.donations;
			flag = false;
		}

	if (flag == true)
		cout << " none\n";
	
	cout << endl;
}

void
MyClass::DisplayBopMembers() { // Display information about the BOP members according to a given parameter

	flag = true;
	while (flag) {
		cout << "\nBenevolent Order of Programmers Report:\na. display by name\t\tb. display by title\nc. display by bopname\t\td. display by preference\nq. quit" <<
			"\nEnter your choise: ";
		char ch = ' ';
		cin >> ch;
		switch (ch) {
		case 'a':
			for (bop x : Arr)
				cout << x.fullname << endl;
			break;
		case 'b':
			for (bop x : Arr)
				cout << x.title << endl;
			break;
		case 'c':
			for (bop x : Arr)
				cout << x.bopname << endl;
			break;
		case 'd':
			for (bop x : Arr)
				switch (x.preference)
				{
				case 1:
					cout << x.title << endl;
					break;
				case 2:
					cout << x.fullname << endl;
					break;
				case 3:
					cout << x.bopname << endl;
					break;
				default:
					break;
				}
			break;
		case 'q':
			cout << "\nBye!\n";
			flag = false;
			break;
		default:
			cout << "\nInvalid input!\n";
			break;
		}
	}
}

void
MyClass::KeyboardInputConversions(void) { // Keyboard Input Conversions

	cout << "\nEnter the text for analysis, and type @ to terminate input.\n"; // request for text for analysis, terminating character @
	char ch;
	cin.get(ch);
	while (ch != '@') {
		if (isdigit(ch) and '.' == cin.peek()) {
			cin.get(); // skip point after the integer part of a fractional number
			cin.get(ch);
			continue;
		}
		else if (isdigit(ch)) {
			cin.get(ch);
			continue;
		}
		else if (isupper(ch))
			ch = tolower(ch);
		else if (islower(ch))
			ch = toupper(ch);
		itsSentence += ch;
		cin.get(ch);
	}
	cout << "\nYour sentence is: " << this->itsSentence << endl;
}

void
MyClass::ReadingFile(void)const { // counting the number of characters in a file

	cout << "Enter name of data file: ";
	std::string filename{};
	cin >> filename;
	std::ifstream inFile;
	inFile.open(filename);
	if (!inFile.is_open())  // failed to open file
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		system("pause");
		cin.get();    // keep window open
		exit(EXIT_FAILURE);
	}
	char ch = ' ';
	int count = 0;          // number of characters read

	inFile >> ch;        // get first character
	while (inFile.good())   // while input good and not at EOF
	{
		++count;            // one more character read
		inFile >> ch;    // get next character
	}
	if (inFile.eof())
		cout << "End of file reached.\n";
	else if (inFile.fail())
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated for unknown reason.\n";
	if (count == 0)
		cout << "No data processed.\n";
	else
		cout << "Characters read: " << count << endl;
	inFile.close();
}

void
MyClass::ReadingWords(void)const { // Reading and sorting words

	cout << "Enter words (q to quit):\n";
	int otherWords = 0, vowelsWords = 0, unspokenWords = 0;
	std::string word{};
	cin >> word;
	while (word != "q") {
		if (word[0] >= 65 and word[0] >= 90 or word[0] >= 97 and word[0] >= 122)
			switch (word[0]) // if entered text is word
			{
			case 'A': case 'E': case 'I': case 'O': case 'U': case 'a': case 'e': case 'i': case 'o': case 'u': // if the first letter is a vowel
				++vowelsWords;
				break;
			default: // if the first letter is not a vowel
				++unspokenWords;
				break;
			}
		else
			++otherWords;
		cin >> word;
	}
	cout << endl << vowelsWords << " beginning with vowels\n" << unspokenWords << " beginning with consonants\n" <<
		otherWords << " other\n";
}

void
MyClass::ShowsMenu(void) { // prototype menu
	cout << "Please enter one of the following choices:\n" << std::setw(15) << " c) carnivore" << std::setw(15) << "p) pianist\n"
		<< std::setw(15) << "t) tree" << std::setw(15) << "g) game\n";
	char ch{ ' ' };
	while (flag) {
		cin >> ch;
		switch (ch) {
		case 'c': {
			cout << "\nc++ is a fastest programming language.\n";
			flag = false;
			break;
		}
		case 'p': {
			cout << "\nA pianist is an individual musician who plays the piano.\n";
			flag = false;
			break;
		}
		case 't': {
			cout << "\nIn botany, a tree is a perennial plant with an elongated stem, or trunk, supporting branches and leaves in most species.\n";
			flag = false;
			break;
		}
		case 'g': {
			cout << "\nA game is a structured form of play, usually undertaken for enjoyment and sometimes used as an educational tool.\n";
			flag = false;
			break;
		}
		default:
			cout << "\nPlease enter a c, p, t, or g: \n";
			break;
		}
	}
}

void
MyClass::TaxCalculate(void)const { // Calculate income tax in Neutron

	cout << "\nEnter the amount of your income in the tvarps: ";
	double income{ 0 }, taxValue{ 0 };
	while (cin >> income) {
		if (income < 0)
			break;
		if (income <= 5000)
			cout << "\nAmount to pay taxes: 0 tvarps.\n";
		else if (income <= 15000) {
			taxValue = (income - 5000) * 0.1;
			cout << "\nAmount to pay taxes: " << taxValue << " tvarps.\n";
		}
		else if (income <= 35000) {
			taxValue = ((income - 15000) * 0.15) + 1000;
			cout << "\nAmount to pay taxes: " << taxValue << " tvarps.\n";
		}
		else {
			taxValue = ((income - 35000) * 0.2) + 4000;
			cout << "\nAmount to pay taxes: " << taxValue << " tvarps.\n";
		}
		cout << "\nEnter the amount of your income in the tvarps: ";
	}
}