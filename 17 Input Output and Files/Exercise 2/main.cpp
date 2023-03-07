#include <iostream>
#include <fstream>
#include <cstdlib>  

int main(int argc, char * argv[])
{
	using namespace std;
	if (argc == 1)          // quit if no arguments
	{
		cerr << "Usage: " << argv[0] << " filename[s]\n";
		system("pause");
		exit(EXIT_FAILURE);
	}

	ofstream fout;              // open stream

	fout.open(argv[1]);  // connect stream to argv[1]
	if (!fout.is_open())
	{
		cerr << "Could not open " << argv[1] << endl;
		fout.clear();
	}

	std::cout << "\nEnter a string: ";
	char ch;
	while (cin.peek() != EOF){
		std::cin.get(ch);
		fout << ch;
	}

	fout.close();           // disconnect file

	system("pause");
	return 0;
}
