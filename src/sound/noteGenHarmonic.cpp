#include "noteGenHarmonic.h"

NoteGenHarmonic::NoteGenHarmonic(){
}

NoteGenHarmonic::~NoteGenHarmonic(){
	this->cleanupNotes();
}

void NoteGenHarmonic::cleanupNotes(){
	for(Notes* note : this->chordNotes){
		delete note;
	}
	this->chordNotes.clear();
	if(this->rootNote){
		delete this->rootNote;
	}
}

void NoteGenHarmonic::generateRandomNote() {
	if(this->chordChoices.size() == 0){
		std::cerr << "Chord choices not initialized" << std::endl;
		this->setChords({3, 5});
	}
  int currNoteNumber = this->lowerBound + (std::rand() % (this->upperBound - this->lowerBound + 1));
  this->chosenIndex = std::rand() % this->chordChoices.size();

  this->rootNote->setNote(currNoteNumber);
  for (int i = 0; i < this->chordChoices.size(); i++) {
		this->chordNotes[i]->setNote(currNoteNumber + this->chordChoices[i]);
  }
	this->currentNoteIndex = -1;
}

void NoteGenHarmonic::playSelectedChord(){
	this->rootNote->start();
	this->chordNotes[this->chosenIndex]->start();
}
void NoteGenHarmonic::stopSelectedChord(){
	this->rootNote->stop();
	this->chordNotes[this->chosenIndex]->stop();
}

bool NoteGenHarmonic::playValidationNotes(){
	if(this->currentNoteIndex >= 0){
		this->rootNote->stop();
		this->chordNotes[this->currentNoteIndex]->stop();
	}
	this->currentNoteIndex++;
	if(this->currentNoteIndex >= this->chordChoices.size()){
		return false;
	}
	this->rootNote->start();
	this->chordNotes[this->currentNoteIndex]->start();
	return true;
}

void NoteGenHarmonic::stopAllNotes(){
	for(Notes* note: this->chordNotes){
		note->stop();
	}
	this->rootNote->stop();
}

void NoteGenHarmonic::setChords(std::vector<int> chords){
	this->cleanupNotes();
	this->chordChoices = chords;
	for(int i = 0; i < chords.size(); i++){
		this->chordNotes.push_back(new Notes());
	}
	this->rootNote = new Notes();
}

