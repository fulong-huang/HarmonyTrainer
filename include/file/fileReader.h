#pragma once
#include <iostream>
#include <fstream>
#include "trainingSettings.h"

class FileReader{
public:
	FileReader();
	FileReader(std::string fileName);
	~FileReader();

	void openFile(std::string fileName);
	void closeFile();
	bool isValidFile();

	std::string readLine();
	std::string readRemaining();

private:
	FileReader(FileReader& f);
	FileReader* operator=(FileReader& f);

	std::ifstream readFile;

};




