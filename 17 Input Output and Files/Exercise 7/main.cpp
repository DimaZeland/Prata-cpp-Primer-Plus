#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Store {
private:
	std::ofstream * pfout;
public:
	Store(ofstream & fout) { pfout = &fout; }
	Store& operator() (const std::string& str) {
		size_t len = str.length();
		pfout->write((char*)&len, sizeof(size_t));
		pfout->write(str.data(), len);
		return *this;
	}
};

void ShowStr(const std::string &);
void GetStrs(std::ifstream& , vector<string>&);

int main(){
	using namespace std;
	vector<string> vostr;
	string temp;
	// acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
	system("pause");
	return 0;
}

void ShowStr(const std::string & str) {
	std::cout << str << '\n';
}

void GetStrs(ifstream & fin, vector<string> & vistr)
{
	size_t len;
	string str;
	char ch;
	// check that there is something to read
	while (fin.peek() && !fin.eof())
	{
		fin.read((char *)&len, sizeof(size_t));
		for (size_t i = 0; i < len; i++)
		{
			fin.read(&ch, sizeof(char));
			str.push_back(ch);
		}
		vistr.push_back(str);
		str.clear();
	}
}