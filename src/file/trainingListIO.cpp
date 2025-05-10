#include "trainingListIO.h"

TrainingListIO::TrainingListIO(std::string fileName)
    : trainingListFileName(fileName) {
	this->assignListContent();
}

TrainingListIO::~TrainingListIO() {}

std::vector<std::string> TrainingListIO::getListContent(){
	return this->trainingListContent;
}

bool TrainingListIO::addListItem(std::string itemName) {
  // TODO:
  // 	Validate item name characters No special characters
  FileWriter fileWriter(this->trainingListFileName);
  try {
    bool success =
        fileWriter.writeToFile(this->to_string() + itemName);
    fileWriter.closeFile();
    if (success) {
			this->trainingListContent.push_back(itemName);
    }
    return success;
  } catch (...) {
    fileWriter.closeFile();
    return false;
  }
}

void TrainingListIO::assignListContent(){
	std::string contentString;
	FileReader fileReader(this->trainingListFileName);
	std::string currString = fileReader.readLine();
	while(currString.size() > 0){
		this->trainingListContent.push_back(currString);
		currString = fileReader.readLine();
	}
}

std::string TrainingListIO::to_string() const{
	std::string result;
	for(std::string str: this->trainingListContent){
		result += str + '\n';
	}
	return result;
}

std::ostream& operator<<(std::ostream &out, const TrainingListIO &t){
	out << t.to_string();
	return out;
}

