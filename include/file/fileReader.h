#include <iostream>
#include <fstream>

class FileReader{
public:
	FileReader(std::string fileName);
	~FileReader();

	bool isValidFile();

	std::string readLine();
	std::string readRemaining();

private:
	FileReader(FileReader& f);
	FileReader* operator=(FileReader& f);

	std::ifstream* readFile;

};




