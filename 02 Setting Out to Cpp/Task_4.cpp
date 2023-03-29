#include <iostream>

int converts(int a) { return a * 12; }

int main() {
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;
    std::cout << "Your age in months is " << converts(age) << std::endl;
    return 0;
}
