// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<iterator>
#include<memory>

struct Review {
	std::string title;
	int rating;
	double price;
};

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
//bool operator_less(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool sorting_price_increase(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2); // sorting by price increase
bool FillReview(Review & rr);
void ShowReview(const std::shared_ptr<Review> rr);

int main()
{
	using namespace std;

	vector<shared_ptr<Review>> books;
	//Review temp;
	shared_ptr<Review> temp (new Review);
	while (FillReview(*temp)){
		books.push_back(temp);
		//shared_ptr<Review> temp1(new Review);
		temp = shared_ptr<Review> (new Review);
	}
	if (books.size() > 0)
	{
		int choise = 0;
		bool out = false;
		system("cls");
		std::cout << "\nThank you. Please select the desired order of displaying the list of books:\n" <<
			"1 - in the original order\n2 - in alphabetical order\n3 - in ascending order of rating\n4 - in ascending order of price\n5 - in order of decreasing price\n" <<
			"0 - end of the program\n";
			while(std::cin >> choise and choise){
				system("cls");
				switch (choise){
				case 1: 
					std::cout << "\nList of books in original order:\n";
					for_each(books.begin(), books.end(), ShowReview);
					break;
				case 2:
					std::cout << "\nList of books in alphabetical order:\n";
					sort(books.begin(), books.end());
					for_each(books.begin(), books.end(), ShowReview);
					break;
				case 3:
					std::cout << "\nList of books in ascending order of rating:\n";
					sort(books.begin(), books.end(), worseThan);
					for_each(books.begin(), books.end(), ShowReview);
					break;
				case 4:
					std::cout << "\nList of books in ascending order of price:\n";
					sort(books.begin(), books.end(), sorting_price_increase);
					for_each(books.begin(), books.end(), ShowReview);
					break;
				case 5:
					std::cout << "\nList of books in order of decreasing price:\n";
					sort(books.begin(), books.end(), sorting_price_increase);
					for_each(books.rbegin(), books.rend(), ShowReview);
					break;
				case 0:
					out = true;
				default:
					std::cout << "\nList of books in original order:\n";
					for_each(books.begin(), books.end(), ShowReview);
					break;
				}
				if (out)
					break;
				std::cout << "\nPlease select the desired order of displaying the list of books:\n" <<
					"1 - in the original order\n2 - in alphabetical order\n3 - in ascending order of rating\n4 - in ascending order of price\n5 - in order of decreasing price\n" <<
					"0 - end of the program\n";
			}
	}
	else
		std::cout << "No entries. ";
	std::cout << "Bye.\n";
	system("pause");
	return 0;
}

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool FillReview(Review & rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	std::cout << "Enter book price: ";
	std::cin >> rr.price;
	if (!std::cin)
		return false;
	// get rid of rest of input line
	while (std::cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const std::shared_ptr<Review> rr)
{
	std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << '$' << std::endl;
}

bool sorting_price_increase(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2) { // sorting by price increase
	if (r1->price < r2->price)
		return true;
	else
		return false;
}
