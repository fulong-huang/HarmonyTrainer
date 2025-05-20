#include "noteGenMelodic.h"

NoteGenMelodic::NoteGenMelodic(){
}

NoteGenMelodic::~NoteGenMelodic(){
	this->cleanupNotes();
}

void NoteGenMelodic::cleanupNotes(){
	this->chordChoices.clear();
	this->stopAllNotes();
	for(Notes* note : this->melodicNotes){
		delete note;
	}
	this->melodicNotes.clear();
	this->harmonicNotes.clear();
}

void NoteGenMelodic::generateRandomNote() {
	if(this->chordChoices.size() == 0){
		std::cerr << "Chord choices not initialized" << std::endl;
		this->setChords({3, 5});
	}
  int currNoteNumber = this->lowerBound + (std::rand() % (this->upperBound - this->lowerBound + 1));
  int chosenChordIndex = std::rand() % this->chordChoices.size();
  int endingNote = currNoteNumber + this->chordChoices[chosenChordIndex];
	this->currentNoteIndex = -1;

  this->melodicNotes[0]->setNote(currNoteNumber);
  this->harmonicNotes[0] = this->melodicNotes[0];
	this->endingNoteIndex = 1;
  for (int i = 0; i < 7; i++) {
    currNoteNumber += MajorSteps[i];
		this->endingNoteIndex++;
    if (currNoteNumber >= endingNote) {
      break;
    }
    this->melodicNotes[i + 1]->setNote(currNoteNumber);
  }
	this->melodicNotes[this->endingNoteIndex-1]->setNote(endingNote);
  this->harmonicNotes[1] = this->melodicNotes[this->endingNoteIndex-1];
}

void NoteGenMelodic::playSelectedChord(){
	this->harmonicNotes[0]->start();
	this->harmonicNotes[1]->start();
}
void NoteGenMelodic::stopSelectedChord(){
	this->harmonicNotes[0]->stop();
	this->harmonicNotes[1]->stop();
}

bool NoteGenMelodic::playValidationNotes(){
	if(this->currentNoteIndex >= 0){
		this->melodicNotes[this->currentNoteIndex]->stop();
	}
	this->currentNoteIndex++;
	if(this->currentNoteIndex >= this->endingNoteIndex){
		return false;
	}
	this->melodicNotes[this->currentNoteIndex]->start();
	return true;
}

void NoteGenMelodic::stopAllNotes(){
	for(Notes* note: this->melodicNotes){
		note->stop();
	}
}

void NoteGenMelodic::setChords(std::vector<int> chords){
	this->cleanupNotes();
	this->chordChoices = chords;
	for(int i = 0; i < chords[chords.size()-1]; i++){
		this->melodicNotes.push_back(new Notes());
	}
	this->harmonicNotes.push_back(new Notes());
	this->harmonicNotes.push_back(new Notes());
}

