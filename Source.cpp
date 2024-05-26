#include <iostream> 
#include <fstream> 
#include <filesystem> 
#include <string> 
#include "A.h"

using namespace std;
int main() {
    A a;
    string folderPath, searchWord, replaceWord;
    bool removeWord = false;

    cout << "Введите путь к папке: ";
    getline(cin, folderPath);

    cout << "Введите слово для поиска: ";
    getline(cin, searchWord);

    cout << "Вы хотите удалить искомое слово? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        removeWord = true;
    }
    else {
        cout << "Введите слово для замены: ";
        cin >> replaceWord;
    }

    a.searchAndReplace(folderPath, searchWord, replaceWord, removeWord);

    return 0;
}