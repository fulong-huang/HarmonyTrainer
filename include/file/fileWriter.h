#pragma once
#include <iostream>
#include <fstream>

class FileWriter{
public:
	FileWriter();
	FileWriter(std::string fileName);
	~FileWriter();

	void openFile(std::string fileName);
	void closeFile();

	bool isOpen();
	bool writeToFile(std::string content);

private:
	FileWriter(FileWriter& f);
	FileWriter* operator=(FileWriter& f);

	std::ofstream writeFile;

};

