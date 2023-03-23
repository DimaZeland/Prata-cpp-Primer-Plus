#include "MyClass.h"

int main() {

    MyClass *pObject = new MyClass;
    // Exercise 1
    cout << "\nExercise 1\n";
    pObject->OutputLine(pObject->GetpItsStr(), pObject->GetitsCalls());
    // Exercise 2
    cout << "\nExercise 2\n";
    CandyBar *pCand = new CandyBar;
    pObject->DefinitionCandyBar(*pCand);
    pObject->ShowCandyBar(*pCand);
    // Exercise 3
    cout << "\nExercise 3\n";
    std::string str = "cpp is the best programming language";
    cout << "\nEnter a string (q to quit): ";
    cin >> str;
    while (str != "q") {
        pObject->UppercaseTranslation(str);
        cout << str << endl;
        cout << "\nNext string (q to quit): ";
        cin >> str;
    }
    cout << "\nBye.";
    pObject->UppercaseTranslation(str);
    cout << str << endl;
    // Exercise 5
    cout << "\nExercise 5\n";
    int Arr1[5]{1, 2, 3, 4, 5};
    cout << "Max value in Arr[5] (int) is " << max5(Arr1) << '\n';
    double Arr2[5]{1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "Max value in Arr[5] (double) is " << max5(Arr2) << '\n';
    // Exercise 6
    cout << "\nExercise 6\n";
    int Arr3[6]{1, 2, 3, 4, 5, 6};
    cout << "Max value in Arr[6] (int) is " << maxn(Arr3, 6) << '\n';
    double Arr4[4]{1.1, 2.2, 3.3, 4.4};
    cout << "Max value in Arr[4] (double) is " << maxn(Arr4, 4) << '\n';
    char one[4] = "One";
    char two[4] = "Two";
    char three[6] = "Three";
    char *Arr5[3]{one, two, three};
    cout << "Max value in Arr[5] (const char*) is " << maxn(Arr5, 3) << '\n';
    delete pObject, pCand;
    pObject = NULL, pCand = NULL;
    system("pause");
    return 0;
}

template<typename T>
// Exercise 6
T maxn(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

template<>
// Exercise 6 specialization of the function template for the type char
char *maxn<char *>(char *arr[], int size) {
    int max = strlen(arr[0]), max_index = 0;
    for (int i = 1; i < size; ++i)
        if (strlen(arr[i]) > max) {
            max = strlen(arr[i]);
            max_index = i;
        }
    return arr[max_index];
}
