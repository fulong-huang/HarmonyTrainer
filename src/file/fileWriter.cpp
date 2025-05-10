#include "fileWriter.h"

const std::string SAVE_FILE_PATH = []{
	std::string srcDir = std::__fs::filesystem::path(__FILE__).parent_path();
	srcDir += "/../../saves/";
	return srcDir;
}();


FileWriter::FileWriter(){
}

FileWriter::FileWriter(std::string fileName){
	this->openFile(fileName);
}

FileWriter::~FileWriter(){
	this->closeFile();
}

void FileWriter::openFile(std::string fileName){
	this->closeFile();
	this->writeFile.open(SAVE_FILE_PATH + fileName);
}

void FileWriter::closeFile(){
	if(this->writeFile.is_open()){
		this->writeFile.close();
	}
}

bool FileWriter::isOpen(){
	return this->writeFile.is_open();
}

bool FileWriter::writeToFile(std::string content){
	try{
		this->writeFile << content;
	}
	catch(...){
		std::cerr << "Exception occured during file writing\n"
			"File Content: \n\t"
			"\t" << content << "\nEND of File Content"
			<< std::endl;
		return false;
	}
	return true;
}

