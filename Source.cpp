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

    cout << "������� ���� � �����: ";
    getline(cin, folderPath);

    cout << "������� ����� ��� ������: ";
    getline(cin, searchWord);

    cout << "�� ������ ������� ������� �����? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        removeWord = true;
    }
    else {
        cout << "������� ����� ��� ������: ";
        cin >> replaceWord;
    }

    a.searchAndReplace(folderPath, searchWord, replaceWord, removeWord);

    return 0;
}