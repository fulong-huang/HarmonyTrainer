#include "noteGenBySteps.h"

NoteGenBySteps::NoteGenBySteps(){
}

NoteGenBySteps::~NoteGenBySteps(){
}

void NoteGenBySteps::generateRandomNote(std::vector<Notes *> &harmonyNotes,
                        std::vector<Notes *> &melodyNotes,
                        std::vector<int> harmonyGaps,
												int lowerBound, int upperBound
												) {
	
	std::cout << "FUNC CALLED: " << std::endl;
	// TODO:
	// 	Reuse Notes instead of cleaning them all up
  for (Notes *note : melodyNotes) {
    note->stop();
    std::cout << "Delete a note" << std::endl;
    delete note;
  }
	std::cout << "Clearning notes" << std::endl;
  melodyNotes.clear();
  harmonyNotes.clear();
  std::cout << "RETURNING FROM CLEAN UP" << std::endl;
  int currNoteNumber = lowerBound + (std::rand() % (upperBound - lowerBound + 1));
  bool isFirstHarmony = std::rand() % 2;
  int lastNote = currNoteNumber + harmonyGaps[isFirstHarmony];

  Notes *currNote = new Notes(currNoteNumber);
  harmonyNotes.push_back(currNote);
  melodyNotes.push_back(currNote);
  for (int i = 0; i < 7; i++) {
    currNoteNumber += MajorSteps[i];
    if (currNoteNumber >= lastNote) {
      break;
    }
    currNote = new Notes(currNoteNumber);
    melodyNotes.push_back(currNote);
  }
  currNote = new Notes(lastNote);
  harmonyNotes.push_back(currNote);
  melodyNotes.push_back(currNote);

}
