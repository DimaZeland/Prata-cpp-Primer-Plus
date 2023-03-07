#include <iostream>
#include<vector>
#include<algorithm>
#include<list>

int reduce(long ar[], int n); // sorting an array, removing duplicate elements, returning the number of elements in a reduced array
int reduce1(long ar[], int n); // STL functions

int main() {

	long Arr[10]{ 10,9,8,6,6,4,3,8,2,5 };
	long Arr1[10]{ 10,9,8,6,6,4,3,8,2,5 };

	std::cout << "\nArr[10]:\n";
	for (int i = 0; i < 10; ++i)
		std::cout << i + 1 << ' ' << Arr[i] << '\n';

	reduce(Arr, 10);
	reduce1(Arr1, 10);
	system("pause");
	return 0;
}

int reduce(long ar[], int n) { // sorting an array, removing duplicate elements, returning the number of elements in a reduced array
	for (int i = 0; i < n; ++i) // sorting by ar[] by bubble method in ascending order
		for (int m = 0; m < n - i - 1; ++m)
			if (ar[m] > ar[m + 1])
				std::swap(ar[m], ar[m + 1]);
	std::cout << "\nsorting by ar[] by bubble method in ascending order:\n";
	for (int i = 0; i < n; ++i)
		std::cout << i << ' ' << ar[i] << '\n';

	std::vector<long> vec;
	vec.push_back(ar[0]);
	for (int i = 1; i < n; ++i) // removing duplicate elements
	if(ar[i] != vec.at(vec.size()-1))
		vec.push_back(ar[i]);
	
	int i = 0;
	for(long x: vec) // rewrite array
		ar[i++] = x;

	std::cout << "\nreduce:\n";
	for (int i = 0; i < vec.size(); ++i)
		std::cout << i + 1 << ' ' << ar[i] << '\n';

	return vec.size();
}

int reduce1(long ar[], int n) { // STL functions
	std::list<long> val(ar,ar+n);
	val.sort();
	val.unique();

	int i = 0;
	for (long x : val){
		ar[i] = x;
		++i;
	}

	std::cout << "\nreduce 1:\n";
	for (int i = 0; i < val.size(); ++i)
		std::cout << i + 1 << ' ' << ar[i] << '\n';

	return val.size();
}
