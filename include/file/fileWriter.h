#include <iostream>
#include <fstream>

const std::string SAVE_FILE_PATH = []{
  std::string srcDir = std::__fs::filesystem::path(__FILE__).parent_path();
  srcDir += "/../../saves/";
	return srcDir;
}();

class FileWriter{
public:
	FileWriter(std::string fileName);
	~FileWriter();

	bool isValidFile();
	bool writeToFile(std::string content);

private:
	FileWriter(FileWriter& f);
	FileWriter* operator=(FileWriter& f);

	std::ofstream* writeFile;

};

