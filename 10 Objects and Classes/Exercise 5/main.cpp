// stacker.cpp -- testing the Stack class
#include <iostream>
#include <cctype>  // or ctype.h
#include "Stack.h"

int main() {
    using namespace std;
    Stack st; // create an empty stack
    char ch;
    customer str;
    double payroll = 0;
    cout << "Please enter A to push a customer,\n"
         << "P to pop a customer, or Q to quit: ";
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch) {
            case 'A':
            case 'a': {
                if (st.isfull()) {
                    cout << "stack already full\n";
                    break;
                } else {
                    cout << "Enter a customer fullname to add: ";
                    cin >> str.fullname;
                    cout << "Enter a customer payment to add: ";
                    cin >> str.payment;
                    st.push(str);
                    break;
                }
            }
            case 'P':
            case 'p': {
                if (st.isempty())
                    cout << "stack already empty\n";
                else {
                    st.pop(str);
                    cout << "\ncustomer" << str.fullname << " popped\n";
                    payroll += str.payment;
                    cout << "\nTotal salary paid: " << payroll << '\n';
                }
                break;
            }
        }
        cout << "Please enter A to push a customer,\n"
             << "P to pop a customer, or Q to quit: ";
    }
    cout << "Bye\n";
    return 0;
}
