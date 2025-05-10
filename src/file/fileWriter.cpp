#include "fileWriter.h"

const std::string SAVE_FILE_PATH = []{
	std::string srcDir = std::__fs::filesystem::path(__FILE__).parent_path();
	srcDir += "/../../saves/";
	return srcDir;
}();


FileWriter::FileWriter(){
}

FileWriter::FileWriter(std::string fileName){
	this->writeFile.open(SAVE_FILE_PATH + fileName);
}

FileWriter::~FileWriter(){
	if(this->writeFile.is_open()){
		this->writeFile.close();
	}
}

void FileWriter::openFile(std::string fileName){
	if(this->writeFile.is_open()){
		this->writeFile.close();
	}
	this->writeFile.open(SAVE_FILE_PATH + fileName);
}

bool FileWriter::isValidFile(){
	return this->writeFile.is_open();
}

bool FileWriter::writeToFile(std::string content){
	this->writeFile << content;
	return true;
}

