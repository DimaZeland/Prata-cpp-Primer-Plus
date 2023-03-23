#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    using namespace std;
    if (argc == 1) { // quit if no arguments
        cerr << "Usage: " << argv[0] << " filename[s]\n";
        system("pause");
        exit(EXIT_FAILURE);
    }

    ifstream fin;
    fin.open(argv[1]);  // connect stream to argv[1]
    if (!fin.is_open()) {
        cerr << "Could not open " << argv[1] << endl;
        fin.clear();
    }

    ofstream fout;              // open stream
    fout.open(argv[2], std::ios_base::out | std::ios_base::app);  // connect stream to argv[1]
    if (!fout.is_open()) {
        cerr << "Could not open " << argv[2] << endl;
        fout.clear();
    }

    char ch;
    while (fin.get(ch))
        fout << ch;

    fin.close(); // disconnect file
    fout.close(); // disconnect file

    system("pause");
    return 0;
}
