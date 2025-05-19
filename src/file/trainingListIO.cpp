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
	this->trainingListContent = this->readListContent();
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

bool TrainingListIO::createTrainingSettings(std::string fileName, TrainingSettings* settings){
	// TODO: 
	// 	When attempting to crteate file,
	// 	must check if name is valid.
	// 	Valid name required at least one alphanumeric character
	FileWriter fileWriter("customTrainings/"+fileName);

	switch(settings->chordType){
		case INTERVAL:
			fileWriter.writeToFile("chord type: 0\n");
			break;
		case TRAID:
			fileWriter.writeToFile("chord type: 1\n");
			break;
		case SEVENTH:
			fileWriter.writeToFile("chord type: 2\n");
			break;
	}
	fileWriter.writeToFile("chord range: {" + std::to_string(settings->chordRange[0]) + ", " + std::to_string(settings->chordRange[1]) + "}\n");
	fileWriter.writeToFile("wait time: " + std::to_string(settings->waitTime) + '\n');
	fileWriter.writeToFile("harmonic duration: " + std::to_string(settings->harmonicDuration) + '\n');
	fileWriter.writeToFile("melodic duration: " + std::to_string(settings->melodicDuration) + '\n');
	fileWriter.writeToFile("new question wait time: " + std::to_string(settings->newQuestionWaitTime));
	return true;
}

std::vector<std::string> TrainingListIO::readListContent(){
	FileReader fileReader(this->trainingListFileName);
	std::vector<std::string> result;
	std::string currString = fileReader.readLine();
	while(currString.size() > 0){
		result.push_back(currString);
		currString = fileReader.readLine();
	}
	return result;
}

void TrainingListIO::loadTrainingSettings(std::string fileName, SoundControl* soundControl){
	FileReader fileReader("customTrainings/"+fileName);
	TrainingSettings trainingSettings;
	std::string currLine = fileReader.readLine();
	static const std::unordered_map<std::string, int> m = {
		{"chord type", 0},
		{"chord range", 1},
		{"wait time", 2},
		{"harmonic duration", 3},
		{"melodic duration", 4},
		{"new question wait time", 5},
	};
	while(currLine.size() != 0){
		std::string settingName, settingValue;
		std::size_t separateCharacterIndex = currLine.find(':');
		if(separateCharacterIndex == std::string::npos){
			// TODO: 
			//  File most likely curropted
			//  Rewrite file?
			break;
		}
		settingName = currLine.substr(0, separateCharacterIndex);
		// index + 2 to skip the space
		settingValue = currLine.substr(separateCharacterIndex + 2);

		switch(m.at(settingName)){
			case 0:
				if(settingValue.size() != 1){
					std::cerr << "Chord Type incorrect value" << std::endl;
					trainingSettings.chordType = INTERVAL;
				}
				else{
					trainingSettings.chordType = ChordType(settingValue[0] - '0');
				}
				break;
			case 1:
				settingValue = settingValue.substr(1, settingValue.size()-2);
				separateCharacterIndex = settingValue.find(',');
				if(separateCharacterIndex != std::string::npos){
					int start = std::stoi(settingValue.substr(0, separateCharacterIndex));
					int end = std::stoi(settingValue.substr(separateCharacterIndex + 2));
					trainingSettings.chordRange = {start, end};
				}
				else{
					std::cerr << "interval range required two values" << std::endl;
				}
				break;
			case 2:
				for(char c : settingValue){
					if(!std::isdigit(c)){
						std::cerr << "Wait time is not a number" << std::endl;
						settingValue = "2";
						break;
					}
				}
				trainingSettings.waitTime = std::stoi(settingValue);
				break;
			case 3:
				for(char c : settingValue){
					if(!std::isdigit(c)){
						std::cerr << "harmonic time is not a number" << std::endl;
						settingValue = "2";
						break;
					}
				}
				trainingSettings.harmonicDuration = std::stoi(settingValue);
				break;
			case 4:
				for(char c : settingValue){
					if(!std::isdigit(c)){
						std::cerr << "melodic time is not a number" << std::endl;
						settingValue = "1";
						break;
					}
				}
				trainingSettings.melodicDuration = std::stoi(settingValue);
				break;
			case 5:
				for(char c : settingValue){
					if(!std::isdigit(c)){
						std::cerr << "new question time is not a number" << std::endl;
						settingValue = "2";
						break;
					}
				}
				trainingSettings.newQuestionWaitTime = std::stoi(settingValue);
				break;
		}
		currLine = fileReader.readLine();
	}
	std::cout << trainingSettings << std::endl;
	soundControl->setSoundControl(&trainingSettings);
}






