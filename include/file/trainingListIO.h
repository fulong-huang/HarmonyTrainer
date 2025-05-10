#include <iostream>
#include "fileWriter.h"
#include "fileReader.h"

class TrainingListIO{
public:
	TrainingListIO(std::string fileName = "customTrainingList.txt");
	~TrainingListIO();

	std::string to_string() const;

	std::vector<std::string> getListContent();

	bool addListItem(std::string itemName);

	friend std::ostream& operator<<(std::ostream &out, const TrainingListIO &t);

private:
	TrainingListIO(TrainingListIO& t);
	TrainingListIO* operator=(TrainingListIO& t);

	std::string trainingListFileName;
	std::vector<std::string> trainingListContent;

	void assignListContent();
};


