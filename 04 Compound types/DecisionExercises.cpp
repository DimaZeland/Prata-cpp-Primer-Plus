//Stephen Prata
//"C++ Primer Plus"
//Sixth Edition

//Chapter 4. Compound types

//Programming exercises

#include <iostream>
#include<vector>
#include<array>
#include<string>
#include<cstring>
#include<array>

class MyClass {
public:
    MyClass();

    ~MyClass();

    void Resume(); // query and display user data
private:
    std::string *pFirstName, *pLastName;
    int *pRating, *pAge;
};

struct Pizza {
    Pizza();

    ~Pizza();

    std::string *itsManufactured;
    float *itsDiameter;
    float *itsWeight;
};

Pizza::Pizza() {
    itsManufactured = new std::string{" "};
    itsDiameter = new float{0.0};
    itsWeight = new float{0.0};
    std::cout << "Good day! Please entered the next information about pizza:\n";
    std::cout << "The diameter of pissa in cm: ";
    std::cin >> *itsDiameter;
    std::cin.get();
    std::cout << "The Name of the company manufactured : ";
    std::getline(std::cin, *itsManufactured);
    std::cout << "The weight of the pizza: ";
    std::cin >> *(this->itsWeight);
    std::cout << "\nThank you for information!\nPizza manufactired: " << *(this->itsManufactured)
              << ", the diameter of pizza: " <<
              *(this->itsDiameter) << ", the weight is " << *(this->itsWeight) << std::endl;
}

Pizza::~Pizza() {
    delete itsManufactured, itsDiameter, itsWeight;
    itsManufactured = NULL, itsDiameter = NULL, itsWeight = NULL;
}

MyClass::MyClass() :
        pFirstName{new std::string("Dima")},
        pLastName{new std::string("Yukhimets")},
        pRating{new int(12)},
        pAge{new int(28)} {}

MyClass::~MyClass() {
    delete pFirstName, pLastName, pRating, pAge;
    pFirstName = NULL, pLastName = NULL, pRating = NULL, pAge = NULL;

}

void
MyClass::Resume() {// çàïðîñ è âûâîä äàííûõ ïîëüçîâàòåëÿ
    std::cout << "What is your first name?";
    std::cin >> *(this->pFirstName);
    std::cout << "What is your last name?";
    std::cin >> *(this->pLastName);
    std::cout << "What letter grade do you deserve?";
    std::cin >> *(this->pRating);
    std::cout << "What is your age?";
    std::cin >> *(this->pAge);
    std::cout << *(this->pLastName) << ", " << *(this->pFirstName) <<
              "\nRating: " << *(this->pRating) << "\nAge: " << *(this->pAge) << std::endl;
    return;
}


int main() {
    setlocale(LC_ALL, "RUS");
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
    using std::vector;
    using std::array;

    MyClass *Obj = new MyClass;
    Obj->Resume();

    constexpr int arSize = 80;
    char firstName[arSize]{};
    char lastName[arSize]{};

    cout << "Enter your first name: ";
    cin.getline(firstName, arSize);
    cout << "Enter your last name: ";
    cin.getline(lastName, arSize);
    cout << "Here's the information in a single string:" << lastName << ", " << firstName << endl;

    Pizza *Zeland = new Pizza[3];

    for (int i = 0; i < 3; ++i)
        cout << "Zeland[" << i << "].itsCompany = " << *(Zeland[i].itsManufactured) <<
             "Zeland[" << i << "].itsWeight = " << *(Zeland[i].itsWeight) <<
             "Zeland[" << i << "].itsDiameter = " << *(Zeland[i].itsDiameter) << endl;

    Pizza *My = new Pizza;

    array<double, 4> forty{};
    for (int i = 0; i < 3; ++i) {
        cout << "Please entered the time of " << i + 1 << " race (sec): ";
        cin >> forty[i];
        forty[3] += forty[i];
    }

    for (int i = 0; i < 3; ++i)
        cout << "Result of " << i + 1 << " race: " << forty[i] << endl;
    cout << "The average time of run: " << forty[3] / 3 << " sec\n";

    delete Obj;
    delete[] Zeland;
    Obj = NULL, Zeland = NULL;

    system("pause");
    return 0;
}