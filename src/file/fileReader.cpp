#include "fileReader.h"

FileReader::FileReader(std::string fileName){
	this->readFile = new std::ifstream(fileName);
}

FileReader::~FileReader(){
	this->readFile->close();
}

bool FileReader::isValidFile(){
	return this->readFile->is_open();
}


std::string FileReader::readLine(){
	std::string result;
	if(this->readFile->is_open()){
		std::getline(*this->readFile, result);
	}
	return result;
}
std::string FileReader::readRemaining(){
	std::string result;
	std::string line;
	if(this->readFile->is_open()){
		while(std::getline(*this->readFile, line)){
			result += line;
		}
	}
	return result;
}


