//arrobj.cpp -- functions with array objects
#include <iostream>
#include <array>
#include <string>
const int Seasons = 4;
const char* Snames [Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };

struct Str {
public:
	Str() : expenses{} {}
	double expenses[Seasons];
};

void fill(Str&, int = Seasons);
void show(Str&, int = Seasons);
int main()
{
	Str Obj;
	fill(Obj);
	show(Obj);
	std::cin.get();
	std::cin.get();
	return 0;
}

void fill(Str& Obj, int Seasons)
{
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << "Enter " << Snames[i] << " expenses: ";
		std::cin >> Obj.expenses[i];
	}
}

void show(Str& Obj, int Seasons)
{
	double total = 0.0;
	std::cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << Snames[i] << ": $" << Obj.expenses[i] << '\n';
		total += Obj.expenses[i];
	}
	std::cout << "Total: $" << total << '\n';
}
