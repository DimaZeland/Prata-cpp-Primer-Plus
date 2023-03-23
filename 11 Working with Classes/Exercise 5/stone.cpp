// stone.cpp -- user-defined conversions
// compile with stonewt.cpp
#include <iostream>

using std::cout;

#include "stonewt.h"

void display(Stonewt &st, int n);

int main() {
    Stonewt incognito = (275, Stonewt::STOUN); // uses constructor to initialize
    Stonewt wolfe(285.7, Stonewt::POUND);    // same as Stonewt wolfe = 285.7;
    Stonewt taft(21, 8, Stonewt::STOUNPOUNDS);

    cout << "The celebrity weighed " << incognito << '\n';
    cout << "The detective weighed " << wolfe << '\n';
    cout << "The President weighed " << taft << '\n';
    incognito = 276.8;      // uses constructor for conversion
    taft = 325;             // same as taft = Stonewt(325);
    cout << "After dinner, the celebrity weighed " << incognito << '\n';
    cout << "After dinner, the President weighed " << taft << '\n';
    display(taft, 2);
    cout << "The wrestler weighed even more.\n";
    display(incognito, 2);
    cout << "No stone left unearned\n";
    system("pause");
    return 0;
}

void display(Stonewt &st, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Wow! ";
        cout << st << '\n';
    }
}
