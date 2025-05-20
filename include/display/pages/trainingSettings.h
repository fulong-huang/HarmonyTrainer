#pragma once
#include <unordered_map>
#include <vector>
enum ChordType{
	INTERVAL, TRAID, SEVENTH
};
enum PlayBackMode{
	MELODIC, HARMONIC
};

struct TrainingSettings{
	ChordType chordType = INTERVAL;
	PlayBackMode playBackMode = MELODIC;
	std::vector<int> chordRange = {36, 60};
	std::vector<int> chordChoice = {4, 7};
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
		switch(item.playBackMode){
			case MELODIC:
				result += "play back mode: MELODIC\n";
				break;
			case HARMONIC:
				result += "play back mode: HARMONIC\n";
				break;
		}
		result += "chord range: {" + std::to_string(item.chordRange[0]) + ", " + std::to_string(item.chordRange[1]) + '}';
		result += "\nchord choice: {" + std::to_string(item.chordChoice[0]);
		for(int i = 1; i < item.chordChoice.size(); i++){
			result += ", " + std::to_string(item.chordChoice[i]);
		}
		result += '}';
		result += "\nwait time: " + std::to_string(item.waitTime);
		result += "\nharmonic duration: " + std::to_string(item.harmonicDuration);
		result += "\nmelodic duration: " + std::to_string(item.melodicDuration);
		result += "\nnew question wait time: " + std::to_string(item.newQuestionWaitTime);
		return out << result;
	}
};



