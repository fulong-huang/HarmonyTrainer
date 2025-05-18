#include <iostream>
#include "fileWriter.h"
#include "fileReader.h"
#include "trainingSettings.h"

class TrainingListIO{
public:
	TrainingListIO(std::string fileName = "customTrainingList.txt");
	~TrainingListIO();

	std::string to_string() const;

	std::vector<std::string> getListContent();

	bool addListItem(std::string itemName);
	
	bool createTrainingSettings(std::string fileName, TrainingSettings* settings);

	// TODO: 
	// renameFile

	friend std::ostream& operator<<(std::ostream &out, const TrainingListIO &t);

	std::vector<std::string> readListContent();
	TrainingSettings* readTrainingSettings(std::string fileName);

private:
	TrainingListIO(TrainingListIO& t);
	TrainingListIO* operator=(TrainingListIO& t);

	std::string trainingListFileName;
	std::vector<std::string> trainingListContent;

	void assignListContent();
};


