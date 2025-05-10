#include "fileReader.h"

const std::string SAVE_FILE_PATH = []{
	std::string srcDir = std::__fs::filesystem::path(__FILE__).parent_path();
	srcDir += "/../../saves/";
	return srcDir;
}();

FileReader::FileReader(){
}

FileReader::FileReader(std::string fileName){
	this->readFile.open(SAVE_FILE_PATH + fileName);
}

FileReader::~FileReader(){
	if(this->readFile.is_open()){
		this->readFile.close();
	}
}

void FileReader::openFile(std::string fileName){
	if(this->readFile.is_open()){
		this->readFile.close();
	}
}

bool FileReader::isValidFile(){
	return this->readFile.is_open();
}


std::string FileReader::readLine(){
	std::string result;
	if(this->readFile.is_open()){
		std::getline(this->readFile, result);
	}
	return result;
}
std::string FileReader::readRemaining(){
	std::string result;
	std::string line;
	if(this->readFile.is_open()){
		while(std::getline(this->readFile, line)){
			result += line;
		}
	}
	return result;
}


