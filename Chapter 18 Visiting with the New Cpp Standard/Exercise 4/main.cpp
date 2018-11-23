// functor.cpp -- using a functor
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T>  // functor class defines operator()()
class TooBig
{
public:
	T cutoff;
public:
	TooBig(const T & t) : cutoff(t) {}
	/*bool operator()(const T & v) { return v > cutoff; }*/
	};

auto outint = [](int n) { std::cout << n << " "; };

int main()
{
	using std::list;
	using std::cout;
	using std::endl;
	using std::for_each;
	using std::remove_if;

	TooBig<int> f100 = (100); // limit = 100
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10); // range constructor
	list<int> etcetera(vals, vals + 10);

	// C++0x can use the following instead
	//  list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	//  list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if([&f100](int v)->bool {return v > f100.cutoff; });               // use a unnamed lymbda
	etcetera.remove_if([](int v)->bool {return v > 200; });
	cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	 std::cin.get();
	return 0;
}
