#include <iostream>
#include <fstream>
#include <cstdlib>  
#include<list>
#include<string>

int main()
{
	using namespace std;
	const char* file1 = "C:\\Users\\User\\source\\repos\\Prata\\Prata\\mat.dat";
	const char* file2 = "C:\\Users\\User\\source\\repos\\Prata\\Prata\\pat.dat";
	const char* file3 = "C:\\Users\\User\\source\\repos\\Prata\\Prata\\matnpat.dat";

	list<std::string> list_file1, list_file2;

	ifstream fin1;
	fin1.open(file1, std::ios_base::in);
	if (!fin1.is_open()){
		cerr << "Could not open " << file1 << endl;
		fin1.clear();
	}

	std::string str;
	
	while(fin1 >> str) // write Mat Friends names to container
	list_file1.push_back(str);
	fin1.close(); // disconnect file
	list_file1.sort();

	ifstream fin2;
	fin2.open(file2, std::ios_base::in);
	if (!fin2.is_open()) {
		cerr << "Could not open " << file2 << endl;
		fin2.clear();
	}
	
	while (fin2 >> str) // write Mat Friends names to container
		list_file2.push_back(str);
	fin2.close(); // disconnect file
	list_file2.sort();

	list_file1.merge(list_file2); // MatFriend + PatFriend
	list_file1.unique(); // remove duplicates neighbor names
	
	ofstream fout; // open stream
	fout.open(file3, std::ios_base::out | std::ios_base::trunc);  // connect stream to argv[1]
	if (!fout.is_open()){
		cerr << "Could not open " << file3 << endl;
		fout.clear();
	}

	for (std::string x : list_file1) // write all friends to container
		fout << x << '\n';

	fout.close();
	
	system("pause");
	return 0;
}
