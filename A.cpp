#include "A.h"

void A::searchAndReplace(const string& folderPath, const string& searchWord, const string& replaceWord, bool removeWord)
{

    int matches = 0;
    for (const auto& entry : filesystem::recursive_directory_iterator(folderPath)) {
        if (!entry.is_regular_file()) {
            continue;
        }

        string filePath = entry.path().string();

        ifstream inputFile(filePath);
        ofstream outputFile(filePath + ".tmp"); 

        string line;
        while (getline(inputFile, line)) {
            size_t pos = line.find(searchWord);
            if (pos != string::npos) {
                matches++;
                if (removeWord) {
                    line.erase(pos, searchWord.length());
                }
                else {
                    line.replace(pos, searchWord.length(), replaceWord);
                }
            }
            outputFile << line << endl; 
        }

        inputFile.close();
        outputFile.close();

        
        filesystem::rename(filePath + ".tmp", filePath);
    }

    if (matches == 0) {
        cout << "Совпадений не найдено." << endl;
    }
    else {
        cout << "Всего найдено совпадений: " << matches << endl;
    }
}
