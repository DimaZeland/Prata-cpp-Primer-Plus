#include <iostream>
#include <fstream>
#include <cstdlib>  

int main()
{
	using namespace std;
	const char* file1 = "C:\\Users\\User\\source\\repos\\Prata\\Prata\\1.txt";
	const char* file2 = "C:\\Users\\User\\source\\repos\\Prata\\Prata\\2.txt";
	const char* file3 = "C:\\Users\\User\\source\\repos\\Prata\\Prata\\3.txt";

	ifstream fin1;
	fin1.open(file1, std::ios_base::in);
	if (!fin1.is_open()){
		cerr << "Could not open " << file1 << endl;
		fin1.clear();
	}

	ifstream fin2;
	fin2.open(file2, std::ios_base::in);  // connect stream to argv[1]
	if (!fin2.is_open()) {
		cerr << "Could not open " << file2 << endl;
		fin2.clear();
	}

	ofstream fout;              // open stream
	fout.open(file3, std::ios_base::out | std::ios_base::trunc);  // connect stream to argv[1]
	if (!fout.is_open()){
		cerr << "Could not open " << file3 << endl;
		fout.clear();
	}

	char ch;
	while(!fin1.eof() or !fin2.eof()){
		
		while (fin1.peek() != '\n' and !fin1.eof()) { // reading the line from the first file
			fin1.get(ch);
			cout << ch;
			fout << ch;
		}
		if (fin1.peek() == '\n'){
			fin1.get();
			fout << ' ';
			cout << ' ';
		}
			
		while (fin2.peek() != '\n' and !fin2.eof()) { // reading the line from the second file
			fin2.get(ch);
			cout << ch;
			fout << ch;
		}
		if (!fin2.eof()) {
			fin2.get(ch);
			fout << ch;
			cout << ch;
		}
		else if (fin2.is_open()){
			fout << '\n';
			cout << '\n';
			fin2.close(); // disconnect file
		}
	}



	fin1.close(); // disconnect file
	fin2.close(); // disconnect file
	fout.close(); // disconnect file

	system("pause");
	return 0;
}
