#pragma once
#include <unordered_map>
#include <vector>
enum ChordType{
	INTERVAL, TRAID, SEVENTH
};

struct TrainingSettings{
	ChordType chordType = INTERVAL;
	std::vector<int> chordRange = {36, 60};
	int waitTime = 2;
	int harmonicDuration = 2;
	int melodicDuration = 1;
	int newQuestionWaitTime = 2;

	friend std::ostream& operator<<(std::ostream &out, const TrainingSettings &item){
		std::string result;
		switch(item.chordType){
			case INTERVAL:
				result += "chord type: INTERVAL\n";
				break;
			case TRAID:
				result += "chord type: TRAID\n";
				break;
			case SEVENTH:
				result += "chord type: SEVENTH\n";
				break;
		}
		result += "chord range: " + std::to_string(item.chordRange[0]) + ", " + std::to_string(item.chordRange[1]);
		result += "\nwait time: " + std::to_string(item.waitTime);
		result += "\nharmonic duration: " + std::to_string(item.harmonicDuration);
		result += "\nmelodic duration: " + std::to_string(item.melodicDuration);
		result += "\nnew question wait time: " + std::to_string(item.newQuestionWaitTime);
		return out << result;
	}
};



