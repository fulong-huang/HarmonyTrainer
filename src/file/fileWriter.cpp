#include "fileWriter.h"

FileWriter::FileWriter(std::string fileName){
	this->writeFile = new std::ofstream(SAVE_FILE_PATH + fileName);
}

FileWriter::~FileWriter(){
	this->writeFile->close();
}

bool FileWriter::isValidFile(){
	return this->writeFile->is_open();
}

bool FileWriter::writeToFile(std::string content){
	*this->writeFile << content;
	return true;
}

