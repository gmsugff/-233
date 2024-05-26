#pragma once
#include <string>
#include <iostream> 
#include <fstream> 
#include <filesystem> 
#include <string> 
class A {
public:
	void searchAndReplace(const string& folderPath, const string& searchWord, const string& replaceWord, bool removeWord);
};